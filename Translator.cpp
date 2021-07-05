#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "HeaderTranslator.h"
#define MAX 300

const char* one[] = { " один", " два", " три", " чотири", " п'€ть", " шiсть", " сiм", " вiсiм", " дев'€ть" };
const char* tro[] = { " одинадц€ть", " дванадц€ть", " тринадц€ть", " чотирнадц€ть", " п'€тнадц€ть", " шiстнадц€ть", " сiмнадц€ть", " вiсiмнадц€ть", " дев'€тнадц€ть" };
const char* ten[] = { " двадц€ть", " тридц€ть", " сорок", " п'€тдес€т", " шiстдес€т", " сiмдес€т", " вiсiмдес€т", " дев'€носто" };
const char* hundred[] = { " сто", " двiстi", " триста", " чотириста", " п'€тсот", " шiстсот", " сiмсот", " вiсiмсот", " дев'€тсот" };
const char* thousand[] = { " одна тис€ча", " двi тис€чi", " три тис€чi", " чотири тис€чi", " п'€ть тис€ч", " шiсть тис€ч", " сiм тис€ч", " вiсiм тис€ч", " д'ев€ть тис€ч" };
const char* million[] = { " один мiльйон", " два мiльйони", " три мiльйони", " чотири мiльйони", " п'€ть мiльйонiв", " шiсть мiльйонiв", " ciм мiльйонiв", " вiсiм мiльйонiв", " дев'€ть мiльйонiв" };
const char* miliard[] = { " один мiль€рд", " два мiль€рдa", "три мiль€рдa", " чотири мiль€рдa", " п'€ть мiль€рдiв", " шiсть мiль€рдiв", " ciм мiль€рдiв", " вiсiм мiль€рдiв", " дев'€ть мiль€рдiв" };


bool translator(double  number, char* link)
{
    int g, h, k, m, n, t, v, d, a, j;   //"тимчасов≥" перем≥нн≥ дл€ ц≥лих
    const char* odin = "", * dva = "", * tri = "", * chetiri = "", * pyat = "", * shest = "", * sem = "", * vosem = "", * devat = "", * desat = "", * odinad = "";//дл€ ц≥лих
    const char* minus = "";
    int natural;
    link[0] = 0;

    if (number < -2147483647 || number > 2147483647)
    {
        printf(" ¬аше число поза дiапазоном ");
        return false;
    }

    if (number < 0)
    {
        minus = "мiнус";
        number *= -1;
    }

    natural = (int)number;

    //разбиваем число на составные цифры дл€ целой части
    g = natural % 10;                 //число одиниць
    h = (natural % 100) / 10;         //число дес€тк≥в
    k = (natural % 1000) / 100;       //число сотень
    m = (natural % 10000) / 1000;    //число тис€ч
    n = (natural % 100000) / 10000;   //число дес€тков тис€ч
    t = (natural % 1000000) / 100000; //число сотень тис€
    v = (natural % 10000000) / 1000000;   // число мiльйонiв
    d = (natural % 100000000) / 10000000; // число дес€тк≥в мiлiонiв
    a = (natural % 1000000000) / 100000000;  // число сотень мiлiонiв
    j = (natural % 10000000000) / 1000000000; // число м≥ль€рдiв

    //нуль
    if (g == 0 && h == 0 && k == 0 && m == 0 && n == 0 && t == 0)
        odin = "нуль";

    // 1-10
    if (g != 0 && h != 1)
        odin = one[g - 1];
    else if (g == 0 && h == 1)
        odin = "дес€ть";
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
        pyat = "дес€ть тис€ч";
    else if (m != 0 && n == 1 && n != 0)
        pyat = strcat(_strdup(tro[m - 1]), " тис€ч");

    // 20 000-99 999
    if (n != 0 && n != 1 && m == 0)
        pyat = strcat(_strdup(ten[n - 2]), " тис€ч");
    else if (n != 0 && n != 1 && m != 0)
        pyat = ten[n - 2];

    // 100 000-999 999
    if (t != 0 && n == 0 && m == 0)
        shest = strcat(_strdup(hundred[t - 1]), " тис€ч");
    else if (t != 0)
        shest = hundred[t - 1];

    // 1 000 000-9 999 999
    if (v != 0 )
        sem = million[v - 1];

    // 10 000 000
    if (d == 1 && v == 0)
        sem = " дес€ть мiльйонiв";

    // 11 000 000-19 999 999
    else if (d == 1 && d != 0 && v != 0)
        sem = strcat(_strdup(tro[v - 1]), " мiльйонiв");

    // 20 000 000-99 999 999
    else if (d != 0 && d != 1 && v == 0)
        sem = strcat(_strdup(ten[d - 2]), " мiльйонiв");
    else if (d != 0 && d != 1 && v != 0)
        vosem = ten[d - 2];

        // 100 000 000- 999 999 999
        if (a == 1 && d == 0 && v == 0)
            devat = "сто мiльйонiв";
        else if (a != 0 && d == 0 && v == 0)
            devat = strcat(_strdup(hundred[a - 1]), " мiльйонiв");
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