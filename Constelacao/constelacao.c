#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M_PI 3.14159
#define MAX_ESTRELAS 100

typedef struct {
    float x, y;
    float raio;
    float r, g, b;
} Estrela;

Estrela estrelas[MAX_ESTRELAS];
int total = 0;
int modoNoturno = 0;

void desenharEstrela(float x, float y, float raio) {

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    for (int i = 0; i <= 100; i++) {

        float ang = 2.0f * M_PI * i / 100;

        glVertex2f(
            x + cos(ang) * raio / 500.0f,
            y + sin(ang) * raio / 500.0f
        );
    }

    glEnd();
}

void adicionarEstrela() {

    if (total >= MAX_ESTRELAS) return;

    estrelas[total].x = ((float)rand() / RAND_MAX) * 2 - 1;
    estrelas[total].y = ((float)rand() / RAND_MAX) * 2 - 1;
    estrelas[total].raio = 10 + rand() % 41;

    estrelas[total].r = (float)rand() / RAND_MAX;
    estrelas[total].g = (float)rand() / RAND_MAX;
    estrelas[total].b = (float)rand() / RAND_MAX;

    total++;
}

void removerEstrela() {

    if (total <= 0) return;

    int idx = rand() % total;

    estrelas[idx] = estrelas[total - 1];
    total--;
}

void resetar() {

    total = 0;

    for (int i = 0; i < 7; i++)
        adicionarEstrela();
}

void draw() {

    if (modoNoturno)
        glClearColor(0, 0, 0, 1);
    else
        glClearColor(0.05, 0.05, 0.1, 1);

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.6, 0.6, 0.6);

    glBegin(GL_LINES);

    for (int i = 0; i < total - 1; i++) {
        glVertex2f(estrelas[i].x, estrelas[i].y);
        glVertex2f(estrelas[i + 1].x, estrelas[i + 1].y);
    }

    glEnd();

    for (int i = 0; i < total; i++) {

        if (modoNoturno) {
            glColor3f(1.0, 1.0, 0.8); 
        } else {
            glColor3f(estrelas[i].r, estrelas[i].g, estrelas[i].b);
        }

        desenharEstrela(estrelas[i].x, estrelas[i].y, estrelas[i].raio);
    }

    glFlush();
}

void teclado(unsigned char key, int x, int y) {

    switch (key) {

        case 'n':
            adicionarEstrela();
            break;

        case 'x':
            removerEstrela();
            break;

        case 'r':
            resetar();
            break;

        case 't':
            modoNoturno = !modoNoturno;
            break;
    }

    glutPostRedisplay();
}

void init() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);

    srand(time(NULL));

    resetar();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutCreateWindow("Constelacao dos Guardioes");

    init();

    glutDisplayFunc(draw);

    glutKeyboardFunc(teclado);

    glutMainLoop();

    return 0;
}