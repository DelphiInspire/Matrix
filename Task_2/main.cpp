#include "Matrix.h"


int main()
{

	int input_2d_int[4][4] = {  {1, 2, 3, 0},
								{4, 5, 6, 0},
								{7, 8, 9, 0},
								{10, 11, 12, 0} };

	int* input_array[4];
	for (size_t i = 0; i < 4; i++)
		input_array[i] = input_2d_int[i];

	Matrix* first = Matrix::CreateDataIntoMatrix(input_array, 4, 4);

	std::string check_first = first->ToString();

	std::cout << "check first" << check_first << std::endl;;
	char t[] = "[a,b,c; d,e,f]";
	Matrix* second = Matrix::CreateStringIntoMatrix(t, 2, 3);
	Matrix* third;
	third = second;

	std::string check_second = second->ToString();
	std::string check_third = third->ToString();
	std::cout << check_second << std::endl;
	std::cout << check_third << std::endl;

	return 0;
}

