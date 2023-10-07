#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include<string>
using namespace std;

float win;                              // win (window), vai definir o tamanho de cada viewport (quanto maior valor de win, mais longe da tela)
float aspecto;                          // aspecto: variável para controlar windowsize
int largura, altura;                    //largura e altura da minha janela
GLfloat movx1 = 0, movy1 = 0;           // variáveis de movimentação para x e y respectivo ao jogador 1
GLfloat movx2 = 0, movy2 = 0;           // variáveis de movimentação para x e y respectivo ao jogador 2
GLfloat mov = 0;
int jogadores = 1;                      //variavel que representa a quantidade de jogadores na partida
int seed;                               //variavel usada para iniciar a localização aleatoria das rochas
int cont_t = 0;                         //variavel que conta o tempo para aumenytar a velocidade
int timer = 600;                        //variavel que starta o tempo e acelera a velocidade do jogo
int passo = 3;                          //passo usado para a movimentação do carro
                                        //vetor que contem todas as cores usadas apenas no carro 1
float coresC1[15] = {0,0,0,0.86,0.86,0.86,1,0.46,0.09,1,0.46,0.09,1,0.55,0};
                                        //vetor que contem todas as cores usadas apenas no carro 2
float coresC2[15] = {0,0,0,0.86,0.86,0.86,1,0.46,0.09,1,0.46,0.09,1,0.55,0};
GLfloat r = 0, g = 0, b = 0;            //variaveis usadas para pegar a cor selecionada e armazena la no array
int subMenuCor;                         //variavel para controle do menu cor
int SubMenuPar_car, partC;              //variavel para controle do menu de parte do carro
int mousex;                             //posição do mouse
int colisao1 = 3, coli1 = 6;                       //essa é a variavel que controla a quantidade de colisões possiveis para cada jogador
int colisao2 = 3, coli2 = 6;                       //essa é a variavel que controla a quantidade de colisões possiveis para cada jogador
int comeca = 0;                         //variavel que vai iniciar o jogo


int randomiza(int quan, int lim){       //função que randomiza valores, que tem como entrada o range de numeros necessarios e o segundo paramentro é delimitar os possiveis numeros gerados
    int semente;
    return semente = lim + rand()%quan;
}

void timerPonto(int passo){                //função timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
    if(comeca == 1){
        mov+=1;
        cont_t++;
    }
    if(mov == 140){
        mov = 0;
        cout << "Passou aqui no rezeta mov";
        seed = randomiza(30, 5);
        int NP = randomiza(2,0);            //variavel que verifica se a semente utilizada será positiva ou negativa
                                        //se randomiza for 0 a semente sera positiva, o contrario sera negativa
        if(NP == 1)
            seed = -seed;
    }
    switch(cont_t){
        case 15:
        case 25:
        case 35:
        case 45:
        case 55: timer-=100;
            break;
        case 65:
        case 100:
        case 180:
        case 300:
        case 400:
        case 500:
        case 700:
        case 900:
        case 1100: timer-=10;
        break;
    }
    glutPostRedisplay();
    glutTimerFunc(timer,timerPonto,1);
}

//INICIO DO BLOCO DE PRIMITIVAS QUE UNIADAS FORMAM A FIGURA COMPLETA DE UM CARRO
void corp_car_t(){
    glLineWidth(5);
    glBegin(GL_QUADS);
        glVertex2f(-2.0, -3.0);
        glVertex2f(-2.0, 3.0);
        glVertex2f(2.0, 3.0);
        glVertex2f(2.0, -3.0);
    glEnd();
}

void aerofolio(){                                   //forma o aerofolio do carro
    glLineWidth(5);
    glBegin(GL_QUADS);
        glVertex2f(-3.0, -4.0);
        glVertex2f(-3.0, -2.0);
        glVertex2f(3.0, -2.0);
        glVertex2f(3.0, -4.0);
    glEnd();
}

void corp_car_f(){                                  //forma o corpo frontal do carro(capô e parachoque frontal)
    glLineWidth(5);
    glBegin(GL_TRIANGLES);
        glVertex2f(-1.0, 3.0);
        glVertex2f(0.0, 8.0);
        glVertex2f(1.0, 3.0);
    glEnd();
}

