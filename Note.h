#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <string.h>
using namespace std;

class Note
{
private:
    string name; // ���
    string phone; // �������
    string year; // ���� ��������

public:
    Note(); // ����������� �� ���������
    Note(string name, string phone, string year); // ����������� � ����������
    Note(const Note& n); // ����������� �����������
    ~Note(); // ����������

    void Extract(); // ����� ���������� ��������
    void Get(); // ����� ��������� �����
    void GetInformatio(); // ����� ��������� ���������� � ���������� ��������
    string GetName(); // ����� ��������� ���� ����� ��� ��������������
    string GetPhone(); // ����� ��������� ��������
    string GetYear(); // ����� ��������� ���� ��������
    void Set(); // ����� ��������� ��������
    void Change(); // ����� �������������� ��������

    friend ostream& operator<< (ostream& stream, Note& n); // ���������� ��������� �����������
    friend istream& operator>> (istream& stream, Note& n); // ���������� ��������� �������
};

#endif