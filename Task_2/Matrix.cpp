#include "Matrix.h"

Matrix::Matrix()
{
	std::cout << "Simple constructor" << std::endl;
}

Matrix::Matrix(int** input_data, int rows, int columns) 
{
	Columns = columns;
	Rows = rows;
	getMemory();

	initData_int(input_data);
	
	std::cout << "int constructor worked" << std::endl;
}

Matrix::Matrix(int input_number)
{
	Columns = 1;
	Rows = 1;
	getMemory();

	std::cout << "int constructor worked" << std::endl;

}

Matrix::Matrix(char* input_line)
{
	verifyCharinput(input_line);
	getMemory();
	initData_int();
	std::cout << "int constructor with char input worked" << std::endl;
}


Matrix::Matrix(const Matrix& copy_matrix)
{	
	Rows = copy_matrix.Rows;
	Columns = copy_matrix.Columns;
	getMemory();
	for (size_t row = 0; row <= Rows - 1; row++)
		for (size_t colm = 0; colm <= Columns - 1; colm++)
			StorageData_int[row][colm] = copy_matrix.StorageData_int[row][colm];
	std::cout << "int copy constructor worked" << std::endl;	
}

Matrix::Matrix(Matrix&& moving_matrix)
{
	Columns = moving_matrix.Columns;
	moving_matrix.Columns = 0;
	Rows = moving_matrix.Rows;
	moving_matrix.Rows = 0;

	if (moving_matrix.StorageData_int != nullptr)
	{
		StorageData_int = moving_matrix.StorageData_int;
		moving_matrix.StorageData_int = nullptr;
		std::cout << "int moving constructor worked" << std::endl;
	}	
}

void Matrix::getMemory()
{
	StorageData_int = new int* [Rows];
	for (size_t row = 0; row < Rows; row++)
		StorageData_int[row] = (int*) new int[Columns];
}

void Matrix::initData_int(int** input_data)
{
	for (size_t row = 0; row < Rows; row++)
		for (size_t colm = 0; colm < Columns; colm++)
		{
			if (input_data != nullptr)
				StorageData_int[row][colm] = input_data[row][colm];//[row * Columns + colm];
			else StorageData_int[row][colm] = 0;
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
			for (size_t row = 0; row < Rows; row++)
				delete[] StorageData_int[row];
		}
		if (Rows > 0)
			delete[] StorageData_int;
		StorageData_int = nullptr;
	}

	Rows = copy_matrix.Rows;
	Columns = copy_matrix.Columns;
	getMemory();

	for (size_t row = 0; row <= Rows - 1; row++)
		for (size_t colm = 0; colm <= Columns - 1; colm++)
			StorageData_int[row][colm] = copy_matrix.StorageData_int[row][colm];
	std::cout << "int copy operator worked" << std::endl;		
}

Matrix& Matrix::operator=(Matrix&& moving_matrix)
{
	if (&moving_matrix == this)
		return *this;
	
	Rows = moving_matrix.Rows;
	Columns = moving_matrix.Columns;
	moving_matrix.Rows = 0;
	moving_matrix.Columns = 0;
	if (moving_matrix.StorageData_int != nullptr)
	{
		StorageData_int = moving_matrix.StorageData_int;
		moving_matrix.StorageData_int = nullptr;
		std::cout << "int moving operator worked" << std::endl;
	}
}

void Matrix::symbolMatrixRepresentation()
{
	unsigned int inner_counter(0);
	std::cout << "[";

	for (size_t rows = 0; rows < Rows; rows++)
	{
		for (size_t colms = 0; colms < Columns; colms++)
		{
			std::cout << char(97 + inner_counter);
			if (colms != Columns - 1)
				std::cout << ",";
			inner_counter++;
		}
		if (rows != Rows - 1)
			std::cout << ";"<<'\t';
	}
	std::cout << "]" << std::endl;
}

void Matrix::verifyCharinput(const char* input_line)
{
	unsigned int elements_counter(0);
	unsigned int row_counter(1);
	unsigned int comma_counter(0);
	for (size_t carriage = 0; carriage < strlen(input_line); carriage++)
	{
		if (input_line[carriage] >= char(97) || input_line[carriage] >= char(122))
			elements_counter++;
		else if (input_line[carriage] == ',')
			comma_counter++;
		else if (input_line[carriage] == ';')
			row_counter++;
	}
	
	assert(input_line[0] == '[' && input_line[strlen(input_line) - 1] == ']' &&
			"Error, check brackets in the input data");
	
		
	assert(elements_counter % row_counter == 0 && comma_counter % row_counter == 0 
			&& "Error, please check matrix dimension or type of all input elements");
		
	
	Rows = row_counter;
	Columns = static_cast<int>(elements_counter / row_counter);
	
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
}

