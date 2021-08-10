#include "Matrix.h"


Matrix::Matrix(int** inData, int inRows, int inColumns)
{
	columns = inColumns;
	rows = inRows;
	getMemory();
	initData(inData);
}


Matrix::Matrix(int inNumber, int inRows, int inColumns)
{
	columns = inColumns;
	rows = inRows;
	getMemory();
	initData(inNumber);
}


Matrix::Matrix(char* inString)
{
	assert(verifyCharinput(inString) && "Something gone wrong");
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
		if (storageData != nullptr)
		{
			if (columns > 0)
			{
				for (size_t row = 0; row < rows; row++)
				{
					delete[] storageData[row];
				}
			}
			if (rows > 0)
			{
				delete[] storageData;
			}
			storageData = nullptr;
		}

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

void Matrix::getMemory()
{
	storageData = new int* [rows];
	for (size_t row = 0; row < rows; row++)
	{
		storageData[row] = new int[columns];
	}
		
}

void Matrix::initData(int** inData)
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

void Matrix::initData(const int inNumber)
{
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t colm = 0; colm < columns; colm++)
		{

			storageData[row][colm] = inNumber;
		}
	}
}

void Matrix::initData(const std::vector<int>& input_data)
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

bool Matrix::verifyCharinput(const char* inString)
{

	size_t sizeString{ strlen(inString) }; //size of the input char*
	size_t rowCounter{ 1 };
	size_t columnCounter{ 1 };
	size_t columnCounter_previous{ 1 };// for check quantity equals in each row

	std::string bufferNumber;//collector of the char '0-9'

	std::vector<int> representation_char_to_int;// collector of the convering result for data init

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
			break;
		}
		}
	}
	rows = rowCounter;
	columns = columnCounter;
	getMemory();
	initData(representation_char_to_int);
	return true;
}

Matrix::~Matrix()
{
	if (storageData != nullptr)
	{
		if (columns > 0)
		{
			for (size_t i = 0; i < rows; i++)
			{
				delete[] storageData[i];
			}
				
		}
		if (rows > 0)
		{
			delete[] storageData;
		}
			
		storageData = nullptr;
	}
}