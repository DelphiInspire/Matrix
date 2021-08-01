#include "Matrix.h"
#include<iomanip>




//Matrix generate_intMatrix(const int rows, const int colms)
//{
//
//	int** generator;
//	generator = new int* [rows];
//
//	for (size_t i = 0; i < rows; i++)
//		generator[i] = new int[colms];
//
//	for (size_t i = 0; i < rows; i++)
//		for (size_t j = 0; j < colms; j++)
//			generator[i][j] = static_cast<int>(rand());
//	Matrix result{ reinterpret_cast<int*>(generator), rows, colms };
//
//	for (size_t i = 0; i < rows; i++)
//		delete[] generator[i];
//	delete[] generator;
//	return result;
//}

//void outresult(std::string* input, int row, int colm)
//{
//	char*** buffer;
//
//	buffer = new char**[row];
//	for (size_t i = 0; i < row; i++)
//		buffer[i] = new char*[colm];
//
//
//	for (int i = 0; i < row; i++)
//		for (int j = 0; j < colm; j++)
//	{
//			buffer[i][j] = new char[input[i * colm + j].length()];
//		strcpy_s(buffer[i][j], sizeof(input[i * colm + j]), input[i * colm + j].c_str());	
//	}
//
//	for (int i = 0; i < row; i++)
//		for (int j = 0; j < colm; j++)
//			delete[] buffer[i][j];
//	for (int i = 0; i < row; i++)
//		delete[] buffer[i];
//
//	delete[] buffer;
//
////	strcpy_s(buffer[0], input[0].c_str());
//	//std::cout << buffer[0][1];
//}

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
	int input = 5;
	//Matrix help(input);

	int* input_array[4];
	for (size_t i = 0; i < 4; i++)
		input_array[i] = input_2d_int[i];
	char t[] = "[a,b,c; d,e,f; g,h,i]";
	Matrix a(t);

	a.symbolMatrixRepresentation();


	
	//int Matrix constructor
	//Matrix a(input_2d_int, 4, 3);
	//char Matrix constructor
	//Matrix c(reinterpret_cast<char*>(input_2d_char), 4, 3);
	////Copy int constructor
	//Matrix a_copy_constr { a };

	////Copy char constructor
	//Matrix c_copy_constr{ c };
	////Copy int operator
	//Matrix a_copy_oper;
	//a_copy_oper = a;
	////Copy float operator
	//Matrix b_copy_oper;

	////Copy char operator
	//Matrix c_copy_oper;
	//c_copy_oper = c;

	////Moving constructor, moving operator
	//Matrix f;
	//f = generate_intMatrix(5, 5);
	//// char representation int Matrix f
	//f.convertNumData2char();
	//c.convertNumData2char();

	const char* str = "Copy string";
	std::string test[2][2] = { {"Yes", "No"},
								{"Ok", "Nok"} };
	//outresult(reinterpret_cast<std::string*>(test), 2, 2);
	return 0;
}

