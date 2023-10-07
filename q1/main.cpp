#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <locale.h>

float win;                          // win (window), vai definir o tamanho de cada viewport (quanto maior valor de win, mais longe da tela)
float aspecto;                      // aspecto: vari�vel para controlar windowsize
int largura, altura;                //largura e altura da minha janela

void quadrado(){
    glBegin(GL_QUADS);                      //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0,1,0);                   //adiciona cor ao nosso quadrado
        glVertex2f(-5, -5);                 //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-5, 5);                  //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(5, 5);                   //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(5, -5);                  //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
}

void triangulo(){
    glBegin(GL_TRIANGLES);                   //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(1,0,0);                    //adiciona cor ao nosso quadrado
        glVertex2f(-6, -5);                  //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso triangulo
        glVertex2f(0, 5);                    //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso triangulo
        glVertex2f(6, -5);                   //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso triangulo
    glEnd();
}

void contorno(){                            //desenha linhas para ter melhor visualiza��o das viewports
    glLineWidth(2);                         //adiciona espessura da linha
    glBegin(GL_LINE_LOOP);                  //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0,0,0);                   //adiciona cor na linha
        glVertex2f(-win*aspecto, -win);     //inferior esquerdo
        glVertex2f(-win*aspecto, win);      //superior esquerdo
        glVertex2f(win*aspecto, win);       //superior direito
        glVertex2f(win*aspecto, -win);      //inferior direito
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);                         //buffer padr�o (limpa a tela toda vez que a fun��o � chamada)

	glViewport(0, 0, largura, altura);                    //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
	glPushMatrix();                                       //insere a matriz de transforma��o corrente na pilha
		quadrado();                                       //chama a fun��o quadrado
		contorno();                                       //chama a fun��o contorno
	 glPopMatrix();                                       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente
	glViewport(largura, 0, largura, altura);              //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
    glPushMatrix();                                       //insere a matriz de transforma��o corrente na pilha
		triangulo();                                      //chama a fun��o triangulo
		contorno();                                       //chama a fun��o contorno
	 glPopMatrix();                                       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

	glutSwapBuffers();                                    //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers)
}

void alteraTamanhoJanela(GLsizei w, GLsizei h){           //faz o controle do tamanho das viewports (padr�o de par�metros, altura e largura) (800x600 no glutInitWindowSize)
    if(h == 0) h = 1;                                     //caso altura seja = 0, setamos ela pra 1, pra corrigir eventuais erros
    largura = w/2;                                        //largura eu divido o valor da janela por 2, para criar duas viewports do mesmo tamanho, no caso 800/2
    altura = h;                                           //altura eu mantenho a mesma, pois vou dividir s� em duas partes.

    aspecto = (float) largura / altura;                   // largura dividida pela altura (utilizada para controlar a largura da janela automaticamente, independente de eu alterar a windowsize) (faz com que as janelas tenham a mesma propor��o em cada viewport)

    glMatrixMode(GL_PROJECTION);                          //proje��o do tipo modelo
    glLoadIdentity();                                     //carrega a identidade de proje��o de modelo
    gluOrtho2D(-win*aspecto, win*aspecto, -win, win);     //sistema de coordenadas, agora definido de acordo com os par�metros de janela, win e aspecto) direta x, esqueda -x, abaixo -y e acima y (cada viewport ter� seu sistema de coordenadas)
}

void inicializa(){                                        // inicializa nossas vari�veis
     glClearColor(1,1,1,0);                               //informa a cor de fundo da tela (branco)
     win = 80;                                            // quanto menor o valor de win, mais perto da tela (como se fosse um zoom)
}

void MouseAndando (int x, int y)
{
    printf("Mouse na Posi��o: (%d, %d)\n", x, y );
}

int main(void){
     printf("",setlocale(LC_ALL, "Portuguese")); // para usar acentos nos printf's
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);          //somente um double buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                          //define o tamanho da janela
    glutInitWindowPosition(320,150);                      //medidas usadas para posicionar a janela no meio da tela - isso depende da resolu��o do monitor
	glutCreateWindow("Exemplo Viewport");                 //permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjetos);                      //fun��o de callback - chama a fun��o desenhaObjetos
    glutPassiveMotionFunc(MouseAndando);
    glutReshapeFunc(alteraTamanhoJanela);                 //fun��o que altera o tamanho da janela, redesenha o tamanho da janela
    inicializa();
    glutMainLoop();                                       //loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;                                             //retorna zero
}
