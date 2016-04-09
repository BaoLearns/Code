#include <iostream>
#include <tuple>
#include <bits/stdc++.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main()
{
    /*tuple <int, int , string, double ,float> t(1, 2, "LL", 1.5, 0.5);
    auto st = get<1>(t);
    cout << st << endl;
    typedef decltype(t) T;
    auto i = tuple_size<T> :: value;
    cout << i << endl;
    tuple_element<1, T> :: type cnt = get<1>(t);  // get<1>(t);
    cout << cnt << endl;
    decltype*/
    int gdriver = DETECT, gmode, errorcode;
    int midx, midy;
    int radis = 100;
    initgraph(&gdriver, &gmode,"");
    errorcode = graphresult();
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    setcolor(getmaxcolor());
    circle(midx, mdiy, radius);
    closegraph();
    return 0;
}
