#include <iostream>
#include <string>
#include "Note.h"

using namespace std;

// ����������� �� ���������
Note::Note()
{
    this->name = "None";
    this->phone = "None";
    this->year = "None";

    cout << "By default" << endl; // ����������� ������ Note
}

// ����������� � ����������
Note::Note(string name, string phone, string year)
{
    this->name = name;
    this->phone = phone;
    this->year = year;

    cout << "With the parameter" << endl;
}

// ����������� �����������
Note::Note(const Note& n)
{
    this->name = n.name;
    this->phone = n.phone;
    this->year = n.year;

    cout << "Copying" << endl;
}

// ����������
Note::~Note()
{
    cout << "Destructor" << endl;
}

// ����� ���������� �����
void Note::Extract()
{
    cout << *this;
}

// ����� ��������� �����
void Note::Get()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nChoose what you want\n" <<// ���������� ������ ����
        "1 - Full name\n" <<
        "2 - Phone number\n" <<
        "3 - Birthday\n" << endl;
    cout << "Choise: ";
    cin >> choice;// ����

    // ��������� �������������� ��������
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

// ����� ��������� ���������� � ������
void Note::GetInformatio()
{
    cout << "Full name: " << this->name << " | Phone number: " << this->phone << " | Birthday: " << this->year << endl;
}

// ����� ��������� ���� ������� (��� ����������)
string Note::GetName()
{
    return this->name;
}

// ����� ��������� ������ ����������
string Note::GetPhone()
{
    return this->phone;
}

// ����� ��������� ������ ������
string Note::GetYear()
{
    return this->year;
}

// ����� ��������� ��������
void Note::Set()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    cin >> *this;
}

void Note::Change()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nChoose what you want\n" <<
        "1 - Full name\n" <<
        "2 - Phone number\n" <<
        "3 - Birthday\n" << endl;
    cout << "Choise: ";
    cin >> choice;

    // ��������� �������������� ��������
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

// ���������� ��������� ������
std::ostream& operator<< (std::ostream& stream, Note& n) // ���������� ��������� �����������
{
    stream << "\nAll fields of the class:" << endl;
    stream << n.name << endl;
    stream << n.phone << endl;
    stream << n.year << endl;

    return stream;
}

// ���������� ��������� �����
std::istream& operator>> (std::istream& stream, Note& n) // ���������� ��������� �������
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