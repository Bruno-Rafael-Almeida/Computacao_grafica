#include <GL/gl.h> 					//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 				//bibliotecao que permite a manipula��o de janelas
#include <Math.h>                   //conjunto de fun��es para opera��es matem�ticas

GLfloat escala=1;                  // vari�vel para escala
GLfloat rotacao=0;                 // vari�vel para rota��o
GLfloat movex = 0, movey = 0;      // vari�veis de movimenta��o para x e y

void carro(){
    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(1,1,1);          //adiciona cor ao quadrado
        glVertex2f(70,-90);         //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(70,-87);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        //glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(73,-87);           //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(73,-90);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
    glEnd();
}

void gramado(){
    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0.13,0.55,0.13);          //adiciona cor ao quadrado
        glVertex2f(-100,-100);         //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(-100,100);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        //glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(100,100);           //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(100,-100);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
    glEnd();
}

void asfalto1(){
    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0,0,0);          //adiciona cor ao quadrado
        glVertex2f(65,-100);         //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(65,90);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        //glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(90,90);           //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(90,-100);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
    glEnd();
}

void asfalto2(){
    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0,0,0);          //adiciona cor ao quadrado
        glVertex2f(-100,65);         //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(-100,90);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        //glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(90,90);           //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(90,65);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
    glEnd();
}

void faixa(){
    glLineWidth(5);           //adiciona espessura das ponto
    glColor3f(1, 1, 0);   //adiciona cor as linhas
    glBegin(GL_LINES);             //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(78, 78);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(68, 78);
        glVertex2f(58, 78);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(48, 78);
        glVertex2f(38, 78);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(28, 78);
        glVertex2f(18, 78);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(8, 78);
        glVertex2f(-2, 78);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(-12, 78);
        glVertex2f(-22, 78);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(-32, 78);
        glVertex2f(-42, 78);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(-52, 78);
        glVertex2f(-62, 78);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(-72, 78);
        glVertex2f(-82, 78);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(-92, 78);

        glVertex2f(78, 79);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, 68);        //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, 58);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, 48);        //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, 38);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, 28);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, 18);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, 8);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, -02);        //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, -12);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, -22);        //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, -38);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, -48);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, -58);
        glVertex2f(78, -68);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, -78);
        glVertex2f(78, -88);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(78, -98);
    glEnd();
}

void desenhaObjeto(void){                 //fun��o de desenho
    glClear(GL_COLOR_BUFFER_BIT);         //buffer padr�o; limpa a tela toda vez que a fun��o � chamada
	glMatrixMode(GL_PROJECTION);          //proje��o dos pontos definidos no plano cartesiano
    glLoadIdentity(); 				      //carrega a proje��o
    gluOrtho2D(-100,100,-100,100);            //define o tamanho do plano cartesiano
	glMatrixMode(GL_MODELVIEW);           //proje��o do tipo modelo
    glLoadIdentity();                     //carrega essa identidade de proje��o de modelo

    glPushMatrix();
        gramado();
    glPopMatrix();

    glPushMatrix();
        asfalto1();
    glPopMatrix();

    glPushMatrix();
        //glRotatef(rotacao, 0,0,1);
        //glTranslatef(movex, movey,0);
        asfalto2();
    glPopMatrix();

    glPushMatrix();
        faixa();
    glPopMatrix();


    glPushMatrix();                           //insere a matriz de transforma��o corrente na pilha
        //glScalef(escala, escala, 0);          //chama a fu��o escala e passa como par�metro o valor da escala ( as mesmas para x e y)
        //glRotatef(rotacao, 0,0,1);            //chama a fu��o rota��o e passa como par�metro o �ngulo
        glTranslatef(movex, movey,0);         //chama a fu��o de tranla��o e passa como par�metro o valor para transladar em x e y
        carro();                           // chama a fun��o que desenha um quadrado
    glPopMatrix();

	glFlush();                                //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)
}

/*fun��o que atriui valores as nossas vari�veis de escala e rota��o (dependendo da tecla pressionada) */
void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '+': escala++;         // adiciona 1 ao valor de escala
        break;
        case '-': escala--;         // remove 1 ao valor de escala
        break;
        case '1': rotacao-=10;      // rotaciona o objeto no sentido hor�rio (diminui o �ngulo em 10)
        break;
        case '2': rotacao+=10;      // rotaciona o objeto no sentido anti-hor�rio (aumenta o �ngulo em 10)
        break;
    }
    glutPostRedisplay();            //redesenha a cena que est� na janela
}

/*fun��o que atriui valores as nossas vari�veis de movimenta��o x e y (dependendo da tecla pressionada) */
void setasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){
        case GLUT_KEY_LEFT: movex--;               // move nosso objeto para a esquerda
        break;
        case GLUT_KEY_RIGHT: movex++;              // move nosso objeto para a direita
        break;
        case GLUT_KEY_UP: movey++;                 // move nosso objeto para cima
        break;
        case GLUT_KEY_DOWN: movey--;               // move nosso objeto para baixo
        break;
    }
    glutPostRedisplay();
}

int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                        // somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                        // define o tamanho da janela
     glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,         // medidas usadas para posicionar a janela no meio
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);        // da tela - isso depende da resolu��o do monitor
	glutCreateWindow("atv04-corrida de carro");                              // permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjeto);                                     // fun��o de callback - chama a fun��o Desenha
    glutKeyboardFunc(teclas);                                           // Chamada da fun��o teclado (cada pressionamento gera uma chamada do teclado)
    glutSpecialFunc(setasDirecionais);                                  // Chamada da fun��o teclado especial (para quando as teclas direcionais s�o pressionadas)
    glClearColor(1,1,1,0);                                              // informa a cor de fundo da tela
    glutMainLoop();                                                     // loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;                                                           // retorna zero
}
