#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <cmath>
#include <iostream>

#pragma pack(push, 1)
typedef struct tagBITMAPFILEHEADER_ {
	unsigned short		bfType;
	unsigned long		bfSize;
	unsigned short		bfReserved1;
	unsigned short		bfReserved2;
	unsigned long		bfOffBits;
} BITMAPFILEHEADER_;

typedef struct tagBITMAPINFOHEADER_ {
	unsigned long       		biSize;
	long				biWidth;
	long				biHeight;
	unsigned short      		biPlanes;
	unsigned short      		biBitCount;
	unsigned long       		biCompression;
	unsigned long       		biSizeImage;
	long				biXPelsPerMeter;
	long				biYPelsPerMeter;
	unsigned long       		biClrUsed;
	unsigned long       		biClrImportant;
} BITMAPINFOHEADER_;

typedef struct tagRGBQUAD_ {
	unsigned char    rgbBlue;
	unsigned char    rgbGreen;
	unsigned char    rgbRed;
	unsigned char    rgbReserved;
} RGBQUAD_;
#pragma pack(pop)

#define BI_RGB_        0L

template<class T>
T** matrix(int nH, int nW) {
	T** temp;

	temp = new T * [nH];
	for (int y = 0; y < nH; ++y)
		temp[y] = new T[nW];

	return temp;
}

template<class T>
void free_matrix(unsigned char ** img, int nH, int nW) {
	for (int i = 0; i < nH; i++)
		delete[] img[i];

	delete[] img;
}

class CImage {
public:
	int m_nW, m_nH;
	unsigned char** m_Red, ** m_Green, ** m_Blue;

	CImage();
	CImage(int nW, int nH, unsigned char r, unsigned char g, unsigned char b);
	~CImage();

	void ReadBmp(const char* FileName);
	bool SaveBmp(const char* FileName);
	void DrawLine(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b);
};

CImage::CImage() : m_nW(0), m_nH(0) {
	m_Red = m_Green = m_Blue = nullptr;
}

CImage::CImage(int nW, int nH, unsigned char r, unsigned char g, unsigned char b) : m_nW(nW), m_nH(nH) {
	m_Red = matrix<unsigned char>(m_nH, m_nW);
	m_Green = matrix<unsigned char>(m_nH, m_nW);
	m_Blue = matrix<unsigned char>(m_nH, m_nW);

	for (int y = 0; y < m_nH; ++y)
		for (int x = 0; x < m_nW; ++x) {
			m_Red[y][x] = r;
			m_Green[y][x] = g;
			m_Blue[y][x] = b;
		}
}

CImage::~CImage() {
	if(m_Red) free_matrix<unsigned char>(m_Red, m_nH, m_nW);
	if(m_Green) free_matrix<unsigned char>(m_Green, m_nH, m_nW);
	if(m_Blue) free_matrix<unsigned char>(m_Blue, m_nH, m_nW);
}

void DrawLine(unsigned char** img, int nW, int nH, int x0, int y0, int x1, int y1, unsigned char g) {
	if (x0 > x1) {
		int tmp1 = x0;
		int tmp2 = y0;
		x0 = x1; y0 = y1;
		x1 = tmp1; y1 = tmp2;
	}
	// Sketch line
	if (x1 == x0) {
		if (y0 > y1) {
			int tmp1 = x0;
			int tmp2 = y0;
			x0 = x1; y0 = y1;
			x1 = tmp1; y1 = tmp2;
		}
		for (int y = y0; y < y1; y++)
			img[y][x0] = g;
	}
	else if (y1 == y0) {
		for (int x = x0; x < x1; x++)
			img[y0][x] = g;
	}
	else if (abs(x1 - x0) >= abs(y1- y0)) {
		int y;
		for (int x = x0; x < x1; x++){
			y = static_cast<int>((static_cast<double>(y1) - y0) / (static_cast<double>(x1) - x0) * x + y0);
			img[y][x] = g;
		}
	}
	else {
		if (y0 > y1) {
			int tmp1 = x0;
			int tmp2 = y0;
			x0 = x1; y0 = y1;
			x1 = tmp1; y1 = tmp2;
		}
		int x;
		for (int y = y0; y < y1; y++) {
			x = static_cast<int>((static_cast<double>(x1) - x0) / (static_cast<double>(y1) - y0) * y + x0);
			img[y][x] = g;
		}
	}
}

