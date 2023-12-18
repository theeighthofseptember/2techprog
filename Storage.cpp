#include <iostream>
#include <string>
#include <algorithm>
#include "Storage.h"
#include "Note.h"

using namespace std;

// конструктор по умолчанию
Store::Store()
{
    this->array = new Note * [1]; // выделяем память
    this->countElement = 0; // кол-во элементов = 0
    cout << "By default" << endl; //конструктор класса Store
}

// конструктор с параметром
Store::Store(int size)
{
    this->array = new Note * [size]; // выделяем память под размер
    this->countElement = 0; // кол-во элементов = 0
    cout << "With the parameter" << endl;
}

// конструктор копирования
Store::Store(const Store& s)
{
    this->countElement = s.countElement; // копируем кол-во элементов
    this->array = new Note * [this->countElement]; // выделяем необходимое кол-во памяти

    for (int id = 0; id < this->countElement; id++) this->array[id] = s.array[id]; // копируем каждое значение

    cout << "Copying" << endl;
}

// деструктор
Store::~Store()
{
    delete array; // освобождаем выделенную память
    cout << "Destructor" << endl;
}

// сортировка массива
void Store::SortedArray()
{
    // метод сортировки - Пузырьком
    for (int id1 = 0; id1 < countElement; id1++) // кол-во итераций = кол-ву элементов
    {
        for (int id2 = 0; id2 < countElement - 1; id2++) // перебираем элементы не доходя до последнего
        {
            if (array[id2]->GetName() > array[id2 + 1]->GetName()) // если текущий больше последуещего, то меняем их местами
            {
                Note* buf = array[id2];
                array[id2] = array[id2 + 1];
                array[id2 + 1] = buf;
            }
        }
    }
}

// поиск по месяцу
void Store::FindYear()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    string findYear; // переменная, которая хранит значения месяца
    cout << "\nChoose month: ";
    getline(cin, findYear); // ввод

    int flagFind = 0; // флаг, есть ли найденные люди по стажу

    cout << "\nInfomation about people" << endl;

    for (int id = 0; id < countElement; id++) // перебираем все элементы
    {
        string bufline = array[id]->GetYear();
        string month;
        int flagPoint = 0; // чтобы вычленить месяц
        for (int i = 0; i < bufline.size(); i++)
        {
            if (flagPoint)
            {
                if (bufline[i] == '.') break;
                month += bufline[i];
            }
            if (bufline[i] == '.') flagPoint = 1;
        }

        if (stoi(findYear) == stoi(month)) // если месяц
        {
            flagFind = 1; // меняем флаг, так как нашли человека
            cout << array[id]->GetName() << endl; // выводим человека
        }
    }

    if (!flagFind) cout << "\nAy caramba!No people like this" << endl; // если людей нет
}

// извлечение всех значений
void Store::ExtractField()
{
    for (int id = 0; id < countElement; id++) array[id]->Extract(); // выводим все значения
}

// получение полей
void Store::GetFiel()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice; // переменная выбора элемента
    cout << "\nEnter the number of the element whose fields you want to output: ";
    cin >> choice; // ввод

    // проверка на правильность ввода (работа с исключительной ситуацией)
    try
    {
        // если в строке есть буквы, выкидываем ошибку
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // если в строке есть буквы, выкидываем ошибку
        if (!all_of(choice.begin(), choice.end(), ::isdigit)) throw "Error";
    }
    catch (const char* mssg) // обработка ошибки
    {
        cout << "Ay-ay-ay, wrong!" << endl;
        exit(0);
    }

    // если выбор элемента превышает значения кол-ва элементов или меньше 0, то ошибка
    if (choice > to_string(countElement) or choice < "0")
    {
        cout << "Error" << endl;
        exit(0);
    }

    // иначе
    else
    {
        int idChoice = stoi(choice);
        array[idChoice]->Get(); // выводим поля
    }
}

// метод установки значения
void Store::Set()
{
    Note* note = new Note(); // создаем указатель на объект
    note->Set(); // вызываем метод ввода значеий
    array[countElement++] = note; // вставляем в массив
    this->SortedArray(); // сортируем массив по времени отправления
}

// метод изменения значения
void Store::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    cout << "\nSelect the number of the item whose data you want to change: ";
    string choice; // переменная выбора элемента, значения которого мы хотим изменить
    cin >> choice; // ввод

    // обработка исключительной ситуации (проверка на ввод)
    try
    {
        // проверяем нет ли букв
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // если не лежит в диапазоне
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch (const char* mssg) // обработка ошибок
    {
        cout << "Stopo el missing porfavor" << endl;
        exit(0);
    }

    // вызываем метод изменения знаения
    array[stoi(choice)]->Change();
}

// метод удаления
void Store::Delete()
{
    // очищаем поток вводов
    string buf;
    getline(cin, buf);

    cout << "\nSelect the number of the item whose data you want to delete: ";
    string choice; // переменная ввода номера элемента
    cin >> choice; // ввод

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch (const char* mssg)
    {
        cout << "well well well" << endl;
        exit(0);
    }

    // удаление значений
    for (int id = stoi(choice); id < countElement - 1; id++) array[id] = array[id + 1];
    countElement--;
}