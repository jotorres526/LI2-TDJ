#include "data.h"
/*******************Manipulação de COORDENADA******************/
// Recebe uma coluna e uma linha e retorna uma coordenada
COORDENADA setCoordenada(int line, int col) {
    COORDENADA c;
    c.coluna = col;
    c.linha = line;
    return c;
}

int getColuna(COORDENADA c) {
    return c.coluna;
}

int getLinha(COORDENADA c) {
    return c.linha;
}

/*******************Manipulação de JOGADA******************/
//Retorna a jogada idx + 1
JOGADA getJogada(ESTADO *e, int idx) {
    return e->jogadas[idx];
}

//Recebe as coordenadas do jogador1 e do jogador2 respetivamente para criar uma nova jogada
JOGADA setJogada(COORDENADA c1, COORDENADA c2) {
    JOGADA jog; 
    jog.jogador1.coluna = c1.coluna;
    jog.jogador1.linha = c1.linha;
    jog.jogador2.coluna = c2.coluna;
    jog.jogador2.linha = c2.linha;
    return jog;
}

//Retorna a ultima jogada 
COORDENADA getUltimaJogada (ESTADO *e) {
    return e->ultima_jogada;
}

//Recebe o estado atual e uma coordenada
//Altera a ultima_jogada do estado para a nova coordenada
void setUltimaJogada(ESTADO *e, COORDENADA c1) {
    e -> ultima_jogada = setCoordenada(c1.linha, c1.coluna);
}

//Recebe:
    //O estado atual
    //Uma jogada
//Adiciona a jogada a lista de jogadas e incrementa o numero de jogadas
void addToJogadas(ESTADO *e, JOGADA j) {
    if(e->num_jogadas < 32) e->jogadas[e->num_jogadas++] = j;
}

//Retorna o numero de jogadas efetuadas(Cada jogada tem o movimento dos dois jogadores)
int getNumJogadas(ESTADO *e) {
    return e->num_jogadas;
}


/*******************Manipulação de CASA******************/
//Retorna o estado atual da casa na coordenada c (Branca, Preta ou Vazia)
CASA getCasa(ESTADO *e, COORDENADA c) {
    return e->tab[c.linha][c.coluna];
}

CASA getCasa_parametro(ESTADO *e, int x,int y) {
    return e->tab[x][y];
}

//Recebe:  
    //O estado atual
    //1 coordenada do tabuleiro
    //1 casa que pode ser: {VAZIO, BRANCA, PRETA}
//Altera o tabuleiro na coordenada 'c' com o valor de 'casa'
void setCasa(ESTADO *e, COORDENADA c, CASA casa) {
    e->tab[c.linha][c.coluna] = casa;
}

/*******************Manipulação de jogador******************/
//Recebe o estado atual
//Troca o jogador atual
    //Se o jogador atual for o 1 troca para o jogador 2
    //Caso contrario troca para o jogador 1
void swapJogador(ESTADO *e) {
    if(e->jogador_atual == 1) {
        e->jogador_atual = 2;
    }
    else e->jogador_atual = 1;
}
// Função que retorna o jogador atual que vai jogar
int getjogador(ESTADO *e) {
    return e->jogador_atual;
}
/*******************Inicializacao******************/
//Inicializa o estado do jogo
//A peça branca começa na coluna 4 da linha 4 e considera se essa a ultima jogada
//Todo o resto do tabuleiro é inicializado a VAZIO
//O tabuleiro é representado por um array bidimensional do tipo tab[linha][coluna]
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    COORDENADA pecaBranca = setCoordenada(4, 4);
    COORDENADA c;
    setUltimaJogada(e, pecaBranca);
    FORI(8) 
        FORJ(8) {
            c = setCoordenada(i, j);
            setCasa(e, c, VAZIO);
        }
    setCasa(e, pecaBranca, BRANCA);
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    setCasa(e,setCoordenada(7, 7),DOIS);
    setCasa(e,setCoordenada(0, 0),UM);
    return e;
}