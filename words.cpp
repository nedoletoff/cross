#include "words.hpp"
#include "exceptions.hpp"
#include <list>

Words::Words(std::string filename)
{
	std::list<std::string> words;
	numbers = 0;
	used_numbers = 0;
	std::ifstream file(filename);
	if (!file)
		throw Exception("file not found");

	std::string temp;
	file >> temp;
	words.push_back(temp);
	auto it = words.begin();
	for (file >> temp; !file.eof(); file >> temp)
    {
		for (it = words.begin(); it  !=  words.end() || temp.size() < it->size(); it++)
			if (temp == *it)
			{
				words.erase(it);
				break;
			}
		words.insert(it, temp);
    }

	for (auto e : words)	
	{
		words_and_status.push_back({e, false});
		numbers++;
	}

}

std::string Words::get_word(size_t n)
{
	if (n >= numbers)
		throw Exception("n out of range");

	return words_and_status[n].word;
}

bool Words::get_word_status(size_t n)
{
	if (n >= numbers)
		throw Exception("n out of range");

	return words_and_status[n].status;
}

void Words::change_word_status(size_t n, bool value)
{
	if (n >= numbers)
		throw Exception("n out of range");

	if (words_and_status[n].status != value)
	{
		if (value)
			used_numbers++;
		else
			used_numbers--;
	}
	words_and_status[n].status = value;
}

void Words::add_word(std::string value)
{
	words_and_status.push_back({value, false});
	numbers++;
}
size_t Words::get_words_numbers()
{
	return numbers;
}

size_t Words::get_words_used_numbers()
{
	return used_numbers;
}
