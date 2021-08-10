#pragma once
#include<string>
#include<vector>
#include<cassert>

class Matrix
{
public:
	Matrix() {};
	Matrix(int inNumber, int inRows, int inColumns);//constructor int 
	Matrix(int** inData, int inRows, int inColumns);// constructor int**
	Matrix(char* inString);// constructor char
	Matrix(const Matrix& copy_matrix);//copy constructor
	Matrix(Matrix&& moving_matrix);//moving constructor
	
	Matrix operator=(const Matrix& copy_matrix);
	
	Matrix& operator=(Matrix&& moving_matrix);

	std::string ToString();
	~Matrix();
private:
	int rows; 
	int columns;
	int** storageData;
	
	bool verifyCharinput(const char* inString);
	void getMemory();
	
	void initData(int** input_data = nullptr);
	void initData(const std::vector<int> input_data);
	void initData(const int inNumber);
};
