#include <GL/gl.h> 					//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 				//bibliotecao que permite a manipulação de janelas
#include <Math.h>                   //conjunto de funções para operações matemáticas

GLfloat escala=1;                  // variável para escala
GLfloat rotacao=0;                 // variável para rotação
GLfloat movex = 0, movey = 0;      // variáveis de movimentação para x e y

void carro(){
    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(1,1,1);          //adiciona cor ao quadrado
        glVertex2f(70,-90);         //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(70,-87);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        //glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(73,-87);           //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(73,-90);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
    glEnd();
}

void gramado(){
    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(0.13,0.55,0.13);          //adiciona cor ao quadrado
        glVertex2f(-100,-100);         //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(-100,100);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        //glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(100,100);           //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(100,-100);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
    glEnd();
}

void asfalto1(){
    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(0,0,0);          //adiciona cor ao quadrado
        glVertex2f(65,-100);         //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(65,90);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        //glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(90,90);           //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(90,-100);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
    glEnd();
}

void asfalto2(){
    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(0,0,0);          //adiciona cor ao quadrado
        glVertex2f(-100,65);         //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(-100,90);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        //glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(90,90);           //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(90,65);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
    glEnd();
}

void faixa(){
    glLineWidth(5);           //adiciona espessura das ponto
    glColor3f(1, 1, 0);   //adiciona cor as linhas
    glBegin(GL_LINES);             //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(78, 78);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(68, 78);
        glVertex2f(58, 78);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(48, 78);
        glVertex2f(38, 78);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(28, 78);
        glVertex2f(18, 78);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(8, 78);
        glVertex2f(-2, 78);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(-12, 78);
        glVertex2f(-22, 78);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(-32, 78);
        glVertex2f(-42, 78);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(-52, 78);
        glVertex2f(-62, 78);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(-72, 78);
        glVertex2f(-82, 78);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(-92, 78);

        glVertex2f(78, 79);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, 68);        //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, 58);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, 48);        //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, 38);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, 28);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, 18);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, 8);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, -02);        //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, -12);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, -22);        //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, -38);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, -48);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, -58);
        glVertex2f(78, -68);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, -78);
        glVertex2f(78, -88);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(78, -98);
    glEnd();
}

void desenhaObjeto(void){                 //função de desenho
    glClear(GL_COLOR_BUFFER_BIT);         //buffer padrão; limpa a tela toda vez que a função é chamada
	glMatrixMode(GL_PROJECTION);          //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity(); 				      //carrega a projeção
    gluOrtho2D(-100,100,-100,100);            //define o tamanho do plano cartesiano
	glMatrixMode(GL_MODELVIEW);           //projeção do tipo modelo
    glLoadIdentity();                     //carrega essa identidade de projeção de modelo

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


    glPushMatrix();                           //insere a matriz de transformação corrente na pilha
        //glScalef(escala, escala, 0);          //chama a fução escala e passa como parâmetro o valor da escala ( as mesmas para x e y)
        //glRotatef(rotacao, 0,0,1);            //chama a fução rotação e passa como parâmetro o ângulo
        glTranslatef(movex, movey,0);         //chama a fução de tranlação e passa como parâmetro o valor para transladar em x e y
        carro();                           // chama a função que desenha um quadrado
    glPopMatrix();

	glFlush();                                //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)
}

/*função que atriui valores as nossas variáveis de escala e rotação (dependendo da tecla pressionada) */
void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '+': escala++;         // adiciona 1 ao valor de escala
        break;
        case '-': escala--;         // remove 1 ao valor de escala
        break;
        case '1': rotacao-=10;      // rotaciona o objeto no sentido horário (diminui o ângulo em 10)
        break;
        case '2': rotacao+=10;      // rotaciona o objeto no sentido anti-horário (aumenta o ângulo em 10)
        break;
    }
    glutPostRedisplay();            //redesenha a cena que está na janela
}

/*função que atriui valores as nossas variáveis de movimentação x e y (dependendo da tecla pressionada) */
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
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);        // da tela - isso depende da resolução do monitor
	glutCreateWindow("atv04-corrida de carro");                              // permite a criação de uma janela
    glutDisplayFunc(desenhaObjeto);                                     // função de callback - chama a função Desenha
    glutKeyboardFunc(teclas);                                           // Chamada da função teclado (cada pressionamento gera uma chamada do teclado)
    glutSpecialFunc(setasDirecionais);                                  // Chamada da função teclado especial (para quando as teclas direcionais são pressionadas)
    glClearColor(1,1,1,0);                                              // informa a cor de fundo da tela
    glutMainLoop();                                                     // loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                                           // retorna zero
}
