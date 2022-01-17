#include "header181.h"
#include "MatPart181_2\header_functions181.h"

#include <boost/program_options.hpp>

using namespace boost::program_options;

void on_array_size_1(int number)
{
	std::cout << "On array_size_1: " << number << '\n';
}

void on_array_size_2(int number)
{
	std::cout << "On array_size_2: " << number << '\n';
}
void on_matrix_size(int number)
{
	std::cout << "On matrix_size: " << number << '\n';
}

void main(int argc, const char* argv[]) {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int default_size = 17;//Стандартные размеры 
	int array_size_1 = 10, array_size_2 = 15;
	int matrix_size = 7;

	try//Через командную строку
	{
		options_description desc{ "Options" };
		desc.add_options()
			("help,h", "Help screen")
			("array_size_1", value<int>()->notifier(on_array_size_1), "on_array_size_1")//Размер векторов
			("array_size_2", value<int>()->notifier(on_array_size_2), "on_array_size_2")//Размер векторов
			("matrix_size", value<int>()->notifier(on_matrix_size), "Matrix_size");//Размер матриц

		variables_map vm;
		//АСИ 18-1 --array_size_1 7 --array_size_2 3
		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_1")) {
			std::cout << "Array_size_1: " << vm["array_size_1"].as<int>() << '\n';
			array_size_1 = vm["array_size_1"].as<int>();//Записываем в наш размер значение из командной строки
		}

		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_2")) {
			std::cout << "Array_size_2: " << vm["array_size_2"].as<int>() << '\n';
			array_size_2 = vm["array_size_2"].as<int>();//Записываем в наш размер значение из командной строки
		}

		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("matrix_size")) {
			std::cout << "Matrix_size: " << vm["matrix_size"].as<int>() << '\n';
			matrix_size = vm["matrix_size"].as<int>();//Записываем в наш размер значение из командной строки
		}

	}
	catch (const error& ex)
	{
		std::cerr << ex.what() << '\n';
	}

	//Работа с векторами и матрицами
	double* array_int_time = new double[array_size_1];
	double* array_int_data = new double[array_size_2];
	double** matrix_int_time = new double* [matrix_size];
	double** matrix_int_data = new double* [matrix_size];
	for (int i = 0; i < matrix_size; i++) {
		matrix_int_time[i] = new double[matrix_size];
		matrix_int_data[i] = new double[matrix_size];
	}

	initialization(array_int_time, array_int_data, array_size_1, array_size_2, matrix_int_time, matrix_int_data, matrix_size);
	printf("Начальный вектор time: \n");
	output_array(array_int_time, array_size_1);
	printf("Начальный вектор data: \n");
	output_array(array_int_data, array_size_2);
	printf("Начальная матрица time: \n");
	output_matrix(matrix_int_time, matrix_size);


	double* B = F1(array_int_time, array_size_1);
	printf("Вектор после удвоени¤ числа: \n");
	output_array(B, array_size_1);

	int array_size_3 = array_size_1;
	double* B2 = F1(B, array_size_1);
	printf("Вектор после удвоени¤ числа: \n");
	output_array(B2, array_size_3);
	

	RELU(array_int_data, array_size_2);
	printf("Вектор после функции RELU: \n");
	output_array(array_int_data, array_size_2);

	DOB(B, array_size_1,2,32);
	printf("Вектор после вставки нового элемента: \n");
	output_array(B, array_size_1);

	double O;
	Zad(B2, array_size_3, O);
	cout << endl;



	cout << endl;
	//_getch();
	system("pause");
}


