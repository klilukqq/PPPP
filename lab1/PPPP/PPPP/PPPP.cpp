#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void delete_matrix(int** matrix, int row) {
	for (int i = 0; i < row; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void matrix_print(int** matrix, int matrix_row_first, int matrix_column_first) {
	
	for (int number_lines = 0; number_lines < matrix_row_first; number_lines++)
	{
		for (int number_columns = 0; number_columns < matrix_column_first; number_columns++)
			cout << matrix[number_lines][number_columns] << " ";
		cout << endl;
	}
}

void filling_matrix(int** matrix,int matrix_row, int matrix_column, int type_filling) {
	switch (type_filling)
	{
	case 1:
		for (int number_lines = 0; number_lines < matrix_row; number_lines++)
			for (int number_columns = 0; number_columns < matrix_column; number_columns++)
				cin >> matrix[number_lines][number_columns];
		break;
	case 2:
		for (int number_lines = 0; number_lines < matrix_row; number_lines++)
			for (int number_columns = 0; number_columns < matrix_column; number_columns++)
				matrix[number_lines][number_columns] = rand() % 10;
		break;
	default:
		break;
	}
}


void convertion_matrix(int** modified_matrix, int** matrix, int required_matrix_size, int matrix_row, int matrix_column) {
	for (int number_lines = 0; number_lines < required_matrix_size; number_lines++)
	{
		modified_matrix[number_lines] = new int[required_matrix_size];
		for (int number_columns = 0; number_columns < required_matrix_size; number_columns++)
			modified_matrix[number_lines][number_columns] = 0;
	}
	for (int number_lines = 0; number_lines < matrix_row; number_lines++)
	{
		for (int number_columns = 0; number_columns < matrix_column; number_columns++)
			modified_matrix[number_lines][number_columns] = matrix[number_lines][number_columns];
	}
}

void create_optional_matrix(int ** inter_matrix, int required_matrix_size) {
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		inter_matrix[number_lines] = new int[required_matrix_size / 2];
	}
}

void filling_submatrix(int** submatrix,int** modified_matrix,int required_matrix_size,int choose) {

	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		submatrix[number_lines] = new int[required_matrix_size / 2];
		for (int number_columns = 0; number_columns < required_matrix_size / 2; number_columns++)
			switch (choose)
			{
			case 1:
				submatrix[number_lines][number_columns] = modified_matrix[number_lines][number_columns];
				break;
			case 2:
				submatrix[number_lines][number_columns] = modified_matrix[number_lines][number_columns + required_matrix_size / 2];
				break;
			case 3:
				submatrix[number_lines][number_columns] = modified_matrix[number_lines + required_matrix_size / 2][number_columns];
				break;
			case 4:
				submatrix[number_lines][number_columns] = modified_matrix[number_lines + required_matrix_size / 2][number_columns + required_matrix_size / 2];
				break;
			default:
				break;
			}
	}
}


