#define _CRT_SECURE_NO_WARNINGS
#include "HeaderTranslator.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>
#define MAX 300


using namespace std;

bool translator(double  number, const char* link);

int main()
{
    setlocale(LC_ALL, "ukr");
    bool isRange;
    double  number; // ����� �� �������
    const char* minus = ""; //����
    int natural;          //������� ��� ������ � ������ � ���������
    char link[MAX];
   

    printf("����i�� �����: ");
    scanf_s("%lg", &number);

    isRange = translator(number, link);

    if (isRange == false) 
    {
        return 0;
    }
    printf("%s",link);
    }

    