void eixo_f(){                                      //forma o eixo frontal o carro
    glLineWidth(5);
    glBegin(GL_QUADS);
        glVertex2f(-2.0, 5.0);
        glVertex2f(-2.0, 6.0);
        glVertex2f(2.0, 6.0);
        glVertex2f(2.0, 5.0);
    glEnd();
}

void r_s_e(){                                       //roda superior esquerda
    glLineWidth(5);
    glBegin(GL_QUADS);
        glVertex2f(-4.0, 4.0);
        glVertex2f(-4.0, 7.0);
        glVertex2f(-2.0, 7.0);
        glVertex2f(-2.0, 4.0);
    glEnd();
}

void r_s_d(){                                       //roda superior direita
    glLineWidth(5);
    glBegin(GL_QUADS);
        glVertex2f(2.0, 4.0);
        glVertex2f(2.0, 7.0);
        glVertex2f(4.0, 7.0);
        glVertex2f(4.0, 4.0);
    glEnd();
}

void r_i_e(){                                       //roda inferior esquerda
    glLineWidth(5);
    glBegin(GL_QUADS);
        glVertex2f(-4.0, -3.0);
        glVertex2f(-4.0, 0.0);
        glVertex2f(-2.0, 0.0);
        glVertex2f(-2.0, -3.0);
    glEnd();
}

void r_i_d(){                                       //roda inferior direita
    glLineWidth(5);
    glBegin(GL_QUADS);
        glVertex2f(2.0, -3.0);
        glVertex2f(2.0, 0.0);
        glVertex2f(4.0, 0.0);
        glVertex2f(4.0, -3.0);
    glEnd();
}
//FIM DO BLOCO DE PRIMITIVAS QUE UNIADAS FORMAM A FIGURA COMPLETA DE UM CARRO
void contorno(){                            //função que gera o contorno em volta da janela
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glColor3f(0,0,0);
        glVertex2f(-win*aspecto, -win);     //inferior esquerdo
        glVertex2f(-win*aspecto, win);      //superior esquerdo
        glVertex2f(win*aspecto, win);       //superior direito
        glVertex2f(win*aspecto, -win);      //inferior direito
    glEnd();
}

void asfalto(){                         //primitivas que formal o asfalto
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex2f(-100, -100);
        glVertex2f(-100, 100);
        glVertex2f(100,100);
        glVertex2f(100, -100);
    glEnd();
}

void linha_as(){                        //linha pontilhada do asfalto
    int x = 100;
    glLineWidth(6);
    glColor3f(1, 1, 0);
    while(x != -100){
        glBegin(GL_LINES);
            glVertex2f(0, x);
            x-=5;
            glVertex2f(0, x);
            x-=5;
        glEnd();
    }
}

void pedra(){                           //primitivas que formam a rocha usada como obstaculo da corrida
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_POLYGON);
        glVertex2f(-11, -5);
        glVertex2f(-10, -2);
        glVertex2f(-7, -1);
        glVertex2f(-6, -2);
        glVertex2f(-4, 1);
        glVertex2f(-3, 2);
        glVertex2f(-2, 0);
        glVertex2f(-1, 0);
        glVertex2f(1, -5);
    glEnd();
}

void coracao(){                             //forma um coração que simboliza a vida do carro
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(0.0,-3.0);
        glVertex2f(-2.0,-1.0);
        glVertex2f(-2.0,0.0);
        glVertex2f(-1.0,1.0);
        glVertex2f(0.0,0.0);
        glVertex2f(1.0,1.0);
        glVertex2f(2.0,0.0);
        glVertex2f(2.0,-1.0);
    glEnd();
}

bool colisao(int x1, int y1, int lar1, int alt1, int x2, int y2, int lar2, int alt2){   //função de colisão, os 4 primeiros parametros são respectivos a rochas e os 4 ultimos ao carro
    if(((x1 < (x2 + lar2)) && ((x1 + lar1) > x2)) && ((y1 < (y2 + alt2)) && ((y1 + alt1) > y2)))
        return true;
    return false;
                                    //Para essa função foi desenvolvidas duas maneiras de gerar a colisão entre pedra e carro
    /*
    int deltax = abs(x1-x2);
    int deltay = abs(y1-y2);
    int l, a;
    if(x1 < x2)
        l = lar1;
    else
        l = lar2;
    if(y1 < y2)
        a = alt1;
    else
        a = alt2;
    if((deltax >= l) || (deltay >= a))
        return false;
    return true;*/
}

