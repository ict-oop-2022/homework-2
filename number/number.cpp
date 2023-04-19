#include "number.h"

// Default constructor and destructor
number_t::number_t() = default;
number_t::~number_t() = default;

// Constructor with an int64_t argument
number_t::number_t(const int64_t a) : val(a) {}

// Copy constructor
number_t::number_t(const number_t &a) : val(a.val) {}

// Assignment operator
number_t &number_t::operator=(const number_t &a) {
  val = a.val;
  return *this;
}

// Arithmetic assignment operators
number_t &number_t::operator+=(const number_t &a) {
  val += a.val;
  return *this;
}
number_t &number_t::operator-=(const number_t &a) {
  val -= a.val;
  return *this;
}
number_t &number_t::operator*=(const number_t &a) {
  val *= a.val;
  return *this;
}
number_t &number_t::operator/=(const number_t &a) {
  val /= a.val;
  return *this;
}
number_t &number_t::operator%=(const number_t &a) {
  val %= a.val;
  return *this;
}
number_t &number_t::operator^=(const number_t &a) {
  val ^= a.val;
  return *this;
}
number_t &number_t::operator&=(const number_t &a) {
  val &= a.val;
  return *this;
}
number_t &number_t::operator|=(const number_t &a) {
  val |= a.val;
  return *this;
}
number_t &number_t::operator<<=(const number_t &a) {
  val <<= a.val;
  return *this;
}
number_t &number_t::operator>>=(const number_t &a) {
  val >>= a.val;
  return *this;
}

// Increment and decrement operators
number_t &number_t::operator++() {
  ++val;
  return *this;
}
number_t &number_t::operator--() {
  --val;
  return *this;
}
number_t number_t::operator++(int) {
  return number_t(val++);
}
number_t number_t::operator--(int) {
  return number_t(val--);
}

// Conversion operators
number_t::operator bool() const {
  return val != 0;
}
number_t::operator int64_t() const {
  return val;
}
number_t::operator std::string() const {
  return std::to_string(val);
}

// Input/output stream operators
std::ostream &operator<<(std::ostream &os, const number_t &a) {
  os << a.val;
  return os;
}
std::istream &operator>>(std::istream &is, number_t &a) {
  is >> a.val;
  return is;
}
