#include <stdio.h>
/**
 * Declare a pointer variable
 * Open file using fopen()
 * Process the file using the suitable function
 * Close the file using fclose()
*/
int main()
{
	FILE *fp; /*Declare a pointer*/

	fp = fopen("filename.txt", "w");
	//Processing
	fprintf(fp, "%s", "Hello World");
	// End of processing
	fclose(fp);
	return (0);
}