#include <iostream>
#include <fstream>
#include <string>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // ������� ����� �����
    file.open("Text.txt"); // �������� �����

    if (!file.is_open()) // ���� ���� �� ��������
    {
        cout << "A!" << endl;
        exit(0);
    }

    else
    {
        string line; // ������, � ������� ����� ����������� �������� �� �����
        string suggestion;
        while (!file.eof()) // ���� �� ����� �����
        {
            string bufLine;
            getline(file, bufLine); // ��������� ������
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

    file.close(); // ��������� ����
}