void CImage::ReadBmp(const char* FileName) {
	if(m_Red) free_matrix<unsigned char>(m_Red, m_nH, m_nW);
	if(m_Green) free_matrix<unsigned char>(m_Green, m_nH, m_nW);
	if(m_Blue) free_matrix<unsigned char>(m_Blue, m_nH, m_nW);

	m_Red = m_Green = m_Blue = nullptr;

	BITMAPFILEHEADER_ bmiFileHeader;
	BITMAPINFOHEADER_ bmiHeader;

	FILE* fp;
	int nColors;

	fp = fopen(FileName, "rb");

	if (!fp) return;

	fread(&bmiFileHeader, sizeof(BITMAPFILEHEADER_), 1, fp);

	if (bmiFileHeader.bfType != 'M' * 0x0100 + 'B') {
		fclose(fp);
		return;
	}

	fread(&bmiHeader, sizeof(BITMAPINFOHEADER_), 1, fp);

	if (bmiHeader.biCompression != BI_RGB_) {
		fclose(fp);
		return;
	}

	if (bmiHeader.biClrUsed == 0)
		nColors = 1 << bmiHeader.biBitCount;
	else
		nColors = bmiHeader.biClrUsed;

	RGBQUAD_* Palette = nullptr;

	switch (bmiHeader.biBitCount) {
	case 24:
		break;

	case 1:
	case 4:
	case 8:
		Palette = new RGBQUAD_[nColors];

		int i;
		for (i = 0; i < nColors; i++) {
			unsigned char r, g, b, temp;

			fread(&b, sizeof(unsigned char), 1, fp);
			fread(&g, sizeof(unsigned char), 1, fp);
			fread(&r, sizeof(unsigned char), 1, fp);
			fread(&temp, sizeof(unsigned char), 1, fp);

			Palette[i].rgbRed = r;
			Palette[i].rgbGreen = g;
			Palette[i].rgbBlue = b;
		}
		break;
	}

	fseek(fp, bmiFileHeader.bfOffBits, SEEK_SET);

	m_nW = bmiHeader.biWidth;
	m_nH = bmiHeader.biHeight;

	m_Red = matrix<unsigned char>(m_nH, m_nW);
	m_Green = matrix<unsigned char>(m_nH, m_nW);
	m_Blue = matrix<unsigned char>(m_nH, m_nW);

	unsigned char* Image1D = nullptr;

	Image1D = new unsigned char[m_nH * ((m_nW * 3 + 3) / 4 * 4)];

	if (bmiHeader.biBitCount == 24)
		fread(Image1D, sizeof(unsigned char), m_nH * ((m_nW * 3 + 3) / 4 * 4), fp);

	long Row, Col;

	for (Row = 0; Row < bmiHeader.biHeight; Row++)
	{
		if (bmiHeader.biBitCount != 24)
		{
			int BitCount = 0;
			unsigned int mask = (1 << bmiHeader.biBitCount) - 1;

			unsigned char ReadByte = 0;
			int ReadByteCnt = 0;

			for (Col = 0; Col < m_nW; Col++)
			{
				int PaletteIndex = 0;

				if (BitCount <= 0) {
					BitCount = 8;
					fread(&ReadByte, sizeof(unsigned char), 1, fp);
					ReadByteCnt++;
				}

				BitCount -= bmiHeader.biBitCount;

				PaletteIndex = (ReadByte >> BitCount) & mask;

				int Pos;

				Pos = (((m_nW * 3 + 3) / 4 * 4) * Row) + Col * 3;
				Image1D[Pos++] = Palette[PaletteIndex].rgbBlue;
				Image1D[Pos++] = Palette[PaletteIndex].rgbGreen;
				Image1D[Pos] = Palette[PaletteIndex].rgbRed;
			}

			while (ReadByteCnt & 3)
			{
				char temp;
				fread(&temp, sizeof(char), 1, fp);
				ReadByteCnt++;
			}
		}
	}

	if (Palette) delete[] Palette;

	fclose(fp);

	for (int y = 0; y < m_nH; y++)
		for (int x = 0; x < m_nW; x++) {
			int pos = (m_nW * 3 + 3) / 4 * 4 * (m_nH - y - 1) + x * 3;

			m_Red[y][x] = Image1D[pos + 2];
			m_Green[y][x] = Image1D[pos + 1];
			m_Blue[y][x] = Image1D[pos];
		}

	delete[] Image1D;
}

