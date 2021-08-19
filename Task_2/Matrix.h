#pragma once
#include<string>
#include<vector>
#include<cassert>
#include <iostream>

class Matrix
{
public:
	Matrix();
	Matrix(float inNumber, int inRows, int inColumns);//constructor int 
	Matrix(float** inData, int inRows, int inColumns);// constructor int**
	Matrix(char* inString);// constructor char
	Matrix(const Matrix& copy_matrix);//copy constructor
	Matrix(Matrix&& moving_matrix);//moving constructor
	

	Matrix operator+(const Matrix& addMatrix);
	Matrix operator-(const Matrix& minusMatrix);
	Matrix operator*(const Matrix& multiplyMatrix);
	Matrix operator/(const Matrix& divideMatrix);
	Matrix operator*=(const float member);
	Matrix operator*=(const Matrix& multiplyMatrix);

	Matrix operator=(const Matrix& copy_matrix);
	
	Matrix& operator=(Matrix&& moving_matrix);

	std::string ToString();
	Matrix inverseMatrix();
	~Matrix();
private:
	int rows; 
	int columns;
	float** storageData;
	
	void getMemory();
	void initData(float** input_data = nullptr);
	void initData(const std::vector<float>& input_data);
	void initData(const float inNumber);
	void clearMemory(float** data, const int rows);

	int searchDeterminant();
	Matrix transpose();
	Matrix getMinor(const int row, const int column);

	bool isAllowCharinput(const char* inString);
	bool isAllowPlusMinus(const Matrix& first, const Matrix& second) const;
	bool isAllowMultiply(const Matrix& first, const Matrix& second) const;
	bool isAllowDivide(const Matrix& first, const Matrix& second) const;


	bool isPlusOverflow(const int firstMemmber, const int secondMember) const;
	bool isMinusOverflow(const int firstMember, const int secondMember) const;
	
};
