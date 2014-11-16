#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
int main (int argc, char *argv[] ){
	FILE* ptr=fopen(argv[1], "rt");
	int i=0;
	double sum=0;
	double count=0;
	double ave=0;
	if (ptr == NULL)
	{	perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	while(1)
	{ 
		int s;
		while((s=fgetc(ptr)) != ',' && s != EOF){
		printf("%c", s);
		}

		if(s == EOF)
			break;
		printf("\t");
		count = sum = 0;
		while(1==fscanf(ptr, "%d%*c", &i)) // skip , and \n
	{
	sum += i;
	count++;
}
	ave= sum/count;
	printf("%.2f\n", ave);
}
fclose(ptr);
return 0;
}
