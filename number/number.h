#pragma once

#include <cstdint>
#include <iostream>

class number_t {
public:
    number_t();
    number_t(const number_t&);
    number_t(int64_t);
    number_t(int);

    explicit operator bool();
    explicit operator int64_t();
    explicit operator int();
    explicit operator std::string();

    friend number_t operator+(const number_t &lhs, const number_t& rhs);
    friend number_t operator-(const number_t &lhs, const number_t& rhs);
    friend number_t operator*(const number_t &lhs, const number_t& rhs);
    friend number_t operator/(const number_t &lhs, const number_t& rhs);
    friend number_t operator%(const number_t &lhs, const number_t& rhs);

    friend number_t operator&(const number_t &lhs, const number_t& rhs);
    friend number_t operator^(const number_t &lhs, const number_t& rhs);
    friend number_t operator|(const number_t &lhs, const number_t& rhs);

    friend number_t operator<<(const number_t &lhs, const number_t& rhs);
    friend number_t operator>>(const number_t &lhs, const number_t& rhs);

    number_t& operator+=(const number_t &other);
    number_t& operator-=(const number_t &other);
    number_t& operator*=(const number_t &other);
    number_t& operator/=(const number_t &other);
    number_t& operator%=(const number_t &other);

    number_t& operator&=(const number_t &other);
    number_t& operator^=(const number_t &other);
    number_t& operator|=(const number_t &other);

    number_t& operator<<=(const number_t &other);
    number_t& operator>>=(const number_t &other);

    number_t operator-() const;
    number_t operator+() const;
    number_t operator~() const;
    number_t operator!() const;

    number_t& operator++();
    number_t operator++(int);
    number_t& operator--();
    number_t operator--(int);

    friend bool operator==(const number_t &lhs, const number_t &rhs);
    friend bool operator!=(const number_t &lhs, const number_t &rhs);
    friend bool operator<(const number_t &lhs, const number_t &rhs);
    friend bool operator>(const number_t &lhs, const number_t &rhs);
    friend bool operator<=(const number_t &lhs, const number_t &rhs);
    friend bool operator>=(const number_t &lhs, const number_t &rhs);

    friend std::istream& operator>>(std::istream&, number_t&);
    friend std::ostream& operator<<(std::ostream&, const number_t&);
private:
    int64_t inner;
};