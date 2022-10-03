//
// Created by User on 01.09.2022.
//

#pragma once
#define numberBitonBite 8
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <climits>
class BigInt {
public:
    BigInt();
    explicit BigInt(int);
    explicit BigInt(std::string);
    BigInt(const BigInt&);
    ~BigInt();

    BigInt& operator=(const BigInt&);

    BigInt operator~() const;

    BigInt& operator++();
    const BigInt operator++(int);
    BigInt& operator--();
    const BigInt operator--(int);
    BigInt& operator+=(const BigInt&);
    BigInt& operator*=(const BigInt&);
    BigInt& operator-=(const BigInt&);
    BigInt& operator/=(const BigInt&);
    BigInt& operator^=(const BigInt&);
    BigInt& operator%=(const BigInt&);
    BigInt& operator&=(const BigInt&);
    BigInt& operator|=(const BigInt&);
    void resize(size_t size);
    BigInt operator+() const;  // unary +
    BigInt operator-() const;  // unary -

    bool operator==(const BigInt&) const;
    bool operator!=(const BigInt&) const;
    bool operator<(const BigInt&) const;
    bool operator>(const BigInt&) const;
    bool operator<=(const BigInt&) const;
    bool operator>=(const BigInt&) const;

    explicit operator int() const;
    explicit operator std::string() const;

    size_t size() const;  // size in bytes
    void clean();
    void div2();
    bool sign;
    size_t counter;
    unsigned int *data;
};

BigInt operator+(const BigInt&, const BigInt&);
BigInt operator-(const BigInt&, const BigInt&);
BigInt operator*(const BigInt&, const BigInt&);
BigInt operator/(const BigInt&, const BigInt&);
BigInt operator^(const BigInt&, const BigInt&);
BigInt operator%(const BigInt&, const BigInt&);
BigInt operator&(const BigInt&, const BigInt&);
BigInt operator|(const BigInt&, const BigInt&);
std::ostream& operator<<(std::ostream& o, const BigInt& i);