void DesenhaTexto(void *font, char *string){            //função usada para imprimir um texto na tela
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*string++);
}

void desenhaObjetos(void){                                  //Função que desenha todas as primitivas na tela
    glClear(GL_COLOR_BUFFER_BIT);                           //buffer padrão (limpa a tela toda vez que a função é chamada)

        if((mousex < 400) || (jogadores == 1)){                     //verifica onde o mouse esta,e coloca a cor no carro correto
            switch(partC){
                case 0:                                             //coloca as cores nas rodas
                    coresC1[0] = r;
                    coresC1[1] = g;
                    coresC1[2] = b;
                    break;
                case 1:                                             //coloca as cores no eixo frontal
                    coresC1[3] = r;
                    coresC1[4] = g;
                    coresC1[5] = b;
                    break;
                case 2:                                             //coloca as cores no corpo frontal do carro
                    coresC1[6] = r;
                    coresC1[7] = g;
                    coresC1[8] = b;
                    break;
                case 3:                                             //coloca as cores no corpo traseiro do carro
                    coresC1[9] = r;
                    coresC1[10] = g;
                    coresC1[11] = b;
                    break;
                case 4:                                             //coloca as cores no aerofolio
                    coresC1[12] = r;
                    coresC1[13] = g;
                    coresC1[14] = b;
                    break;
                }
            }
            else{
                switch(partC){
                    case 0:                                             //coloca as cores nas rodas
                        coresC2[0] = r;
                        coresC2[1] = g;
                        coresC2[2] = b;
                        break;
                    case 1:                                             //coloca as cores no eixo frontal
                        coresC2[3] = r;
                        coresC2[4] = g;
                        coresC2[5] = b;
                        break;
                    case 2:                                             //coloca as cores no corpo frontal do carro
                        coresC2[6] = r;
                        coresC2[7] = g;
                        coresC2[8] = b;
                        break;
                    case 3:                                             //coloca as cores no corpo traseiro do carro
                        coresC2[9] = r;
                        coresC2[10] = g;
                        coresC2[11] = b;
                        break;
                    case 4:                                             //coloca as cores no aerofolio
                        coresC2[12] = r;
                        coresC2[13] = g;
                        coresC2[14] = b;
                        break;
                }
            }
    if(jogadores == 2)                                          //verifica se existem dois jogadores no momento de inicio da partida para então usar o viewport e dividir a tela
        glViewport(0, 0, largura, altura);                      //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
    glPushMatrix();                                             //desenha as principais coisas de cada visão, asfalto, linha e contorno
        asfalto();
        linha_as();
        contorno();
    glPopMatrix();

    glPushMatrix();                                             //desenha as rodas do carro 1
        glTranslatef(movx1, movy1,0);
        glColor3f(coresC1[0],coresC1[1],coresC1[2]);
        r_s_e();
        r_s_d();
        r_i_e();
        r_i_d();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(movx1, movy1,0);                           //desenha o eixo frontal do carro1
        glColor3f(coresC1[3],coresC1[4],coresC1[5]);
        eixo_f();
    glPopMatrix();

    glPushMatrix();                                             //desnha o corpo traseiro do carro1
        glTranslatef(movx1, movy1,0);
        glColor3f(coresC1[9],coresC1[10],coresC1[11]);
        corp_car_t();
    glPopMatrix();

    glPushMatrix();                                             //desenha o corpo traseiro do carro1
        glTranslatef(movx1, movy1,0);
        glColor3f(coresC1[6],coresC1[7],coresC1[8]);
        corp_car_f();
    glPopMatrix();

    glPushMatrix();                                             //desnha o aerofolio do carro
        glTranslatef(movx1, movy1,0);
        glColor3f(coresC1[12],coresC1[13],coresC1[14]);
        aerofolio();
        if(colisao(-11+seed,(2+abs(seed)+40)-mov,12,7,-4+movx1,2+movy1,8,13) == true){      //checa a colisãp com a pedra
            if(coli1 == 6){
                colisao1--;
                coli1-=1;
            }
            else
                coli1-=1;

            if(coli1 == 0)
                coli1 = 6;
        }
    glPopMatrix();

    glPushMatrix();                                 //desenha e movimenta a pedra
        glTranslatef(seed, (abs(seed)+40) - mov,0);
        pedra();
    glPopMatrix();

                                    //posiciona e desenha as vidas no canto inferior esquerdo
    if(colisao1 >= 1){
        glPushMatrix();
            glTranslatef(-37, -55,0);
            coracao();
        glPopMatrix();
    }

    if(colisao1 >= 2){
        glPushMatrix();
            glTranslatef(-32, -55,0);
            coracao();
        glPopMatrix();
    }
    if(colisao1 == 3){
        glPushMatrix();
            glTranslatef(-27, -55,0);
            coracao();
        glPopMatrix();
    }
    if(colisao1 <= 0){                                  //verifica se o jogador perdeu e para a movimentação das rochas
        glColor3f(0,0,0);
        glRasterPos2f(-13,0);
        DesenhaTexto(GLUT_BITMAP_HELVETICA_18,"VOCE PERDEU");
        comeca = 0;
    }
    if(colisao2 <= 0){                                  //verifica se o jogador ganhou
        glColor3f(0,0,0);
        glRasterPos2f(-13,0);
        DesenhaTexto(GLUT_BITMAP_HELVETICA_18,"VOCE GANHOU");
    }

//////////////////////JOGADOR 2, a logica apresentada acima foi replicada para o jogador 2, com excessão da movimentação que funciona em teclas diferentes para cada um///////////////////////////////////////////////////////

	if(jogadores == 2){
        glViewport(largura, 0, largura, altura);              //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
        glPushMatrix();
            asfalto();
            linha_as();
            contorno();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(movx2, movy2,0);
            glColor3f(coresC2[0],coresC2[1],coresC2[2]);
            r_s_e();
            r_s_d();
            r_i_e();
            r_i_d();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(movx2, movy2,0);
            glColor3f(coresC2[3],coresC2[4],coresC2[5]);
            eixo_f();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(movx2, movy2,0);
            glColor3f(coresC2[9],coresC2[10],coresC2[11]);
            corp_car_t();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(movx2, movy2,0);
            glColor3f(coresC2[6],coresC2[7],coresC2[8]);
            corp_car_f();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(movx2, movy2,0);
            glColor3f(coresC2[12],coresC2[13],coresC2[14]);
            aerofolio();
            if(colisao(-11+seed,(2+abs(seed)+40)-mov,12,7,-4+movx2,2+movy2,8,13) == true){
                if(coli2 == 6){
                colisao2--;
                coli2-=1;
            }
            else
                coli2-=1;

            if(coli2 == 0)
                coli2 = 10;
        }
         glPopMatrix();

         glViewport(largura, 0, largura, altura);
         glPushMatrix();
            glTranslatef(seed, (abs(seed)+40) - mov,0);
            pedra();
        glPopMatrix();

                                        //vidas
        if(colisao2 >= 1){
            glPushMatrix();
                glTranslatef(-37, -55,0);
                coracao();
            glPopMatrix();
        }
        if(colisao2 >= 2){
            glPushMatrix();
                glTranslatef(-32, -55,0);
                coracao();
            glPopMatrix();
        }
        if(colisao2 == 3){
            glPushMatrix();
                glTranslatef(-27, -55,0);
                coracao();
            glPopMatrix();
        }
        if(colisao2 <= 0){
            glColor3f(0,0,0);
            glRasterPos2f(-13,0);
            DesenhaTexto(GLUT_BITMAP_HELVETICA_18,"VOCE PERDEU");
            comeca = 0;
        }
        if(colisao1 <= 0){
            glColor3f(0,0,0);
            glRasterPos2f(-13,0);
            DesenhaTexto(GLUT_BITMAP_HELVETICA_18,"VOCE GANHOU");
        }
	}
	glutSwapBuffers();
}

