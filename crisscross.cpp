#include "crisscross.hpp"

bool add_word(Words& words, size_t n, Matrix& matrix, size_t h, size_t w)
{
	size_t word_size = words.get_word(n).size();
	std::string value = words.get_word(n);
	bool check = true;
	if (w + word_size > matrix.get_width())
		throw Exception("w + word_size");
	for (size_t i = 0; i < word_size; i++)
		if (!(matrix.get_cell(h, w + i) == '\0' ||
			       	matrix.get_cell(h, w + i) == value[i]))
		{
			check = false;
			break;
		}
	if (check)
	{
		for (size_t i = 0; i < word_size; i++)
			matrix.set_cell(h, w + i, value[i]);
		words.change_word_status(n, true);
		return true;
	}
	check = true;
	if (h + word_size > matrix.get_height())
		throw Exception("h + word_size");
	for (size_t i = 0; i < word_size; i++)
		if (!(matrix.get_cell(h + i, w) == '\0' ||
			       	matrix.get_cell(h + i, w) == value[i]))
		{
			check = false;
			break;
		}
	if (check)
	{
		for (size_t i = 0; i < word_size; i++)
			matrix.set_cell(h + i, w, value[i]);
		words.change_word_status(n, true);
		return true;
	}
	return false;
}
	
bool delete_word_g(Words& words, size_t n, Matrix& matrix, size_t h, size_t w)
{
	size_t word_size = words.get_word(n).size();
	std::string value = words.get_word(n);
	if (w + word_size > matrix.get_width())
		throw Exception("w + word_size");
	for (size_t i = 0; i < word_size; i++)
		if (matrix.get_cell(h, w + i) != value[i])
			return false;
	for (size_t i = 0; i < word_size; i++)
		if (matrix.get_cell(h - 1, w + i) != '\0' ||
			       matrix.get_cell(h + 1, w + i) != '\0')
			matrix.set_cell(h, w + i, value[i]);
	words.change_word_status(n, false);
	return true;
}
			       
bool delete_word_v(Words& words, size_t n, Matrix& matrix, size_t h, size_t w)
{
	size_t word_size = words.get_word(n).size();
	std::string value = words.get_word(n);
	if (h + word_size > matrix.get_height())
		throw Exception("h + word_size");
	for (size_t i = 0; i < word_size; i++)
		if (matrix.get_cell(h + i, w) != value[i])
			return false;
	for (size_t i = 0; i < word_size; i++)
		if (matrix.get_cell(h + i, w - 1) != '\0' ||
			       matrix.get_cell(h + i, w + 1) != '\0')
			matrix.set_cell(h + i, w, value[i]);
	words.change_word_status(n, false);
	return true;
}


