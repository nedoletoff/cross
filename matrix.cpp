#include "matrix.hpp"
#include <iosream>

Matrix::Matrix(size_t h, size_t w)
{
	if (h < 0)
		throw 3;
	if (w < 0) 
		throw 4;

	width = w;
	height = h;
	array = new char*[height];
	for (size_t i = 0; i < height; ++i)
		array[i] = new char[width];
	set_null();
}

Matrix::Matrix(Matrix& a);
{
	height = a.height;
	width = a.width;
	array = new char*[height];
	for (size_t i = 0; i < height; ++i)
		array[i] = new char[width];
	for (size_t h = 0; h < height; ++h)
		for (size_t w = 0; w < width; ++w)
			array[h][w] = a.array[h][w];
}

Matrix& Matrix::operator=(Matrix& a)
{
	if (&a == this)
		return *this;

	height = a.height;
	width = a.width;
	array = new char*[height];
	for (size_t i = 0; i < height; ++i)
		array[i] = new char[width];
	for (size_t h = 0; h < height; ++h)
		for (size_t w = 0; w < width; ++w)
			array[h][w] = a.array[h][w];
	return *this;
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < height; ++i)
		delete array[i];
	delete array;
}

Matrix::set_null()
{
	for (size_t h = 0; h < height; ++h)
		for (size_t w = 0; w < width; ++w)
			array[h][w] = ' ';
}

void Matrix::miror()
{
	Matrix a = this;

	for (size_t i = 0; i < height; ++i)
		delete array[i];
	delete array;

	height = a.width;
	width = a.height;
	for (size_t h = 0; h < height; ++h)
		for (size_t w = 0; w < weight; ++w)
			array[h][w] = a.array[w][h];
}

void Matrix::print()
{
	for (size_t h = 0; h < height; ++h)
	{
		for (size_t  w = 0; w < width; ++w)
			std::cout << array[h][w] << "  ";
		std::cout << std::endl;
	}
}

char Matrix::get_char(size_t h, size_t w)
{
	if (h >= height)
		throw 1;
	if (w >= Width)
		throw 2;
	if (h < 0)
		throw 3;
	if (w < 0) 
		throw 4;

	std::cout << int(array[h][w]) << std::endl;
	return array[h][w];
}

void Matrix::set_char(char value, size_t h, size_t w)
{
	if (h >= height)
		throw 1;
	if (w >= Width)
		throw 2;
	if (h < 0)
		throw 3;
	if (w < 0) 
		throw 4;

	array[h][w] = value;
	std::cout << array[h][w] << std::endl;
}

size_t Matrix::get_unfilled()
{
	size_t count = 0;
	for (size_t h = 0; h < height; ++h)
                for (size_t w = 0; w < weight; ++w
				if (array[h][w] == ' ')
					++count;
	return count;
}
	

size_t Matrix::get_width()
{
	return width;
}

size_t Matrix::get_height()
{
	return height;
}




