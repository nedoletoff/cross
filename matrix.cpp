#include "matrix.hpp"
#include "exceptions.hpp"

Matrix::Matrix(size_t h, size_t w)
{
	height = h; 
	width = w;
	data = new char*[h];
	for (size_t i = 0; i < h; i++)
		data[i] = new char[w];
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < height; i++)
		delete[] data[i];
	delete[] data;
}

Matrix::Matrix(Matrix& a)
{
	height = a.height;
	width = a.width;
	data = new char*[height];
	for (size_t i = 0; i < height; i++)
		data[i] = new char[width];
	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			data[i][j] = a.data[i][j];
}

Matrix& Matrix::operator=(Matrix& a)
{
	if (&a == this)
		return *this;

	for (size_t i = 0; i < height; i++)
		delete[] data[i];
	delete[] data;

	height = a.height;
	width = a.width;
	data = new char*[height];
	for (size_t i = 0; i < height; i++)
		data[i] = new char[width];
	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			data[i][j] = a.data[i][j];
	return *this;
}

void Matrix::set_cell(size_t h, size_t w, char value)
{
	if (h >= height)
        throw Exception("h out of range");
	if (w >= width)
		throw Exception("w out of range");
	data[h][w] = value;
}

char Matrix::get_cell(size_t h, size_t w)
{
	if (h >= height)
        throw Exception("h out of range");
	if (w >= width)
		throw Exception("w out of range");
	return data[h][w];
}

size_t Matrix::get_height()
{
	return height;
}

size_t Matrix::get_width()
{
	return width;
}

size_t Matrix::get_unfilled(char check)
{
	size_t count = 0;
	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			if (data[i][j] == check)
				count++;
	return count;
}

void Matrix::change_unfilled(char check, char value)
{
	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			if (data[i][j] == check)
				data[i][j] = value;
}

/*
size_t Matrix::are_free(size_t h_start, size_t h_finish, size_t w_start, size_t w_finish)
{
    if (h_start >= height)
        throw Exception("h_start out of range");
    if (h_finish >= height)
        throw Exception("h_finish out of range");
    if (w_start >= height)
        throw Exception("w_start out of range");
    if (w_finish >= height)
        throw Exception("w_finish out of range");

    if (h_start < h_finish)
        throw Exception("h_start < h_finish");
    if (w_start < w_finish)
        throw Exception("w_start < w_finish");

    if (h_start == h_finish && w_start != w_finish)
        return are_free_v(w_start, w_finish, h_start);

    if (w_start == w_finish && h_start != h_finish)
        return are_free_g(h_start, h_finish, w_start);

    else
        throw Exception("Wrong arguments");
}

size_t Matrix::are_free_g(size_t h_start, size_t h_finish, size_t w)
{
    if (h_start != 0)

}
*/
