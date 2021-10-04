#pragma once

class Matrix
{
	private:
		size_t height;
		size_t width;
		char** array;
	public:
		Matrix(size_t, size_t);			//height width
		Matrix(Matrix&);
		Matrix& operator=(Matrix&);
		~Matrix();
		void set_null();			//fill the matrix with ' ' 
		void mirror(); 				//height -> width; width -> height; array[l][w] -> array[w][l]
		void print();
		char get_char(size_t, size_t);		//height width
		void set_char(char, size_t, size_t);	//height width
		int get_unfilled_column();
		int get_unfilled_string();
		size_t update_height();			//delete unfilled string
		size_t update_width();			//delete unfilled column
		size_t get_width();
		size_t get_height();
};

