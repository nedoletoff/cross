#include "crisscross.hpp"
#include <iostream>


bool add_word(Words& words, size_t n, Matrix& matrix, size_t h, size_t w)
{
	if (words.get_word_status(n))
		return false;
	std::string value = words.get_word(n) + ' ';
	size_t word_size = value.size();
	bool check = true;
	if (w + word_size <= matrix.get_width())
	{
		try 
		{
		if (matrix.get_cell_status(h, w - 1) % used == 0)
			check = false;
		}
		catch (Exception e) {}
		try 
		{
			if (matrix.get_cell_status(h, w + word_size + 1) % used == 0)
				check = false;
		}
		catch (Exception e) {}
			


		for (size_t i = 0; i < word_size && check; i++)

			if (matrix.get_cell_status(h, w + i) %
			::gorizontal == 0 || (matrix.get_cell_status(h, w + i) %
			::used == 0 && matrix.get_cell(h, w + i) != value[i]))

				check = false;
		if (check)
		{
			for (size_t i = 0; i < word_size; i++)
			{
				matrix.set_cell(h, w + i, value[i]);
				matrix.multiply_cell_status(h, w + i, ::used);
				try
				{
					matrix.multiply_cell_status(h - 1, w + i, ::gorizontal);
				}
				catch (Exception e) {}
				try
				{
					matrix.multiply_cell_status(h + 1, w + i, ::gorizontal);
				}
				catch (Exception e) {}

			}

			words.change_word_status(n, true);
			words.set_coordinates(n, -1, h, w);
			return true;
		}
	}
	check = true;
	if (h + word_size > matrix.get_height())
		return false;
	try 
	{
		if (matrix.get_cell_status(h - 1, w) % used == 0)
			check = false;
	}
	catch (Exception e) {}
	try 
	{
		if (matrix.get_cell_status(h + word_size + 1, w) % used == 0)
			check = false;
	}
	catch (Exception e) {}

	for (size_t i = 0; i < word_size && check; i++)

		if (matrix.get_cell_status(h + i, w) % ::vertical == 0 ||
		(matrix.get_cell_status(h + i, w) % ::used == 0 &&
		matrix.get_cell(h + i, w) != value[i]))

			check = false;
	if (check)
	{
		for (size_t i = 0; i < word_size; i++)
		{
			matrix.set_cell(h + i, w, value[i]);
			matrix.multiply_cell_status(h + i, w, ::used);
			try
			{
				matrix.multiply_cell_status(h + i, w - 1, ::vertical);
			}
			catch (Exception e) {}
			try
			{
				matrix.multiply_cell_status(h + i, w + 1, ::vertical);
			}
			catch (Exception e) {}


		}
		words.change_word_status(n, true);
		words.set_coordinates(n, 1, h, w);
		return true;
	}
	return false;
}

void delete_word_g(std::string value, Matrix& matrix, size_t h, size_t w)
{
	size_t word_size = value.size();
	if (w + word_size> matrix.get_height())
		throw Exception("w + word_size");

	for (size_t i = 0; i < word_size; i++)
		if (matrix.get_cell(h, w + i) && matrix.get_cell(h, w + i) != value[i])
			throw Exception("words is not in place" );
	for (size_t i = 0; i < word_size; i++)
	{
		matrix.set_cell(h, w + i, '\0');
		matrix.divide_cell_status(h, w + i, ::used);
		try
		{
			matrix.divide_cell_status(h - 1, w + i, ::gorizontal);
		}
		catch (Exception e) {}
		try
		{
			matrix.divide_cell_status(h + 1, w + i, ::gorizontal);
		}
		catch (Exception e) {}
	}
}

void delete_word_v(std::string value, Matrix& matrix, size_t h, size_t w)
{
	size_t word_size = value.size();
	if (h + word_size > matrix.get_height())
		throw Exception("h + word_size");
	for (size_t i = 0; i < word_size; i++)
		if (matrix.get_cell(h + i, w) && matrix.get_cell(h + i, w)!= value[i])
			throw Exception("words is not in place");

	for (size_t i = 0; i < word_size; i++)
	{
		matrix.set_cell(h + i, w, '\0');
		matrix.divide_cell_status(h + i, w, ::used);
		try
		{
			matrix.divide_cell_status(h + i, w + 1, ::vertical);
		}
		catch (Exception e) {}
		try
		{
			matrix.divide_cell_status(h + i, w - 1, ::vertical);
		}
		catch (Exception e) {}
	}
}

bool delete_word(Words& words, size_t n, Matrix& matrix)
{
	if (!words.get_word_status(n))
		return false;
	std::string value = words.get_word(n) + ' ';
	Coordinates c = words.get_coordinates(n);
	if (c.orientation > 0)
		delete_word_v(value, matrix, c.h, c.w);
	if (c.orientation < 0)
		delete_word_g(value, matrix, c.h, c.w);

	words.change_word_status(n, false);
	words.set_coordinates(n, 0);
	return true;
}

bool add_word(Words& words, size_t n, Matrix& matrix)
{
	double start_coef = matrix.get_coef();
	for (size_t i = 0; i < matrix.get_height(); i++)
		for (size_t j = 0; j < matrix.get_width(); j++)
		{
			if (add_word(words, n, matrix, i, j) && start_coef <
			matrix.get_coef())
			{
				std::cout << start_coef << " < " << matrix.get_coef() << std::endl;

				return true;
			}
			else
				delete_word(words, n, matrix);
		}
	return false;
}

void cross(Words& words, Matrix& matrix, Matrix& res, std::list<size_t>& l)
{
	for (size_t k = 0; k < words.get_words_numbers(); k++)
		if (add_word(words, k, matrix))
		{
			if (res.get_coef() <= matrix.get_coef())
				res = matrix;
			l.push_back(k);
            if (l.size() > words.get_words_numbers())
                throw Exception("what");
			cross(words, matrix, res, l);
			delete_word(words, l.back(), matrix);
			l.pop_back();
		}
//	for (auto& e : l)
//		std::cout << e << '\t';
//	std::cout << std::endl;
}

void crisscross(Words& words, Matrix& matrix)
{
	Matrix res(matrix);
	std::list<size_t> l;
	cross(words, matrix, res, l);
	matrix = res;

}