bool CImage::SaveBmp(const char* FileName) {
	if (m_Red == nullptr) return false;
	if (m_Green == nullptr) return false;
	if (m_Blue == nullptr) return false;

	unsigned char* Image1D = new unsigned char[m_nH * ((m_nW * 3 + 3) / 4 * 4)];

	for (int y = 0; y < m_nH; y++)
		for (int x = 0; x < m_nW; x++)
		{
			int pos = (m_nW * 3 + 3) / 4 * 4 * (m_nH - y - 1) + x * 3;

			Image1D[pos + 2] = m_Red[y][x];
			Image1D[pos + 1] = m_Green[y][x];
			Image1D[pos] = m_Blue[y][x];
		}

	unsigned long dwBitsSize;

	unsigned long widthDW = (m_nW * 3 + 3) / 4 * 4;;
	unsigned long size = widthDW * m_nH;
	dwBitsSize = sizeof(BITMAPFILEHEADER_) + sizeof(BITMAPINFOHEADER_) + size;

	BITMAPINFOHEADER_ bmiHeader;
	bmiHeader.biSize = sizeof(BITMAPINFOHEADER_);
	bmiHeader.biWidth = m_nW;
	bmiHeader.biHeight = m_nH;
	bmiHeader.biPlanes = 1;
	bmiHeader.biBitCount = 24;
	bmiHeader.biCompression = BI_RGB_;
	bmiHeader.biSizeImage = size;
	bmiHeader.biXPelsPerMeter = 200;
	bmiHeader.biYPelsPerMeter = 200;
	bmiHeader.biClrUsed = 0;
	bmiHeader.biClrImportant = 0;

	BITMAPFILEHEADER_ bmiFileHeader;
	bmiFileHeader.bfType = 'M' * 0x0100 + 'B';
	bmiFileHeader.bfSize = dwBitsSize;
	bmiFileHeader.bfReserved1 = 0;
	bmiFileHeader.bfReserved2 = 0;
	bmiFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER_) + sizeof(BITMAPINFOHEADER_);

	FILE* fp;

	fp = fopen(FileName, "wb");
	if (!fp) return false;

	fwrite(&bmiFileHeader, 1, sizeof(BITMAPFILEHEADER_), fp);
	fwrite(&bmiHeader, 1, sizeof(BITMAPINFOHEADER_), fp);
	fwrite(Image1D, 1, size, fp);
	fclose(fp);

	delete[] Image1D;

	return true;
}

void CImage::DrawLine(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b) {
	::DrawLine(m_Red, m_nW, m_nH, x0, y0, x1, y1, r);
	::DrawLine(m_Green, m_nW, m_nH, x0, y0, x1, y1, g);
	::DrawLine(m_Blue, m_nW, m_nH, x0, y0, x1, y1, b);
}

///****************	Fn01() ****************			

class CPoint {
public:
	double X, Y;

	CPoint() : X(0), Y(0) {}
	CPoint(double x, double y) : X(x), Y(y) {}

	void clear() { X = 0; Y = 0; }

	CPoint operator+(const CPoint p);
	void operator+=(const CPoint p);
};

CPoint CPoint::operator+(const CPoint p) {
	CPoint temp(X + p.X, Y + p.Y);
	return temp;
}

void CPoint::operator+=(const CPoint p) {
	X += p.X; Y += p.Y;
}

std::ostream& operator<<(std::ostream& os, const CPoint &p) {
	os << "(" << p.X << "," << p.Y << ")";
	return os;
}

class CLine {
public:
	CPoint Start, End;

