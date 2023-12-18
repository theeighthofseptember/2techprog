#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include "Note.h"

using namespace std;

class Store
{
private:
    Note** array; // ������ ��� �������� ��������
    int countElement; // ���-�� ���������

public:
    Store(); // ����������� �� ���������
    Store(int size); // ����������� � ����������
    Store(const Store& s); // ����������� �����������
    ~Store(); // ����������

    void SortedArray(); // ���������� ����� �����
    void FindYear(); // ����� �� ������ ������
    void ExtractField(); // ������� �������� �������
    void GetFiel(); // �������� ����
    void Set(); // �������� �������� �������
    void Change(); // �������� ��������
    void Delete(); // ������� �������
};

#endif