#pragma once

#include <cstdint>
#include <iostream>

class number_t {
private:
  long long _n1{0};
public:
  number_t(const number_t&);
  number_t(long long _n1 = 0);
  number_t& operator=(const number_t&);
  explicit operator bool() const;
  explicit operator int64_t() const;
  explicit operator std::string() const;

  friend number_t operator+(number_t , const number_t& right);
  friend number_t operator-(number_t, const number_t& right);
  friend number_t operator*(number_t, const number_t& right);
  friend number_t operator/(number_t, const number_t& right);
  friend number_t operator %(number_t, const number_t& right);

  number_t& operator+=(const number_t& right);
  number_t& operator-=(const number_t& right);
  number_t& operator*=(const number_t& right);
  number_t& operator/=(const number_t& right);
  number_t& operator%=(const number_t& right);

  friend number_t operator^(number_t , const number_t& right);
  friend number_t operator&(number_t , const number_t& right);
  friend number_t operator|(number_t , const number_t& right);
  friend number_t operator>>(number_t , const number_t& right);
  friend number_t operator << (number_t , const number_t& );

  number_t& operator^=(const number_t& right);
  number_t& operator&=(const number_t& right);
  number_t& operator|=(const number_t& right);
  number_t& operator<<=(const number_t& right);
  number_t& operator>>=(const number_t& right);

  friend std::ostream& operator<< (std::ostream&, const number_t&);
  friend std::istream& operator>> (std::istream&, number_t&);

  number_t operator-() const;
  number_t operator+() const;
  number_t operator!() const;
  number_t operator~() const;

  number_t operator++(int);
  number_t operator--(int);
  number_t& operator++();
  number_t& operator--();

  friend bool operator > (const number_t &, const number_t &);
  friend bool operator <= (const number_t &, const number_t &);

  friend bool operator < (const number_t &, const number_t &);
  friend bool operator >= (const number_t &, const number_t &);

  friend bool  operator == (const number_t&,const number_t&);
  friend bool  operator != (const number_t &,const number_t &);

};