#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include "exceptions.hpp"

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

struct Coordinates
{
	int orientation;
	size_t h;
	size_t w;

	friend std::ostream& operator<<(std::ostream& os, Coordinates& value)
	{
		os << "orientation - ";
		if (value.orientation > 0)
			os << "vertical\t";
		else if (value.orientation < 0)
			os << "gorizontal\t";
		else 
			os << "not\t";
		os << value.h << " - " << value.w;
		return os;
	}
	friend std::ostream& operator<<(std::ostream& os, Coordinates value)
	{
		os << "orientation - ";
		if (value.orientation > 0)
			os << "vertical\t";
		else if (value.orientation < 0)
			os << "gorizontal\t";
		else 
			os << "not\t";
		os << value.h << " - " << value.w;
		return os;
	}
};

class Words
{
	private:
		std::vector<Pair> words_and_status; 	//заменить использование статуса на использование ориентации
		std::vector<Coordinates> coordinates;
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
		Coordinates get_coordinates(size_t n);
		void set_coordinates(size_t n, int o, size_t h, size_t w);
		void set_coordinates(size_t n, int o);
    bool are_all_words_used();
	friend std::ostream& operator<<(std::ostream& os, Words& value)
	{
		for (auto& e : value.words_and_status)
			os << e << std::endl;
		return os;
	}
};
