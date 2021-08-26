#pragma once
#include<string>
#include<vector>
#include<cassert>

class Matrix
{
public:
	Matrix();
	Matrix(float inNumber, size_t inRows, size_t inColumns);//constructor int 
	Matrix(float** inData, size_t inRows, size_t inColumns);// constructor int**
	Matrix(char* inString);// constructor char
	Matrix(const Matrix& copy_matrix);//copy constructor
	Matrix(Matrix&& moving_matrix);//moving constructor

	Matrix operator=(const Matrix& copy_matrix);

	Matrix& operator=(Matrix&& moving_matrix);

	Matrix operator+(const Matrix& addMatrix) const;
	Matrix* operator+=(const Matrix& addMatrix);

	Matrix operator-(const Matrix& minusMatrix) const;
	Matrix* operator-=(const Matrix& minusMatrix);

	Matrix operator*(const Matrix& multiplyMatrix) const;
	Matrix operator*(const float multiplyMember) const;
	Matrix operator*(const char* const inString) const;
	Matrix* operator*=(const Matrix& multiplyMatrix);
	Matrix* operator*=(const float multiplyMember);
	
	Matrix operator/(const Matrix& divideMatrix) const;
	Matrix operator/(const float divideMember) const;
	Matrix operator/(const char* const inString) const;
	Matrix* operator/=(const Matrix& divideMatrix);
	Matrix* operator/=(const float divideMember);
	
	bool operator>(const Matrix& comparisonMatrix) const;
	bool operator<(const Matrix& comparisonMatrix) const;
	bool operator>=(const Matrix& comparisonMatrix) const;
	bool operator<=(const Matrix& comparisonMatrix) const;
	bool operator==(const Matrix& comparisonMatrix) const;
	bool operator!=(const Matrix& comparisonMatrix) const;

	std::string ToString();

	~Matrix();
private:
	size_t rows; 
	size_t columns;
	float** storageData;
	
	void getMemory();
	void initData(float** input_data = nullptr);
	void initData(const std::vector<std::vector<float>>& input_data);
	void initData(const float inNumber);
	void clearMemory(float** data, const size_t rows);

	float searchDeterminant() const;
	Matrix transpose() const;
	Matrix getMinor(const size_t row, const size_t column) const;
	Matrix inverseMatrix() const;
	float getSum() const;

	std::vector<std::vector<float>> VerifyCharInput(const char* const inString) const;

	bool isAllowPlusMinus(const Matrix& first, const Matrix& second) const;
	bool isAllowMultiply(const Matrix& first, const Matrix& second) const;
	bool isAllowDivide(const Matrix& first, const Matrix& second) const;
	bool isAllowDeterminant(const Matrix& matrix) const;
	bool isPlusOverflow(const float firstMemmber, const float secondMember) const;
	bool isMinusOverflow(const float firstMember, const float secondMember) const;
};
