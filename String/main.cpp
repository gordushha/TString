#include "String.h"

#include<iostream>
int  main()
{
  TString s1;
	TString s2("PRIVET");
	TString s3("PASHA");
	TString s4 = s2.Sum(s3);
	TString s5("abcdecf");

	TString* sm;
	int count = 0;
	s5.Razbienie('c', sm, count);

	s1.Print();
	s2.Print();
	s3.Print();
	s4.Print();
	s1.Print();
	for (int i = 0; i < count; i++)
		sm[i].Print();
	return 0;
}
