#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>	
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <ctime>
#include <iostream>
#include <time.h>//necessário p/ função time()
#define fila 18
#define coluna 22
using namespace std;
int main()
{/*====================================================================
					variaves
========================================================================*/
	int poltrona[22][18];
	int Caso_cadeira, i, j, n, m, fil = 19, col = 23, condi, x = 0, y = 0, l;
	char livre = 48, ocupado = 88, pref = 80, t, f, c[2];
	int a = 0, b = 0;
	/*====================================================================
				comando para utilização de data e hora
	========================================================================*/
	time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	int dia = horarioLocal->tm_mday, mes = horarioLocal->tm_mon + 1, ano = horarioLocal->tm_year + 1900;
	int hora = horarioLocal->tm_hour, min = horarioLocal->tm_min, sec = horarioLocal->tm_sec;
	/*====================================================================
			definição das cadeiras entre lives ocupadas e preferenciais
	========================================================================*/
	for (i = 0; i < coluna; i++)
	{
		if (i >= 20) {
			for (j = 0; j < fila; j++)
			{
				poltrona[i][j] = 1;
			}
		}
		else
		{
			for (j = 0; j < fila; j++)
			{
				poltrona[i][j] = 0;
			}
		}
	}
	for (i = 9; i <= 19; i++)
	{
		for (j = 8; j <= 9; j++)
		{
			poltrona[i][j] = 2;
		}
	}//*/
/*====================================================================
	  inicio do codigo para a escolha
========================================================================*/
	do
	{ //tela de inicio 
		system("CLS");//comando de limpar a tela
		printf("[1] - Escolher Cadeira\n");
		printf("[2] - Cancelar cadeira\n");
		printf("[3] - Sorteio\n\n");
		printf("[0] - Fechar \n\n");
		scanf("%d", &Caso_cadeira);//escolhae as opções acima 

		switch (Caso_cadeira)
		{
		case 0:
			break;

		case 1: //Escolher Cadeira
			do {
				system("CLS");
				/*====================================================================
					   escreve a tabela com os acentos
				========================================================================*/
				n = 0;
				printf("                                    Colunas\n");//22
				printf("\n\t    A  B  C  D  E  F  G  H  I     J  K  L  M  N  O  P  Q  R\n");//18
				for (i = 0; i < coluna; i++)
				{
					if (n == 11)
					{
						printf(" Filas\t%2d ", n);
						n++;
					}
					else
					{
						printf("\t");
						printf("%2d ", n);
						n++;
					}
					for (j = 0; j < fila; j++)
					{

						if (poltrona[i][j] == 0)
						{
							if (j != 9)
							{
								printf(" %c ", livre);
							}
							else
							{
								printf("   ");
								printf(" %c ", livre);

							}
						}
						if (poltrona[i][j] == 1)
						{
							if (j != 9)
							{
								printf(" %c ", ocupado);
							}
							else
							{
								printf("   ");
								printf(" %c ", ocupado);

							}
						}
						if (poltrona[i][j] == 2)
						{
							if (j != 9)
							{
								printf(" %c ", pref);
							}
							else
							{
								printf("   ");
								printf(" %c ", pref);

							}
						}
					}

					printf("\n");
				}
				printf("\n                                    palco");
				printf("\n--------------------------------------------------------------------------------\n");
				printf("  \t%c = Livre\n  \t%c = Ocupado\n  \t%c = Preferencial\n\n", livre, ocupado, pref); //legenda

	/*====================================================================
		   escolher os acentos
	========================================================================*/
				do
				{
					fil = 19;
					col = 23;
					m = 0;
					y = 0;
					printf("Digite seu E-mail:\n ");
					scanf("%s", &m);
					printf("escolha o numero da Fila e aperte enter:\n ");
					scanf("%d", &col);
					printf("escolha a letra da Coluna e aperte enter:\n ");
					scanf("%s", &f);
					if (f <= 's' || f <= 'S') {
						if (f == 'a' || f == 'A') {
							fil = 0;
						}
						if (f == 'b' || f == 'B') {
							fil = 1;
						}
						if (f == 'c' || f == 'C') {
							fil = 2;
						}
						if (f == 'd' || f == 'D') {
							fil = 3;
						}
						if (f == 'e' || f == 'E') {
							fil = 4;
						}
						if (f == 'f' || f == 'F') {
							fil = 5;
						}
						if (f == 'g' || f == 'G') {
							fil = 6;
						}
						if (f == 'h' || f == 'H') {
							fil = 7;
						}
						if (f == 'i' || f == 'I') {
							fil = 8;
						}
						if (f == 'j' || f == 'J') {
							fil = 9;
						}
						if (f == 'k' || f == 'K') {
							fil = 10;
						}
						if (f == 'l' || f == 'L') {
							fil = 11;
						}
						if (f == 'm' || f == 'M') {
							fil = 12;
						}
						if (f == 'n' || f == 'N') {
							fil = 13;
						}
						if (f == 'o' || f == 'O') {
							fil = 14;
						}
						if (f == 'p' || f == 'P') {
							fil = 15;
						}
						if (f == 'q' || f == 'Q') {
							fil = 16;
						}
						if (f == 'r' || f == 'R') {
							fil = 17;
						}
					}
					else
					{
						fil = 20;
					}//*/
					if (fil < fila && col < coluna)
					{
						if (poltrona[col][fil] == 0 || poltrona[col][fil] == 2)
						{
							poltrona[col][fil] = 1;
							// -----------------ticket-----------------------------------
							cout << "\n\nHorario: " << hora << ":" << min << ":" << sec << endl;// escreve a hora
							cout << "Data: " << dia << "/" << mes << "/" << ano << endl;//escreve a data 
							printf("cadeira escolida Fila:%d coluna:%c\n", col, f);// escreve qual foi o asento escolido 
							printf("Email: %s    \n", &m);// escreve qual E-mail foi escolhido
							printf("Escolher outra cadeira S/N \n");
							scanf("%s", &t);
							if (t == 's' || t == 'S')
							{
								y = 1;
								break;
							}
						}
						else
						{
							printf("******ATENCAO CADEIRA OCUPADA******\n");
							printf("**********Tente de novo**********\n");
							x = 1;
						}
					}
					else
					{
						printf("******CADEIRA INEXISTENTE******\n");
						printf("**********Tente de novo**********\n");
						x = 1;
					}
				} while (x != 0);
			} while (y != 0);
			break;

		case 2: //cancelar cadeiras
			system("CLS");
			printf("O que deseja fazer?\n");
			printf("[1] - Cancelar uma cadeira?\n");
			printf("[2] - Cancelar todas as cadeiras?\n");
			scanf("%d", &condi);
			if (condi == 1)
			{
				printf("\nnumero da fila: ");
				scanf("%d", &col);
				printf("\nletra da coluna: ");
				scanf("%d", &f);

				if (fil <= fila && col <= coluna)
				{
					poltrona[col][fil] = 0;
				}
				else
				{
					printf("******CADEIRA INEXISTENTE******\n");
				}
			}
			else
				for (i = 0; i < 20; i++)
				{
					for (j = 0; j < fila; j++)
					{
						poltrona[i][j] = 0;
					}
				}
			printf("\n-------------------------------------------------------------\n");
			break;

		case 3:
			system("CLS");
			do {
				l = 0;
				c[2] = '0';
				printf("quantos numeros deve ser sorteado\n ");
				scanf("%2d", &l);
				srand(time(NULL));
				for (i = 1; i <= l; i++) {
					a = rand() % 19;
					b = rand() % coluna;
					if (a == 0) {
						c[2] = 'A';
					}
					if (a == 1) {
						c[2] = 'B';
					}
					if (a == 2) {
						c[2] = 'C';
					}
					if (a == 3) {
						c[2] = 'D';
					}
					if (a == 4) {
						c[2] = 'E';
					}
					if (a == 5) {
						c[2] = 'F';
					}
					if (a == 6) {
						c[2] = 'G';
					}
					if (a == 7) {
						c[2] = 'H';
					}
					if (a == 8) {
						c[2] = 'I';
					}
					if (a == 9) {
						c[2] = 'J';
					}
					if (a == 10) {
						c[2] = 'K';
					}
					if (a == 11) {
						c[2] = 'L';
					}
					if (a == 12) {
						c[2] = 'M';
					}
					if (a == 13) {
						c[2] = 'N';
					}
					if (a == 14) {
						c[2] = 'O';
					}
					if (a == 15) {
						c[2] = 'P';
					}
					if (a == 16) {
						c[2] = 'Q';
					}
					if (a == 17) {
						c[2] = 'R';
					}

					printf("\t  coluna:  %1s\n", &c[2]);
					printf("\t  fileira: %1d\n\n ", b);
				}
				printf("teminhar o sorteio s/n?");
				scanf("%s", &t);
				if (t == 'S' || t == 's')
				{
					break;
				}
			} while (y != 1);
			break;

		default:
			break;

		}



	} while (Caso_cadeira != 0);
	//system("pause");
	return(0);
}

