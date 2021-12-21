#include "crisscross.hpp"
#include <iostream>

///Функция вставки слов по координатам горизонтально
bool add_word_g(Words& words, size_t n, Matrix& matrix, size_t h, size_t w)	
{
	std::string value = words.get_word(n);
	size_t word_size = value.size();
	bool check = true;

	if (!(w + word_size < matrix.get_width()))
		return false;

	if (matrix.legal(h, w - 1) &&  
	matrix.get_cell_status(h, w - 1) % used == 0)
			check = false;

	if (matrix.legal(h, w + word_size) && 
	matrix.get_cell_status(h, w + word_size) % ::used == 0)
			check = false;

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
			if (matrix.legal(h - 1, w + i))
				matrix.multiply_cell_status(h - 1, w + i, ::gorizontal);
			if (matrix.legal(h + 1, w + i))
				matrix.multiply_cell_status(h + 1, w + i, ::gorizontal);
		}
		if (matrix.legal(h, w + word_size))
			matrix.multiply_cell_status(h, w + word_size, ::used);
		words.change_word_status(n, true);
		words.set_coordinates(n, -1, h, w);
		return true;
	}
	return false;
}

///Функция вставки слов по координатам вертикально
bool add_word_v(Words& words, size_t n, Matrix& matrix, size_t h, size_t w)	
{
	std::string value = words.get_word(n);
	size_t word_size = value.size();
	bool check = true;

	if (!(h + word_size < matrix.get_height()))
		return false;

	if (matrix.legal(h - 1, w) && 
	matrix.get_cell_status(h - 1, w) % used == 0)
		check = false;

	if (matrix.legal(h + word_size + 1, w) && 
	matrix.get_cell_status(h + word_size, w) % used == 0)
		check = false;

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
			if (matrix.legal(h + i, w - 1))
				matrix.multiply_cell_status(h + i, w - 1, ::vertical);
			if (matrix.legal(h + i, w + 1))
				matrix.multiply_cell_status(h + i, w + 1, ::vertical);
		}
		if (matrix.legal(h + word_size, w))
			matrix.multiply_cell_status(h + word_size, w, ::used);
		words.change_word_status(n, true);
		words.set_coordinates(n, 1, h, w);
		return true;
	}
	return false;
}

///Функция вставки слов по координатам
bool add_word(Words& words, size_t n, Matrix& matrix, size_t h, size_t w)	
{
	if (add_word_g(words, n, matrix, h, w))
			return true;
	return add_word_v(words, n, matrix, h, w);
}

///Функция удаления горизонтальных слов
void delete_word_g(std::string value, Matrix& matrix, size_t h, size_t w)	
{
	size_t word_size = value.size();
	if (w + word_size > matrix.get_width())
		throw Exception("w + word_size");

	for (size_t i = 0; i < word_size; i++)
		if (matrix.get_cell(h, w + i) && matrix.get_cell(h, w + i) != value[i])
			throw Exception("words is not in place" );
	for (size_t i = 0; i < word_size; i++)
	{
		if (matrix.get_cell_status(h, w + i) / (::used*::used) == 0)
			matrix.set_cell(h, w + i, '\0');
		matrix.divide_cell_status(h, w + i, ::used);

		if (matrix.legal(h - 1, w + i))
			matrix.divide_cell_status(h - 1, w + i, ::gorizontal);

		if (matrix.legal(h + 1, w + i))
			matrix.divide_cell_status(h + 1, w + i, ::gorizontal);
	}
	if (matrix.legal(h, w + word_size))
		matrix.divide_cell_status(h, w + word_size, ::used);
}

///Функция удаления вертикальных слов
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
		if (matrix.get_cell_status(h + i, w) / (::used*::used) == 0)
			matrix.set_cell(h + i, w, '\0');
		matrix.divide_cell_status(h + i, w, ::used);

		if (matrix.legal(h + i, w + 1))
			matrix.divide_cell_status(h + i, w + 1, ::vertical);

		if (matrix.legal(h + i, w - 1))
			matrix.divide_cell_status(h + i, w - 1, ::vertical);
	}
	if (matrix.legal(h + word_size, w))
		matrix.divide_cell_status(h + word_size, w, ::used);
}

///Фунцкия удаления слов независящая от ориентации
bool delete_word(Words& words, size_t n, Matrix& matrix)	
{
	if (!words.get_word_status(n))
		return false;

	std::string value = words.get_word(n);
	Coordinates c = words.get_coordinates(n);
	if (c.orientation > 0)
		delete_word_v(value, matrix, c.h, c.w);
	if (c.orientation < 0)
		delete_word_g(value, matrix, c.h, c.w);

	words.change_word_status(n, false);
	words.set_coordinates(n, 0);
	return true;
}

///Функция вставки слов в подходящее место матрицы
bool add_word(Words& words, size_t n, Matrix& matrix)	
{
	double m_coef = matrix.get_coef();
	bool check = false;
	size_t h, w;

	if (words.get_word_status(n))
		return false;

	for (size_t i = 0; i < matrix.get_height(); i++)
		for (size_t j = 0; j < matrix.get_width(); j++)
			if (add_word(words, n, matrix, i, j))
			{
				if (m_coef < matrix.get_coef())
				{
//					std::cout << delete_word(words, n, matrix) << add_word(words, n, matrix, i, j) << "work?" <<std::endl;
					check = true;
					h = i; w = j;
					m_coef = matrix.get_coef();
				}
				delete_word(words, n, matrix);
			}
	if (check)
		return (add_word(words, n, matrix, h, w));
	return false;
}

///Рекурсивный алгоритм вставки слов
void cross(Words& words, Matrix& matrix, Matrix& res, std::list<size_t>& l)	
{
	for (size_t k = 0; k < words.get_words_numbers(); k++)
		if (add_word(words, k, matrix))
		{
//           		 if (l.size() > words.get_words_numbers())
//                		throw Exception("what");
			if (matrix.get_coef() > res.get_coef())
			{
//				std::cout << res.get_coef() << " - " << matrix.get_coef() << std::endl;
				res = matrix;
			}
			l.push_back(k);
			cross(words, matrix, res, l);
		}
//	std::cout << matrix.get_coef() << " get_coef\n";

	delete_word(words, l.back(), matrix);
	if (l.size())
		l.pop_back();
}

///Функция обертка алгоритма составления крисскросса
void crisscross(Words& words, Matrix& matrix)	
{
	Matrix res(matrix);
	std::list<size_t> l;
	cross(words, matrix, res, l);
	matrix = res;
	std::cout << matrix.get_unfilled() << std::endl;
	matrix.shrink_to_fit('\0');
	matrix.change_unfilled('\0', ' ');
	std::cout << "List of not used words:";
	for (size_t i = 0; i < words.get_words_numbers(); i++)
		if (!words.get_word_status(i))
			std::cout << words.get_word(i) << " ";
	std::cout << std::endl;
}


