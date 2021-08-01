#include "Matrix.h"

Matrix::Matrix()
{
	std::cout << "Simple constructor" << std::endl;
}

Matrix::Matrix(int* input_data[], int rows, int columns) 
{
	Data_Type = 'i';
	Columns = columns;
	Rows = rows;
	getMemory();

	initData_int(input_data);
	std::cout << "int constructor worked" << std::endl;
}

Matrix::Matrix(int input_number)
{
	Data_Type = 'i';
	Columns = 1;
	Rows = 1;
	getMemory();

	//initData_int(&input_number);
	std::cout << "int constructor worked" << std::endl;

}

Matrix::Matrix(char* input_data, int rows, int columns) 
{
	Columns = columns;
	Rows = rows;
	verifyCharinput(input_data);
	if (correct_charData)
	{
		Data_Type = 'c';
		getMemory();

		initData_char(input_data);
		std::cout << "char constructor worked" << std::endl;
	}
}

Matrix::Matrix(const Matrix& copy_matrix)
{	
	Rows = copy_matrix.Rows;
	Columns = copy_matrix.Columns;
	Data_Type = copy_matrix.Data_Type;
	if (copy_matrix.Data_Type == 'i')
	{
		getMemory();
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Columns - 1; colm++)
				StorageData_int[row][colm] = copy_matrix.StorageData_int[row][colm];
		std::cout << "int copy constructor worked" << std::endl;
	}
	else if (copy_matrix.Data_Type == 'c')
	{
		getMemory();
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Columns - 1; colm++)
				StorageData_char[row][colm] = copy_matrix.StorageData_char[row][colm];
		std::cout << "char copy constructor worked" << std::endl;
	}
		
	
}

Matrix::Matrix(Matrix&& moving_matrix)
{
	Columns = moving_matrix.Columns;
	moving_matrix.Columns = 0;
	Rows = moving_matrix.Rows;
	moving_matrix.Rows = 0;
	Data_Type = moving_matrix.Data_Type;
	moving_matrix.Data_Type = '0';
	if (moving_matrix.StorageData_int != nullptr)
	{
		StorageData_int = moving_matrix.StorageData_int;
		moving_matrix.StorageData_int = nullptr;
		std::cout << "int moving constructor worked" << std::endl;
	}
	else if (moving_matrix.StorageData_char != nullptr)
	{
		StorageData_char = moving_matrix.StorageData_char;
		moving_matrix.StorageData_char = nullptr;
		std::cout << "char moving constructor worked" << std::endl;
	}
	
	
}

void Matrix::getMemory()
{
	if (Data_Type == 'i')
	{
		StorageData_int = new int* [Rows];

		for (size_t i = 0; i < Rows; i++)
			StorageData_int[i] = (int*) new int[Columns];
	}
	else if (Data_Type == 'c')
	{
		StorageData_char = new char* [Rows];
		for (size_t i = 0; i < Rows; i++)
			StorageData_char[i] = (char*) new char[Columns];
	}
}

void Matrix::initData_int(int *input_data[])
{
	for (size_t row = 0; row < Rows; row++)
		for (size_t colm = 0; colm < Columns; colm++)
		{
			StorageData_int[row][colm] = input_data[row][colm];//[row * Columns + colm];
		}
			
			
}

void Matrix::initData_char(char* input_data)
{
	for (size_t row = 0; row < Rows; row++)
		for (size_t colm = 0; colm < Columns; colm++)
		{
			StorageData_char[row][colm] = input_data[row * Columns + colm];
		}
			
}

void Matrix::verifyCharinput(const char* input_data)
{
	for (size_t i = 0; i < Rows; i++)
		for (size_t j = 0; j < Columns; j++)
		{
			if (input_data[i * Columns + j] < char(97) || input_data[i * Columns + j] > char(122))
			{
				correct_charData = false;
				std::cout << "Invalid input, matrix wasn`t constructed" << std::endl;
			}
			else correct_charData = true;
				
		}
}

Matrix Matrix::operator=(const Matrix& copy_matrix)
{
	if (&copy_matrix == this)
		return *this;

	if (StorageData_int != nullptr)
	{
		if (Columns > 0)
		{
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_int[i];
		}
		if (Rows > 0)
			delete[] StorageData_int;
		StorageData_int = nullptr;
	}
	if (StorageData_char != nullptr)
	{
		if (Columns > 0)
		{
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_char[i];
		}

		if (Rows > 0)
			delete[] StorageData_char;
		StorageData_char = nullptr;
	}
	Rows = copy_matrix.Rows;
	Columns = copy_matrix.Columns;
	Data_Type = copy_matrix.Data_Type;
	getMemory();

	if (copy_matrix.Data_Type == 'i')
	{
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Columns - 1; colm++)
				StorageData_int[row][colm] = copy_matrix.StorageData_int[row][colm];
		std::cout << "int copy operator worked" << std::endl;

	}
	if (copy_matrix.Data_Type == 'c')
	{
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Columns - 1; colm++)
				StorageData_char[row][colm] = copy_matrix.StorageData_char[row][colm];
		std::cout << "char copy operator worked" << std::endl;
	}		
}

Matrix& Matrix::operator=(Matrix&& moving_matrix)
{
	if (&moving_matrix == this)
		return *this;
	
	Rows = moving_matrix.Rows;
	Columns = moving_matrix.Columns;
	Data_Type = moving_matrix.Data_Type;
	moving_matrix.Rows = 0;
	moving_matrix.Columns = 0;
	moving_matrix.Data_Type = 0;
	if (moving_matrix.StorageData_int != nullptr)
	{
		StorageData_int = moving_matrix.StorageData_int;
		moving_matrix.StorageData_int = nullptr;
		std::cout << "int moving operator worked" << std::endl;
	}
	if (moving_matrix.StorageData_char != nullptr)
	{
		StorageData_char = moving_matrix.StorageData_char;
		moving_matrix.StorageData_char = nullptr;
		std::cout << "char moving operator worked" << std::endl;
	}

}



void Matrix::convertNumData2char()
{ 
	char* buffer;
	int counter(0);
	buffer =  new char [Rows * Columns];
	
	for (size_t row = 0; row < Rows; row++)
		for (size_t colm = 0; colm < Columns; colm++)
		{
			buffer[row * Columns + colm] = char(97 + counter);
			counter++;
			if (counter > 25) counter = 0;
		}
	Matrix* symbolView = new Matrix(buffer, Rows, Columns);

	delete[] buffer;

	symbolView->~Matrix();
}

Matrix::~Matrix()
{
	if (StorageData_int != nullptr)
	{
		if (Columns > 0)
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_int[i];
		if (Rows > 0)
			delete[] StorageData_int;
		StorageData_int = nullptr;
		std::cout << "int destructor worked" << std::endl;

	}
	if (StorageData_char != nullptr)
	{
		if (Columns > 0)
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_char[i];
		if (Rows > 0)
			delete[] StorageData_char;
		StorageData_char = nullptr;
		std::cout << "char destructor worked" << std::endl;
	}
}

