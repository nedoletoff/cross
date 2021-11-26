#include "crisscross.hpp"

void cross(Matrix& matrix, Words& words)
{
    Matrix a(matrix), b(matrix), c(matrix);
    while (words.are_all_words_used())
    {
        for (size_t i = 0; i < words.get_words_numbers(); i++)
        {
            if (!words.get_word_status(i))
                words.change_word_status(i, add_word(a, words.get_word(i)));
        }
    }
}

bool add_word(Matrix& matrix, const std::string& word)
{
    if (matrix.get_unfilled('\0') == matrix.get_height() * matrix.get_width())
    {
        for (size_t i = 0; i <= word.size(); i++)
            matrix.set_cell(i, 0, word[i]);
        matrix.set_cell(word.size() + 1, 0, ' ');
        return true;
    }
        for (size_t hi = 0; hi < matrix.get_height(); hi++)
            for (size_t wi = 0; wi < matrix.get_width(); wi++)
                for (char letter : word)
                {
                    if ()
    return false;
}
