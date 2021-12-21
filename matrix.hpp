#pragma once
#include <iostream>
#include <vector>
#include "exceptions.hpp"
//#include <algorithm>

const int not_used(1);
const int gorizontal(2);
const int vertical(3);
const int used(5);


class Matrix	///Класс для графического вывода
{
	private:
		size_t height;
		size_t width;
		char** data;
		int** status;
	public:
		Matrix(size_t h, size_t w);
		~Matrix();	
		Matrix(Matrix& a);
		Matrix& operator=(Matrix& a);
		///Метод установки значения клетки
		void set_cell(size_t h, size_t w, char value);	
		///Метод извлечения значения клетки
		void set_cell_status(size_t h, size_t w, int value);	
		///Метод умножения значения клетки статуса
		void multiply_cell_status(size_t h, size_t w, int value);	
		///Метод деления значения клетки статуса
		void divide_cell_status(size_t h, size_t w, int value);	
		///Метод установки значения клетки
		char get_cell(size_t h, size_t w);
		///Метод возврата значения статуса клетки	
		int get_cell_status(size_t h, size_t w);	
		///Метод возврата высоты матрицы
		size_t get_height();	
		///Метод возврата ширины матрицы
		size_t get_width();	
		///Метод возврата незаполненных клеток по значению
		size_t get_unfilled(char check);	
		///Метод возврата незаполненных клеток по статусу
		size_t get_unfilled();	
		///Метод изменения значения  незаполненных клеток 
		/// \details принимает значение для незаполенной клетки и значение замены этой клетки
		void change_unfilled(char check, char value);
		///Метод увеличения размера	
		void increase_size(size_t h, size_t w);
		///Метод приведения матрицы к оптимальному размеру
		void shrink_to_fit(char check);	
		///Метод возврата коэфицента оптимальности матрицы
		double get_coef();	
		///Метод проверки возможности использования клетки
		bool legal(size_t h, size_t w);	
	friend std::ostream& operator<<(std::ostream& os, Matrix& value)
	{
		for (size_t i = 0; i < value.height; i++)
		{
			for (size_t j = 0; j < value.width; j++)
				os << value.data[i][j];
			os << std::endl;
		}
		return os;
	}
};
