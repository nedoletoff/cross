#include "words.hpp"
#include <fsream>
#include <string>
#include <cstring>

Words::Words(char** file_name)
{
//	setlocale(LC_ALL, "rus");
	ifstream file (file_name);

	if (!file.is_open())
	{
		std::cout << "file did not open" << std::endl;
		throw 1;
	}
//	std::string size_s;
//	file >> size_s;
//	words_count = stoi(size_s);
	file >> words_count;
	words = new std::string[words_count];
	for (size_t i = 0; i < words_count; ++i)
		file >> std::string[i];
	file.close();
}

Words::~Words()
{
	delete words;
}

void Words::get_word(size_t num, std::string* rv)
{
	*rv = std::string[num];
}

size_t Words::get_size();
{
	return words_count;
}

size_t Words::delete_repeating_words()
{
	size_t count = 0;
	for (size_t i = 0; i < words_count-1; ++i)
		for (size_t j = i+1; j < words_count; ++j)
			if (std::strcmp(words[i], words[j]))
			{
				++count;
				std::swap(words[j],words[--words_count]);
			}
	if (count)
	{
		std::string* temp = words;
		delete words;
		words = new std::string[words_count];
		for (size_t i = 0; i < words_count; ++i)
			words[i] = temp[i];
	}
	return count;
}

void get_words(std::string** rv)
{
	*rv = new std::string[words_count];
	for (size_t i = 0; i < words_count; ++i)
		*rv[i] = words[i];
}

