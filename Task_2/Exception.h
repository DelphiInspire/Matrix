#pragma once
#include<iostream>

struct exceptionInfo
{
	const char* description;
	bool isDeterminated;
};


class Exception
{
private:
	exceptionInfo explenation;
public:
	Exception() {};
	Exception(const char* const msg) 
	{
		explenation.description = msg;
		explenation.isDeterminated = true;
	};
	virtual const char* what() const
	{
		return explenation.description;
	}
};

class Exception_CharInputVerification : public Exception
{
public:
	Exception_CharInputVerification() : Exception{ "Wrong char input verification" }{};
};

class Exception_MemoryAllocation : public Exception
{
public:
	Exception_MemoryAllocation() : Exception{ "Bad memory allocation" } {};
};


class Exception_IllegalPlusMinusOperation : public Exception
{
public:
	Exception_IllegalPlusMinusOperation() : 
				Exception{ "Illegal plus/minus operation, matrix dimensions must be equal" } {};
};

class Exception_OverflowOperation : public Exception
{
private:
	exceptionInfo explenation;
public:
	Exception_OverflowOperation() :
		Exception{ "Overflow error" } {};
};

class Exception_MultiplyOperation : public Exception
{
public:
	Exception_MultiplyOperation() :
		Exception{ "Illegal multiply operation, check right dimensions of matrix"} {};
};

class Exception_DivideOperation : public Exception
{
public:
	Exception_DivideOperation() :
		Exception{ "Illegal divide operation, check right dimensions of matrix" } {};
};