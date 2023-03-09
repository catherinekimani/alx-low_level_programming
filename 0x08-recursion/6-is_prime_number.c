#include "main.h"

/**
 * is_prime_number - check if a number is a prime number
 * @n: int number
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	int check_prime(int n_divider, int n);

	int n_divider = 2;

	if (n < 2)
	{
		return (0);
	}
	if (n % n == 0 || n % 1 == 0)
	{
		if (check_prime(n_divider, n) != 0)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}

/**
 * check_prime - helper function to determine if a number is prime
 * @n: number given to original function is_prime
 * @n_divider: incrementer divisor
 * Return: 0 if not prime, 1 if prime
 */
int check_prime(int n_divider, int n)
{
	if (n_divider < n)
	{
		if (n % n_divider == 0)
		{
			return (0);
		}
		else
		{
			++n_divider;
			return (check_prime(n_divider, n));
		}
	}
	else
	{
		return (1);
	}
}
