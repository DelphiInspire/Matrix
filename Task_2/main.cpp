#include "Matrix.h"
#include <iostream>
#include<iomanip>
#include<typeinfo>
#include<vector>

Matrix generate_intMatrix(const int rows, const int colms)
{

	int** generator;
	generator = new int* [rows];

	for (size_t i = 0; i < rows; i++)
		generator[i] = new int[colms];

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < colms; j++)
			generator[i][j] = static_cast<int>(rand());
	Matrix result{ reinterpret_cast<int*>(generator), rows, colms };

	for (size_t i = 0; i < rows; i++)
		delete[] generator[i];
	delete[] generator;
	return result;
}

int main()
{

	
	int input_1d_int[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int input_2d_int[4][3] = {  {1, 2, 3},
								{4, 5, 6},
								{7, 8, 9},
								{10, 11, 12} };

	float input_2d_float[4][3] = {  {1.1, 2.2, 3.3},
									{4.4, 5.5, 6.6},
									{7.7, 8.8, 9.9},
									{10.10, 11.11, 12.12} };

	char input_2d_char[4][3] = { {'a', 'b', 'c'},
								 {'d', 'e', 'f'},
								 {'g', 'o', 'p'},
								 {'r', 's', 't'} };
	//int Matrix constructor
	Matrix a(reinterpret_cast<int*>(input_2d_int), 4, 3);
	std::cout << a << std::endl;
	//float Matrix constructor
	Matrix b(reinterpret_cast<float*>(input_2d_float), 4, 3);
	std::cout << b << std::endl;
	//char Matrix constructor
	Matrix c(reinterpret_cast<char*>(input_2d_char), 4, 3);
	std::cout << c << std::endl;
	//Copy int constructor
	Matrix a_copy_constr { a };
	std::cout << a_copy_constr << std::endl;
	//Copy float contructor
	Matrix b_copy_constr{ b };
	std::cout << b_copy_constr << std::endl;
	//Copy char constructor
	Matrix c_copy_constr{ c };
	std::cout << c_copy_constr << std::endl;
	//Copy int operator
	Matrix a_copy_oper;
	a_copy_oper = a;
	std::cout << a_copy_oper << std::endl;
	//Copy float operator
	Matrix b_copy_oper;
	b_copy_oper = b;
	std::cout << b_copy_oper << std::endl;
	//Copy char operator
	Matrix c_copy_oper;
	c_copy_oper = c;
	std::cout << c_copy_oper << std::endl;
	//Moving constructor, moving operator
	Matrix f;
	f = generate_intMatrix(5, 5);
	std::cout << f << std::endl;
	// char representation int Matrix f
	f.convertNumData2char();
	c.convertNumData2char();
	//take element from matrix
	std::cout << b(1, 1) << std::endl;
	return 0;
}