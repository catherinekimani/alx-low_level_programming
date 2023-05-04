#include <stdio.h>
int main()
{
	//File handling part two
	FILE *fp; /*Pointer variable*/
	char ch[100];
	fp = fopen("filename.txt","r");
	printf("%s", fgets(ch,50,fp));
	fclose(fp);
	return (0);
}