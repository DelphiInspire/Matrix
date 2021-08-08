#include "Matrix.h"
#include<vector>



Matrix::Matrix()
{
	std::cout << "Simple constructor worked" << std::endl;
}

Matrix::Matrix(int** input_data, int rows, int columns)
{
	fcolumns = columns;
	frows = rows;
	getMemory();

	initData(input_data);
	
	std::cout << "int constructor worked" << std::endl;
}

Matrix* Matrix::CreateDataIntoMatrix(int** input_data, int rows, int columns)
{
	bool is_valid;
	is_valid = verifyDataInput(input_data, rows, columns);
	if (is_valid)
	{
		return new Matrix(input_data, rows, columns);
	}
	else
	{
		return nullptr;
	}
}


Matrix::Matrix(int input_number, int rows, int columns)
{
	fcolumns = columns;
	frows = rows;
	getMemory();
	fstorageData[0][0] = input_number;

	std::cout << "int constructor worked" << std::endl;
}

Matrix* Matrix::CreateNumberIntoMatrix(int input_number, int rows, int columns)
{
	if (rows == 1 & columns == 1)
	{
		return new Matrix(input_number, rows, columns);
	}
	else
	{
		return nullptr;
	}
}

Matrix::Matrix(char* input_line, int rows, int columns)
{
	fcolumns = columns;
	frows = rows;
	getMemory();
	initData();
	std::cout << "int constructor with char input worked" << std::endl;
}


Matrix* Matrix::CreateStringIntoMatrix(char* input_line, int rows, int columns)
{
	bool is_valid;
	is_valid = verifyCharinput(input_line, rows, columns);
	if (is_valid)
	{
		return new Matrix(input_line, rows, columns);
	}
	else
	{
		return nullptr;
	}
}

Matrix::Matrix(const Matrix& copy_matrix)
{	
	frows = copy_matrix.frows;
	fcolumns = copy_matrix.fcolumns;
	getMemory();
	for (size_t row = 0; row <= frows - 1; row++)
	{
		for (size_t colm = 0; colm <= fcolumns - 1; colm++)
		{
			fstorageData[row][colm] = copy_matrix.fstorageData[row][colm];
		}
			
	}
		
	std::cout << "int copy constructor worked" << std::endl;	
}

Matrix::Matrix(Matrix&& moving_matrix)
{
	fcolumns = moving_matrix.fcolumns;
	moving_matrix.fcolumns = 0;
	frows = moving_matrix.frows;
	moving_matrix.frows = 0;

	if (moving_matrix.fstorageData != nullptr)
	{
		fstorageData = moving_matrix.fstorageData;
		moving_matrix.fstorageData = nullptr;
		std::cout << "int moving constructor worked" << std::endl;
	}	
}

void Matrix::getMemory()
{
	fstorageData = new int* [frows];
	for (size_t row = 0; row < frows; row++)
	{
		fstorageData[row] = new int[fcolumns];
	}
		
}

void Matrix::initData(int** input_data)
{
	for (size_t row = 0; row < frows; row++)
	{
		for (size_t colm = 0; colm < fcolumns; colm++)
		{
			if (input_data != nullptr)
			{
				fstorageData[row][colm] = input_data[row][colm];
			}
			else
			{
				fstorageData[row][colm] = 0;
			}
		}
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
		if (fstorageData != nullptr)
		{
			if (fcolumns > 0)
			{
				for (size_t row = 0; row < frows; row++)
				{
					delete[] fstorageData[row];
				}
			}
			if (frows > 0)
			{
				delete[] fstorageData;
			}
			fstorageData = nullptr;
		}

		frows = copy_matrix.frows;
		fcolumns = copy_matrix.fcolumns;
		getMemory();

		for (size_t row = 0; row <= frows - 1; row++)
		{
			for (size_t colm = 0; colm <= fcolumns - 1; colm++)
			{
				fstorageData[row][colm] = copy_matrix.fstorageData[row][colm];
			}
		}
		return *this;
	}
		
	std::cout << "int copy operator worked" << std::endl;		
}

