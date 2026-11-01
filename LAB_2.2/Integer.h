// Integer.h
// заголовний файл – визначення класу
#pragma once
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Integer
{
    int x;                                  // значення цілого числа

public:
    Integer();                              // конструктор за умовчанням
    Integer(int);                           // конструктор ініціалізації
    Integer(const Integer&);                // конструктор копіювання
    ~Integer();

    void SetX(int);                         // метод запису
    int  GetX() const;                      // метод зчитування

    Integer& operator = (const Integer&);
    operator string() const;                // приведення типу до рядка

    friend Integer operator + (const Integer&, const Integer&);
    friend Integer operator - (const Integer&, const Integer&);
    friend Integer operator * (const Integer&, const Integer&);
    friend Integer operator / (const Integer&, const Integer&);
    friend Integer operator % (const Integer&, const Integer&);
    friend Integer operator ^ (const Integer&, const Integer&);   // степінь

    bool operator [] (int) const;           // чи кратне n (a[2] – парність)
    bool operator ~ () const;               // чи просте

    friend ostream& operator << (ostream&, const Integer&);
    friend istream& operator >> (istream&, Integer&);
};
