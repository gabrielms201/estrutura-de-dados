#ifndef ERRORS_H
#define ERRORS_H

// Includes && Using Namespace
#include <iostream>
#include <string>
using namespace std;

// Struct dosd Errors
struct Errors 
{
	static void AvisoOverFlow()
	{
		cout << "ERRO: OVERFLOW" << endl;
	}	

	static void AvisoUnderFlow()
	{
		cout << "ERRO: UNDERFLOW" << endl;
	}
};
#endif // #ifndef ERRORS_H
