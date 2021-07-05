#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "HeaderTranslator.h"
#define MAX 300

const char* one[] = { " ����", " ���", " ���", " ������", " �'���", " �i���", " �i�", " �i�i�", " ���'���" };
const char* tro[] = { " ����������", " ����������", " ����������", " ������������", " �'���������", " �i���������", " �i��������", " �i�i��������", " ���'���������" };
const char* ten[] = { " ��������", " ��������", " �����", " �'�������", " �i�������", " �i������", " �i�i������", " ���'������" };
const char* hundred[] = { " ���", " ��i��i", " ������", " ���������", " �'�����", " �i�����", " �i����", " �i�i����", " ���'�����" };
const char* thousand[] = { " ���� ������", " ��i �����i", " ��� �����i", " ������ �����i", " �'��� �����", " �i��� �����", " �i� �����", " �i�i� �����", " �'����� �����" };
const char* million[] = { " ���� �i�����", " ��� �i������", " ��� �i������", " ������ �i������", " �'��� �i�����i�", " �i��� �i�����i�", " ci� �i�����i�", " �i�i� �i�����i�", " ���'��� �i�����i�" };
const char* miliard[] = { " ���� �i�����", " ��� �i�����a", "��� �i�����a", " ������ �i�����a", " �'��� �i�����i�", " �i��� �i�����i�", " ci� �i�����i�", " �i�i� �i�����i�", " ���'��� �i�����i�" };


bool translator(double  number, char* link)
{
    int g, h, k, m, n, t, v, d, a, j;   //"��������" ������� ��� �����
    const char* odin = "", * dva = "", * tri = "", * chetiri = "", * pyat = "", * shest = "", * sem = "", * vosem = "", * devat = "", * desat = "", * odinad = "";//��� �����
    const char* minus = "";
    int natural;
    link[0] = 0;

    if (number < -2147483647 || number > 2147483647)
    {
        printf(" ���� ����� ���� �i�������� ");
        return false;
    }

    if (number < 0)
    {
        minus = "�i���";
        number *= -1;
    }

    natural = (int)number;

    //��������� ����� �� ��������� ����� ��� ����� �����
    g = natural % 10;                 //����� �������
    h = (natural % 100) / 10;         //����� �������
    k = (natural % 1000) / 100;       //����� ������
    m = (natural % 10000) / 1000;    //����� �����
    n = (natural % 100000) / 10000;   //����� �������� �����
    t = (natural % 1000000) / 100000; //����� ������ ����
    v = (natural % 10000000) / 1000000;   // ����� �i�����i�
    d = (natural % 100000000) / 10000000; // ����� ������� �i�i��i�
    a = (natural % 1000000000) / 100000000;  // ����� ������ �i�i��i�
    j = (natural % 10000000000) / 1000000000; // ����� ������i�

    //����
    if (g == 0 && h == 0 && k == 0 && m == 0 && n == 0 && t == 0)
        odin = "����";

    // 1-10
    if (g != 0 && h != 1)
        odin = one[g - 1];
    else if (g == 0 && h == 1)
        odin = "������";
    else if (g == 0 && h == 0)
        odin = "";

    // 11-99
    if (h == 0)
        dva = "";
    else if (h == 1 && g != 0)
        dva = tro[g - 1];
    else if (h != 1)
        dva = ten[h - 2];

    // 100-999
    if (k != 0)
        tri = hundred[k - 1];

    // 1 000-19 999
    if (m != 0 && n != 1)
        chetiri = thousand[m - 1];
    else if (m == 0 && n == 1)
        pyat = "������ �����";
    else if (m != 0 && n == 1 && n != 0)
        pyat = strcat(_strdup(tro[m - 1]), " �����");

    // 20 000-99 999
    if (n != 0 && n != 1 && m == 0)
        pyat = strcat(_strdup(ten[n - 2]), " �����");
    else if (n != 0 && n != 1 && m != 0)
        pyat = ten[n - 2];

    // 100 000-999 999
    if (t != 0 && n == 0 && m == 0)
        shest = strcat(_strdup(hundred[t - 1]), " �����");
    else if (t != 0)
        shest = hundred[t - 1];

    // 1 000 000-9 999 999
    if (v != 0 )
        sem = million[v - 1];

    // 10 000 000
    if (d == 1 && v == 0)
        sem = " ������ �i�����i�";

    // 11 000 000-19 999 999
    else if (d == 1 && d != 0 && v != 0)
        sem = strcat(_strdup(tro[v - 1]), " �i�����i�");

    // 20 000 000-99 999 999
    else if (d != 0 && d != 1 && v == 0)
        sem = strcat(_strdup(ten[d - 2]), " �i�����i�");
    else if (d != 0 && d != 1 && v != 0)
        vosem = ten[d - 2];

        // 100 000 000- 999 999 999
        if (a == 1 && d == 0 && v == 0)
            devat = "��� �i�����i�";
        else if (a != 0 && d == 0 && v == 0)
            devat = strcat(_strdup(hundred[a - 1]), " �i�����i�");
        else if (a != 0)
            desat = hundred[a - 1];

    // 1 000 000 000-2 147 483 647
    if (j != 0)
        odinad = miliard[j - 1];

    strcat(link, minus);
    strcat(link, odinad);
    strcat(link, desat);
    strcat(link, devat);
    strcat(link, vosem);
    strcat(link, sem);
    strcat(link, shest);
    strcat(link, pyat);
    strcat(link, chetiri);
    strcat(link, tri);
    strcat(link, dva);
    strcat(link, odin);

}