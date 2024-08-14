// Bibliotecas usadas
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <malloc.h>




// Variáveis globais
FILE *fp;
char usuario[25];
int meses,contador,opc,opc2;
float inicial,investimento, acresmensal, variacao,*porcentagem;




// Função da tela inicial para definir o usuario
void definirus () {
    printf(" __________________________________________________________________\n");
    printf("|                                                                  |\n");
    printf("|                                                                  |\n");
    printf("|                   BEM VINDO, nós somos a ******.                 |\n");
    printf("|                                                                  |\n");
    printf("|     Iremos calcular como andarão seus investimentos.             |\n");
    printf("|                                                                  |\n");
    printf("|                                                                  |\n");
    printf("|__________________________________________________________________|\n\n");
    printf("Por favor, para começarmos, digite seu nome -> ");
    gets (usuario);
    printf ("Olá %s, espero que aproveite nosso conteúdo.\n",usuario);
}




// Função para sabermos sobre o investimento
void perguntas () {
    printf ("Digite por quantos meses você pretende investir\n > ");
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
    // Caso o usuário erre a entrada na escolha do alcance de risco
    start:
    printf ("Insira a faixa de risco desejada: \n(Esses valores representam variações mensais)\n");
    printf ("1 - Seguro = 0.4%% a 1%%\n");
    printf ("2 - Intermediário = 0%% a 2%%\n");
    printf ("3 - Arriscado = -9%% a 11%%\n");
    scanf ("%d",&opc);
    if (opc != 1 && opc != 2 && opc != 3) {
        system ("cls");
        printf ("Opção inválida!\n");
        goto start;
    }
    confirmacao: // A próxima sessão pode realizar um loop onde voltar para esse ponto é importante
    system ("cls");
    printf ("As informações inseridas são as seguintes:\n");
    printf ("Incremento mensal = R$ %.2f\n",acresmensal);
    printf ("Valor inicial = R$ %.2f\n",investimento);
    printf ("Tempo observado: %d meses\n",meses);
    switch (opc) {
        case 1:
            printf ("Faixa de risco segura (0.4%% a 1%%)\n\n");
            break;
        case 2:
            printf ("Faixa de risco intermediária (0%% a 2%%)\n\n");
            break;
        case 3:
            printf ("Faixa de risco arriscada (-9%% a 11%%)\n\n");
            break;
    } 
    printf ("Você quer prosseguir com essas informações?\n 1 - Sim \n 2 - Não \n >> ");
    scanf ("%d",&opc2);
    switch (opc2) { // Checar se o usuário tem certeza das escolhas que fez
        case 1:
            break; // Se tiver, fecha o switch
        case 2: // Se não, abre as oportunidades de edição
            alterar: // Caso o usuário erre o valor da escolha
            system ("cls");
            printf ("Qual valor você quer alterar?\n");
            printf ("1 - Incremento Mensal\n",acresmensal);
            printf ("2 - Valor Inicial\n",investimento);
            printf ("3 - Tempo observado\n",meses);
            printf ("4 - Faixa de risco\n >> ");
            scanf ("%d",&opc2);
            switch (opc2) {
                case 1:
                    system ("cls");
                    printf ("Insíra o novo incremento mensal (Em R$): ");
                    scanf ("%f",&acresmensal);
                    break;
                case 2:
                    system ("cls");
                    printf ("Insíra o novo valor incial (Em R$): ");
                    scanf ("%f",&investimento);
                    break;
                case 3:
                    system ("cls");
                    free(porcentagem);
                    printf ("Insíra o novo tempo para observação: ");
                    scanf ("%d",&meses);
                    porcentagem = (float*)malloc(sizeof(float) * meses);
                    contador = meses;
                    break;
                case 4:
                    repeti: // Repeti essa pergunta para o caso do usuário errar a escolha
                    system ("cls");
                    printf ("Insira a faixa de risco desejada: \n(Esses valores representam variações mensais)\n");
                    printf ("1 - Seguro = 0.4%% a 1%%\n");
                    printf ("2 - Intermediário = 0%% a 2%%\n");
                    printf ("3 - Arriscado = -9%% a 11%%\n");
                    scanf ("%d",&opc);
                    if (opc != 1 && opc != 2 && opc != 3) {
                        printf ("Opção inválida!\n");
                        goto repeti;
                    }
                    break;
                default:
                    printf ("Opção inválida!\n");
                    goto alterar;
                    break;
            }
            goto confirmacao;
            break;
        default:
            printf ("Opção inválida");
            goto confirmacao;
    }
}


