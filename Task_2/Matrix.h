#pragma once
#include<cassert>
#include<iostream>

class Matrix
{
public:
	Matrix(); 
	Matrix(int input_number);
	Matrix(int* input_data[], int rows, int columns);// constructor int
	Matrix(char* input_data, int rows, int columns);//constructor char

	Matrix(const Matrix& copy_matrix);//copy constructor
	Matrix(Matrix&& moving_matrix);//moving constructor
	
	Matrix operator=(const Matrix& copy_matrix);
	
	Matrix& operator=(Matrix&& moving_matrix);

	void convertNumData2char();

	~Matrix();
private:
	char Data_Type;
	int Rows{ 0 }, Columns{ 0 };
	int** StorageData_int = nullptr;
	char** StorageData_char = nullptr;
	bool valid_index = true;
	bool correct_charData = true;

	void getMemory();
	void verifyCharinput(const char* input_data);
	void initData_int(int* input_data[]);
	void initData_char(char* input_data);
};
