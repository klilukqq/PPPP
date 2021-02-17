#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void matrix_print(int** matrix, int matrix_row_first, int matrix_column_first) {
	
	for (int number_lines = 0; number_lines < matrix_row_first; number_lines++)
	{
		for (int number_columns = 0; number_columns < matrix_column_first; number_columns++)
			cout << matrix[number_lines][number_columns] << " ";
		cout << endl;
	}

}

int** asd(int** submatrix,int** modified_matrix,int required_matrix_size,int choose) {

	
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
	return submatrix;
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
		for (int number_lines = 0; number_lines < matrix_row_first; number_lines++)
			for (int number_columns = 0; number_columns < matrix_column_first; number_columns++)
				cin >> matrix_first[number_lines][number_columns];
		for (int number_lines = 0; number_lines < matrix_row_second; number_lines++)
			for (int number_columns = 0; number_columns < matrix_column_second; number_columns++)
				cin >> matrix_second[number_lines][number_columns];
		cout << "\nМатрица 1\n\n";
		matrix_print(matrix_first, matrix_row_first, matrix_column_first);
		cout << "\nМатрица 2\n\n";
		matrix_print(matrix_second, matrix_row_second, matrix_column_second);

		break;
	case 2:
		for (int number_lines = 0; number_lines < matrix_row_first; number_lines++)
			for (int number_columns = 0; number_columns < matrix_column_first; number_columns++)
				matrix_first[number_lines][number_columns] = rand() % 10;
		for (int number_lines = 0; number_lines < matrix_row_second; number_lines++)
			for (int number_columns = 0; number_columns < matrix_column_second; number_columns++)
				matrix_second[number_lines][number_columns] = rand() % 10;
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
	for (int number_lines = 0; number_lines < required_matrix_size; number_lines++)
	{
		modified_matrix_first[number_lines] = new int[required_matrix_size];
		for (int number_columns = 0; number_columns < required_matrix_size; number_columns++)
			modified_matrix_first[number_lines][number_columns] = 0;
	}
	int** modified_matrix_second = new int* [required_matrix_size];
	for (int number_lines = 0; number_lines < required_matrix_size; number_lines++)
	{
		modified_matrix_second[number_lines] = new int[required_matrix_size];
		for (int number_columns = 0; number_columns < required_matrix_size; number_columns++)
			modified_matrix_second[number_lines][number_columns] = 0;
	}
	for (int number_lines = 0; number_lines < matrix_row_first; number_lines++)
	{
		for (int number_columns = 0; number_columns < matrix_column_first; number_columns++)
			modified_matrix_first[number_lines][number_columns] = matrix_first[number_lines][number_columns];
	}
	for (int number_lines = 0; number_lines < matrix_row_second; number_lines++)
	{
		for (int number_columns = 0; number_columns < matrix_column_second; number_columns++)
			modified_matrix_second[number_lines][number_columns] = matrix_second[number_lines][number_columns];
	}
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	matrix_print(modified_matrix_first, required_matrix_size, required_matrix_size);
	cout << "\nМатрица 2\n\n";
	matrix_print(modified_matrix_second, required_matrix_size, required_matrix_size);


	//Разбиение матриц на подматрицы и их заполнение

	int** submatrix_first = new int* [required_matrix_size / 2];;
	submatrix_first = asd(submatrix_first, modified_matrix_first, required_matrix_size, 1);
	int** submatrix_second = new int* [required_matrix_size / 2];
	submatrix_second = asd(submatrix_second, modified_matrix_first, required_matrix_size, 2);
	int** submatrix_third = new int* [required_matrix_size / 2];
	submatrix_third = asd(submatrix_third, modified_matrix_first, required_matrix_size, 3);
	int** submatrix_fourth = new int* [required_matrix_size / 2];
	submatrix_fourth = asd(submatrix_fourth, modified_matrix_first, required_matrix_size, 4);
	int** submatrix_fifth = new int* [required_matrix_size / 2];
	submatrix_fifth = asd(submatrix_fifth, modified_matrix_second, required_matrix_size, 1);
	int** submatrix_sixth = new int* [required_matrix_size / 2];
	submatrix_sixth = asd(submatrix_sixth, modified_matrix_second, required_matrix_size, 2);
	int** submatrix_seventh = new int* [required_matrix_size / 2];
	submatrix_seventh = asd(submatrix_seventh, modified_matrix_second, required_matrix_size, 3);
	int** submatrix_eighth = new int* [required_matrix_size / 2];

	submatrix_eighth = asd(submatrix_eighth, modified_matrix_second, required_matrix_size, 4);


	//Создание промежуточных матриц
	int** intermedia_matrix_first = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		intermedia_matrix_first[number_lines] = new int[required_matrix_size / 2];
	}
	int** intermedia_matrix_second = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		intermedia_matrix_second[number_lines] = new int[required_matrix_size / 2];
	}
	int** intermedia_matrix_third = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		intermedia_matrix_third[number_lines] = new int[required_matrix_size / 2];
	}
	int** intermedia_matrix_fourth = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		intermedia_matrix_fourth[number_lines] = new int[required_matrix_size / 2];
	}
	int** intermedia_matrix_fifth = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		intermedia_matrix_fifth[number_lines] = new int[required_matrix_size / 2];
	}
	int** intermedia_matrix_sixth = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		intermedia_matrix_sixth[number_lines] = new int[required_matrix_size / 2];
	}
	int** intermedia_matrix_seventh = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		intermedia_matrix_seventh[number_lines] = new int[required_matrix_size / 2];
	}



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
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		supporting_matrix_first[number_lines] = new int[required_matrix_size / 2];
	}
	int** supporting_matrix_second = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		supporting_matrix_second[number_lines] = new int[required_matrix_size / 2];
	}
	int** supporting_matrix_third = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		supporting_matrix_third[number_lines] = new int[required_matrix_size / 2];
	}
	int** supporting_matrix_fourth = new int* [required_matrix_size / 2];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		supporting_matrix_fourth[number_lines] = new int[required_matrix_size / 2];
	}



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
	for (int number_lines = 0; number_lines < first_null_line; number_lines++)
	{
		for (int number_columns = 0; number_columns < first_null_column; number_columns++)
			cout << aligned_resulting_matrix[number_lines][number_columns] << " ";
		cout << endl;
	}

	system("pause");



	//Очистка динамической памяти
	for (int number_lines = 0; number_lines < matrix_row_first; number_lines++)
		delete[] matrix_first[number_lines];
	for (int number_lines = 0; number_lines < matrix_row_second; number_lines++)
		delete[] matrix_second[number_lines];
	for (int number_lines = 0; number_lines < required_matrix_size; number_lines++)
	{
		delete[] modified_matrix_first[number_lines];
		delete[] modified_matrix_second[number_lines];
		delete[] resulting_matrix[number_lines];
	}
	for (int number_lines = 0; number_lines < first_null_line; number_lines++)
		delete[] aligned_resulting_matrix[number_lines];
	for (int number_lines = 0; number_lines < required_matrix_size / 2; number_lines++)
	{
		delete[] submatrix_first[number_lines];
		delete[] submatrix_second[number_lines];
		delete[] submatrix_third[number_lines];
		delete[] submatrix_fourth[number_lines];
		delete[] submatrix_fifth[number_lines];
		delete[] submatrix_sixth[number_lines];
		delete[] submatrix_seventh[number_lines];
		delete[] submatrix_eighth[number_lines];
		delete[] supporting_matrix_first[number_lines];
		delete[] supporting_matrix_second[number_lines];
		delete[] supporting_matrix_third[number_lines];
		delete[] supporting_matrix_fourth[number_lines];
		delete[] intermedia_matrix_first[number_lines];
		delete[] intermedia_matrix_second[number_lines];
		delete[] intermedia_matrix_third[number_lines];
		delete[] intermedia_matrix_fourth[number_lines];
		delete[] intermedia_matrix_fifth[number_lines];
		delete[] intermedia_matrix_sixth[number_lines];
		delete[] intermedia_matrix_seventh[number_lines];
	}
	delete[] matrix_first, matrix_second, modified_matrix_first, modified_matrix_second, resulting_matrix, aligned_resulting_matrix;
	delete[] submatrix_first, submatrix_second, submatrix_third, submatrix_fourth, submatrix_fifth, submatrix_sixth, submatrix_seventh, submatrix_eighth, supporting_matrix_first, supporting_matrix_second, supporting_matrix_third, supporting_matrix_fourth;
	delete[] intermedia_matrix_first, intermedia_matrix_second, intermedia_matrix_third, intermedia_matrix_fourth, intermedia_matrix_fifth, intermedia_matrix_sixth, intermedia_matrix_seventh;
}