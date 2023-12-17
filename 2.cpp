#include <iostream>
//#include "Storage.h"
//#include "Note.h"
#include "TextScan.h"
#include <string>

using namespace std;

int main()
{
    //Store store;  объект, где будут храниться данные

    // цикл меню
    while (1)
    {
        string choice; // переменная выбора пользователя

        cout << "\nMENU" << endl;
        cout << "1 - Search by month\n"
            << "2 - Extract object fields\n"
            << "3 - Get specific fields\n"
            << "4 - Insert the value\n"
            << "5 - Change the value\n"
            << "6 - Delete the value\n"
            << "7 - Replacing the first vowel with a capital one" << endl;
        cout << "Choice: ";
        cin >> choice; // ввод выбора
        cout << "\n" << endl;

        // обработка ввода (исключительные ситуации)
        try
        {
            // проверяем все символы
            for (int id = 0; id < choice.size(); id++)
            {
                // если буква, кидаем ошибку
                if (isalpha(choice[id])) throw "Ay carramba";
            }

            // если выбор не лежит в диапазоне, кидаем ошибку
            if (choice > "7" || choice < "1") throw "Ay carramba";
        }
        catch (const char* mssg) // обработка ошибки
        {
            cout << "El deportato" << endl;
            exit(0);
        }
        // проверка выбора пользователя
        if (choice == "1") { cout << "Ay carramba, el deportato" << endl; exit(0); } //store.FindYear();
        else if (choice == "2") { cout << "Ay carramba, el deportato" << endl; exit(0); } //store.ExtractField();
        else if (choice == "3") { cout << "Ay carramba, el deportato" << endl; exit(0); } //store.GetFiel();
        else if (choice == "4") { cout << "Ay carramba, el deportato" << endl; exit(0); } //store.Set();
        else if (choice == "5") { cout << "Ay carramba, el deportato" << endl; exit(0); } //store.Change();
        else if (choice == "6") { cout << "Ay carramba, el deportato" << endl; exit(0); } //store.Delete();
        else if (choice == "7") TextScaner();
        else { cout << "Ay carramba, el deportato" << endl; exit(0); }
    }
}