#pragma once

#include <iostream>
#include "matrix.hpp"
#include "words.hpp"
#include "exceptions.hpp"

struct Coordinates
{
  size_t h_begin;
  size_t h_end;
  size_t w_begin;
  size_t w_end;

  friend &ostream operator>>(ostream& os, Coordinates& value)
  {
    os << "begin: " << h_begin << "   " << w_begin << std::endl;
    os << "end: " << h_end << "   " << w_end;
    return os;
  }

};

bool check_space(Coordinates& space, Matrix& matrix);
