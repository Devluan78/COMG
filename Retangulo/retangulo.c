#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Variáveis do retângulo
float largura;
float altura;

// Cor do retângulo
float rectR = 1.0f;
float rectG = 0.0f;
float rectB = 0.0f;

// Cor do fundo
float fundoR = 0.0f;
float fundoG = 0.0f;
float fundoB = 0.0f;

void gerarCores() {

    // Cor do retângulo
    rectR = (float)rand() / RAND_MAX;
    rectG = (float)rand() / RAND_MAX;
    rectB = (float)rand() / RAND_MAX;

    // Cor do fundo
    fundoR = (float)rand() / RAND_MAX;
    fundoG = (float)rand() / RAND_MAX;
    fundoB = (float)rand() / RAND_MAX;
}

void draw() {

    // Define cor do fundo
    glClearColor(fundoR, fundoG, fundoB, 1.0f);

    // Limpa a tela
    glClear(GL_COLOR_BUFFER_BIT);

    // Cor do retângulo
    glColor3f(rectR, rectG, rectB);

    // Desenha retângulo
    glBegin(GL_QUADS);

        glVertex2f(-largura / 2, -altura / 2);
        glVertex2f( largura / 2, -altura / 2);
        glVertex2f( largura / 2,  altura / 2);
        glVertex2f(-largura / 2,  altura / 2);

    glEnd();

    glutSwapBuffers();
}

void teclado(unsigned char key, int x, int y) {

    // Barra de espaço
    if (key == 32) {

        gerarCores();

        glutPostRedisplay();
    }
}

void init() {

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    srand(time(NULL));

    // Entrada do usuário
    printf("Digite a largura do retangulo (0.1 a 1.0): ");
    scanf("%f", &largura);

    printf("Digite a altura do retangulo (0.1 a 1.0): ");
    scanf("%f", &altura);

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Retangulo com Cores Aleatorias");

    init();

    gerarCores();

    glutDisplayFunc(draw);

    glutKeyboardFunc(teclado);

    glutMainLoop();

    return 0;
}