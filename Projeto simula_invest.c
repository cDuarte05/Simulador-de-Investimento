// Bibliotecas usadas
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <malloc.h>




// Vari�veis globais
FILE *fp;
char usuario[25];
int meses,contador,opc,opc2;
float inicial,investimento, acresmensal, variacao,*porcentagem;




// Fun��o da tela inicial para definir o usuario
void definirus () {
    printf(" __________________________________________________________________\n");
    printf("|                                                                  |\n");
    printf("|                                                                  |\n");
    printf("|                   BEM VINDO, n�s somos a ******.                 |\n");
    printf("|                                                                  |\n");
    printf("|     Iremos calcular como andar�o seus investimentos.             |\n");
    printf("|                                                                  |\n");
    printf("|                                                                  |\n");
    printf("|__________________________________________________________________|\n\n");
    printf("Por favor, para come�armos, digite seu nome -> ");
    gets (usuario);
    printf ("Ol� %s, espero que aproveite nosso conte�do.\n",usuario);
}




// Fun��o para sabermos sobre o investimento
void perguntas () {
    printf ("Digite por quantos meses voc� pretende investir\n > ");
    scanf ("%d",&meses);
    porcentagem = (float*)malloc(sizeof(float) * meses);
    contador = meses; //Guardando os valores de meses para uso futuro
    system ("cls");
    printf ("Insira a quantia que pretende inserir de dinheiro mensalmente (Em R$)\n > ");
    scanf ("%f",&acresmensal);
    system ("cls");
    printf ("Insira o valor inicial de investimento (Em R$)\n > ");
    scanf ("%f",&investimento);
    inicial = investimento; //Guardando o valor do investimento para uso futuro
    system ("cls");
    // Caso o usu�rio erre a entrada na escolha do alcance de risco
    start:
    printf ("Insira a faixa de risco desejada: \n(Esses valores representam varia��es mensais)\n");
    printf ("1 - Seguro = 0.4%% a 1%%\n");
    printf ("2 - Intermedi�rio = 0%% a 2%%\n");
    printf ("3 - Arriscado = -9%% a 11%%\n");
    scanf ("%d",&opc);
    if (opc != 1 && opc != 2 && opc != 3) {
        system ("cls");
        printf ("Op��o inv�lida!\n");
        goto start;
    }
    confirmacao: // A pr�xima sess�o pode realizar um loop onde voltar para esse ponto � importante
    system ("cls");
    printf ("As informa��es inseridas s�o as seguintes:\n");
    printf ("Incremento mensal = R$ %.2f\n",acresmensal);
    printf ("Valor inicial = R$ %.2f\n",investimento);
    printf ("Tempo observado: %d meses\n",meses);
    switch (opc) {
        case 1:
            printf ("Faixa de risco segura (0.4%% a 1%%)\n\n");
            break;
        case 2:
            printf ("Faixa de risco intermedi�ria (0%% a 2%%)\n\n");
            break;
        case 3:
            printf ("Faixa de risco arriscada (-9%% a 11%%)\n\n");
            break;
    } 
    printf ("Voc� quer prosseguir com essas informa��es?\n 1 - Sim \n 2 - N�o \n >> ");
    scanf ("%d",&opc2);
    switch (opc2) { // Checar se o usu�rio tem certeza das escolhas que fez
        case 1:
            break; // Se tiver, fecha o switch
        case 2: // Se n�o, abre as oportunidades de edi��o
            alterar: // Caso o usu�rio erre o valor da escolha
            system ("cls");
            printf ("Qual valor voc� quer alterar?\n");
            printf ("1 - Incremento Mensal\n",acresmensal);
            printf ("2 - Valor Inicial\n",investimento);
            printf ("3 - Tempo observado\n",meses);
            printf ("4 - Faixa de risco\n >> ");
            scanf ("%d",&opc2);
            switch (opc2) {
                case 1:
                    system ("cls");
                    printf ("Ins�ra o novo incremento mensal (Em R$): ");
                    scanf ("%f",&acresmensal);
                    break;
                case 2:
                    system ("cls");
                    printf ("Ins�ra o novo valor incial (Em R$): ");
                    scanf ("%f",&investimento);
                    break;
                case 3:
                    system ("cls");
                    free(porcentagem);
                    printf ("Ins�ra o novo tempo para observa��o: ");
                    scanf ("%d",&meses);
                    porcentagem = (float*)malloc(sizeof(float) * meses);
                    contador = meses;
                    break;
                case 4:
                    repeti: // Repeti essa pergunta para o caso do usu�rio errar a escolha
                    system ("cls");
                    printf ("Insira a faixa de risco desejada: \n(Esses valores representam varia��es mensais)\n");
                    printf ("1 - Seguro = 0.4%% a 1%%\n");
                    printf ("2 - Intermedi�rio = 0%% a 2%%\n");
                    printf ("3 - Arriscado = -9%% a 11%%\n");
                    scanf ("%d",&opc);
                    if (opc != 1 && opc != 2 && opc != 3) {
                        printf ("Op��o inv�lida!\n");
                        goto repeti;
                    }
                    break;
                default:
                    printf ("Op��o inv�lida!\n");
                    goto alterar;
                    break;
            }
            goto confirmacao;
            break;
        default:
            printf ("Op��o inv�lida");
            goto confirmacao;
    }
}


