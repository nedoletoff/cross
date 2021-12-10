#pragma once

#include <iostream>
#include "matrix.hpp"
#include "words.hpp"
#include "exceptions.hpp"


bool add_word(Words& words, size_t n, Matrix& matrix, size_t h, size_t w);
bool delete_word_g(Words& words, size_t n, Matrix& matrix, size_t h, size_t w);
bool delete_word_v(Words& words, size_t n, Matrix& matrix, size_t h, size_t w);
