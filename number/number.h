#include "number.h"

//Конструкторы (пустой, копирования, от числа)
number_t::number_t() : m_number{0} {}
number_t::number_t(const number_t &other_number) : m_number{other_number.m_number} {}
number_t::number_t(int64_t other_nember) : m_number{other_nember} {}

//Деструктор
number_t::~number_t() = default;

//Оператор присвоения
number_t& number_t::operator=(number_t other_number) {
    m_number = other_number.m_number;
    return *this;
}

//Каст (bool, числу, std::string)
number_t::operator bool() const {
    return !!m_number;
}
number_t::operator int64_t() const {
    return m_number;
}
number_t::operator std::string() const {
    return std::to_string(m_number);
}

//Бинарные арифметические и битовые операторы
number_t operator+(number_t first, number_t second) {
    return first.m_number + second.m_number;
}
number_t &number_t::operator+=(number_t other_number) {
    m_number += other_number.m_number;
    return *this;
}
number_t operator-(number_t first, number_t second) {
    return first.m_number - second.m_number;
}
number_t &number_t::operator-=(number_t other_number) {
    m_number -= other_number.m_number;
    return *this;
}
number_t operator*(number_t first, number_t second) {
    return first.m_number * second.m_number;
}
number_t &number_t::operator*=(number_t other_number) {
    m_number *= other_number.m_number;
    return *this;
}
number_t operator/(number_t first, number_t second) {
    return first.m_number / second.m_number;
}
number_t &number_t::operator/=(number_t other_number) {
    m_number /= other_number.m_number;
    return *this;
}
number_t operator%(number_t first, number_t second) {
    return first.m_number % second.m_number;
}
number_t &number_t::operator%=(number_t other_number) {
    m_number %= other_number.m_number;
    return *this;
}
number_t operator&(number_t first, number_t second) {
    return first.m_number & second.m_number;
}
number_t &number_t::operator&=(number_t other_number) {
    m_number &= other_number.m_number;
    return *this;
}

number_t operator|(number_t first, number_t second) {
    return first.m_number | second.m_number;
}
number_t &number_t::operator|=(number_t other_number) {
    m_number |= other_number.m_number;
    return *this;
}
number_t operator^(number_t first, number_t second) {
    return first.m_number ^ second.m_number;
}
number_t &number_t::operator^=(number_t other_number) {
    m_number ^= other_number.m_number;
    return *this;
}
number_t number_t::operator~() const {
    return ~m_number;
}
number_t operator>>(number_t first, number_t second) {
    return first.m_number >> second.m_number;
}
number_t &number_t::operator>>=(unsigned char zn) {
    m_number >>= zn;
    return *this;
}
number_t operator<<(number_t first, number_t second) {
    return first.m_number << second.m_number;
}
number_t &number_t::operator<<=(unsigned char zn) {
    m_number <<= zn;
    return *this;
}

//Унарные операторы
number_t number_t::operator+() const {
    return +m_number;
}
number_t number_t::operator-() const {
    return -m_number;
}

//Операторы инкремента и декремента
number_t &number_t::operator++() {
    m_number++;
    return *this;
}
number_t number_t::operator++(int) {
    number_t num{m_number};
    m_number++;
    return num;
}
number_t &number_t::operator--() {
    m_number--;
    return *this;
}
number_t number_t::operator--(int) {
    number_t num{m_number};
    m_number--;
    return num;
}

//Операторы сравнения
bool operator<(number_t first, number_t second) {
    return first.m_number < second.m_number;
}
bool operator>(number_t first, number_t second) {
    return first.m_number > second.m_number;
}
bool operator<=(number_t first, number_t second) {
    return first.m_number <= second.m_number;
}
bool operator>=(number_t first, number_t second) {
    return first.m_number >= second.m_number;
}
bool operator==(number_t first, number_t second) {
    return first.m_number == second.m_number;
}
bool operator!=(number_t first, number_t second) {
    return first.m_number != second.m_number;
}
//Операторы вывода в поток и ввода из потока
std::ostream &operator<<(std::ostream &out, number_t &num) {
    out << num.m_number;
    return out;
}
std::istream &operator>>(std::istream &in, number_t &num) {
    in >> num.m_number;
    return in;
}
