#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <string.h>
using namespace std;

class Note
{
private:
    string name; // ФИО
    string phone; // телефон
    string year; // день рождения

public:
    Note(); // конструктор по умолчанию
    Note(string name, string phone, string year); // конструктор с параметром
    Note(const Note& n); // конструктор копирования
    ~Note(); // деструктор

    void Extract(); // метод извлечения значения
    void Get(); // метод получения полей
    void GetInformatio(); // метод получения информации о конкретном человеке
    string GetName(); // метод получения поля имени для упорядочивания
    string GetPhone(); // метод получения телефона
    string GetYear(); // метод получения года рождения
    void Set(); // метод установки значения
    void Change(); // метод редактирования значений

    friend ostream& operator<< (ostream& stream, Note& n); // перегрузка оператора извлеченния
    friend istream& operator>> (istream& stream, Note& n); // перегрузка оператора вставки
};

#endif