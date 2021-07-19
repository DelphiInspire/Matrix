#pragma once
#include <iostream>
#include<cassert>

class Matrix
{
public:
	Matrix(); 
	Matrix(int* a, int rows, int colms);// constructor int
	Matrix(float* a, int rows, int colms);// constructor float
	Matrix(char* a, int rows, int colms);//constructor char

	Matrix(const Matrix& m);//copy constructor
	Matrix(Matrix&& m);//moving constructor
	
	Matrix operator=(const Matrix& m);
	
	Matrix& operator=(Matrix&& m);

	float operator()(int i, int j);

	friend std::ostream& operator<<(std::ostream& out, const Matrix& m);

	void convertNumData2char();

	~Matrix();
private:
	char Data_Type;
	int Rows{ 0 }, Colms{ 0 };
	int** StorageData_int = nullptr;
	float** StorageData_float = nullptr;
	char** StorageData_char = nullptr;
	bool valid_index = true;
	bool correct_charData = true;

	void getMemory4StoringData(const int& rows, const int& colms, const char& data_type);
	void verifyCharinput(const char* a, const int& row, const int& colm);
	void initData_int(int* a, const int& rows, const int& colms);
	void initData_float(float* a, const int& rows, const int& colms);
	void initData_char(char* a, const int& rows, const int& colms);
};
