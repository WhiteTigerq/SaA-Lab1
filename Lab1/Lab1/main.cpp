//
//  main.cpp
//  Lab1
//
//  Created by Олег Джинганин on 14/11/2019.
//  Copyright © 2019 Олег Джинганин. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void BinOut(unsigned char* Buf, int len) {

    int i, j;

    unsigned char byte;

    for (i = len - 1; i >= 0; i--)

        for (j = 1, byte = Buf[i]; j <= 8; byte <<= 1, j++)

            cout << (byte & 0x80 ? '1' : '0');

    printf("\n");

}

void BinIn(unsigned char* Buf, int len) {

    int i, j;

    char ch;

    for (i = len - 1; i >= 0; i--)

        for (j = 1, Buf[i] = 0; j <= 8; Buf[i] = (Buf[i] << 1) + (ch - '0'), j++) {

            while ((ch = getchar()) != '0' && ch != '1');

            cout << ch;

        }

    printf("\n");

}

struct none {
    char name[10];
    int age;
    char gender;
};

int main()
{
    setlocale(0, "");
    unsigned char x;
    int xbuff;
    long double x1;
    none x3;
    cout << "Введите значение типа unsigned char: ";
    cin >> xbuff;
    x = xbuff;
    cout << "Это двоичное представление значения: " << endl;
    BinOut(&x, sizeof(x));
    ///////////////////////// BinOut
    cout << "Введите двоичное представление типа unsigned char: " << endl;
    BinIn(&x, sizeof(x));
    cout << "Это его значение: " << (int)x << endl;
    ///////////////////////// BinIn
    cout << "Введите значение типа long double: ";
    cin >> x1;
    cout << "Это двоичное представление значения:" << endl;
    BinOut((unsigned char*)&x1, sizeof(x1));
    ///////////////////////// BinOut
    cout << "Введите двоичное представление типа long double: " << endl;
    BinIn((unsigned char*)&x1, sizeof(x1));
    cout << "Это его значение: " << x1 << endl;
    ///////////////////////// BinIn
    cout << "Введите Ваше имя" << endl;
    cin >> x3.name;
    cout << "Сколько вам лет?" << endl;
    cin >> x3.age;
    cout << "Какого вы пола? (M,F)" << endl;
    cin >> x3.gender;
    cout << "Это двоичное представление Вашего имени: " << endl;
    BinOut((unsigned char*)&x3.name, sizeof(x3.name));
    cout << "Это двоичное представление Вашего возраста: " << endl;
    BinOut((unsigned char*)&x3.age, sizeof(x3.age));
    cout << "Это двоичное представление Вашего пола: " << endl;
    BinOut((unsigned char*)&x3.gender, sizeof(x3.gender));
    cout << "Введите двоичное представление имени: " << endl;
    BinIn((unsigned char*)&x3.name, sizeof(x3.name));
    cout << "Это его значение: " << x3.name << endl;
    cout << "Введите двоичное представление возраста: " << endl;
    BinIn((unsigned char*)&x3.age, sizeof(x3.age));
    cout << "Это его значение: " << x3.age << endl;
    cout << "Введите двоичное представление пола: " << endl;
    BinIn((unsigned char*)&x3.gender, sizeof(x3.gender));
    cout << "Это его значение: " << x3.gender << endl;
    system("pause");
    return 0;
}

