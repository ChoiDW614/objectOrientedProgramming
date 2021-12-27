#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void ReadCsv(std::string FileName, std::vector<std::vector<std::string>>& Data)
{
	std::ifstream ifs;

	ifs.open(FileName);
	if (!ifs.is_open()) return;

	std::string LineString = "";
	std::string Delimeter = ",";
	while (getline(ifs, LineString))
	{
		std::vector<std::string> RowData;
		unsigned int nPos = 0, nFindPos;
		do {
			nFindPos = LineString.find(Delimeter, nPos);
			if (nFindPos == std::string::npos) nFindPos = LineString.length();

			RowData.push_back(LineString.substr(nPos, nFindPos - nPos));
			nPos = nFindPos + 1;
		} while (nFindPos < LineString.length());
		Data.push_back(RowData);
	}
	
	ifs.close();
}

int main()
{
	std::vector<std::vector<std::string>> diabetes_data;
	ReadCsv("diabetes.csv", diabetes_data);
	
	// represent the data in the vector
	for (int i = 0; i < diabetes_data.size(); i++) {
		for (int j = 0; j < diabetes_data[i].size(); j++)
		{
			std::cout << diabetes_data[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}