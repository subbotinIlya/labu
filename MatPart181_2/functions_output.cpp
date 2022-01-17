#include "header_functions181.h"

//Вывод матрицы в консоль
void output_matrix(double** matrix_int_data, int matrix_size) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			printf(" %g ", matrix_int_data[i][j]);
		}
		cout << endl;
	}
}
//Вывод вектора на экран
void output_array(double* array_numb, int array_size) {
	for (int i = 0; i < array_size; i++) {
		if (i % 10 == 0) printf("\n");
		printf("%g  ", array_numb[i]);
	}
	printf("\n");
}