//Fun��o dos c�lculos matem�ticos 
void contas () { 
    switch (opc) {
        case 1:
            while (meses > 0) {
            variacao = (rand()%7) + 4; // Pegar uma varia��o entre 4 e 10
            variacao = 1 + (variacao / 1000);
            porcentagem[meses - 1] = variacao;
            investimento = investimento + acresmensal;
            investimento = investimento * variacao;
            meses--;
            }
            break;




        case 2:
            while (meses > 0) {
            variacao = (rand()%21); // Pegar uma varia��o entre 0 e 20
            variacao = 1 + (variacao / 1000);
            porcentagem[meses - 1] = variacao;  
            investimento = investimento + acresmensal;
            investimento = investimento * variacao;
            meses--;
            }
            break;
   
        case 3:
            while (meses > 0) {
            variacao = (rand()%201) - 90; // Pegar uma varia��o entre -90 e 110
            variacao = 1 + (variacao / 1000);
            porcentagem[meses - 1] = variacao;  
            investimento = investimento + acresmensal;
            investimento = investimento * variacao;
            meses--;
            }
            break;
    }
}




void resultado () { // Mostra todas as informa��es obtidas e utilizadas anteriormente
    printf ("\nValor inicial = R$ %.2f\n",inicial);
    printf ("Incremento mensal = R$ %.2f (Totalizou R$ %.2f)\n",acresmensal,acresmensal*contador);
    printf ("N�mero de meses simulados = %d meses\n\n",contador);
    printf ("Valor vindo de %s = R$ %.2f\n",usuario,(acresmensal*contador)+inicial);
    printf ("Valor rendido = R$ %.2f\n\n",investimento-((acresmensal*contador) + inicial));
    printf ("Valor final = R$ %.2f\n\n",investimento);
}




void porcentagens () { // Fun��o que mostra quais foram as porcentagens utilizadas nos c�lculos
    for (meses = 0; meses < contador; meses++) {
        porcentagem[meses] = (porcentagem[meses] - 1) * 100;
        printf ("M�s %d = %.2f%%\n",meses+1,porcentagem[meses]);
    }
}




void exportResultado () { // Transfere todas as informa��es do resultao + data atual para um arquivo txt (Isso, sob a escolha do usu�rio)
    time_t t;
    time(&t);
    fp = fopen ("resultados.txt","a");
    fprintf (fp,"C�lculos realizados em: %s",ctime(&t));
    fprintf (fp,"Resultados do Usu�rio : %s\n\n",usuario);
    fprintf (fp,"Valor inicial = R$ %.2f\n",inicial);
    fprintf (fp,"Incremento mensal = R$ %.2f (Totalizou R$ %.2f)\n",acresmensal,acresmensal*contador);
    fprintf (fp,"N�mero de meses simulados = %d meses\n\n",contador);
    fprintf (fp,"Valor vindo de %s = R$ %.2f\n",usuario,(acresmensal*contador)+inicial);
    fprintf (fp,"Valor rendido = R$ %.2f\n\n",investimento-((acresmensal*contador) + inicial));
    fprintf (fp,"Valor final = R$ %.2f\n\n",investimento);
    for (meses = 0; meses < contador; meses++) {
        fprintf (fp,"M�s %d = %.2f%%\n",meses+1,porcentagem[meses]);
    }
    fclose(fp);
}




// Fun��o main
void main () {
    srand ((unsigned) time (NULL)); // Para sempre deixar os resultados do rand() diferentes
    setlocale(LC_ALL,"Portuguese");
    system ("cls");  
    definirus();
    perguntas();
    system ("cls");
    contas();
    porcentagens();
    resultado();
    export: // Para caso a pessoa erre a entrada no questionamento de exporta��o
    printf ("\nVoc� deseja exportar seus resultados?\n1 - Sim\n2 - N�o\n >> ");
    scanf ("%d",&opc);
    switch (opc) { // Sess�o que checa se o usu�rio quer ou n�o exportar as informa��es
        case 1:
            exportResultado();
            printf ("Pronto! Obrigado pelo uso! (Cheque o diret�rio do software)\n");
            break;
        case 2:
            printf ("Obrigado pelo uso!\n");
            break;
        default:
            printf ("Op��o inv�lida!");
            goto export;
    }
    free(porcentagem);
system("pause");
}
