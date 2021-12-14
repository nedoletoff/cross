#pragma once

#include <iostream>
#include <list>
#include "matrix.hpp"
#include "words.hpp"
#include "exceptions.hpp"

extern const int not_used;
extern const int gorizontal;
extern const int vertical;
extern const int used;


bool add_word(Words& words, size_t n, Matrix& matrix);
bool delete_word(Words& words, size_t n, Matrix& matrix);
void crisscross(Words& words, Matrix& matrix);

