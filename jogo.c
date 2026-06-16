#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VIDA_INICIAL 100
#define ATAQUE_BASE 15
#define BONUS_VANTAGEM 10
#define PENALIDADE_DESVANTAGEM 5

#define FOGO 0
#define TERRA 1
#define RAIO 2
#define AGUA 3
#define AR 4

#define TRUE 1
#define FALSE 0

typedef struct {
    char nome[20];
    char elemento[10];
    int tipo;
    int vida;
    int ataque;
} Animal;

//Tipo de retorno
void func(/*parametros da funcao*/) //Assinatura
//Corpo da funcao:
{

}

void mostrarMenu();
void mostrarRegras();
void mostrarCriaturas(Animal criaturas[]);
int escolherCriatura();
int verificarVantagem(int atacante, int defensor);
int calcularDano(Animal atacante, Animal defensor);
void batalha(Animal jogador, Animal computador);

int main() {

    srand(time(NULL));

    Animal criaturas[5] = {
        {"Pyronix", "Fogo", FOGO, VIDA_INICIAL, ATAQUE_BASE},
        {"Terragor", "Terra", TERRA, VIDA_INICIAL, ATAQUE_BASE},
        {"Voltigar", "Raio", RAIO, VIDA_INICIAL, ATAQUE_BASE},
        {"Aquarion", "Agua", AGUA, VIDA_INICIAL, ATAQUE_BASE},
        {"Aerofin", "Ar", AR, VIDA_INICIAL, ATAQUE_BASE}
    };

    int opcao;

    do {

        mostrarMenu();
        scanf("%d", &opcao);

        switch(opcao) {

            case 1: {

                mostrarCriaturas(criaturas);

                int escolhaJogador = escolherCriatura() - 1;
                int escolhaComputador = rand() % 5;

                Animal jogador = criaturas[escolhaJogador];
                Animal computador = criaturas[escolhaComputador];

                printf("\nVoce escolheu %s (%s)\n",
                       jogador.nome,
                       jogador.elemento);

                printf("Computador escolheu %s (%s)\n",
                       computador.nome,
                       computador.elemento);

                batalha(jogador, computador);

                break;
            }

            case 2:
                mostrarRegras();
                break;

            case 3:
                printf("\nSaindo do jogo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 3);

    return 0;
}

void mostrarMenu() {

    printf("\n===== GUERRA ELEMENTAL =====\n");
    printf("1 - Jogar\n");
    printf("2 - Regras\n");
    printf("3 - Sair\n");
    printf("Escolha: ");
}

void mostrarRegras() {

    printf("\n===== REGRAS =====\n");

    printf("Fogo vence Terra\n");
    printf("Terra vence Raio\n");
    printf("Raio vence Agua\n");
    printf("Agua vence Ar\n");
    printf("Ar vence Fogo\n");

    printf("\nCada criatura possui 100 pontos de vida.\n");
    printf("A batalha acontece em turnos.\n");
    printf("Quem zerar a vida do adversario vence.\n");
}

void mostrarCriaturas(Animal criaturas[]) {

    printf("\n===== ESCOLHA SUA CRIATURA =====\n");

    for(int i = 0; i < 5; i++) {

        printf("%d - %s (%s)\n",
               i + 1,
               criaturas[i].nome,
               criaturas[i].elemento);
    }
}

int escolherCriatura() {

    int escolha;

    do {

        printf("\nEscolha uma criatura: ");
        scanf("%d", &escolha);

        if(escolha < 1 || escolha > 5) {
            printf("Opcao invalida!\n");
        }

    } while(escolha < 1 || escolha > 5);

    return escolha;
}

int verificarVantagem(int atacante, int defensor) {

    switch(atacante) {

        case FOGO:
            return defensor == TERRA;

        case TERRA:
            return defensor == RAIO;

        case RAIO:
            return defensor == AGUA;

        case AGUA:
            return defensor == AR;

        case AR:
            return defensor == FOGO;
    }

    return 0;
}

int calcularDano(Animal atacante, Animal defensor) {

    int dano = atacante.ataque;

    if(verificarVantagem(atacante.tipo, defensor.tipo)) {

        dano += BONUS_VANTAGEM;

    } else if(verificarVantagem(defensor.tipo, atacante.tipo)) {

        dano -= PENALIDADE_DESVANTAGEM;
    }

    return dano;
}

void batalha(Animal jogador, Animal computador) {

    int acaoJogador;
    int defesaJogador;
    int defesaComputador;

    while(jogador.vida > 0 && computador.vida > 0) {

        defesaJogador = 0;
        defesaComputador = 0;

        printf("\n========================\n");
        printf("%s: %d HP\n", jogador.nome, jogador.vida);
        printf("%s: %d HP\n", computador.nome, computador.vida);

        printf("\n1 - Atacar\n");
        printf("2 - Defender\n");
        printf("Escolha: ");
        scanf("%d", &acaoJogador);

        if(acaoJogador == 1) {

            int dano = calcularDano(jogador, computador);

            computador.vida -= dano;

            printf("\n%s causou %d de dano!\n",
                   jogador.nome,
                   dano);

        } else {

            defesaJogador = 1;

            printf("\n%s entrou em defesa!\n",
                   jogador.nome);
        }

        if(computador.vida <= 0) {
            break;
        }

        int acaoComputador = rand() % 2 + 1;

        if(acaoComputador == 1) {

            int dano = calcularDano(computador, jogador);

            if(defesaJogador) {
                dano /= 2;
            }

            jogador.vida -= dano;

            printf("%s causou %d de dano!\n",
                   computador.nome,
                   dano);

        } else {

            defesaComputador = 1;

            printf("%s entrou em defesa!\n",
                   computador.nome);
        }
    }

    printf("\n========================\n");

    if(jogador.vida > 0) {

        printf("VOCE VENCEU!\n");

    } else {

        printf("VOCE PERDEU!\n");
    }
}

/*
Modificar o jogo Elementos para suportar o modo aventura
No modo aventura o jogador percorre um mundo aleatoriamente
e Eventos de encontros aleatorios acontem periodicamente

1. O jogador pode encontrar uma criatura selvagem
    1. O jogador pode derrotar a criatura
    2. O jogador pode fugir da criatura
    3. O jogador pode capturar a criatura para usar ela posteriormente
2. O jogador pode encontrar um treinador aleatorio
    1. O jogador PRECISA derrotar o treinador

A quantidade de encontros que o jogador tera que resolver (sendo esses, 
encontros com criaturas selvagens ou treinadores) fica a criterio do dev.

Mudancas na batalha
O jogador antes de entrar em batalha pode escolher entre 3 criaturas que ele 
possui. O jogador sempre comeca com 1 criatura.
*/

//ESTADO