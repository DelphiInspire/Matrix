#include "Matrix.h"
#include <iostream>


int main()
{
	
	float input_2d_int[3][2] = {  {1, -1},
								{2, 0},
								{3, 0}};

	float multiplyarray[4][4] = /*{ {2, 4, 5},
								{3, -1, 2},
								{-4, 1, 1} }; */
	{ {6.0, -5.0, 8.0, 4.0},
	{ 9.0, 7.0, 5.0, 2.0 },
	{ 7.0, 5.0, 3.0, 7.0 },
	{ -4.0, 8.0, -8.0, -3.0 } };

	
	float* first_array[3];
	for (size_t i = 0; i < 3; i++)
		first_array[i] = input_2d_int[i];

	float* second_array[4];
	for (size_t i = 0; i < 4; i++)
		second_array[i] = multiplyarray[i];
	try
	{
		Matrix member_1(first_array, 3, 2);
		Matrix member_2(second_array, 4, 4);
		member_2 = member_2  * "";
		Matrix multiplyresult;
		multiplyresult = member_1 - member_2;
		char t[] = "[125,144,12,186;156,56,98,45;145,98,181,65;65,74,8596]";
		Matrix second(t);
		Matrix third;
		third = second;
		std::string check_second = second.ToString();
		std::string check_third = third.ToString();	
	}
	catch (Exception & wrong)
	{
		std::cout << wrong.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unexpected exception" << std::endl;
	}
	return 0;

	
}

