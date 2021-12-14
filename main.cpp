#include "crisscross.hpp"
#include "exceptions.hpp"
#include "matrix.hpp"
#include "words.hpp"

#include <fstream>
#include <iostream>

int main() 
{
	try
	{
		Words words("inputfile.txt");
		Matrix matrix(words.get_words_numbers(), words.get_words_numbers());
		crisscross(words, matrix);
//		matrix.shrink_to_fit('\0');
		std::ofstream file("output.txt");
		std::cout << delete_word_g(words, 1, matrix, 2, 0) << std::endl;
		add_word(words, 1, matrix, 0, 2);
		std::cout << matrix.get_unfilled() << std::endl;
		std::cout << matrix.get_unfilled('\0') << std::endl;
		matrix.change_unfilled('\0', ' ');
		file << matrix;
	}
	catch (Exception e)
	{
		std::cout << e << std::endl;
	}
	
	return 0;
}
