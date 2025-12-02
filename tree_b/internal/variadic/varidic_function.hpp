#pragma once

// c-style variadic functions use va_list/va_start/va_arg/va_end and iterate
// throught the variables in a loop

// https://en.cppreference.com/w/cpp/utility/variadic.html

#include <cstdarg>
#include <iostream>
 
void simple_printf(const char* fmt...) // C-style "const char* fmt, ..." is also valid
{
    va_list args;
    va_start(args, fmt);
 
    while (*fmt != '\0')
    {
        if (*fmt == 'd')
        {
            int i = va_arg(args, int);
            std::cout << i << '\n';
        }
        else if (*fmt == 'c')
        {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            std::cout << static_cast<char>(c) << '\n';
        }
        else if (*fmt == 'f')
        {
            double d = va_arg(args, double);
            std::cout << d << '\n';
        }
        ++fmt;
    }
 
    va_end(args);
}