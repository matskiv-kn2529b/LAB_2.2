// Integer.cpp
// файл реалізації – реалізація методів класу
#include "Integer.h"
#include <sstream>
#include <windows.h>
using namespace std;

Integer::Integer() : x(0)
{ }

Integer::Integer(int y) : x(0)
{
    SetX(y);                    // повторне використання коду
}

Integer::Integer(const Integer& r) : x(r.x)
{ }

Integer::~Integer()
{ }

void Integer::SetX(int value)
{
    x = value;                  // будь-яке ціле значення допустиме
}

int Integer::GetX() const
{
    return x;
}

Integer& Integer::operator = (const Integer& r)
{
    x = r.x;
    return *this;
}

Integer::operator string() const
{
    stringstream ss;
    ss << x;
    return ss.str();
}

Integer operator + (const Integer& a, const Integer& b)
{
    return Integer(a.x + b.x);
}

Integer operator - (const Integer& a, const Integer& b)
{
    return Integer(a.x - b.x);
}

Integer operator * (const Integer& a, const Integer& b)
{
    return Integer(a.x * b.x);
}

Integer operator / (const Integer& a, const Integer& b)
{
    if (b.x == 0)
    {
        cerr << "Error: division by zero!" << endl;
        return Integer(0);
    }
    return Integer(a.x / b.x);
}

Integer operator % (const Integer& a, const Integer& b)
{
    if (b.x == 0)               // перевіряється дільник
    {
        cerr << "Error: division by zero!" << endl;
        return Integer(0);
    }
    return Integer(a.x % b.x);
}

// піднесення a до цілого степеня b (результат цілий)
Integer operator ^ (const Integer& a, const Integer& b)
{
    if (b.x == 0)
        return Integer(1);                  // будь-яке число (і 0) в степені 0 = 1
    if (a.x == 0)
    {
        if (b.x < 0)
        {
            cerr << "Error: 0 in negative power!" << endl;
            return Integer(0);
        }
        return Integer(0);                  // 0 в додатному степені = 0
    }
    if (b.x < 0)                            // a^(-n) = 1 / a^n: у цілих числах
    {
        if (a.x == 1) return Integer(1);
        if (a.x == -1) return Integer(b.x % 2 == 0 ? 1 : -1);
        return Integer(0);                  // |a| > 1 -> дробове число < 1 -> 0
    }
    long long result = 1, base = a.x;       // швидке піднесення до степеня
    unsigned n = static_cast<unsigned>(b.x);
    while (n > 0)
    {
        if (n & 1) result *= base;
        base *= base;
        n >>= 1;
    }
    return Integer(static_cast<int>(result));
}

// перевірка кратності числа n (a[2] – перевірка на парність)
bool Integer::operator [] (int n) const
{
    if (n == 0)
    {
        cerr << "Error: n must be non-zero!" << endl;
        return false;
    }
    return x % n == 0;
}

// перевірка, чи число просте
bool Integer::operator ~ () const
{
    if (x < 2)
        return false;
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

ostream& operator << (ostream& out, const Integer& a)
{
    out << string(a);           // формат виводу визначено в operator string()
    return out;
}

istream& operator >> (istream& in, Integer& a)
{
    int t = 0;
    in >> t;
    a.SetX(t);                  // запис через метод запису
    return in;
}
