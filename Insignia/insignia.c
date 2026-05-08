#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float r_centro = 0.8f, g_centro = 0.6f, b_centro = 0.1f;
float r_pontas = 0.5f, g_pontas = 0.1f, b_pontas = 0.8f;

float gerarCorAleatoria() {
    return (float)rand() / (float)RAND_MAX;
}

void desenharInsignia() {
    
    glColor3f(r_pontas, g_pontas, b_pontas);
    glBegin(GL_TRIANGLES);
        // Braço Superior (2 triângulos formando o corte em V)
        glVertex2f(-10.0f, 10.0f);  glVertex2f(-30.0f, 60.0f);  glVertex2f(0.0f, 40.0f);
        glVertex2f(10.0f, 10.0f);   glVertex2f(30.0f, 60.0f);   glVertex2f(0.0f, 40.0f);

        // Braço Inferior
        glVertex2f(-10.0f, -10.0f); glVertex2f(-30.0f, -60.0f); glVertex2f(0.0f, -40.0f);
        glVertex2f(10.0f, -10.0f);  glVertex2f(30.0f, -60.0f);  glVertex2f(0.0f, -40.0f);

        // Braço Direito
        glVertex2f(10.0f, 10.0f);   glVertex2f(60.0f, 30.0f);   glVertex2f(40.0f, 0.0f);
        glVertex2f(10.0f, -10.0f);  glVertex2f(60.0f, -30.0f);  glVertex2f(40.0f, 0.0f);

        // Braço Esquerdo
        glVertex2f(-10.0f, 10.0f);  glVertex2f(-60.0f, 30.0f);  glVertex2f(-40.0f, 0.0f);
        glVertex2f(-10.0f, -10.0f); glVertex2f(-60.0f, -30.0f); glVertex2f(-40.0f, 0.0f);
    glEnd();

    glColor3f(r_centro, g_centro, b_centro);
    glBegin(GL_QUADS);
        glVertex2f(-10.0f, -10.0f); // Inferior esquerdo
        glVertex2f(10.0f, -10.0f);  // Inferior direito
        glVertex2f(10.0f, 10.0f);   // Superior direito
        glVertex2f(-10.0f, 10.0f);  // Superior esquerdo
    glEnd();
}

void displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT);

    desenharInsignia();

    glFlush();
}

void teclado(unsigned char tecla, int x, int y) {
   
    if (tecla == 'c' || tecla == 'C') {
        // Carrega a insígnia com nova energia (novas cores)
        r_centro = gerarCorAleatoria();
        g_centro = gerarCorAleatoria();
        b_centro = gerarCorAleatoria();

        r_pontas = gerarCorAleatoria();
        g_pontas = gerarCorAleatoria();
        b_pontas = gerarCorAleatoria();

        // Solicita que o OpenGL redesenhe a tela imediatamente
        glutPostRedisplay();
    }
}

void inicializar() {
    
    glClearColor(0.05f, 0.05f, 0.1f, 1.0f); 

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

int main(int argc, char** argv) {

    srand(time(NULL));

    printf("--- Insignia de Malta --- \n");
    printf("O Portal dos Pixels aguarda sua energia.\n");
    printf(">>> Pressione a tecla 'C' para alterar as cores da insignia!\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600); 
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Portal dos Pixels - Insignia de Malta");

    inicializar();

    glutDisplayFunc(displayCallback);
    glutKeyboardFunc(teclado); 

    glutMainLoop();

    return 0;
}