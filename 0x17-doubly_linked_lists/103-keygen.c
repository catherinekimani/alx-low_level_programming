#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generate and print password.
 * @argc: no. of args.
 * @argv: an arr.
 *
 * Return: 0 SUCCESS.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char password[7], *key;
	int length = strlen(argv[1]), idx, tmp_val;

	key = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	tmp_val = (length ^ 59) & 63;
	password[0] = key[tmp_val];

	tmp_val = 0;
	for (idx = 0; idx < length; idx++)
		tmp_val += argv[1][idx];
	password[1] = key[(tmp_val ^ 79) & 63];

	tmp_val = 1;
	for (idx = 0; idx < length; idx++)
		tmp_val *= argv[1][idx];
	password[2] = key[(tmp_val ^ 85) & 63];

	tmp_val = 0;
	for (idx = 0; idx < length; idx++)
	{
		if (argv[1][idx] > tmp_val)
			tmp_val = argv[1][idx];
	}
	srand(tmp_val ^ 14);
	password[3] = key[rand() & 63];

	tmp_val = 0;
	for (idx = 0; idx < length; idx++)
		tmp_val += (argv[1][idx] * argv[1][idx]);
	password[4] = key[(tmp_val ^ 239) & 63];

	for (idx = 0; idx < argv[1][0]; idx++)
		tmp_val = rand();
	password[5] = key[(tmp_val ^ 229) & 63];

	password[6] = '\0';
	printf("%s", password);
	return (0);
}
