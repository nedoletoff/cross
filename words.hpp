#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Pair
{
	std::string word;
	bool status;

	friend std::ostream& operator<<(std::ostream& os, Pair& value)
	{
		os << value.word << " - " << value.status;
		return os;
	}
};

class Words
{
	private:
		std::vector<Pair> words_and_status;
		size_t numbers;
		size_t used_numbers;
	public:
		Words(std::string filename);
		std::string get_word(size_t n);
		bool get_word_status(size_t n);
		void change_word_status(size_t n, bool value);
		void add_word(std::string value);
		size_t get_words_numbers();
		size_t get_words_used_numbers();
        bool are_all_words_used();
	friend std::ostream& operator<<(std::ostream& os, Words& value)
	{
		for (auto e : value.words_and_status)
			os << e << std::endl;
		return os;
	}
};
