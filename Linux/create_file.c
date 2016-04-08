#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fp = open("./create.txt", O_CREAT | O_WRONLY, 0660);
	write(fp, "test message!", 14);
	close(fp);
	return 0;
}
