#pragma once
class TString
{
protected:
	char* arr;
	int n;
public:
	TString();
	TString(const char*s);
	TString(const TString&s);
	~TString();

	char& GetChar(int i);
	int GetN();
	void Resize(int _n);
	TString Sum(TString& s);
	int FindChar(char c);
	int Find(TString& s);
	void Razbienie(char c, TString*& str, int& count);
	void Print();
};