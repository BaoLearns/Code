/*����һ���������������D
  ����I��С��
  ÿ�����1�ڵ㿪ʼ�ƶ������˽ڵ��ֵΪ0ʱ��������ƶ������������ƶ�
  ��ʼʱ�����нڵ��ֵ��Ϊ0����С���߹��˽ڵ�󣬻�ı䵱ǰ��״̬
  �����һ��С�����ڵĽڵ�ֵ
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int arr[1<<20];
int main()
{
    int D,I,i,j;
    while(scanf("%d%d",&D,&I))
    {
        memset(arr,0,sizeof(arr));
        for(i=1;i<=I;++i)
        {
            for(j=1;j<pow(2,D);)
            {
                arr[j]=!arr[j];
                if(arr[j])
                    j=j*2;
                else
                    j=j*2+1;
            }
        }
        printf("%d\n",j/2);
    }
    return 0;
}
