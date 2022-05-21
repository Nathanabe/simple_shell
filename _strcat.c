#include "main.h"

/**
 * *_strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int srcn, destn;
	int i;

	srcn = 0;
	destn = 0;

	while (*(dest + destn))
		destn++;
	while (*(src + srcn))
		srcn++;
	for (i = destn; i <= (destn + srcn); i++)
		*(dest + i) = *(src + (i - destn));
	return (dest);
}
