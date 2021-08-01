#pragma once
#include<cassert>
#include<iostream>

class Matrix
{
public:
	Matrix(); 
	Matrix(int input_number);
	Matrix(int** input_data, int rows, int columns);// constructor int
	Matrix(char* input_line);

	Matrix(const Matrix& copy_matrix);//copy constructor
	Matrix(Matrix&& moving_matrix);//moving constructor
	
	Matrix operator=(const Matrix& copy_matrix);
	
	Matrix& operator=(Matrix&& moving_matrix);

	void symbolMatrixRepresentation();
	~Matrix();
private:
	int Rows{ 0 }, Columns{ 0 };
	int** StorageData_int = nullptr;


	void getMemory();
	void verifyCharinput(const char* input_line);
	void initData_int(int** input_data = nullptr);
};
