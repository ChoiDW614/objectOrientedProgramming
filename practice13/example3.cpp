/*
#include <iostream>
#include <vector>

template <class T>
class Set {
	int len;
	std::vector<T> element;
public:
	Set() { len = 0; }
	Set(std::vector<T> v1)
	{
		len = 0;
		for (T t : v1) {
			element.push_back(t);
			len += 1;
		}
	}

	int getLen() { return len; }
	void showElement();
	bool isElement(T t);
	int find(T t);

	void Add(T t);
	void Subtract(T t);

	Set<T> operator+(T t) { Add(t); return (*this); }
	Set<T> operator-(T t) { Subtract(t); return (*this); }
	Set<T> operator+(Set<T> s);
	Set<T> operator-(Set<T> s);
	Set<T> operator&(Set<T> s);
};

template <class T>
void Set<T>::showElement() {
	std::cout << "Set Elements" << std::endl;
	std::cout << "\" ";
	for (int i = 0; i < getLen(); i++)
	{
		std::cout << element[i] << " ";
	}
	std::cout << "\"" << std::endl;
}

template <class T>
bool Set<T>::isElement(T t)
{
	for (int i = 0; i < getLen(); i++)
	{
		if (t == element[i])
			return true;
	}
	return false;
}

template <class T>
int Set<T>::find(T t)
{
	for (int idx = 0; idx < getLen(); idx++)
	{
		if (t == element[idx])
			return idx;
	}
	return 0;
}

template <class T>
void Set<T>::Add(T t)
{
	if (!isElement(t)) {
		element.push_back(t);
		len += 1;
	}
}

template <class T>
void Set<T>::Subtract(T t)
{
	if (isElement(t)) {
		element.erase(element.begin() + find(t));
		len -= 1;
	}
}

template <class T>
Set<T> Set<T>::operator+(Set<T> s)
{
	Set newSet = (*this);
	for (int i = 0; i < s.getLen(); i++) {
		newSet.Add(s.element[i]);
	}
	return newSet;
}

template <class T>
Set<T> Set<T>::operator&(Set<T> s)
{
	Set newSet1 = (*this);
	Set newSet2 = newSet1 - s;
	return (newSet1 - newSet2);
}

template <class T>
Set<T> Set<T>::operator-(Set<T> s)
{
	Set newSet = (*this);
	for (int i = 0; i < s.getLen(); i++) {
		newSet.Subtract(s.element[i]);
	}
	return newSet;
}

int main()
{
	std::vector<int> v1 = { 1 ,2 ,3 };
	Set<int> s1{ v1 };
	s1.showElement();
	std::cout << s1.find(1) << '\n';
	std::cout << s1.isElement(5) << '\n';
	
	s1.Add(5);
	s1 = s1 + 2;
	s1.Subtract(1);
	s1.showElement();

	std::vector<int> v2 = { 1 ,5 ,7 };
	Set<int> s2{ v2 };

	Set<int> s3 = s1 + s2;

	std::cout << "union" << std::endl;
	s1.showElement();
	s2.showElement();
	s3.showElement();

	s3 = s1 - s2;

	std::cout << "relative complement" << std::endl;
	s1.showElement();
	s2.showElement();
	s3.showElement();

	s3 = s1 & s2;

	std::cout << "intersection" << std::endl;
	s3.showElement();
}
*/