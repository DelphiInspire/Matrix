#include "Matrix.h"

Matrix::Matrix()
{
	std::cout << "Simple constructor" << std::endl;
}

Matrix::Matrix(int* a, int rows, int colms) : Colms{ colms }, Rows{rows}
{
	Data_Type = 'i';
	getMemory4StoringData(Rows, Colms, Data_Type);

	initData_int(a, rows, colms);
	std::cout << "int constructor worked" << std::endl;
}

Matrix::Matrix(float* a, int rows, int colms) : Colms{ colms }, Rows{ rows }
{
	Data_Type = 'f';
	getMemory4StoringData(Rows, Colms, Data_Type);

	initData_float(a, rows, colms);
	std::cout << "float constructor worked" << std::endl;
}

Matrix::Matrix(char* a, int rows, int colms) :Colms{ colms }, Rows{rows}
{
	verifyCharinput(a, rows, colms);
	if (correct_charData)
	{
		Data_Type = 'c';
		getMemory4StoringData(Rows, Colms, Data_Type);

		initData_char(a, rows, colms);
		std::cout << "char constructor worked" << std::endl;
	}
}

Matrix::Matrix(const Matrix& m):Rows(m.Rows), Colms(m.Colms), Data_Type(m.Data_Type)
{	
	if (m.Data_Type == 'i')
	{
		getMemory4StoringData(Rows, Colms, m.Data_Type);
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Colms - 1; colm++)
				StorageData_int[row][colm] = m.StorageData_int[row][colm];
		std::cout << "int copy constructor worked" << std::endl;
	}

	else if (m.Data_Type == 'f')
	{
		getMemory4StoringData(Rows, Colms, m.Data_Type);
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Colms - 1; colm++)
				StorageData_float[row][colm] = m.StorageData_float[row][colm];
		std::cout << "float copy constructor worked" << std::endl;
	}
	else if (m.Data_Type == 'c')
	{
		getMemory4StoringData(Rows, Colms, m.Data_Type);
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Colms - 1; colm++)
				StorageData_char[row][colm] = m.StorageData_char[row][colm];
		std::cout << "char copy constructor worked" << std::endl;
	}
		
	
}

Matrix::Matrix(Matrix&& m) :Rows(m.Rows), Colms(m.Colms), Data_Type(m.Data_Type)
{
	m.Colms = 0;
	m.Rows = 0;
	if (m.StorageData_float != nullptr)
	{
		StorageData_float = m.StorageData_float;
		m.StorageData_float = nullptr;
		std::cout << "float moving constructor worked" << std::endl;
	}
	if (m.StorageData_int != nullptr)
	{
		StorageData_int = m.StorageData_int;
		m.StorageData_int = nullptr;
		std::cout << "int moving constructor worked" << std::endl;
	}
	else if (m.StorageData_char != nullptr)
	{
		StorageData_char = m.StorageData_char;
		m.StorageData_char = nullptr;
		std::cout << "char moving constructor worked" << std::endl;
	}
	
	
}

void Matrix::getMemory4StoringData(const int& rows, const int& colms, const char& data_type)
{
	if (data_type == 'i')
	{
		StorageData_int = (int**) new int* [Rows];

		for (size_t i = 0; i < Rows; i++)
			StorageData_int[i] = (int*) new int[Colms];
	}

	else if (data_type == 'f')
	{
		StorageData_float = (float**) new float* [Rows];

		for (size_t i = 0; i < Rows; i++)
			StorageData_float[i] = (float*) new float[Colms];
	}
	else if (data_type == 'c')
	{
		StorageData_char = (char**) new char* [Rows];
		for (size_t i = 0; i < Rows; i++)
			StorageData_char[i] = (char*) new char[Colms];
	}
}

void Matrix::initData_int(int *a, const int& rows, const int& colms)
{
	for (size_t row = 0; row < rows; row++)
		for (size_t colm = 0; colm < colms; colm++)
		{
			StorageData_int[row][colm] = a[row * colms + colm];
		}
			
			
}

void Matrix::initData_float(float* a, const int& rows, const int& colms)
{
	for (size_t row = 0; row < rows; row++)
		for (size_t colm = 0; colm < colms; colm++)
		{
			StorageData_float[row][colm] = a[row * colms + colm];
		}


}

void Matrix::initData_char(char* a, const int& rows, const int& colms)
{
	for (size_t row = 0; row < rows; row++)
		for (size_t colm = 0; colm < colms; colm++)
		{
			StorageData_char[row][colm] = a[row * colms + colm];
		}
			
}

