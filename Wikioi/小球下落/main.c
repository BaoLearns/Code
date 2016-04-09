/*给定一个满二叉树的深度D
  给定I个小球
  每个球从1节点开始移动，当此节点的值为0时就往左边移动，否则往右移动
  初始时，所有节点的值都为0，当小球走过此节点后，会改变当前的状态
  求最后一个小球所在的节点值
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
