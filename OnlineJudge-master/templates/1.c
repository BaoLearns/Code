#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, i;
	while(scanf("%d%d", &a, &b) != EOF){
		printf("%d  \n", a + b);
	}
	for(i = 0; i < 1000; ++i){
		void *pt = (void *)malloc(10000);	
	}
	return 0;
}
