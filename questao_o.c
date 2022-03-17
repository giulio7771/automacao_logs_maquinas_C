#include <stdio.h>
#include <conio.h>

//{ longint momento, int duracao, int operacao, int status }
void main() {
    char *filename = "Maq1.log";
    FILE *fp = fopen(filename, "r");

    printf("\ncarregando o arquivo Maq1.log");
    if (fp == NULL) {
        printf("\nErro ao carregar o arquivo %s", filename);
        return 1;
    }
    printf("\narquivo carregado!");

    char lines_char[10000][30];
    int lci = 0; // lines char count
    int lcj = 0; // lines char column
    int lcj_max[10000]; // numero de caracteres da linha

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            //printf("\n\nlinha: %d", lci);
            lcj_max[lci] = lcj; // armazenando o numero de caracteres da linha lci
            lcj = 0; // resetar indice da coluna
            lci = lci + 1; // proxima linha
            continue;
        }
        //printf("\n lcj: %d caracter:", lcj);
        //putchar(ch);
        lines_char[lci][lcj] = ch;
        lcj = lcj + 1; // proxima column
    }

    //printf("\nnumero de linhas: %d \n", lci + 1);
    int i = 0;

    int status_0[23];
    int status_1[23];
    int status_2[23];
    int status_3[23];

    int h = 0;
    while (h < 23) {
        status_0[h] = 0;
        status_1[h] = 0;
        status_2[h] = 0;
        status_3[h] = 0;
        h = h+1;
    }

    int numero_carregamentos_materia_prima_tipo_1 = 0;
    while (i <= lci) {
        int j = 0;
        //printf("\nlinha: %d \n", i);

        int stage = 0; //posicao entre as virgulas 10000,45,1,1 (45 - posicao 1)

        char duracao[10];
        char operacao;
        char status;

        int virgula1;
        int virgula2;
        int virgula3;
        while (j <= lcj_max[i]) {
            char a = lines_char[i][j];
            int z = 0;
            if (a == ',') {
                if (stage == 0) {
                    virgula1 = j;
                } else if (stage == 1) {
                    virgula2 == j;
                    operacao = lines_char[i][j+1]; // imediatamente apos a segunda virgula encontra-se a operacao
                } else if (stage == 2) {
                    virgula3 = j;
                    status = lines_char[i][j+1]; // // imediatamente apos a segunda virgula encontra-se o status
                }
                stage = stage+1;
            }

            //putchar(a);
            j = j + 1;
        }

        //obter momento posicao 0 ate posicao da virgula1
        int z = 0;
        char momento[virgula1-1];
        while (z < virgula1) {
            momento[z] = lines_char[i][z];
            char a = lines_char[i][z];
            //putchar(a);
            z = z + 1;
        }
        int momento_int = atoi(momento);
        int momento_int_calc = momento_int;
        int minuto = momento_int % 100;
        momento_int_calc = momento_int_calc - minuto;

        int resto_dez_mil = momento_int_calc % 10000;
        int hora =  resto_dez_mil / 100;
        //printf("\nhora: %d", hora);

        int dia = (momento_int_calc - resto_dez_mil) / 10000;

        if (operacao == '1' && hora < 12 && (dia % 2 == 0)) {
            numero_carregamentos_materia_prima_tipo_1 = numero_carregamentos_materia_prima_tipo_1 + 1;
            //printf("carregamento contabilizado! - %d", numero_carregamentos_materia_prima_tipo_1);
        }


         if (status == '0') {
            status_0[hora] = status_0[hora]+1;
        } else if (status == '1') {
            status_1[hora] = status_1[hora]+1;
        } else if (status == '2') {
            status_2[hora] = status_2[hora]+1;
        } else if (status == '3') {
            status_3[hora] = status_3[hora]+1;
        }

        i = i+1;
    }
    //int y = status_1[11];
    //printf("status hora %d ", y);


    fclose(fp);

    FILE *arq;
    int result;
    char Str[50];

    arq = fopen("saida.txt", "a");

    if (arq == NULL)
    {
        printf("\nProblemas na CRIACAO do arquivo de saida\n");
        return;
    }

    //strcpy(Str,"Linha de teste1");
    //result = fputs(Str, arq);


    int g = 0;
    while (g<=23) {
        result = fprintf(arq,"%d,%d,%d\n",g,0, status_0[g]);
        result = fprintf(arq,"%d,%d,%d\n",g,1, status_1[g]);
        result = fprintf(arq,"%d,%d,%d\n",g,2, status_2[g]);
        result = fprintf(arq,"%d,%d,%d\n",g,3, status_3[g]);

        if (result == EOF) {
            printf("\nErro na Gravacao\n");
        }

        g = g+1;
    }


    fclose(arq);

    return 0;
}
