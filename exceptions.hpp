#pragma once

#include <string>
#include <iostream>

class Exception
{
    private:
        std::string val;
    public:
        Exception(const std::string value);
    friend std::ostream& operator<<(std::ostream& os, Exception& obj)
    {
        os << obj.val;
        return os;
    }
};
