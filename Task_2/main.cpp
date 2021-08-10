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

	Matrix first(input_array, 4, 4);

	std::string check_first = first.ToString();

	char t[] = "[125,144;156,56;145,98]";
	Matrix second(t);
	Matrix third;
	third = second;

	std::string check_second = second.ToString();
	std::string check_third = third.ToString();

	return 0;
}

