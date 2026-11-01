// Source.cpp
// головний файл проекту – функція main
#include <iostream>
#include "Integer.h"
#include <windows.h>
using namespace std;

// копії структури полів класу – для порівняння розміру без / з pack(1)
struct Plain { int x; };
#pragma pack(push, 1)
struct Packed { int x; };
#pragma pack(pop)

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // --- різні способи створення об'єктів ---
    Integer c;                          // конструктор за умовчанням
    Integer d(17);                      // конструктор ініціалізації
    Integer e(d);                       // конструктор копіювання
    Integer f = Integer(-4);            // тимчасовий об'єкт
    c = f;                              // присвоєння
    cout << "c = " << c << ", d = " << d << ", e = " << e
         << ", f = " << f << endl;

    // --- масиви об'єктів ---
    Integer arr1[3];                                    // статичний
    Integer arr2[3] = { Integer(2), Integer(9), Integer(13) };
    Integer* arr3 = new Integer[2];                     // динамічний
    arr3[0] = Integer(6);
    arr3[1] = Integer(25);
    for (int i = 0; i < 3; i++)
        cout << "arr2[" << i << "] = " << arr2[i]
             << (~arr2[i] ? " - prime" : " - not prime") << endl;
    cout << "arr3[0] = " << arr3[0] << ", arr3[1] = " << arr3[1] << endl;
    delete[] arr3;

    // --- методи доступу ---
    arr1[0].SetX(100);
    cout << "arr1[0].GetX() = " << arr1[0].GetX() << endl;
    string s = arr1[0];                 // приведення типу до рядка
    cout << "string(arr1[0]) = " << s << endl << endl;

    // --- введення та всі операції ---
    Integer a, b;
    cout << "a = ? "; cin >> a;
    cout << "b = ? "; cin >> b;
    cout << endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a % b = " << a % b << endl;
    cout << "a ^ b = " << (a ^ b) << endl;

    if (~a) cout << "a - prime number" << endl;
    else    cout << "a - not prime number" << endl;

    if (a[2]) cout << "a - even number" << endl;
    else      cout << "a - not even number" << endl;

    cout << "a is divisible by 3: " << (a[3] ? "yes" : "no") << endl << endl;

    // --- розмір класу ---
    cout << "sizeof(Integer)          = " << sizeof(Integer) << endl;
    cout << "sizeof без pack(1)       = " << sizeof(Plain) << endl;
    cout << "sizeof з #pragma pack(1) = " << sizeof(Packed) << endl;

    cin.get(); cin.get();
    return 0;
}
