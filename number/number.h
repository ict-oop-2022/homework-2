#pragma once

#include <cstdint>
#include <iostream>
#include <string>

class number_t {
  int64_t _data{0};
public:
  number_t();
  number_t(const number_t& other);
  number_t(int64_t value);

  number_t& operator=(const number_t& other);

  explicit operator bool() const;
  explicit operator int64_t() const;
  explicit operator std::string() const;

  friend number_t operator+(const number_t& first, const number_t& second);
  friend number_t operator-(const number_t& first, const number_t& second);
  friend number_t operator/(const number_t& first, const number_t& second);
  friend number_t operator*(const number_t& first, const number_t& second);
  friend number_t operator%(const number_t& first, const number_t& second);

  friend number_t operator|(const number_t& first, const number_t& second);
  friend number_t operator&(const number_t& first, const number_t& second);
  friend number_t operator^(const number_t& first, const number_t& second);

  friend number_t operator>>(const number_t& number, uint8_t shift);
  friend number_t operator<<(const number_t& number, uint8_t shift);

  number_t& operator+=(const number_t& other);
  number_t& operator-=(const number_t& other);
  number_t& operator*=(const number_t& other);
  number_t& operator/=(const number_t& other);
  number_t& operator%=(const number_t& other);

  number_t& operator|=(const number_t& other);
  number_t& operator&=(const number_t& other);
  number_t& operator^=(const number_t& other);

  number_t& operator>>=(uint8_t shift);
  number_t& operator<<=(uint8_t shift);

  number_t operator+() const;
  number_t operator-() const;
  number_t operator~() const;
  bool operator!() const;

  number_t operator++(int);
  number_t& operator++();

  number_t operator--(int);
  number_t& operator--();

  friend bool operator==(const number_t& first, const number_t& second);
  friend bool operator!=(const number_t& first, const number_t& second);
  friend bool operator<=(const number_t& first, const number_t& second);
  friend bool operator>=(const number_t& first, const number_t& second);
  friend bool operator<(const number_t& first, const number_t& second);
  friend bool operator>(const number_t& first, const number_t& second);

  friend std::istream& operator>>(std::istream& in, number_t& number);
  friend std::ostream& operator<<(std::ostream& out, const number_t& number);
};