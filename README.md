# Projeto de LPR1 (Linguagem de Programação 1)

## Grupo

- Luis Miguel dos Santos Solera [GitHub](https://github.com/LMSolera) 
- Henrique Chaves Duarte  [GitHub](https://github.com/cDuarte05)

## Estrutura Planejada do Projeto

Nosso objetivo é criar um sistema que auxilie o usuário na obtenção de estimativas de investimentos, a partir de valores e escolhas realizadas pelo usuário. As informações principais que utilizamos são:

- **Valor inicial:** O dinheiro com o qual o usuário irá começar seus investimentos.
- **Incremento mensal:** O valor que o usuário irá adicionar aos investimentos a cada mês.
- **Duração do investimento:** Por quanto tempo o usuário pretende investir.
- **Tipo de investimento:** O nível de risco que o usuário deseja assumir, podendo ser:
  - **Seguro:** Sempre há lucro todos os meses, porém baixo.
  - **Intermediário:** Possibilidade de maior lucro do que no método seguro em um determinado mês, mas também pode não haver mudança.
  - **Arriscado:** Potenciais maiores lucros, mas também a chance de perder dinheiro em um determinado mês.

Com base nos valores fornecidos pelo usuário e sua escolha de método, o sistema fornecerá uma estimativa dos investimentos.

## Fluxograma da Lógica do Algoritmo

Visualize o fluxo de trabalho do algoritmo https://lucid.app/lucidspark/ece3760a-5c34-4450-ae97-5e90dfd345a3/edit?viewport_loc=-6842%2C483%2C10144%2C4821%2C0_0&invitationId=inv_b273f0ca-4d49-4bb6-96a7-a88ed648ea44 

## Nosso Código

O código será composto, inicialmente, por funções para facilitar a organização das partes do algoritmo. As funções planejadas são:

- **Introdução:** Apresenta o nome do software e, interagindo com o usuário, define um nome para ele.
- **Obtenção de Valores:** Obtém os valores necessários para os cálculos por meio da interação com o usuário.
- **Cálculo e Apresentação:** Realiza o cálculo do valor final a partir das informações e escolhas fornecidas pelo usuário, e apresenta esse valor ao usuário.
- **Armazenamento de Resultados:** Cria um arquivo onde os valores obtidos após o cálculo serão armazenados, caso o usuário deseje.
