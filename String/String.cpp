#include "String.h"
#include <math.h>
#include<iostream>
#include <string.h>
TString::TString()
{
	arr = new char[1];
	arr[0] = 0;
	n = 1;
}

TString::TString(const char * s)
{
	n = strlen(s) + 1;
	arr = new char[n];
	for (int i = 0; i < n - 1; i++)
		arr[i] = s[i];
	arr[n - 1] = 0;
}

TString::TString(const TString & s)
{
	n = s.n;
	arr = new char[n];
	for (int i = 0; i < n; i++)
		arr[i] = s.arr[i];
}

TString::~TString()
{
	if (arr != 0)
		delete[]arr;
	arr = 0;
	n = 0;
}

char & TString::GetChar(int i)
{
	if ((i >= 0) && (i < n))
		return arr[i];
	else return arr[0];
}

int TString::GetN()
{
	return (n);
}

void TString::Resize(int _n)
{
	if (_n <= 0||_n==n)
		return;
	char*tmp = new char[n];
	if (_n == n)
		return;
	for (int i = 0; i <(n<_n?n:_n); i++)
		tmp[i] = arr[i];
	tmp[_n - 1] = 0;
	delete[]arr;
	arr = tmp;
}

TString TString::Sum(TString & s)
{
	TString p;
	p.Resize(n + s.n - 1);
	for (int i = 0; i < n - 1; i++)
		p.arr[i] = arr[i];
	for (int i = 0; i < s.n; i++)
		p.arr[i + n - 1] = s.arr[i];
	return p;
}

int TString::FindChar(char c)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == c)
			return i;
	return -1;
}

int TString::Find(TString & s)
{
	bool f = false;
	for (int i = 0; i < n; i++)
	{
		f = false;
		for (int j = 0; j < s.n - 1; j++)
			if (arr[i + j] != s.arr[j])
			{
				f = true;
				break;
			}
	}
	return -1;
}


void TString::Razbienie(char c, TString *& str, int & count)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] == c)
			k++;
	count = k + 1;
	int j = 0;
	int t = 0;
	str = new TString[count];
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == c)
		{
			str[j].Resize(i - t + 1);
			for (int q = t; q < i; q++)
				str[j].arr[str[j].GetN() - 1] = 0;
			t = i + 1;
			j++;
		}
	}
	str[count - 1].Resize(n - t);
	for (int q = t; q < n; q++)
		str[count-1].arr[q-t] = arr[q];
	str[count-1].arr[str[count-1].GetN() - 1] = 0;
}

void TString::Print()
{
	std::cout << arr << std::endl;
}
