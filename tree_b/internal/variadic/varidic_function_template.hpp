#pragma once

// unlike c-style variadic functions, variadic function template have a template
// parameter pack that can be unpacked or forwarded

// https://en.cppreference.com/w/cpp/language/parameter_pack.html

// perfect forwarding using rvalue reference (&&)
// https://en.cppreference.com/w/cpp/language/reference.html#Forwarding_references

template<class... Ts>
void g(Ts... args)
{
    f(&args...); // “&args...” is a pack expansion
                 // “&args” is its pattern
}