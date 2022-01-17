#include "pch.h"
#include "..\MatPart181_2\header_functions181.h"


TEST(Test, Test_DOB_function) { //Добавление элемента в массив с определенным индексом и значением
	double* array1 = new double[4]{ -1, 0, -224 };
	double r = 1;//Индекс
	double t = 78.44;//Значение
	int n = 3;//Начальный размер массива
	double* result = new double[4]{-1, 78.44, 0, -224 };
	array1 = DOB(array1, n, r, t);

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(result[i], array1[i]);

	delete[] array1;
	delete[] result;
}

TEST(Test, Test_DOB_function_1) {		//Добавление элемента в массив, с определенным индексом и значением
	double* array1 = new double[4]{ -1, 0, -224 };
	double r = 0;//Индекс
	double t = 32;//Значение
	int n = 3;//Размер начального массива
	double* result = new double[4]{ 32, -1, 0, -224 };
	array1 = DOB(array1, n, r, t);

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(result[i], array1[i]);

	delete[] array1;
	delete[] result;
}

TEST(Test, Test_F1_function_1) {		//Добавление элемента в массив, с определенным индексом и значением
	double* array1 = new double[9]{ -1, 0, 45,6,-45,45,2,67, -224 };
	int n = 9;//Размер начального массива
	double z = 45;
	double* array2 = F1(array1, n, z);
	double* result = new double[11]{ -1, 0, 45,45,6,-45,45,45,2,67, -224 };
	

	for (int i = 0; i < 11; i++)
		EXPECT_EQ(result[i], array2[i]);

	delete[] array1;
	delete[] array2;
	delete[] result;
}

TEST(Test, Test_RELU_function_1) {		//Обнуление отрицательных элементов
	double* array1 = new double[3]{ -1, 0, -224 };
	int n = 3;//Размер начального массива
	double* result = new double[3]{ 0,0,0 };
	RELU(array1, n);

	for (int i = 0; i < 3; i++)
		EXPECT_EQ(result[i], array1[i]);

	delete[] array1;
	delete[] result;
}
TEST(Test, Test_RELU_function_2) {		//Обнуление отрицательных элементов
	double* array1 = new double[7]{ 2,45,-1,56,67, 0, -224 };
	int n = 7;//Размер начального массива
	double* result = new double[7]{ 2,45,0,56,67,0,0 };
	RELU(array1, n);

	for (int i = 0; i < 7; i++)
		EXPECT_EQ(result[i], array1[i]);

	delete[] array1;
	delete[] result;
}

//Определить отношение суммы элементов массива, расположенных до последнего 
//из максимальных элементов в массиве , если он не единственный, к произведению элементов,
//расположенных после максимального.

TEST(Test, Test_Zad_function_1) {
	double* array1 = new double[7]{ 1,1,1,1,67, 1, 3 };
	int n = 7;//Размер начального массива
	double result = 1;
	double O;
	Zad(array1, n, O);

	EXPECT_EQ(result, O);

	delete[] array1;
}

TEST(Test, Test_Zad_function_2) {
	double* array1 = new double[7]{ 1,32,-32,1,67, 1, 3 };
	int n = 7;//Размер начального массива
	double result = 0.5;
	double O;
	Zad(array1, n, O);

	EXPECT_EQ(result, O);

	delete[] array1;
}