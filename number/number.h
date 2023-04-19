#pragma once

#include <cstdint>
#include <iostream>
#include <string>

class number_t {
public:
number_t() : val(0) {} // Default constructor
~number_t() {} // Destructor
number_t(const int64_t num) : val(num) {} // Constructor from a number
number_t(const number_t &num) : val(num.val) {} // Copy constructor

explicit operator bool() const { return val != 0; }
operator int64_t() const { return val; } // Cast to number
operator std::string() const { return std::to_string(val); } // Cast to string

number_t& operator=(const number_t &rhs) { val = rhs.val; return *this; } // Assignment operator
number_t& operator+=(const number_t &rhs) { val += rhs.val; return *this; } // Addition assignment operator
number_t& operator-=(const number_t &rhs) { val -= rhs.val; return *this; } // Subtraction assignment operator
number_t& operator*=(const number_t &rhs) { val *= rhs.val; return *this; } // Multiplication assignment operator
number_t& operator/=(const number_t &rhs) { val /= rhs.val; return *this; } // Division assignment operator
number_t& operator%=(const number_t &rhs) { val %= rhs.val; return *this; } // Modulo assignment operator
number_t& operator^=(const number_t &rhs) { val ^= rhs.val; return *this; } // Bitwise XOR assignment operator
number_t& operator&=(const number_t &rhs) { val &= rhs.val; return *this; } // Bitwise AND assignment operator
number_t& operator|=(const number_t &rhs) { val |= rhs.val; return *this; } // Bitwise OR assignment operator
number_t& operator<<=(const number_t &rhs) { val <<= rhs.val; return *this; } // Left shift assignment operator
number_t& operator>>=(const number_t &rhs) { val >>= rhs.val; return *this; } // Right shift assignment operator

number_t& operator++() { ++val; return *this; } // Prefix increment operator
number_t& operator--() { --val; return *this; } // Prefix decrement operator
number_t operator++(int) { number_t temp(*this); ++val; return temp; } // Postfix increment operator
number_t operator--(int) { number_t temp(*this); --val; return temp; } // Postfix decrement operator

friend std::ostream &operator<<(std::ostream &out, const number_t &num) { out << num.val; return out; } // Output operator
friend std::istream &operator>>(std::istream &in, number_t &num) { in >> num.val; return in; } // Input operator

private:
int64_t val; // Numerical value
};