Matrix& Matrix::operator=(Matrix&& moving_matrix)
{
	if (&moving_matrix == this)
	{
		return *this;
	}
	else
	{
		frows = moving_matrix.frows;
		fcolumns = moving_matrix.fcolumns;
		moving_matrix.frows = 0;
		moving_matrix.fcolumns = 0;
		if (moving_matrix.fstorageData != nullptr)
		{
			fstorageData = moving_matrix.fstorageData;
			moving_matrix.fstorageData = nullptr;
			std::cout << "int moving operator worked" << std::endl;
		}
		return *this;
	}
}

std::string Matrix::ToString()
{
	unsigned int inner_counter(0);
	std::string result;
	
	result.push_back('[');
	if (this != nullptr)
	for (size_t rows = 0; rows < frows; rows++)
	{
		for (size_t colms = 0; colms < fcolumns; colms++)
		{
			result.push_back(char(97 + inner_counter));
			if (colms != fcolumns - 1)
			{
				result.push_back(',');
			}
			inner_counter++;
		}
		if (rows != frows - 1)
		{
			result.push_back(';');
			result.push_back(char(9));
		}
			
	}
	result.push_back(']');

	return result;
}


Matrix::~Matrix()
{
	if (fstorageData != nullptr)
	{
		if (fcolumns > 0)
		{
			for (size_t i = 0; i < frows; i++)
			{
				delete[] fstorageData[i];
			}
				
		}
		if (frows > 0)
		{
			delete[] fstorageData;
		}
			
		fstorageData = nullptr;
		std::cout << "int destructor worked" << std::endl;

	}
}



bool verifyCharinput(const char* input_line, const int& rows, const int& columns)
{
	bool verification_status = true;
	size_t processing_row = rows - 1;
	size_t processing_column = columns - 1;

	for (size_t counter = 0; counter < strlen(input_line); counter++)
	{
		if (!verification_status)
		{
			break;
		}
		switch (input_line[counter])
		{
		case '[':
		{
			if (counter != 0 || input_line[counter + 1] < char(97) || input_line[counter + 1] > char(122))
			{
				verification_status = false;
			}
			break;
		}
		case ',':
		{
			if (input_line[counter + 1] < char(97) || input_line[counter + 1] > char(122))
			{
				verification_status = false;
			}
			processing_column--;
			break;
		}
		case ' ':
		{
			if (input_line[counter + 1] < char(97) || input_line[counter + 1] > char(122))
			{
				verification_status = false;
			}
			break;
		}
		case ';':
		{
			verification_status = check_next_symbol(input_line[counter + 1], ' ');
			processing_row--;
			processing_column = columns - 1;
			break;
		}
		default:
		{
			if (input_line[counter] >= char(97) & input_line[counter] <= char(122))
			{
				if (processing_row == 0 & processing_column == 0)
				{
					verification_status = check_next_symbol(input_line[counter + 1], ']');
				}
				else if (processing_column != 0)
				{
					verification_status = check_next_symbol(input_line[counter + 1], ',');
				}
				else if (processing_column == 0 & processing_row != 0)
				{
					verification_status = check_next_symbol(input_line[counter + 1], ';');
				}
			}

			break;
		}
		}
	}
	return verification_status;
}

bool verifyDataInput(int** (inputData), const int& rows, const int& columns)
{

	std::vector<int> mainVerificationData;
	std::vector<int> additionalVerificationData;

	if (rows == 1 & columns == 1)
	{
		return false;
		std::cout << "Invalid inputData verification";
	}

	for (size_t row = 0; row < rows; row++)
	{
		for (size_t column = 0; column < columns; column++)
		{
			mainVerificationData.push_back(int(&(inputData[row][column])));
		}
	}

	for (size_t element = 1; element < mainVerificationData.size(); element++)
	{
		if (mainVerificationData[element] - mainVerificationData[element - 1] != sizeof(int*))
		{
			std::cout << "Invalid inputData verification" << std::endl;
			return false;
		}
	}

	//(row < columns) это костыль, чтобы проверять не указали ли меньше строк, чем в дейтсвительности
	for (size_t row = 0; row < columns; row++)
	{
		for (size_t column = 0; column < columns; column++)
		{
			additionalVerificationData.push_back(int(&(inputData[row][column])));
		}
	}


	if (additionalVerificationData.size() != rows * columns)
	{
		std::cout << "Invalid inputData verification" << std::endl;
		return false;
	}
	else return true;

}

	



