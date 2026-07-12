#include "multithreading.h"
#include <stdlib.h>

/**
 * prime_factors - factors a number into a list of prime factors
 * @s: string representation of the number to factor
 * Return: list_t of prime factors
 **/
list_t *prime_factors(char const *s)
{
	unsigned long n = strtoul(s, NULL, 10);
	unsigned long *tmp, p;
	unsigned long delta = 2;
	list_t *list = malloc(sizeof(list_t));

	list_init(list);
	for (p = 2; p <= 3; p++)
	{
		while (n % p == 0)
		{
			tmp = malloc(sizeof(unsigned long));
			*tmp = p;
			list_add(list, (void *)tmp);
			n /= p;
		}
	}

	/* 6k +- 1 wheel: only test candidates coprime to 2 and 3 */
	for (p = 5; p * p <= n; p += delta, delta = 6 - delta)
	{
		while (n % p == 0)
		{
			tmp = malloc(sizeof(unsigned long));
			*tmp = p;
			list_add(list, (void *)tmp);
			n /= p;
		}
	}

	if (n >= 2)
	{
		tmp = malloc(sizeof(unsigned long));
		*tmp = n;
		list_add(list, (void *)tmp);
	}
	return (list);
}
