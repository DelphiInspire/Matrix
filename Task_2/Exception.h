#pragma once
#include<iostream>


class Exception
{
private:
	const char* explenation;
public:
	Exception() {};
	Exception(const char* const msg) : explenation{ msg } {};

	virtual const char* what() const
	{
		return explenation;
	}

	virtual ~Exception() {};
};

class InputVerificationException : public Exception
{
public:
	InputVerificationException() : Exception{ "Wrong char input verification" }{};
	virtual ~InputVerificationException() {};
};

class MemoryAllocException : public Exception
{
public:
	MemoryAllocException() : Exception{ "Bad memory allocation" } {};
	virtual ~MemoryAllocException() {};
};


class PlusMinusException : public Exception
{
public:
	PlusMinusException() : 
				Exception{ "Illegal plus/minus operation, matrix dimensions must be equal" } {};
	virtual ~PlusMinusException() {};
};

class OverflowException : public Exception
{

public:
	OverflowException() : Exception{ "Overflow error" } {};
	virtual ~OverflowException() {};
};

class MultiplyException : public Exception
{
public:
	MultiplyException() : Exception{ "Illegal multiply operation, check right dimensions of matrix"} {};
	virtual ~MultiplyException() {};
};

class DivideException : public Exception
{
public:
	DivideException() :
		Exception{ "Illegal divide operation, check right dimensions of matrix" } {};
	virtual ~DivideException() {};
};