void alteraTamanhoJanela(GLsizei w, GLsizei h){           //faz o controle do tamanho das viewports
    if(h == 0) h = 1;
        largura = w/2;

    altura = h;
    aspecto = (float) largura / altura;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-win*aspecto, win*aspecto, -win, win);
}

void inicializa(){                                        // inicializa nossas variáveis
     glClearColor(1,1,1,0);
     win = 60;
}

void escolheCor(int opcao){             //função que escolhe as cores para pintar o carro
    switch(opcao){
        case 0:                         //caso  o valor de opção for 0 pinta de vermelho
            r = 1;
            g = 0;
            b = 0;
            break;
        case 1:                         //caso  o valor de opção for 1 pinta de verde
            r = 0;
            g = 1;
            b = 0;
            break;
        case 2:                         //caso  o valor de opção for 2 pinta de azul
            r = 0;
            g = 0;
            b = 1;
            break;
        case 3:                         //caso  o valor de opção for 3 pinta de rosa
            r = 1;
            g = 0.75;
            b = 0.8;
            break;
        case 4:                         //caso  o valor de opção for 4 pinta de preto
            r = 0;
            g = 0;
            b = 0;
            break;
        case 5:                         //caso  o valor de opção for 5 pinta de amarelo
            r = 1;
            g = 1;
            b = 0;
            break;
        case 6:                         //caso  o valor de opção for 6 pinta de laranja
            r = 1;
            g = 0.65;
            b = 0;
            break;
        case 7:                         //caso  o valor de opção for 7 pinta de branco antigo(desbotado)
            r = 0.98;
            g = 0.92;
            b = 0.84;
            break;
        case 8:                         //caso  o valor de opção for 8 pinta de ferrugem
            r = 0.72;
            g = 0.25;
            b = 0.05;
            break;
        case 9:                         //caso  o valor de opção for 9 pinta de prata
            r = 0.75;
            g = 0.75;
            b = 0.75;
            break;
    }
    glutPostRedisplay();
}

