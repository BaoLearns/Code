#include <iostream>
#define Pii pair<double, double>
#define Pow(x, y) (((x) - (y)) * ((x) - (y)))
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(int I = 1; I <= T; ++I)
    {
        Pii a[4];
        for(int i = 0; i < 4; ++i)
            scanf("%lf%lf", &a[i].first, &a[i].second);
        printf("Case #%d: ", I);
        Pii mid1 = Pii((a[0].first + a[2].first) / 2, (a[0].second + a[2].second) / 2);
        Pii mid2 = Pii((a[1].first + a[3].first) / 2, (a[1].second + a[3].second) / 2);
        double s1 = Pow(a[0].first, a[1].first) + Pow(a[0].second, a[1].second);
        double s2 = Pow(a[0].first, a[3].first) + Pow(a[0].second, a[3].second);
        double s3 = Pow(a[1].first, a[3].first) + Pow(a[1].second, a[3].second);
        if(mid1 == mid2)
        {
            if(s1 + s2 != s3 && s1 != s2) printf("Parallelogram");
            else if(s1 + s2 == s3 && s1 != s2) printf("Rectangle");
            else if(s1 + s2 == s3 && s1 == s2) printf("Square");
            else printf("Diamond");
        }
        else printf("Others");
        putchar('\n');
    }
    return 0;
}
