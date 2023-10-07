#include <GL/gl.h>
#include <GL/glut.h>


int movex = 0, movey = 0;               //vari�veis para mover o ponto rem rela��o aos eventos do mouse

void ponto(){
    glPointSize(10);                    //adiciona espessura do ponto
    glBegin(GL_POINTS);                 //glBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0,1,0);               //adiciona cor
        glVertex2f(movex,movey);        //desenha um ponto na coordenada x, y, onde y vai ser a vari�vel que criamos para deslocar o ponto neste eixo
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);         //buffer padr�o (limpa a tela toda vez que a fun��o � chamada)
	glMatrixMode(GL_PROJECTION);          //proje��o dos pontos definidos no plano cartesiano
    glLoadIdentity();                     //carrega a proje��o
    gluOrtho2D(0,800,600,0);              // define o tamanho do plano cartesiano
	glMatrixMode(GL_MODELVIEW);           // proje��o do tipo modelo
    glLoadIdentity();                     // carrega a identidade de proje��o de modelo

    glPushMatrix();                       //insere a matriz de transforma��o corrente na pilha
        ponto();                          //chama a fun��o que desenha o ponto
    glPopMatrix();                        //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

	glutSwapBuffers();                    //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers)
}

void movimentaMouse(int x, int y){
    movex = x;
    movey = y;

    glutPostRedisplay();
}

/*---MOUSE CLICK (O ponto se move conforme o bot�o esquerdo do mouse � clicado)--------------------------------

void gerenciaMouse(int botao, int estado, int x, int y){           //Par�metros de entrada da fun��o: (int button, int state, int x, int y).  Os par�metros x e y indicam a localiza��o do mouse no momento que o evento ocorreu.
    if (botao == GLUT_LEFT_BUTTON)                                 //Tr�s valores s�o v�lidos para o par�metro button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON e GLUT_RIGHT_BUTTON.
        if(estado == GLUT_DOWN){                                   //O par�metro state pode ser GLUT_UP ou GLUT_DOWN.
            movex = x;                                             //variavel movex recebe o valor do clique no eixo x
            movey = y;                                             //variavel movey recebe o valor do clique no eixo y
        }
    glutPostRedisplay();                                           //chama a fun��o desenha toda vez que for necess�ria
}

----MOUSE CLICK----------------------------------------------------------------------------------------------*/



///*---MOUSE MOVE (Ponto se move enquanto o bot�o esquerdo do mouse permanece clicado)----------------------------

void gerenciaMouse(int botao, int estado, int x, int y){           //Par�metros de entrada da fun��o: (int button, int state, int x, int y).  Os par�metros x e y indicam a localiza��o do mouse no momento que o evento ocorreu.
    if (botao == GLUT_LEFT_BUTTON)                                 ///Tr�s valores s�o v�lidos para o par�metro button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON e GLUT_RIGHT_BUTTON.
        if(estado == GLUT_DOWN){                                   //O par�metro state pode ser GLUT_UP ou GLUT_DOWN.
            glutMotionFunc(movimentaMouse);                        //glutMotionFunc  define o movimento para a janela atual. O retorno de chamada de movimento para uma janela � chamado quando o mouse se move dentro da janela enquanto um ou mais bot�es do mouse s�o pressionados.
        }
    glutPostRedisplay();                                           //chama a fun��o desenha toda vez que for necess�ria
}

//----MOUSE MOVE--------------------------------------------------------------------------------------------------*/



/*---MOUSE SEGUE (ponto se move onde quer que o mouse for, ap�s clicar com esquerdo)-----------------------------

void gerenciaMouse(int botao, int estado, int x, int y){     //Par�metros de entrada da fun��o: (int button, int state, int x, int y).  Os par�metros x e y indicam a localiza��o do mouse no momento que o evento ocorreu.
    if (botao == GLUT_LEFT_BUTTON)                           //Tr�s valores s�o v�lidos para o par�metro button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON e GLUT_RIGHT_BUTTON.
        if(estado == GLUT_DOWN){                             //O par�metro state pode ser GLUT_UP ou GLUT_DOWN.
            glutPassiveMotionFunc(movimentaMouse);           // glutPassiveMotionFunc define o retorno de chamada do movimento passivo, para a janela atual.
        }
    glutPostRedisplay();                                     //chama a fun��o desenha toda vez que for necess�ria
}

----------MOUSE SEGUE-------------------------------------------------------------------------------------------*/



int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);            //double buffer, pois single ficaria piscando, uma vez que ele tem que desenhar e redesenhar | sistema de cores RGB
    glutInitWindowSize(800,600);                            //define o tamanho da janela
    glutInitWindowPosition(320,150);                        //medidas usadas para posicionar a janela no meio da tela - isso depende da resolu��o do monitor
	glutCreateWindow("Fun��o Mouse - Intera��o");           //permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjetos);                        //fun��o de callback - chama a fun��o desenhaObjetos
    glutMouseFunc(gerenciaMouse);                           //Estabelece a fun��o callback que � chamada pela GLUT cada vez que ocorre um evento de mouse.
    glClearColor(1,1,1,0);                                  //informa a cor de fundo da tela (branco)
    glutMainLoop();                                         //loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;                                               //retorna zero
}
