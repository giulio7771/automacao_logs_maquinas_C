Num ambiente de uma fábrica onde há máquinas têxteis que geram informações sobre suas operações, você é solicitado para gerar programas que auxiliem 
na análise do funcionamento da planta da fábrica, manutenções das máquinas e outras análises de funcionamento e produção.

Uma máquina gera um arquivo com informações (log) no formato de linhas de texto agrupando as seguintes informações em cada linha: { longint momento, int duracao, int operacao, int status }

{ 62215, 40, 1, 0 }
{ 62217, 22, 2, 1 }
{ 62218, 10, 3, 2 }

- momento (dia*10000+hora*100+minuto) é o momento de início da operação, onde dia é o número do dia no ano, hora é a hora desse dia, minuto é o minuto dessa hora;

- duracao é o tempo em minutos que a operacao levou para ser concluída ou apresentar erro;

- operacao pode ser:

1 - operação de carregar matéria-prima 1;

2 - operação de carregar matéria-prima 2;

3 - operação de carregar matéria-prima 3;

4 - operação de processo de secagem;

5 - operação de processo de lavagem; ou

6 - operação de processo de tingimento;

- status pode ser:

0 - operação bem sucedida;

1 - sobrecarga leve;

2 - sobrecarga com probabilidade de dano; ou

3 - parada por erro de funcionamento;

Faça um programa em C que leia o arquivo de log da máquina (disponível abaixo) até o fim e gere as seguintes informações
f) Nos dias pares, quantas vezes a máquina foi carregada com a matéria-prima 1 no período da manhã;
o) Gere um vetor para armazenar os status que aconteceram por hora considerando todos os dias (o índice do vetor indica a hora do dia) e depois grave em um arquivo no formato: hora status qtd_de_vezes;



