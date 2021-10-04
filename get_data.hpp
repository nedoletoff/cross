#pragma once

class Words
{
	private:
		std::string* words;
		size_t words_count;
	public:
		Words(char**);
		~Words();
		void get_word(size_t, std::string*);	
		size_t get_size();
		size_t delete_repeating_words();
		void get_words(std::string**);
};


