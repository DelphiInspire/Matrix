#pragma once
#include<iostream>
#include<cassert>

class Matrix
{
public:
	Matrix();

	static Matrix* CreateNumberIntoMatrix(int input_number, int rows, int columns);
	static Matrix* CreateDataIntoMatrix(int** input_data, int rows, int columns);
	static Matrix* CreateStringIntoMatrix(char* input_line, int rows, int columns);
	Matrix(const Matrix& copy_matrix);//copy constructor
	Matrix(Matrix&& moving_matrix);//moving constructor
	
	Matrix operator=(const Matrix& copy_matrix);
	
	Matrix& operator=(Matrix&& moving_matrix);

	std::string ToString();
	~Matrix();
private:
	int frows; 
	int fcolumns;
	int** fstorageData;
	Matrix(int input_number, int rows, int columns);//constructor int 
	Matrix(int** input_data, int rows, int columns);// constructor int**
	Matrix(char* input_line, int rows, int columns);// constructor char
	void getMemory();
	
	void initData(int** input_data = nullptr);
};

//Help methods
bool verifyCharinput(const char* input_line, const int& rows, const int& columns);
bool verifyDataInput(int** const  (inputData), const int& rows, const int& columns);

inline bool check_next_symbol(const char& symbol, const char& comparison_symbol)
{
	if (symbol != comparison_symbol)
	{
		return false;
	}
	else
	{
		return true;
	}
}
