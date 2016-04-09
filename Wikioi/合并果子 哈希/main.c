#include <stdio.h>
#include <stdlib.h>
int s[100000000]={0};
int main()
{
    int n,i,j,x;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&x);
        s[x]++;
    }
    int sum=0;
    int cnt=n;
    int flag;
    while(cnt!=1)
    {
        flag=1;
        for(i=1;flag;++i)
        {
            if(s[i])
                {
                    --s[i];
                    for(j=i;flag;++j)
                        {
                            if(s[j])
                            {
                                ++s[i+j];
                                --s[j];
                                sum=sum+i+j;
                                --cnt;
                                flag=0;

                                }
                            }
                }
        }
    }
    printf("%d\n",sum);
    return 0;
}
