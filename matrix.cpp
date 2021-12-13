#include "matrix.hpp"

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

void Matrix::increase_size(size_t h, size_t w)
{
	if (h <= height)
		throw Exception("h <= height");
	if (w <= width)
		throw Exception("w <= width");

	Matrix temp(*this);
	for (size_t i = 0; i < height; i++)
		delete[] data[i];
	delete[] data;

	data = new char*[h];
	for (size_t i = 0; i < h; i++)
		data[i] = new char[w];

	for (size_t i = 0; i < h; i++)
		for (size_t j = 0; j < w; j++)
			data[i][j] = '\0';

	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			data[i][j] = temp.data[i][j];
	height = h; width = w;

}

void Matrix::shrink_to_fit(char check)
{
	size_t h = height;
	size_t w = width;
	bool temp;

	for (size_t i =	0; i <	height; i++)
	{
		temp  = true;
		for (size_t j = 0; j < width; j++)
			if (data[i][j] != check)
			{
				temp = false;
				break;
			}
		if (temp)
		{
			h = i;
			break;
		}
	}
	for (size_t i =	0; i <	width; i++)
	{
		temp = true;
		for (size_t j = 0; j < height; j++)
			if (data[j][i] != check)
			{
				temp = false;
				break;
			}
		if (temp)
		{
			w = i;
			break;
		}
	}

	Matrix a(*this);
		for (size_t i = 0; i < height; i++)
		delete[] data[i];
	delete[] data;

	height = h; width = w;
	data = new char*[height];
	for (size_t i = 0; i < height; i++)
		data[i] = new char[width];
	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			data[i][j] = a.data[i][j];
}