void Matrix::verifyCharinput(const char* a, const int& row, const int& colm)
{
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < colm; j++)
		{
			if (a[i * colm + j] < char(97) || a[i * colm + j] > char(122))
			{
				correct_charData = false;
				std::cout << "Invalid input, matrix wasn`t constructed" << std::endl;
			}
			else correct_charData = true;
				
		}
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
	int quantityElements{ (m.Colms - 1) * (m.Rows - 1) };

	out << '[';
		for (size_t row = 0; row < m.Rows; row++)
			for (size_t colm = 0; colm < m.Colms; colm++)
			{
				if (m.Data_Type == 'i') out << m.StorageData_int[row][colm]; 
				if (m.Data_Type == 'f') out << m.StorageData_float[row][colm];
				if(m.Data_Type == 'c') out << m.StorageData_char[row][colm];
				if (row * colm != quantityElements) out << ',' << ' ';
				if ((colm == m.Colms - 1) && (row != m.Rows - 1)) out << std::endl;
			}
	out << ']';
	return out;
}

Matrix Matrix::operator=(const Matrix& m)
{
	if (&m == this)
		return *this;

	if (StorageData_int != nullptr)
	{
		if (Colms > 0)
		{
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_int[i];
		}
		if (Rows > 0)
			delete[] StorageData_int;
		StorageData_int = nullptr;
	}
	
	if (StorageData_float != nullptr)
	{
		if (Colms > 0)
		{
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_float[i];
		}

		if (Rows > 0)
			delete[] StorageData_float;
		StorageData_float = nullptr;
	}
	if (StorageData_char != nullptr)
	{
		if (Colms > 0)
		{
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_char[i];
		}

		if (Rows > 0)
			delete[] StorageData_char;
		StorageData_char = nullptr;
	}
	Rows = m.Rows;
	Colms = m.Colms;
	Data_Type = m.Data_Type;
	getMemory4StoringData(Rows, Colms, m.Data_Type);

	if (m.Data_Type == 'i')
	{
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Colms - 1; colm++)
				StorageData_int[row][colm] = m.StorageData_int[row][colm];
		std::cout << "int copy operator worked" << std::endl;

	}
	if (m.Data_Type == 'f')
	{
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Colms - 1; colm++)
				StorageData_float[row][colm] = m.StorageData_float[row][colm];
		std::cout << "float copy operator worked" << std::endl;
	}
	if (m.Data_Type == 'c')
	{
		for (size_t row = 0; row <= Rows - 1; row++)
			for (size_t colm = 0; colm <= Colms - 1; colm++)
				StorageData_char[row][colm] = m.StorageData_char[row][colm];
		std::cout << "char copy operator worked" << std::endl;
	}		
}

Matrix& Matrix::operator=(Matrix&& m)
{
	if (&m == this)
		return *this;
	
	Rows = m.Rows;
	Colms = m.Colms;
	Data_Type = m.Data_Type;
	m.Rows = 0;
	m.Colms = 0;
	m.Data_Type = 0;
	if (m.StorageData_float != nullptr)
	{
		StorageData_float = m.StorageData_float;
		m.StorageData_float = nullptr;
		std::cout << "float moving operator worked" << std::endl;
	}
	if (m.StorageData_int != nullptr)
	{
		StorageData_int = m.StorageData_int;
		m.StorageData_int = nullptr;
		std::cout << "int moving operator worked" << std::endl;
	}
	if (m.StorageData_char != nullptr)
	{
		StorageData_char = m.StorageData_char;
		m.StorageData_char = nullptr;
		std::cout << "char moving operator worked" << std::endl;
	}

}

float Matrix::operator()(int i, int j) 
{
	if ((i < Rows) && (j < Colms)) valid_index = true;
	else valid_index = false;

	assert(valid_index && "Invalid matrix index");

	if (StorageData_float != nullptr) return StorageData_float[i][j];
	else if (StorageData_int != nullptr) return StorageData_int[i][j];
	else if (StorageData_char != nullptr) return StorageData_char[i][j];
	else return -1;
}

void Matrix::convertNumData2char()
{
	if (StorageData_char != nullptr)
		std::cout << *this << std::endl;
	else
	{ 
		char* buffer;
		int counter(0);
		buffer =  new char [Rows * Colms];
	
		for (size_t row = 0; row < Rows; row++)
			for (size_t colm = 0; colm < Colms; colm++)
			{
				buffer[row * Colms + colm] = char(97 + counter);
				counter++;
				if (counter > 25) counter = 0;
			}
		Matrix* symbolView = new Matrix(buffer, Rows, Colms);

		std::cout << *symbolView << std::endl;

		delete[] buffer;

		symbolView->~Matrix();
	}
}

Matrix::~Matrix()
{
	if (StorageData_int != nullptr)
	{
		if (Colms > 0)
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_int[i];
		if (Rows > 0)
			delete[] StorageData_int;
		StorageData_int = nullptr;
		std::cout << "int destructor worked" << std::endl;

	}
	if (StorageData_float != nullptr)
	{
		if (Colms > 0)
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_float[i];
		if (Rows > 0)
			delete[] StorageData_float;
		StorageData_float = nullptr;
		std::cout << "float destructor worked" << std::endl;
	}
	if (StorageData_char != nullptr)
	{
		if (Colms > 0)
			for (size_t i = 0; i < Rows; i++)
				delete[] StorageData_char[i];
		if (Rows > 0)
			delete[] StorageData_char;
		StorageData_char = nullptr;
		std::cout << "char destructor worked" << std::endl;
	}
}