void escolherParteCarro(int opcao){     //verifica a opção escolhida dentre as parte do carro
    switch(opcao){
        case 0:                         //caso  o valor de opção for 0 seleciona as rodas
           partC = 0;
            break;
        case 1:                         //caso  o valor de opção for 1 seleciona o eixo frontal
            partC = 1;
            break;
        case 2:                         //caso  o valor de opção for 2 seleciona o corpo do carro frontal(parachoque frontal e capo)
            partC = 2;
            break;
        case 3:                         //caso  o valor de opção for 1 seleciona o corpo do carro traseiro(parachoque traseiro e porta-malas)
            partC = 3;
            break;
        case 4:                         //caso  o valor de opção for 2 seleciona o aerofolio
            partC = 4;
            break;
    }
    glutPostRedisplay();                  //chama a função desenha toda vez que for necessária
}

void menuCor(){
    subMenuCor = glutCreateMenu(escolheCor);               //cria um novo menu pop-up
    glutAddMenuEntry("Vermelho", 0);                       //parte do menu que atribui cores
    glutAddMenuEntry("Verde", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Rosa", 3);
    glutAddMenuEntry("Preto", 4);
    glutAddMenuEntry("Amarelo", 5);
    glutAddMenuEntry("Laranja", 6);
    glutAddMenuEntry("Branco Antigo", 7);
    glutAddMenuEntry("Ferrugem", 8);
    glutAddMenuEntry("Prata", 9);
}

void menuParte(){
    SubMenuPar_car = glutCreateMenu(escolherParteCarro);        //cria um novo menu pop-up
    glutAddMenuEntry("Rodas", 0);                               //parte do menu que atribui as formas do carro
    glutAddMenuEntry("Eixo frontal", 1);
    glutAddMenuEntry("Parte frontal", 2);
    glutAddMenuEntry("Parte traseira", 3);
    glutAddMenuEntry("Aerofolio", 4);
}

void criaMenu(){                                                //cria o menu principal e os submenus de cor e forma
    menuCor();
    menuParte();
    glutCreateMenu(0);
    glutAddSubMenu("Escolha qual parte do carro sera pintada", SubMenuPar_car);
    glutAddSubMenu("Escolha uma cor", subMenuCor);

    glutAttachMenu(GLUT_LEFT_BUTTON);
}

void gerenciaMouse(int botao, int estado, int x, int y){      //verifica se o mouse foi clicado.
    if(botao == GLUT_LEFT_BUTTON)
        if(estado == GLUT_DOWN){
            criaMenu();
        }
    glutPostRedisplay();
}

void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case 'a': movx1-=passo;         // move nosso objeto para a esquerda
            break;
        case 'd': movx1+=passo;         // move nosso objeto para a direita
            break;
        case 'w': movy1+=passo;         // move nosso objeto para cima
            break;
        case 's': movy1-=passo;         // move nosso objeto para baixo
            break;
        case 'k': comeca = 1;           // starta o jogo
            break;
    }
    glutPostRedisplay();
}

void setasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){
        case GLUT_KEY_LEFT: movx2-=passo;               // move nosso objeto para a esquerda
            break;
        case GLUT_KEY_RIGHT: movx2+=passo;              // move nosso objeto para a direita
            break;
        case GLUT_KEY_UP: movy2+=passo;                 // move nosso objeto para cima
            break;
        case GLUT_KEY_DOWN: movy2-=passo;               // move nosso objeto para baixo
            break;
    }
    glutPostRedisplay();
}

void posicaoMouse (int x, int y){                       //função usada para saber em qual tela se está fazendo a interação
    mousex = x;
}

int main(void){
    unsigned semente = time(0);         //starta a semente aleatória
    srand(semente);
    seed = randomiza(30, 5);

    int NP = randomiza(2,0);            //variavel que recebe um valor que varia de 0 a 1, e dependendo faz com que a semente seja positiva ou negativa
                                        //se randomiza for 0 a semente sera positiva, o contrario sera negativa
    if(NP == 1)
        seed = -seed;

    cout << "SEJAM BEM VINDOS A CORRIDA DE CARROS" << endl;
    cout << "A CORRIDA DE CARROS FUNCIONA DA SEGUINTE MANEIRA, O MOTORISTA DEVE CONTROLAR SEU CARRO" << endl;
    cout << "EVITANDO COLIDIR O MESMO COM AS PEDRAS QUE APARECERAM NO CAMINHO, E PARA ISSO" << endl;
    cout << "USANDO O TECLADO, NO CASO DE SER APENAS UM JOGADOR AS TECLAS USADAS SAO W, A, D, S" << endl;
    cout << "RESPECTIVAMENTE, CIMA, ESQUERDA, DIRETA E BAIXO, EM CASO DE 2 JOGADORES AS SETAS PODEM SER USADAS." << endl;
    cout << "AMBOS OS CARROS PODER TER SUAS CORES MODIFICADAS DA MANEIRA QUE O JOGADOR QUEIRA, BASTA" << endl;
    cout << "PRESSIONAR O BOTAO ESQUERDO DO MOUSE E ABRIRA O MENU DE CORES E DAS PECAS DO CARRO QUE PODEM SER COLORIDAS" << endl;
    cout << "QUANDO O JOGADOR FOR TROCAR A COR DO CARRO PRIMEIRO ESCOLHER A PECA A SER COLORIDA E DEPOIS A COR" << endl;
    cout << "PRESSIONE A TECLA 'K' QUANDO ACABAR AS MODIFICACOES FEITAS" << endl << endl;
    cout << "POR FAVOR DIGITE A QUANTIDADE DE JOGADORES, PODENDO VARIAR DE 1 A 2 NO MAXIMO: " << endl;
    cin >> jogadores;

    while((jogadores > 2) || (jogadores < 1)){
        cout << "POR FAVOR DIGITE NOVAMENTE A QUANTIDADE DE JOGADORES, PODENDO VARIAR DE 1 A 2 NO MAXIMO:  ";
        cin >> jogadores;
    }
    cout << jogadores << " ESSA FOI A QUANTIDADE DE JOGADORES NA PARTIDA." << endl << "BOA SORTE A TODOS" << endl;

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
	glutCreateWindow("Prova pratica 1");
    glutKeyboardFunc(teclas);
	glutSpecialFunc(setasDirecionais);
    glutDisplayFunc(desenhaObjetos);
    glutReshapeFunc(alteraTamanhoJanela);
    glutTimerFunc(timer,timerPonto,1);
    glutMouseFunc(gerenciaMouse);
    glutPassiveMotionFunc(posicaoMouse);
    inicializa();
    glutMainLoop();
    return 0;
}