//Função dos cálculos matemáticos 
void contas () { 
    switch (opc) {
        case 1:
            while (meses > 0) {
            variacao = (rand()%7) + 4; // Pegar uma variação entre 4 e 10
            variacao = 1 + (variacao / 1000);
            porcentagem[meses - 1] = variacao;
            investimento = investimento + acresmensal;
            investimento = investimento * variacao;
            meses--;
            }
            break;




        case 2:
            while (meses > 0) {
            variacao = (rand()%21); // Pegar uma variação entre 0 e 20
            variacao = 1 + (variacao / 1000);
            porcentagem[meses - 1] = variacao;  
            investimento = investimento + acresmensal;
            investimento = investimento * variacao;
            meses--;
            }
            break;
   
        case 3:
            while (meses > 0) {
            variacao = (rand()%201) - 90; // Pegar uma variação entre -90 e 110
            variacao = 1 + (variacao / 1000);
            porcentagem[meses - 1] = variacao;  
            investimento = investimento + acresmensal;
            investimento = investimento * variacao;
            meses--;
            }
            break;
    }
}




void resultado () { // Mostra todas as informações obtidas e utilizadas anteriormente
    printf ("\nValor inicial = R$ %.2f\n",inicial);
    printf ("Incremento mensal = R$ %.2f (Totalizou R$ %.2f)\n",acresmensal,acresmensal*contador);
    printf ("Número de meses simulados = %d meses\n\n",contador);
    printf ("Valor vindo de %s = R$ %.2f\n",usuario,(acresmensal*contador)+inicial);
    printf ("Valor rendido = R$ %.2f\n\n",investimento-((acresmensal*contador) + inicial));
    printf ("Valor final = R$ %.2f\n\n",investimento);
}




void porcentagens () { // Função que mostra quais foram as porcentagens utilizadas nos cálculos
    for (meses = 0; meses < contador; meses++) {
        porcentagem[meses] = (porcentagem[meses] - 1) * 100;
        printf ("Mês %d = %.2f%%\n",meses+1,porcentagem[meses]);
    }
}




void exportResultado () { // Transfere todas as informações do resultao + data atual para um arquivo txt (Isso, sob a escolha do usuário)
    time_t t;
    time(&t);
    fp = fopen ("resultados.txt","a");
    fprintf (fp,"Cálculos realizados em: %s",ctime(&t));
    fprintf (fp,"Resultados do Usuário : %s\n\n",usuario);
    fprintf (fp,"Valor inicial = R$ %.2f\n",inicial);
    fprintf (fp,"Incremento mensal = R$ %.2f (Totalizou R$ %.2f)\n",acresmensal,acresmensal*contador);
    fprintf (fp,"Número de meses simulados = %d meses\n\n",contador);
    fprintf (fp,"Valor vindo de %s = R$ %.2f\n",usuario,(acresmensal*contador)+inicial);
    fprintf (fp,"Valor rendido = R$ %.2f\n\n",investimento-((acresmensal*contador) + inicial));
    fprintf (fp,"Valor final = R$ %.2f\n\n",investimento);
    for (meses = 0; meses < contador; meses++) {
        fprintf (fp,"Mês %d = %.2f%%\n",meses+1,porcentagem[meses]);
    }
    fclose(fp);
}




// Função main
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
    export: // Para caso a pessoa erre a entrada no questionamento de exportação
    printf ("\nVocê deseja exportar seus resultados?\n1 - Sim\n2 - Não\n >> ");
    scanf ("%d",&opc);
    switch (opc) { // Sessão que checa se o usuário quer ou não exportar as informações
        case 1:
            exportResultado();
            printf ("Pronto! Obrigado pelo uso! (Cheque o diretório do software)\n");
            break;
        case 2:
            printf ("Obrigado pelo uso!\n");
            break;
        default:
            printf ("Opção inválida!");
            goto export;
    }
    free(porcentagem);
system("pause");
}
