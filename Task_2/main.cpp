#include "Matrix.h"



int main()
{

	int input_2d_int[3][2] = {  {1, -1},
								{2, 0},
								{3, 0}};

	int multiplyarray[4][4] = /*{ {2, 4, 5},
								{3, -1, 2},
								{-4, 1, 1} }; */
	{ {6, -5, 8, 4},
	{ 9, 7, 5, 2 },
	{ 7, 5, 3, 7 },
	{ -4, 8, -8, -3 } };

	
	int* first_array[3];
	for (size_t i = 0; i < 3; i++)
		first_array[i] = input_2d_int[i];

	int* second_array[4];
	for (size_t i = 0; i < 4; i++)
		second_array[i] = multiplyarray[i];

	Matrix member_1(first_array, 3, 2);
	Matrix member_2(second_array, 4, 4);
	member_2.inverseMatrix();
	Matrix multiplyresult;
	multiplyresult = member_1 + member_2;

	char t[] =  "[125,144,12,186;156,56,98,45;145,98,181,65;65,74,85,96]" ;
	Matrix second(t);
	Matrix third;
	third = second;

	std::string check_second = second.ToString();
	std::string check_third = third.ToString();


	return 0;
}

