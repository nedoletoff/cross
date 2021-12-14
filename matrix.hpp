#pragma once
#include <iostream>
#include <vector>
#include "exceptions.hpp"
//#include <algorithm>

const int not_used(1);
const int gorizontal(2);
const int vertical(3);
const int used(5);


class Matrix
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
		void set_cell(size_t h, size_t w, char value);
		void set_cell_status(size_t h, size_t w, int value);
		void multiply_cell_status(size_t h, size_t w, int value);
		void divide_cell_status(size_t h, size_t w, int value);
		char get_cell(size_t h, size_t w);
		int get_cell_status(size_t h, size_t w);
		size_t get_height();
		size_t get_width();
		size_t get_unfilled(char check);
		size_t get_unfilled();
		void change_unfilled(char check, char value);
		void increase_size(size_t h, size_t w);
		void shrink_to_fit(char check);
	friend std::ostream& operator<<(std::ostream& os, Matrix& value)
	{
		for (size_t i = 0; i < value.height; i++)
		{
			for (size_t j = 0; j < value.width; j++)
				os << value.data[i][j];
			os << std::endl;
		}
		for (size_t i = 0; i < value.height; i++)
		{
			for (size_t j = 0; j < value.width; j++)
				std::cout << value.status[i][j] << ' ';
			std::cout << std::endl;
		}
		return os;
	}
};
