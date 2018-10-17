/* P3.c */
/* Gabriel Nogueira Nico */
/* 11811EEL012 */

#include <stdio.h>

int main()
{
	char numero[256];
	int i, resultado = 0, potencia = 1;
	scanf("%s", numero);
	for(i = 0; numero[i] != '\0'; i++);
	i--;
	while(i > -1)
	{
		if(numero[i] >= '0' && numero[i] <= '9')
		{
			resultado = resultado + (numero[i] - 48) * potencia;
			i--;
			potencia = potencia * 10;
		}
		else
			i--;
	}
	printf("\n%d", resultado);
}
