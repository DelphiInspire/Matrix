#include "Matrix.h"


Matrix::Matrix()
{
	rows = 0;
	columns = 0;
	storageData = nullptr;
}


Matrix::Matrix(float** inData, int inRows, int inColumns)
{
	columns = inColumns;
	rows = inRows;
	getMemory();
	initData(inData);
}


Matrix::Matrix(float inNumber, int inRows, int inColumns)
{
	columns = inColumns;
	rows = inRows;
	getMemory();
	initData(inNumber);
}


Matrix::Matrix(char* inString)
{
	assert(isAllowCharinput(inString) && "Something gone wrong");
}

Matrix::Matrix(const Matrix& copy_matrix)
{	
	rows = copy_matrix.rows;
	columns = copy_matrix.columns;
	getMemory();
	for (size_t row = 0; row <= rows - 1; row++)
	{
		for (size_t colm = 0; colm <= columns - 1; colm++)
		{
			storageData[row][colm] = copy_matrix.storageData[row][colm];
		}
			
	}
}

Matrix::Matrix(Matrix&& moving_matrix)
{
	columns = moving_matrix.columns;
	moving_matrix.columns = 0;
	rows = moving_matrix.rows;
	moving_matrix.rows = 0;

	if (moving_matrix.storageData != nullptr)
	{
		storageData = moving_matrix.storageData;
		moving_matrix.storageData = nullptr;
	}	
}

Matrix Matrix::operator=(const Matrix& copy_matrix)
{
	if (&copy_matrix == this)
	{
		return *this;
	}
	else
	{
		clearMemory(storageData, rows);
		rows = copy_matrix.rows;
		columns = copy_matrix.columns;
		getMemory();

		for (size_t row = 0; row <= rows - 1; row++)
		{
			for (size_t colm = 0; colm <= columns - 1; colm++)
			{
				storageData[row][colm] = copy_matrix.storageData[row][colm];
			}
		}
		return *this;
	}
}

Matrix& Matrix::operator=(Matrix&& moving_matrix)
{
	if (&moving_matrix == this)
	{
		return *this;
	}
	else
	{
		rows = moving_matrix.rows;
		columns = moving_matrix.columns;
		moving_matrix.rows = 0;
		moving_matrix.columns = 0;
		if (moving_matrix.storageData != nullptr)
		{
			storageData = moving_matrix.storageData;
			moving_matrix.storageData = nullptr;
		}
		return *this;
	}
}

Matrix Matrix::operator+(const Matrix& addMatrix)
{
	if (isAllowPlusMinus(*this, addMatrix))
	{
		Matrix result(0.0, addMatrix.rows, addMatrix.columns);
		for (size_t row = 0; row < rows; row++)
		{
			for (size_t column = 0; column < columns; column++)
			{
				if (isPlusOverflow(storageData[row][column], addMatrix.storageData[row][column]))
				{
					return nullptr;
				}
				else
				{
					result.storageData[row][column] = storageData[row][column] + addMatrix.storageData[row][column];
				}
			}
		}
		return result;
	}
	else
	{
		return Matrix();
	}
	
}

Matrix Matrix::operator-(const Matrix& minusMatrix)
{
	if (isAllowPlusMinus(*this, minusMatrix))
	{
		Matrix result(0.0, this->rows, this->columns);
		for (size_t row = 0; row < rows; row++)
		{
			for (size_t column = 0; column < columns; column++)
			{
				if (isMinusOverflow(storageData[row][column], minusMatrix.storageData[row][column]))
				{
					return nullptr;
				}
				else
				{
					result.storageData[row][column] = storageData[row][column] - minusMatrix.storageData[row][column];
				}
			}
		}
		return result;
	}
	else
	{
		return Matrix();
	}
}

Matrix Matrix::operator*(const Matrix& multiplyMatrix)
{
	if (isAllowMultiply(*this, multiplyMatrix))
	{
		Matrix result(0.0, this->rows, multiplyMatrix.columns);
		float multiplyMember{ 0.0 };
		for (size_t row = 0; row < rows; row++)
		{
			for (size_t column = 0; column < columns; column++)
			{
				for (size_t insideCounter = 0; insideCounter < this->columns; insideCounter++)
				{
					multiplyMember += storageData[row][insideCounter] * multiplyMatrix.storageData[insideCounter][column];
				}
				result.storageData[row][column] = multiplyMember;
				multiplyMember = 0;
			}
		}
		return result;
	}
	else
	{
		return Matrix();
	}
}

Matrix Matrix::operator*=(const float member)
{
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t column = 0; column < columns; column++)
		{
			storageData[row][column] *= member;
		}
	}
	return *this;
		
}

void Matrix::getMemory()
{
	storageData = new float* [rows];
	for (size_t row = 0; row < rows; row++)
	{
		storageData[row] = new float[columns];
	}
		
}

void Matrix::initData(float** inData)
{
	if (inData != nullptr)
	{
		for (size_t row = 0; row < rows; row++)
		{
			for (size_t colm = 0; colm < columns; colm++)
			{
			
				storageData[row][colm] = inData[row][colm];
			}
		}
	}		
}

void Matrix::initData(const float inNumber)
{
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t colm = 0; colm < columns; colm++)
		{

			storageData[row][colm] = inNumber;
		}
	}
}

void Matrix::initData(const std::vector<float>& input_data)
{

	for (size_t row = 0; row < rows; row++)
	{
		for (size_t colm = 0; colm < columns; colm++)
		{

			storageData[row][colm] = input_data[row * columns + colm];
		}
	}
}

