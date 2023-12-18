#include <iostream>
#include <string>
#include <algorithm>
#include "Storage.h"
#include "Note.h"

using namespace std;

// ����������� �� ���������
Store::Store()
{
    this->array = new Note * [1]; // �������� ������
    this->countElement = 0; // ���-�� ��������� = 0
    cout << "By default" << endl; //����������� ������ Store
}

// ����������� � ����������
Store::Store(int size)
{
    this->array = new Note * [size]; // �������� ������ ��� ������
    this->countElement = 0; // ���-�� ��������� = 0
    cout << "With the parameter" << endl;
}

// ����������� �����������
Store::Store(const Store& s)
{
    this->countElement = s.countElement; // �������� ���-�� ���������
    this->array = new Note * [this->countElement]; // �������� ����������� ���-�� ������

    for (int id = 0; id < this->countElement; id++) this->array[id] = s.array[id]; // �������� ������ ��������

    cout << "Copying" << endl;
}

// ����������
Store::~Store()
{
    delete array; // ����������� ���������� ������
    cout << "Destructor" << endl;
}

// ���������� �������
void Store::SortedArray()
{
    // ����� ���������� - ���������
    for (int id1 = 0; id1 < countElement; id1++) // ���-�� �������� = ���-�� ���������
    {
        for (int id2 = 0; id2 < countElement - 1; id2++) // ���������� �������� �� ������ �� ����������
        {
            if (array[id2]->GetName() > array[id2 + 1]->GetName()) // ���� ������� ������ ������������, �� ������ �� �������
            {
                Note* buf = array[id2];
                array[id2] = array[id2 + 1];
                array[id2 + 1] = buf;
            }
        }
    }
}

// ����� �� ������
void Store::FindYear()
{
    // ������� ����� �����
    string buf;
    getline(cin, buf);

    string findYear; // ����������, ������� ������ �������� ������
    cout << "\nChoose month: ";
    getline(cin, findYear); // ����

    int flagFind = 0; // ����, ���� �� ��������� ���� �� �����

    cout << "\nInfomation about people" << endl;

    for (int id = 0; id < countElement; id++) // ���������� ��� ��������
    {
        string bufline = array[id]->GetYear();
        string month;
        int flagPoint = 0; // ����� ��������� �����
        for (int i = 0; i < bufline.size(); i++)
        {
            if (flagPoint)
            {
                if (bufline[i] == '.') break;
                month += bufline[i];
            }
            if (bufline[i] == '.') flagPoint = 1;
        }

        if (stoi(findYear) == stoi(month)) // ���� �����
        {
            flagFind = 1; // ������ ����, ��� ��� ����� ��������
            cout << array[id]->GetName() << endl; // ������� ��������
        }
    }

    if (!flagFind) cout << "\nAy caramba!No people like this" << endl; // ���� ����� ���
}

// ���������� ���� ��������
void Store::ExtractField()
{
    for (int id = 0; id < countElement; id++) array[id]->Extract(); // ������� ��� ��������
}

// ��������� �����
void Store::GetFiel()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    string choice; // ���������� ������ ��������
    cout << "\nEnter the number of the element whose fields you want to output: ";
    cin >> choice; // ����

    // �������� �� ������������ ����� (������ � �������������� ���������)
    try
    {
        // ���� � ������ ���� �����, ���������� ������
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // ���� � ������ ���� �����, ���������� ������
        if (!all_of(choice.begin(), choice.end(), ::isdigit)) throw "Error";
    }
    catch (const char* mssg) // ��������� ������
    {
        cout << "Ay-ay-ay, wrong!" << endl;
        exit(0);
    }

    // ���� ����� �������� ��������� �������� ���-�� ��������� ��� ������ 0, �� ������
    if (choice > to_string(countElement) or choice < "0")
    {
        cout << "Error" << endl;
        exit(0);
    }

    // �����
    else
    {
        int idChoice = stoi(choice);
        array[idChoice]->Get(); // ������� ����
    }
}

// ����� ��������� ��������
void Store::Set()
{
    Note* note = new Note(); // ������� ��������� �� ������
    note->Set(); // �������� ����� ����� �������
    array[countElement++] = note; // ��������� � ������
    this->SortedArray(); // ��������� ������ �� ������� �����������
}

// ����� ��������� ��������
void Store::Change()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    cout << "\nSelect the number of the item whose data you want to change: ";
    string choice; // ���������� ������ ��������, �������� �������� �� ����� ��������
    cin >> choice; // ����

    // ��������� �������������� �������� (�������� �� ����)
    try
    {
        // ��������� ��� �� ����
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // ���� �� ����� � ���������
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch (const char* mssg) // ��������� ������
    {
        cout << "Stopo el missing porfavor" << endl;
        exit(0);
    }

    // �������� ����� ��������� �������
    array[stoi(choice)]->Change();
}

// ����� ��������
void Store::Delete()
{
    // ������� ����� ������
    string buf;
    getline(cin, buf);

    cout << "\nSelect the number of the item whose data you want to delete: ";
    string choice; // ���������� ����� ������ ��������
    cin >> choice; // ����

    // ��������� �������������� ��������
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

    // �������� ��������
    for (int id = stoi(choice); id < countElement - 1; id++) array[id] = array[id + 1];
    countElement--;
}