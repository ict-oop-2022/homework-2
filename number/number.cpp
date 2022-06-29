#include "number.h"

#include <string>

number_t::number_t(): inner(0)
{
}

number_t::number_t(const number_t& other)
        : inner(other.inner)
{
}

number_t::number_t(int64_t num)
        : inner(num)
{
}

number_t::number_t(int num)
        : inner(num)
{
}

number_t::operator bool()
{
    return (bool)inner;
}

number_t::operator int64_t()
{
    return inner;
}

number_t::operator int()
{
    return (int)inner;
}

number_t::operator std::string()
{
    return std::to_string(inner);
}


number_t operator+(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner + rhs.inner;
}
number_t operator-(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner - rhs.inner;
}
number_t operator*(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner * rhs.inner;
}
number_t operator/(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner / rhs.inner;
}
number_t operator%(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner % rhs.inner;
}

number_t operator&(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner & rhs.inner;
}
number_t operator^(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner ^ rhs.inner;
}
number_t operator|(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner | rhs.inner;
}
number_t operator<<(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner << rhs.inner;
}
number_t operator>>(const number_t &lhs, const number_t& rhs)
{
    return lhs.inner >> rhs.inner;
}

number_t& number_t::operator+=(const number_t &other)
{
    inner += other.inner;
    return *this;
}
number_t& number_t::operator-=(const number_t &other)
{
    inner -= other.inner;
    return *this;
}
number_t& number_t::operator*=(const number_t &other)
{
    inner *= other.inner;
    return *this;
}
number_t& number_t::operator/=(const number_t &other)
{
    inner /= other.inner;
    return *this;
}
number_t& number_t::operator%=(const number_t &other)
{
    inner %= other.inner;
    return *this;
}

number_t& number_t::operator&=(const number_t &other)
{
    inner &= other.inner;
    return *this;
}
number_t& number_t::operator^=(const number_t &other)
{
    inner ^= other.inner;
    return *this;
}
number_t& number_t::operator|=(const number_t &other)
{
    inner |= other.inner;
    return *this;
}
number_t& number_t::operator<<=(const number_t &other)
{
    inner <<= other.inner;
    return *this;
}
number_t& number_t::operator>>=(const number_t &other)
{
    inner >>= other.inner;
    return *this;
}

number_t number_t::operator-() const
{
    return -inner;
}
number_t number_t::operator+() const
{
    return +inner;
}
number_t number_t::operator~() const
{
    return ~inner;
}
number_t number_t::operator!() const
{
    return !inner;
}

number_t& number_t::operator++()
{
    ++inner;
    return *this;
}
number_t number_t::operator++(int)
{
    number_t old = *this;
    ++inner;
    return old;
}
number_t& number_t::operator--()
{
    --inner;
    return *this;
}
number_t number_t::operator--(int)
{
    number_t old = *this;
    --inner;
    return old;
}

bool operator==(const number_t &lhs, const number_t &rhs)
{
    return lhs.inner == rhs.inner;
}
bool operator!=(const number_t &lhs, const number_t &rhs)
{
    return lhs.inner != rhs.inner;
}
bool operator<(const number_t &lhs, const number_t &rhs)
{
    return lhs.inner < rhs.inner;
}
bool operator>(const number_t &lhs, const number_t &rhs)
{
    return lhs.inner > rhs.inner;
}
bool operator<=(const number_t &lhs, const number_t &rhs)
{
    return lhs.inner <= rhs.inner;
}
bool operator>=(const number_t &lhs, const number_t &rhs)
{
    return lhs.inner >= rhs.inner;
}

std::istream& operator>>(std::istream& in, number_t& num)
{
    return in >> num.inner;
}
std::ostream& operator<<(std::ostream& out, const number_t& num)
{
    return out << num.inner;
}