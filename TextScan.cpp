#include <iostream>
#include <fstream>
#include <string>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // создаем поток ввода
    file.open("Text.txt"); // открытие файла

    if (!file.is_open()) // если файл не открылся
    {
        cout << "A!" << endl;
        exit(0);
    }

    else
    {
        string line; // строка, в которую будут считываться значения из файла
        string suggestion;
        while (!file.eof()) // пока не конец файла
        {
            string bufLine;
            getline(file, bufLine); // считываем строку
            line += bufLine + '\n';
        }

        bool flagFirst = false;

        for (int id = 0; id < line.size() + 1; id++)
        {
            if ((line[id] == 'a' || line[id] == 'e' || line[id] == 'y' || line[id] == 'u' || line[id] == 'i' || line[id] == 'o' ||
                line[id] == 'A' || line[id] == 'E' || line[id] == 'Y' || line[id] == 'U' || line[id] == 'I' || line[id] == 'O') && id == 0)
            {
                suggestion += toupper(line[id]);
                flagFirst = false;
                //  cout << flagFirst << endl;
                //     cout << line[id] << endl;
                continue;
            }
            if ((line[id] == 'a' || line[id] == 'e' || line[id] == 'y' || line[id] == 'u' || line[id] == 'i' || line[id] == 'o' ||
                line[id] == 'A' || line[id] == 'E' || line[id] == 'Y' || line[id] == 'U' || line[id] == 'I' || line[id] == 'O') && flagFirst)
            {
                flagFirst = false;
                suggestion += toupper(line[id]);
                //      cout << flagFirst << endl;
                // cout << line[id] << endl;
                continue;
            }
            else if (isdigit(line[id]) && flagFirst)
            {
                flagFirst = false;
            }
            else if (line[id] == ' ' || line[id] == '.' || line[id] == ',' || line[id] == '?' || line[id] == '!' || line[id] == '\n')
            {
                flagFirst = true;
            }
            else
            {
                flagFirst = false;
            }
            // cout << flagFirst << endl;
            // cout << line[id] << endl;
            suggestion += line[id];
        }
        cout << suggestion << endl;
    }

    file.close(); // закрываем файл
}