	CLine() : Start(), End() {}
	CLine(CPoint p1, CPoint p2) : Start(p1), End(p2) {}
	CLine(double x1, double y1, double x2, double y2) : Start(x1, y1), End(x2, y2) {}
};

std::ostream& operator<<(std::ostream& os, const CLine &l) {
	os << l.Start << '-' << l.End;
	return os;
}

class CRect {
public:
	CPoint LT, RB;
	double Left, Right, Top, Bottom;

	CRect() : LT(), RB(), Left(0), Right(0), Top(0), Bottom(0) {}
	CRect(double xlt, double ylt, double xrb, double yrb) : LT(xlt, ylt), RB(xrb, yrb), Left(xlt), Right(xrb), Top(ylt), Bottom(yrb) {}

	double Width() { return RB.X - LT.X; }
	double Height() { return RB.Y - LT.Y; }
	CPoint Center() const;
	void Union(CRect r);
	void Intersect(CRect r);
	bool IsRect() const;
};

CPoint CRect::Center() const {
	CPoint temp((LT.X + RB.X) / 2, (LT.Y + RB.Y) / 2);
	return temp;
}

void CRect::Union(CRect r) {
	if (LT.X < RB.X) {
		if (LT.Y < RB.Y) {	// r1 is at the top left
			RB = r.RB;
		}
		else {	// r1 is at the bottom left
			LT.Y = r.LT.Y;
			RB.X = r.RB.X;
		}
	}
	else {
		if (LT.Y < RB.Y) {	// r1 is at the top right
			LT.X = r.LT.X;
			RB.Y = r.RB.Y;
		}
		else {	// r1 is at the bottom right
			LT = r.LT;
		}
	}
}

void CRect::Intersect(CRect r) {
	if ((RB.X < r.LT.X || LT.X > r.RB.X) || (LT.Y > r.RB.Y || RB.Y < r.LT.Y)) {
		LT.clear(); RB.clear();
		return;
	}

	if(LT.X <= r.LT.X) {
		if (LT.Y <= r.LT.Y)
			LT = r.LT;
		else
			LT.X = r.LT.X;
	}
	else {
		if (LT.Y <= r.LT.Y)
			LT.Y = r.LT.Y;
	}

	if (RB.X <= r.RB.X) {
		if (RB.Y > r.RB.Y)
			RB.Y = r.RB.Y;
	}
	else {
		if (RB.Y <= r.RB.Y)
			RB.X = r.RB.X;
		else
			RB = r.RB;
	}
}

bool CRect::IsRect() const {
	if ((LT.X-RB.X)!=0 && (LT.Y-RB.Y)!=0)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const CRect& r) {
	if (!r.IsRect()) return os;
	os << r.LT << '#' << r.RB;
	return os;
}

void Fn1() {
	std::cout << "*** CPoint, CLine, CRect ***" << std::endl;

	CPoint p0, p1(10, 20), p2(100, 200);
	std::cout << p1 << "," << p2 << std::endl;
	p0 += p1 + p2;
	std::cout << p0 << std::endl;
	
	CLine l1(p1, p2), l2(p1.X, p1.Y, p2.X, p2.Y);
	std::cout << l1 << "," << l2 << std::endl;
	
	CRect r0;
	const CRect r1(0, 0, 500, 300), r2(200, 100, 700, 400), r3(550, 350, 750, 400);
	std::cout << r1 << std::endl;
	std::cout << r1.Center() << std::endl;

	r0 = r1;	r0.Union(r2);
	std::cout << r0 << std::endl;
	
	r0 = r1;	r0.Intersect(r2);
	std::cout << r0 << ", Width: " << r0.Width() << ", Height: " << r0.Height() << std::endl;

	r0 = r1;	r0.Intersect(r3);
	std::cout << r0 << std::boolalpha << r0.IsRect() << std::endl;
}

///****************	Fn02() ****************	

class CVector3D {
public:
	double X, Y, Z;

	CVector3D() : X(0), Y(0), Z(0) {}
	CVector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

	static double abs(CVector3D v);
	void Normalize();
	double Dot(CVector3D v);
	CVector3D Cross(CVector3D v);

