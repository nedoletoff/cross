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
				catch (Exception e)
				{
//					std::cout << e;
				}
				try
				{
					matrix.multiply_cell_status(h + 1, w + i, ::gorizontal);
				}
				catch (Exception e)
				{
//					std::cout << e;
				}

			}
			words.change_word_status(n, true);
			return true;
		}
	}
	check = true;
	if (h + word_size > matrix.get_height())
		return false;
	for (size_t i = 0; i < word_size; i++)
		std::cout << matrix.get_cell(h + i, w);
	std::cout << std::endl;
	for (size_t i = 0; i < word_size && check; i++)

		if (matrix.get_cell_status(h + i, w) % ::vertical == 0 || 
		(matrix.get_cell_status(h + i, w) % ::used == 0 ||
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
			catch (Exception e)
			{
//				std::cout << e;
			}

			try
			{
				matrix.multiply_cell_status(h + i, w + 1, ::vertical);
			}
			catch (Exception e)
			{
//				std::cout << e;
			}

		}
		words.change_word_status(n, true);
		return true;
	}
	return false;
}
	
bool delete_word_g(Words& words, size_t n, Matrix& matrix, size_t h, size_t w)
{
	std::string value = words.get_word(n) + ' ';
	size_t word_size = value.size();
	if (w + word_size + 1 > matrix.get_height())
		throw Exception("w + word_size");

	for (size_t i = 0; i < word_size; i++)
		if (matrix.get_cell(h, w + i) != value[i])
			return false;
	for (size_t i = 0; i < word_size; i++)
	{
		matrix.set_cell(h, w + i, '\0');			
		matrix.divide_cell_status(h, w + i, ::used);
		try 
		{
			matrix.divide_cell_status(h - 1, w + i, ::gorizontal);
		}
		catch (Exception e)
		{
//				std::cout << e;
		}
		try
		{
			matrix.divide_cell_status(h + 1, w + i, ::gorizontal);
		}
		catch (Exception e)
		{
//				std::cout << e;
		}
	}

	words.change_word_status(n, false);
	return true;
}
			       
bool delete_word_v(Words& words, size_t n, Matrix& matrix, size_t h, size_t w)
{
	std::string value = words.get_word(n) + ' ';
	size_t word_size = value.size();
	if (h + word_size + 1 > matrix.get_height())
		throw Exception("h + word_size");
	for (size_t i = 0; i < word_size; i++)
		if (matrix.get_cell(h + i, w) != value[i])
			return false;

	for (size_t i = 0; i < word_size; i++)
	{
		matrix.set_cell(h + i, w, '\0');			
		matrix.divide_cell_status(h + i, w, ::used);
		try 
		{
			matrix.divide_cell_status(h + i, w + 1, ::vertical);
		}
		catch (Exception e)
		{
//				std::cout << e;
		}
		try
		{
			matrix.divide_cell_status(h + i, w - 1, ::vertical);
		}
		catch (Exception e)
		{
//				std::cout << e;
		}
	}

	words.change_word_status(n, false);
	return true;
}

void crisscross(Words& words, Matrix& matrix)
{
	for (size_t i = 0; i < matrix.get_height(); i++)
		for (size_t j = 0; j < matrix.get_width(); j++)
			for (size_t n = 0; n < words.get_words_numbers(); n++)
//				std::cout << add_word(words, n, matrix, i, j)<< std::endl;
				add_word(words, n, matrix, i, j);
}
