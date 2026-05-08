#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void desenhaCirculo(float x, float y, float raio, int segmentos) {

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    for (int i = 0; i <= segmentos; i++) {

        float angulo = 2.0f * 3.1415926f * i / segmentos;

        float dx = cos(angulo) * raio;
        float dy = sin(angulo) * raio;

        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void draw() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.5f, 0.0f);

    desenhaCirculo(-0.5f, 0.5f, 0.2f, 100);

    glBegin(GL_QUADS);

        glColor3f(1.0, 0.0, 0.0);

        glVertex2f(0.2f, 0.3f);
        glVertex2f(0.6f, 0.3f);
        glVertex2f(0.6f, 0.7f);
        glVertex2f(0.2f, 0.7f);

    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f(0.0, 1.0, 0.0);

        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.7f, -0.7f);
        glVertex2f(-0.3f, -0.7f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.0, 0.0, 1.0);

        glVertex2f(0.2f, -0.7f);
        glVertex2f(0.7f, -0.7f);
        glVertex2f(0.6f, -0.3f);
        glVertex2f(0.3f, -0.3f);

    glEnd();

    glFlush();
}

void init() {

    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Formas Geometricas - Luan Siqueira");

    init();

    glutDisplayFunc(draw);

    glutMainLoop();

    return 0;
}