	CVector3D operator-();
	CVector3D operator+(const CVector3D v);
	CVector3D operator-(const CVector3D v);
	void operator+=(CVector3D v);
};

std::ostream& operator<<(std::ostream& os, const CVector3D v)
{
	os << '<' << v.X << ',' << v.Y << ',' << v.Z << '>';
	return os;
}

double CVector3D::abs(const CVector3D v) {
	return sqrt(pow(v.X, 2) + pow(v.Y, 2) + pow(v.Z, 2));
}

void CVector3D::Normalize() {
	double norm = abs(*this);
	X /= norm; Y /= norm; Z /= norm;
}

double CVector3D::Dot(CVector3D v) {
	return (X * v.X + Y * v.Y + Z * v.Z);
}

CVector3D CVector3D::Cross(CVector3D v) {
	CVector3D temp((Y * v.Z - Z * v.Y), (Z * v.X - X * v.Z), (X * v.Y - Y * v.X));
	return temp;
}

CVector3D CVector3D::operator-() {
	CVector3D temp(-X, -Y, -Z);
	return temp;
}

CVector3D CVector3D::operator+(const CVector3D v) {
	CVector3D temp(X + v.X, Y + v.Y, Z + v.Z);
	return temp;
}

CVector3D CVector3D::operator-(const CVector3D v) {
	CVector3D temp(X - v.X, Y - v.Y, Z - v.Z);
	return temp;
}

void CVector3D::operator+=(CVector3D v) {
	X += v.X; Y += v.Y; Z += v.Z;
}

CVector3D operator*(double n, CVector3D v) {
	CVector3D temp(n * v.X, n * v.Y, n * v.Z);
	return temp;
}

void Fn2() {
	std::cout << "\n*** CVector3D ***" << std::endl;

	CVector3D v0, v1(0.5, 7.2, -3.5), v2(-3.4, 6.5, 9.3);

	std::cout << v1 << ", abs: " << CVector3D::abs(v1) << std::endl;
	v0 = v1; v0.Normalize();
	std::cout << v0 << std::endl;
	std::cout << v1.Dot(v2) << std::endl;
	v0 = v1.Cross(v2);
	std::cout << v0 << std::endl;
	std::cout << -v0 << std::endl;
	std::cout << v1+v2 << std::endl;
	std::cout << v1-v2 << std::endl;
	v0 = CVector3D();
	v0 += v1+v2;
	std::cout << v0 << std::endl;
	std::cout << 5*v0 << std::endl;
}

///****************	Fn03() ****************	

void Fn3() {
	std::cout << "\n*** Image processing ***" << std::endl;

	int nW = 256, nH = 256;
	unsigned char R = 200, G = 10, B = 50;
	CImage Image(nW, nH, R, G, B);

	Image.SaveBmp("image0.bmp");

	CLine l1(0, 0, 50, 200);
	CLine l2(0, 0, 200, 50);
	CLine l3(50, 0, 0, 200);
	CLine l4(200, 0, 0, 50);
	CRect r(128, 128, 230, 170);

	Image.DrawLine(l1.Start.X, l1.Start.Y, l1.End.X, l1.End.Y, 255, 0, 0);
	Image.DrawLine(l2.Start.X, l2.Start.Y, l2.End.X, l2.End.Y, 255, 0, 0);
	Image.DrawLine(l3.Start.X, l3.Start.Y, l3.End.X, l3.End.Y, 255, 0, 0);
	Image.DrawLine(l4.Start.X, l4.Start.Y, l4.End.X, l4.End.Y, 255, 0, 0);

	Image.DrawLine(r.Left, r.Top, r.Right, r.Top, 255, 0, 255);
	Image.DrawLine(r.Right, r.Top, r.Right, r.Bottom, 255, 0, 255);
	Image.DrawLine(r.Right, r.Bottom, r.Left, r.Bottom, 255, 0, 255);
	Image.DrawLine(r.Left, r.Bottom, r.Left, r.Top, 255, 0, 255);

	Image.SaveBmp("image1.bmp");
}

int main() {
	Fn1();
	Fn2();
	Fn3();
}