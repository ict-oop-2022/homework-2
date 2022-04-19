#pragma once

#include <cstdint>
#include <iostream>

class number_t {
    int64_t m_number;

public:

//Конструкторы (пустой, копирования, от числа)
    number_t();
    number_t(const number_t &other_number);
    number_t(int64_t other);

//Деструктор
    ~number_t();

//Оператор присвоения
    number_t& operator=(number_t other_number);

//Каст (bool, числу, std::string)
    explicit operator bool() const;
    explicit operator int64_t() const;
    explicit operator std::string() const;

//Бинарные арифметические и битовые операторы
    friend number_t operator+(number_t first, number_t second);
    number_t &operator+=(number_t other_number);

    friend number_t operator-(number_t first, number_t second);
    number_t &operator-=(number_t other_number);

    friend number_t operator*(number_t first, number_t second);
    number_t &operator*=(number_t other_number);

    friend number_t operator/(number_t first, number_t second);
    number_t &operator/=(number_t other_number);

    friend number_t operator%(number_t first, number_t second);
    number_t &operator%=(number_t other_number);

    friend number_t operator&(number_t first, number_t second);
    number_t &operator&=(number_t other_number);

    friend number_t operator|(number_t first, number_t second);
    number_t &operator|=(number_t other_number);

    friend number_t operator^(number_t first, number_t second);
    number_t &operator^=(number_t other_number);

    number_t operator~() const;

    friend number_t operator>>(number_t first, number_t second);
    number_t &operator>>=(unsigned char zn);

    friend number_t operator<<(number_t left, number_t right);
    number_t &operator<<=(unsigned char zn);

//Унарные операторы
    number_t operator+() const;
    number_t operator-() const;

//Операторы инкремента и декремента
    number_t &operator++();
    number_t operator++(int);

    number_t &operator--();
    number_t operator--(int);

//Операторы сравнения
    friend bool operator<(number_t first, number_t second);
    friend bool operator>(number_t first, number_t second);
    friend bool operator<=(number_t first, number_t second);
    friend bool operator>=(number_t first, number_t second);
    friend bool operator==(number_t first, number_t second);
    friend bool operator!=(number_t first, number_t second);

//Операторы вывода в поток и ввода из потока
    friend std::ostream &operator<<(std::ostream &out, number_t &num);
    friend std::istream &operator>>(std::istream &in, number_t &num);
};
