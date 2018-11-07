/* P5.c */
/* Gabriel Nogueira Nico */
/* 11811EEL012 */

#include <stdio.h>

typedef
	unsigned long long int
Bytes8;
typedef
	struct LCG { Bytes8 a, c, m, rand_max, atual; }
LCG;

void semente(LCG * r, Bytes8 seed)
{
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) 
{
	r->atual = (r->a * r->atual + r->c) % r->m;
	return r->atual;
}

double lcg_rand_01(LCG * r) 
{
	return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r)
{
	int i;
	for(i = 0; i < tam; i++)
		vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float soma(float *inicio_vetor, float *fim_vetor)
{
	if(fim_vetor == inicio_vetor)
		return *inicio_vetor;
	else
		return *(fim_vetor--) + soma(inicio_vetor, fim_vetor--);
}

float produto(float *inicio_vetor, float *fim_vetor)
{
	if(fim_vetor == inicio_vetor)
		return *inicio_vetor;
	else
		return *(fim_vetor--) * produto(inicio_vetor, fim_vetor--);	
}

int main ()
{
	LCG random;	semente(&random, 123456);
	int opcao, N = 50;
	float vetor[50];
	gera_numeros(vetor, N, 0.5, 1.5, &random);
	printf("1 - Somatorio\n2 - Produtorio\n\n");
	printf("Serao gerados 50 numeros aleatorios\nOpcao: ");
	scanf("%d", &opcao);
	getchar();
	opcao == 1 ? printf("\n%f", soma(&vetor[0], &vetor[49])) : printf("\n%f", produto(&vetor[0], &vetor[49]));
	return 0;	
}
