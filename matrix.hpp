#pragma once
#include <iostream>

class Matrix
{
	private:
		size_t height;
		size_t width;
		char** data;
//    private:
//        size_t are_free_g(size_t h_start, size_t h_finish, size_t w);
//        size_t are_free_v(size_t w_start, size_t w_finish, size_t h);
	public:
		Matrix(size_t h, size_t w);
		~Matrix();
		Matrix(Matrix& a);
		Matrix& operator=(Matrix& a);
		void set_cell(size_t h, size_t w, char value);
		char get_cell(size_t h, size_t w);
		size_t get_height();
		size_t get_width();
		size_t get_unfilled(char check);
		void change_unfilled(char check, char value);
//        size_t are_free(size_t h_start, size_t h_finish, size_t w_start, size_t w_finish);
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
