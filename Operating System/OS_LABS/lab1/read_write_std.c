#include<stdio.h>
#include<unistd.h>
int main()
{
	write(1,"Enter total 10 bytes of data: ",30);
	char buffered_input[10];
	read(0,buffered_input,10);
	write(1, "Stored buffer is: ",18);
	write(1,buffered_input,10);
	write(1,"\n",1);
	return 0;
}
