#include <iostream>
#include <string>
#include "Note.h"

using namespace std;

// конструктор по умолчанию
Note::Note()
{
    this->name = "None";
    this->phone = "None";
    this->year = "None";

    cout << "By default" << endl; // конструктор класса Note
}

// конструктор с параметром
Note::Note(string name, string phone, string year)
{
    this->name = name;
    this->phone = phone;
    this->year = year;

    cout << "With the parameter" << endl;
}

// конструктор копирования
Note::Note(const Note& n)
{
    this->name = n.name;
    this->phone = n.phone;
    this->year = n.year;

    cout << "Copying" << endl;
}

// деструктор
Note::~Note()
{
    cout << "Destructor" << endl;
}

// метод извлечения полей
void Note::Extract()
{
    cout << *this;
}

// метод получения полей
void Note::Get()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nChoose what you want\n" <<// переменная выбора поля
        "1 - Full name\n" <<
        "2 - Phone number\n" <<
        "3 - Birthday\n" << endl;
    cout << "Choise: ";
    cin >> choice;// ввод

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch (const char* mssg)
    {
        cout << "try again pls" << endl;
    }

    if (choice == "1") cout << "Full name: " << this->name << endl;
    else if (choice == "2") cout << "Phone number: " << this->phone << endl;
    else if (choice == "3") cout << "Birthday: " << this->year << endl;
    else if (choice == "4") cout << "Full name: " << this->name << " | Phone number: " << this->phone << " | Birthday: " << this->year << endl;
    else
    {
        cout << "wrong... :(" << endl;
        exit(0);
    }
}

// метод получения информации о поезде
void Note::GetInformatio()
{
    cout << "Full name: " << this->name << " | Phone number: " << this->phone << " | Birthday: " << this->year << endl;
}

// метод получения поля времени (для сортировки)
string Note::GetName()
{
    return this->name;
}

// метод получения пункта назначения
string Note::GetPhone()
{
    return this->phone;
}

// метод получения номера поезда
string Note::GetYear()
{
    return this->year;
}

// метод установки значения
void Note::Set()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    cin >> *this;
}

void Note::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nChoose what you want\n" <<
        "1 - Full name\n" <<
        "2 - Phone number\n" <<
        "3 - Birthday\n" << endl;
    cout << "Choise: ";
    cin >> choice;

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch (const char* mssg)
    {
        cout << "nah...try again" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "Full Name: ";
        getline(cin, this->name);
    }

    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "Phone number: ";
        getline(cin, this->phone);
    }

    else if (choice == "3")
    {
        getline(cin, choice);

        cout << "Birthday";
        getline(cin, this->year);
    }

    else
    {
        cout << "WRONG CHOISE bruh" << endl;
        exit(0);
    }
}

// перегрузка оператора вывода
std::ostream& operator<< (std::ostream& stream, Note& n) // перегрузка оператора извлеченния
{
    stream << "\nAll fields of the class:" << endl;
    stream << n.name << endl;
    stream << n.phone << endl;
    stream << n.year << endl;

    return stream;
}

// перегрузка оператора ввода
std::istream& operator>> (std::istream& stream, Note& n) // перегрузка оператора вставки
{
    string buf;

    cout << "\nInserting values:" << endl;
    cout << "Full Name: ";
    getline(stream, buf);
    n.name = buf;

    cout << "Phone number: ";
    getline(stream, buf);
    n.phone = buf;

    cout << "Birthday (xx.xx.xxxx): ";
    getline(stream, buf);
    n.year = buf;

    return stream;
}