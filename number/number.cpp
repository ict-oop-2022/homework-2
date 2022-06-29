#include "number.h"

number_t::number_t() {
  _data = 0;
}

number_t::number_t(const number_t& other) {
  _data = other._data;
}

number_t::number_t(int64_t data) {
  _data = data;
}

number_t& number_t::operator=(const number_t& other) {
  _data = other._data;
  return *this;
}


number_t::operator int64_t() const {
  return _data;
}

number_t::operator bool() const {
  return _data != 0;
}

number_t::operator std::string() const {
  return std::to_string(_data);
}

number_t operator+(const number_t& first, const number_t& second) {
  return number_t{ first._data + second._data };
}

number_t operator-(const number_t& first, const number_t& second) {
  return number_t{ first._data - second._data };
}

number_t operator/(const number_t& first, const number_t& second) {
  return number_t{ first._data / second._data };
}

number_t operator*(const number_t& first, const number_t& second) {
  return number_t{ first._data * second._data };
}

number_t operator%(const number_t& first, const number_t& second) {
  return number_t{ first._data % second._data };
}

number_t operator|(const number_t& first, const number_t& second) {
  return number_t{ first._data | second._data };
}

number_t operator&(const number_t& first, const number_t& second) {
  return number_t{ first._data & second._data };
}

number_t operator^(const number_t& first, const number_t& second) {
  return number_t{ first._data ^ second._data };
}

number_t operator>>(const number_t& first, uint8_t second) {
  return number_t{ first._data >> second };
}

number_t operator<<(const number_t& first, uint8_t second) {
  return number_t{ first._data << second };
}

number_t& number_t::operator+=(const number_t& other) {
  _data += other._data;
  return *this;
}

number_t& number_t::operator-=(const number_t& other) {
  _data -= other._data;
  return *this;
}

number_t& number_t::operator*=(const number_t& other) {
  _data *= other._data;
  return *this;
}

number_t& number_t::operator/=(const number_t& other) {
  _data /= other._data;
  return *this;
}

number_t& number_t::operator%=(const number_t& other) {
  _data %= other._data;
  return *this;
}

number_t& number_t::operator|=(const number_t& other) {
  _data |= other._data;
  return *this;
}

number_t& number_t::operator&=(const number_t& other) {
  _data &= other._data;
  return *this;
}

number_t& number_t::operator^=(const number_t& other) {
  _data ^= other._data;
  return *this;
}

number_t& number_t::operator>>=(uint8_t shift) {
  _data >>= shift;
  return *this;
}

number_t& number_t::operator<<=(uint8_t shift) {
  _data <<= shift;
  return *this;
}

number_t number_t::operator+() const {
  return number_t{ +_data };
}
number_t number_t::operator-() const {
  return number_t{ -_data };
}
number_t number_t::operator~() const {
  return number_t{ ~_data };
}
bool number_t::operator!() const {
  return !this->operator bool();
}

number_t number_t::operator++(int) {
  int64_t temp = _data;
  ++_data;
  return number_t(temp);
}

number_t& number_t::operator++() {
  ++_data;
  return *this;
}

number_t number_t::operator--(int) {
  int64_t temp = _data;
  --_data;
  return number_t(temp);
}

number_t& number_t::operator--() {
  --_data;
  return *this;
}

bool operator==(const number_t& first, const number_t& second) {
  return first._data == second._data;
}

bool operator!=(const number_t& first, const number_t& second) {
  return first._data != second._data;
}

bool operator<=(const number_t& first, const number_t& second) {
  return first._data <= second._data;
}

bool operator>=(const number_t& first, const number_t& second) {
  return first._data >= second._data;
}

bool operator<(const number_t& first, const number_t& second) {
  return first._data < second._data;
}

bool operator>(const number_t& first, const number_t& second) {
  return first._data > second._data;
}

std::istream& operator>>(std::istream& in, number_t& number) {
  return in >> number._data;
}

std::ostream& operator<<(std::ostream& out, const number_t& number) {
  return out << number._data;
}