#pragma once

#include "matrix.hpp"
#include "words.hpp"
#include "exceptions.hpp"

void cross(Matrix& matrix, Words& words);
bool add_word(Matrix& matrix, const std::string& word);