std::string Matrix::ToString()
{
	unsigned int inner_counter{ 0 };
	std::string result;
	
	result.push_back('[');
	if (this != nullptr)
	{
		for (size_t row = 0; row < rows; row++)
		{
			for (size_t column = 0; column < columns; column++)
			{
				result.push_back(char(97 + inner_counter));
				if (column != columns - 1)
				{
					result.push_back(',');
				}
				inner_counter++;
			}
			if (row != rows - 1)
			{
				result.push_back(';');
				result.push_back(char(9));
			}

		}
	}
	result.push_back(']');

	return result;
}

bool Matrix::isAllowCharinput(const char* inString)
{

	size_t sizeString{ strlen(inString) }; //size of the input char*
	size_t rowCounter{ 1 };
	size_t columnCounter{ 1 };
	size_t columnCounter_previous{ 1 };// for check quantity equals in each row

	std::string bufferNumber;//collector of the char '0-9'

	std::vector<float> representation_char_to_int;// collector of the convering result for data init

	bool isStart_checking{ false }; //begin to check quantity of columns in each row

	for (size_t counter = 0; counter < sizeString; counter++)
	{
		switch (inString[counter])
		{

		case '[':
		{
			break;
		}

		case ']':
		{
			if (isStart_checking)
			{
				if (columnCounter != columnCounter_previous)
				{
					return false;
				}
			}
			representation_char_to_int.push_back(std::stoi(bufferNumber));
			bufferNumber.clear();
			break;
		}

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			bufferNumber.push_back(inString[counter]);
			break;
		}

		case ';':
		{
			columnCounter_previous = columnCounter;
			representation_char_to_int.push_back(std::stoi(bufferNumber));
			bufferNumber.clear();
			if (isStart_checking)
			{
				if (columnCounter != columnCounter_previous)
				{
					return false;
				}
			}
			columnCounter = 1;
			rowCounter++;
			isStart_checking = true;
			break;
		}

		case ',':
		{
			representation_char_to_int.push_back(std::stoi(bufferNumber));
			bufferNumber.clear();
			columnCounter++;
			break;
		}
		default:
		{
			return false;
		}
		}
	}
	rows = rowCounter;
	columns = columnCounter;
	getMemory();
	initData(representation_char_to_int);
	return true;
}


int Matrix::searchDeterminant()
{
	if (rows == 1)
	{
		return storageData[0][0];
	}
	else if (rows == 2)
	{
		return (storageData[0][0] * storageData[1][1] - storageData[0][1] * storageData[1][0]);
	}
	else
	{
		float determinant{ 0.0 };
		for (size_t column = 0; column < columns; column++)
		{

			Matrix* bufferMatrix = new Matrix(0.0, rows - 1, columns - 1);
			*bufferMatrix = getMinor(0, column);
			determinant += (pow(-1, 2 + column) * storageData[0][column] * bufferMatrix->searchDeterminant());
			delete bufferMatrix;
		}
		return determinant;
	}
}

Matrix Matrix::inverseMatrix()
{
	float determinant{ 0 };

	determinant = searchDeterminant();
	Matrix result(0.0, rows, columns);
	Matrix check(0.0, rows, columns);
	if (determinant == 0)
	{
		return result;
	}

	for (size_t row = 0; row < rows; row++)
	{
		for (size_t column = 0; column < columns; column++)
		{
			result.storageData[row][column] = pow(-1, 2 + row + column) * getMinor(row, column).searchDeterminant();
		}
	}

	result = result.transpose();
	result *= (1 / determinant);
	check = *this * result;
	for (size_t row = 0; row < rows; row++)
		for (size_t column = 0; column < columns; column++)
		{
			std::cout << check.storageData[row][column] << ' ';
			if (column == columns - 1)
			{
				std::cout << std::endl;
			}
		}
	return result;
}

Matrix Matrix::getMinor(const int row, const int column)
{
	Matrix bufferMatrix(0.0, rows - 1, columns - 1);
	int rowCounter{ 0 };
	int columnCounter{ 0 };
	for (size_t innerRow = 0; innerRow < rows; innerRow++)
	{
		if (innerRow == row)
		{
			continue;
		}
		for (size_t innerColumn = 0; innerColumn < columns; innerColumn++)
		{
			if (innerColumn == column)
			{
				continue;
			}
			else
			{
				bufferMatrix.storageData[rowCounter][columnCounter] = storageData[innerRow][innerColumn];
				columnCounter++;
			}
		}
		columnCounter = 0;
		rowCounter++;
	}
	return bufferMatrix;
}

Matrix Matrix::transpose()
{
	Matrix result(0.0, rows, columns);
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t column = 0; column < columns; column++)
		{
			result.storageData[column][row] = storageData[row][column];
		}
	}
	return result;
}

void Matrix::clearMemory(float** data, const int rows)
{
	if (data != nullptr)
	{
		for (size_t row = 0; row < rows; row++)
		{
			delete[] data[row];
		}
		delete[] data;
	}
}

bool Matrix::isAllowPlusMinus(const Matrix& first, const Matrix& second) const
{
	if (first.rows != second.rows || first.columns != second.columns)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Matrix::isPlusOverflow(const int firstMember, const int secondMember) const
{
	if ((secondMember > 0 && firstMember > INT_MAX - secondMember) || (secondMember < 0 && firstMember < INT_MIN - secondMember))
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Matrix::isMinusOverflow(const int firstMember, const int secondMember) const 
{
	if ((secondMember > 0 && firstMember < INT_MIN + secondMember) || (secondMember < 0 && firstMember > INT_MAX + secondMember))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Matrix::isAllowMultiply(const Matrix& first, const Matrix& second) const
{
	if (first.columns != second.rows)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Matrix::isAllowDivide(const Matrix& first, const Matrix& second) const
{
	if (first.columns != first.rows || first.rows != second.rows || first.columns != second.columns)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Matrix::~Matrix()
{
	clearMemory(storageData, rows);
	storageData = nullptr;
}