void main()
{
	srand(time(NULL));
	int matrix_row_first, matrix_column_first, matrix_row_second, matrix_column_second, chosen_method, required_matrix_size = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";


	//Ввод размеров матрицы пользователем
	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> matrix_row_first >> matrix_column_first;
	} while (matrix_row_first <= 0 || matrix_column_first <= 0);
	do
	{
		cout << "Введите размеры второй матрицы\n";
		cin >> matrix_row_second >> matrix_column_second;
	} while (matrix_row_second <= 0 || matrix_column_second <= 0);

	int** matrix_first = new int* [matrix_row_first];
	for (int number_lines = 0; number_lines < matrix_row_first; number_lines++)
		matrix_first[number_lines] = new int[matrix_column_first];
	int** matrix_second = new int* [matrix_row_second];
	for (int number_lines = 0; number_lines < matrix_row_second; number_lines++)
		matrix_second[number_lines] = new int[matrix_column_second];

	
	//Выбор способа заполнения и заполнение матриц
	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> chosen_method;
	} while (chosen_method < 1 || chosen_method > 2);
	switch (chosen_method)
	{
	case 1:
		filling_matrix(matrix_first, matrix_row_first, matrix_column_first, 1);
		filling_matrix(matrix_second, matrix_row_second, matrix_column_second, 1);
		cout << "\nМатрица 1\n\n";
		matrix_print(matrix_first, matrix_row_first, matrix_column_first);
		cout << "\nМатрица 2\n\n";
		matrix_print(matrix_second, matrix_row_second, matrix_column_second);

		break;
	case 2:
		filling_matrix(matrix_first, matrix_row_first, matrix_column_first, 2);
		filling_matrix(matrix_second, matrix_row_second, matrix_column_second, 2);
		cout << "\nМатрица 1\n\n";
		matrix_print(matrix_first, matrix_row_first, matrix_column_first);
		cout << "\nМатрица 2\n\n";
		matrix_print(matrix_second, matrix_row_second, matrix_column_second);
		break;
	}

	//Приведение матриц к требуемому размеру
	while (required_matrix_size < matrix_row_first || required_matrix_size < matrix_row_second || required_matrix_size < matrix_column_first || required_matrix_size < matrix_column_second)
		required_matrix_size *= 2;
	int** modified_matrix_first = new int* [required_matrix_size];
	convertion_matrix(modified_matrix_first, matrix_first, required_matrix_size, matrix_row_first, matrix_column_first);
	int** modified_matrix_second = new int* [required_matrix_size];
	convertion_matrix(modified_matrix_second, matrix_second, required_matrix_size, matrix_row_second, matrix_column_second);

	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	matrix_print(modified_matrix_first, required_matrix_size, required_matrix_size);
	cout << "\nМатрица 2\n\n";
	matrix_print(modified_matrix_second, required_matrix_size, required_matrix_size);


	//Разбиение матриц на подматрицы и их заполнение

	int** submatrix_first = new int* [required_matrix_size / 2];;
	filling_submatrix(submatrix_first, modified_matrix_first, required_matrix_size, 1);
	int** submatrix_second = new int* [required_matrix_size / 2];
	filling_submatrix(submatrix_second, modified_matrix_first, required_matrix_size, 2);
	int** submatrix_third = new int* [required_matrix_size / 2];
	filling_submatrix(submatrix_third, modified_matrix_first, required_matrix_size, 3);
	int** submatrix_fourth = new int* [required_matrix_size / 2];
	filling_submatrix(submatrix_fourth, modified_matrix_first, required_matrix_size, 4);
	int** submatrix_fifth = new int* [required_matrix_size / 2];
	filling_submatrix(submatrix_fifth, modified_matrix_second, required_matrix_size, 1);
	int** submatrix_sixth = new int* [required_matrix_size / 2];
	filling_submatrix(submatrix_sixth, modified_matrix_second, required_matrix_size, 2);
	int** submatrix_seventh = new int* [required_matrix_size / 2];
	filling_submatrix(submatrix_seventh, modified_matrix_second, required_matrix_size, 3);
	int** submatrix_eighth = new int* [required_matrix_size / 2];
	filling_submatrix(submatrix_eighth, modified_matrix_second, required_matrix_size, 4);


	//Создание промежуточных матриц
	int** intermedia_matrix_first = new int* [required_matrix_size / 2];
	create_optional_matrix(intermedia_matrix_first, required_matrix_size);
	int** intermedia_matrix_second = new int* [required_matrix_size / 2];
	create_optional_matrix(intermedia_matrix_second, required_matrix_size);
	int** intermedia_matrix_third = new int* [required_matrix_size / 2];
	create_optional_matrix(intermedia_matrix_third, required_matrix_size);
	int** intermedia_matrix_fourth = new int* [required_matrix_size / 2];
	create_optional_matrix(intermedia_matrix_fourth, required_matrix_size);
	int** intermedia_matrix_fifth = new int* [required_matrix_size / 2];
	create_optional_matrix(intermedia_matrix_fifth, required_matrix_size);
	int** intermedia_matrix_sixth = new int* [required_matrix_size / 2];
	create_optional_matrix(intermedia_matrix_sixth, required_matrix_size);
	int** intermedia_matrix_seventh = new int* [required_matrix_size / 2];
	create_optional_matrix(intermedia_matrix_seventh, required_matrix_size);



	//Вычисление значений промежуточных матриц
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		for (int number_columns = 0; number_columns < required_matrix_size / 2; number_columns++)
		{
			intermedia_matrix_first[number_lines][number_columns] = 0;
			for (int z = 0; z < required_matrix_size / 2; z++)
			{
				intermedia_matrix_first[number_lines][number_columns] += (submatrix_first[number_lines][z] + submatrix_fourth[number_lines][z]) * (submatrix_fifth[z][number_columns] + submatrix_eighth[z][number_columns]);
			}

			intermedia_matrix_second[number_lines][number_columns] = 0;
			for (int z = 0; z < required_matrix_size / 2; z++)
			{
				intermedia_matrix_second[number_lines][number_columns] += (submatrix_third[number_lines][z] + submatrix_fourth[number_lines][z]) * submatrix_fifth[z][number_columns];
			}

			intermedia_matrix_third[number_lines][number_columns] = 0;
			for (int z = 0; z < required_matrix_size / 2; z++)
			{
				intermedia_matrix_third[number_lines][number_columns] += submatrix_first[number_lines][z] * (submatrix_sixth[z][number_columns] - submatrix_eighth[z][number_columns]);
			}

			intermedia_matrix_fourth[number_lines][number_columns] = 0;
			for (int z = 0; z < required_matrix_size / 2; z++)
			{
				intermedia_matrix_fourth[number_lines][number_columns] += submatrix_fourth[number_lines][z] * (submatrix_seventh[z][number_columns] - submatrix_fifth[z][number_columns]);
			}

			intermedia_matrix_fifth[number_lines][number_columns] = 0;
			for (int z = 0; z < required_matrix_size / 2; z++)
			{
				intermedia_matrix_fifth[number_lines][number_columns] += (submatrix_first[number_lines][z] + submatrix_second[number_lines][z]) * submatrix_eighth[z][number_columns];
			}

			intermedia_matrix_sixth[number_lines][number_columns] = 0;
			for (int z = 0; z < required_matrix_size / 2; z++)
			{
				intermedia_matrix_sixth[number_lines][number_columns] += (submatrix_third[number_lines][z] - submatrix_first[number_lines][z]) * (submatrix_fifth[z][number_columns] + submatrix_sixth[z][number_columns]);
			}

			intermedia_matrix_seventh[number_lines][number_columns] = 0;
			for (int z = 0; z < required_matrix_size / 2; z++)
			{
				intermedia_matrix_seventh[number_lines][number_columns] += (submatrix_second[number_lines][z] - submatrix_fourth[number_lines][z]) * (submatrix_seventh[z][number_columns] + submatrix_eighth[z][number_columns]);
			}
		}
	}

	//Создание вспомогательных матриц
	int** supporting_matrix_first = new int* [required_matrix_size / 2];
	create_optional_matrix(supporting_matrix_first, required_matrix_size);

	int** supporting_matrix_second = new int* [required_matrix_size / 2];
	create_optional_matrix(supporting_matrix_second, required_matrix_size);

	int** supporting_matrix_third = new int* [required_matrix_size / 2];
	create_optional_matrix(supporting_matrix_third, required_matrix_size);

	int** supporting_matrix_fourth = new int* [required_matrix_size / 2];
	create_optional_matrix(supporting_matrix_fourth, required_matrix_size);




	//Подсчет значений вспомогательных матриц из промежуточных
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		for (int number_columns = 0; number_columns < required_matrix_size / 2; number_columns++)
		{
			supporting_matrix_first[number_lines][number_columns] = intermedia_matrix_first[number_lines][number_columns] + intermedia_matrix_fourth[number_lines][number_columns] - intermedia_matrix_fifth[number_lines][number_columns] + intermedia_matrix_seventh[number_lines][number_columns];
			supporting_matrix_second[number_lines][number_columns] = intermedia_matrix_third[number_lines][number_columns] + intermedia_matrix_fifth[number_lines][number_columns];
			supporting_matrix_third[number_lines][number_columns] = intermedia_matrix_second[number_lines][number_columns] + intermedia_matrix_fourth[number_lines][number_columns];
			supporting_matrix_fourth[number_lines][number_columns] = intermedia_matrix_first[number_lines][number_columns] - intermedia_matrix_second[number_lines][number_columns] + intermedia_matrix_third[number_lines][number_columns] + intermedia_matrix_sixth[number_lines][number_columns];
		}
	}



	//Создание результирующей матрицы
	int** resulting_matrix = new int* [required_matrix_size];
	for (int number_lines = 0; number_lines < required_matrix_size; number_lines++)
	{
		resulting_matrix[number_lines] = new int[required_matrix_size];
	}


	//Занесение информации из вспомогательных матриц в результирующую
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		for (int number_columns = 0; number_columns < required_matrix_size / 2; number_columns++)
		{
			resulting_matrix[number_lines][number_columns] = supporting_matrix_first[number_lines][number_columns];
			resulting_matrix[number_lines][number_columns + required_matrix_size / 2] = supporting_matrix_second[number_lines][number_columns];
			resulting_matrix[number_lines + required_matrix_size / 2][number_columns] = supporting_matrix_third[number_lines][number_columns];
			resulting_matrix[number_lines + required_matrix_size / 2][number_columns + required_matrix_size / 2] = supporting_matrix_fourth[number_lines][number_columns];
		}
	}

	//Выравнивание границ результирующей матрицы
	int nonzero_elements_line = 0, first_null_line = 100, first_null_column = 100;
	for (int number_lines = 0; number_lines < required_matrix_size; number_lines++)
	{
		nonzero_elements_line = 0;
		for (int number_columns = 0; number_columns < required_matrix_size; number_columns++)
		{
			if (resulting_matrix[number_lines][number_columns] != 0)
			{
				nonzero_elements_line++;
				first_null_line = 100;
			}
		}
		if (nonzero_elements_line == 0 && number_lines < first_null_line)
		{
			first_null_line = number_lines;
		}
	}
	for (int number_lines = 0; number_lines < required_matrix_size; number_lines++)
	{
		nonzero_elements_line = 0;
		for (int number_columns = 0; number_columns < required_matrix_size; number_columns++)
		{
			if (resulting_matrix[number_columns][number_lines] != 0)
			{
				nonzero_elements_line++;
				first_null_column = 100;
			}
		}
		if (nonzero_elements_line == 0 && number_lines < first_null_column)
		{
			first_null_column = number_lines;
		}
	}

	int** aligned_resulting_matrix = new int* [first_null_line];
	for (int number_lines = 0; number_lines < first_null_line; number_lines++)
	{
		aligned_resulting_matrix[number_lines] = new int[first_null_column];
		for (int number_columns = 0; number_columns < first_null_column; number_columns++)
			aligned_resulting_matrix[number_lines][number_columns] = resulting_matrix[number_lines][number_columns];
	}

	
	//Вывод результирующей матрицы
	cout << "\nРезультирующая матрица\n\n";
	matrix_print(aligned_resulting_matrix, first_null_line, first_null_column);
	system("pause");


	//Очистка динамической памяти
	delete_matrix(matrix_first, matrix_row_first);
	delete_matrix(matrix_second, matrix_row_second);
	delete_matrix(modified_matrix_first, required_matrix_size);
	delete_matrix(modified_matrix_second, required_matrix_size);
	delete_matrix(resulting_matrix, required_matrix_size);
	delete_matrix(aligned_resulting_matrix, first_null_line);
	delete_matrix(submatrix_first, required_matrix_size / 2);
	delete_matrix(submatrix_second, required_matrix_size / 2);
	delete_matrix(submatrix_third, required_matrix_size / 2);
	delete_matrix(submatrix_fourth, required_matrix_size / 2);
	delete_matrix(submatrix_fifth, required_matrix_size / 2);
	delete_matrix(submatrix_sixth, required_matrix_size / 2);
	delete_matrix(submatrix_seventh, required_matrix_size / 2);
	delete_matrix(submatrix_eighth, required_matrix_size / 2);
	delete_matrix(supporting_matrix_first, required_matrix_size / 2);
	delete_matrix(supporting_matrix_second, required_matrix_size / 2);
	delete_matrix(supporting_matrix_third, required_matrix_size / 2);
	delete_matrix(supporting_matrix_fourth, required_matrix_size / 2);
	delete_matrix(intermedia_matrix_first, required_matrix_size / 2);
	delete_matrix(intermedia_matrix_second, required_matrix_size / 2);
	delete_matrix(intermedia_matrix_third, required_matrix_size / 2);
	delete_matrix(intermedia_matrix_fourth, required_matrix_size / 2);
	delete_matrix(intermedia_matrix_fifth, required_matrix_size / 2);
	delete_matrix(intermedia_matrix_sixth, required_matrix_size / 2);
	delete_matrix(intermedia_matrix_seventh, required_matrix_size / 2);
}