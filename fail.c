#include <stdio.h>

//{ longint momento, int duracao, int operacao, int status }
void main() {
    char *filename = "Maq1.log";
    FILE *fp = fopen(filename, "r");

    printf("carregando o arquivo Maq1.log");
    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }
    printf("arquivo carregado!");

    char ch;
    int stage = 0;
    int i = 0;
    char item[100000];
    int item_count = 0;

    char m[100000][100];
    int ml = 0; //matriz linha
    int mc; // matriz coluna
    int ml_max = 0;
    int mc_max[100000];
    while ((ch = fgetc(fp)) != EOF) {
        //putchar(ch);
        if (ch == '\n') {
            mc = 0;
            ml = ml + 1;
            ml_max = ml_max + 1;
        }
        if (ch == ',') {
            char new_item[item_count];
            int nic = 0;
            while (nic < item_count) {
                new_item[nic] = item[nic];
                //putchar(new_item[nic]);
                printf("passou");
            }
            //x = atoi(str2);
            m[ml][mc] = ch;
            item_count = 0;
        }
        item[item_count] = ch;
        item_count = item_count + 1;




        /*if (ch == '\n') { // se chegou ao final da linha
            stage = 0;
            item_count = 0;
            continue;
        }

        if (stage == 0) {
            if (ch == ',') {
                 printf("%d", i);

            }

        } else if (stage == 1) {
        } else if (stage == 2) {
        } else if (stage == 3) {
        }*/

        i = i + 1;

    }


    fclose(fp);

    return 0;
}
