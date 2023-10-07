#include <gl/glut.h>
#include <stdio.h>

GLfloat aspecto, angulo, rotacaoN = 0, rotacaoE = 0;                // rotacaoN é responsavel por passar o movimento ao nucleo, rotacaoE é responsavel por passar movimento para os eletrons.
int mX = 0, mY = 80, mZ = 200, m = 0;                               //variaveis responsaveis por movimentar a camera para a posição que o usuario desejar


void timer_eletrons(int passo){                                     //função timer que dita a velocidade de rotação do nucleo
    rotacaoE++;                                                     //variavel que incrementa e faz a velocidade do nucleo

    glutPostRedisplay();
    glutTimerFunc(10,timer_eletrons,1);
}
void timer_nucleo(int passo){                                       //função timer que dita a velociade de rotação dos eletrons
    rotacaoN++;                                                     //variavel que incrementa e faz a velocidade dos eletrons

    glutPostRedisplay();
    glutTimerFunc(100,timer_nucleo,1);
}

void desenhaObjetos(void){                                          //função que desenha os objetos
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //NUCLEO DO ATOMO De CARBONO
    glPushMatrix();
        glColor4f(0, 1, 0, 0.7);
        glTranslatef(0, 18, 0);
        glutSolidSphere(10, 50, 50);
    glPopMatrix();
    glPushMatrix();
        glColor4f(1, 0, 0, 0.7);
        glTranslatef(0, -19, 0);
        glutSolidSphere(10, 50, 50);
    glPopMatrix();

    glPushMatrix();
        glRotatef(rotacaoN, 0, 1, 0);

        glPushMatrix();
            glColor4f(1, 0, 0, 0.7);

            glPushMatrix();
                glRotatef(324, 0, 1, 0);
                glTranslatef(17, -9, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glRotatef(36, 0, 1, 0);
                glTranslatef(17, -9, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glRotatef(72, 0, 1, 0);
                glTranslatef(17, 8, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glRotatef(144, 0, 1, 0);
                glTranslatef(17, 8, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glRotatef(252, 0, 1, 0);
                glTranslatef(17, -9, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glColor4f(0, 1, 0, 0.7);

            glPushMatrix();
                glRotatef(180, 0, 1, 0);
                glTranslatef(17, -9, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glRotatef(216, 0, 1, 0);
                glTranslatef(17, 8, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glRotatef(108, 0, 1, 0);
                glTranslatef(17, -9, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glRotatef(288, 0, 1, 0);
                glTranslatef(17, 8, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(17, 8, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    //ELETRONS DA CAMADA MAIS INTERNA
    glPushMatrix();
        glColor4f(0, 0, 1, 0.7);
        glRotatef(rotacaoE, 0, 0, 1);

            glPushMatrix();
                glTranslatef(80, 0, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-80, 0, 0);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
    glPopMatrix();
    //ELETRONS DA CAMADA MAIS EXTERNA, COVALÊNCIA
    glPushMatrix();
        glColor4f(0, 0, 1, 0.7);
        glRotatef(rotacaoE, 0, 1, 0);

            glPushMatrix();
                glTranslatef(140, 0, 70);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-140, 0, -70);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glColor4f(0, 0, 1, 0.7);
        glRotatef(rotacaoE+50, 0, 1, 0);

            glPushMatrix();
                glTranslatef(125, 0, 70);
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-125, 0, -70); //-125, 0, 70
                glutSolidSphere(10, 50, 50);
            glPopMatrix();
    glPopMatrix();

     glutSwapBuffers();                                               //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers)
}

void Inicializa (void){

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	//Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;

    glClearColor(0,0,0,1);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);


    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

    angulo = 50;
}

void projetaPlano(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angulo, aspecto, 0.4, 800);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(mX,mY,mZ, 0,0,0, 0,1,0);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    if ( h == 0 ) h = 1;
    glViewport(0, 0, w, h);
    aspecto = (GLfloat)w/(GLfloat)h;
    projetaPlano();
}


void teclasDirecionais(GLint tecla, GLint x, GLint y){      //Função que movimenta a camera
    switch(tecla){
        case GLUT_KEY_LEFT: mX-=2;               //esqueda -x
        break;
        case GLUT_KEY_RIGHT: mX+=2;              // direira +x
        break;
        case GLUT_KEY_UP: mY+=2;                 //cima  +y
        break;
        case GLUT_KEY_DOWN:	mY-=2;               //baixo -y
        break;
        case GLUT_KEY_PAGE_DOWN: mZ-=2;          //afasta -z
        break;
        case GLUT_KEY_PAGE_UP: mZ+=2;            //aprpxima +z
        break;
    }
    projetaPlano();                                        //chama a função projetaPlano
    glutPostRedisplay();                                   //redesenha a cena que está na janela
}

int main(void)
{
    printf("O SEGUINTE TRABALHO ABRESENTA A ESTRUTURA ATOMICA DO \n");
    printf("ELEMENTO CARBONO\n");
    printf("AS SETAS DIRECIONAIS, PGUP E PGDOWN PODEM SER USADAS PARA MOVIMENTAR A CAMERA\n");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);       //somente um double buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                       //define o tamanho da janela
    glutInitWindowPosition(300,120);                   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
    glutCreateWindow("Trabalho pratico 1");            //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                   //função de callback - chama a função desenhaObjetos
    glutSpecialFunc(teclasDirecionais);                //chama a função que escuta nossas teclas direcionais
    glutReshapeFunc(AlteraTamanhoJanela);              //função que altera o tamanho da janela, redesenha o tamanho da janela
    Inicializa();                                      //função que inicializa nossas variáveis
    glutTimerFunc(100,timer_nucleo,1);
    glutTimerFunc(10,timer_eletrons,1);
    glutMainLoop();                                    //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                          //retorna zero
}
