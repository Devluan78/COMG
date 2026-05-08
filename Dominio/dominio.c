#include <GL/glut.h>
#include <stdio.h>

void desenhaTexto(float x, float y, char *texto) {

    glRasterPos2f(x, y);

    while (*texto) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *texto);
        texto++;
    }
}

void draw() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINES);
  
        //Eixo X
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
        //Eixo Y
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);

    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);

        glVertex2f(0.2, 0.2);
        glVertex2f(0.5, 0.2);
        glVertex2f(0.35, 0.5);

    glEnd();

    desenhaTexto(0.2, 0.55, "(0.35 , 0.3)");

    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_TRIANGLES);

        glVertex2f(-0.7, 0.2);
        glVertex2f(-0.4, 0.2);
        glVertex2f(-0.55, 0.5);

    glEnd();

    desenhaTexto(-0.75, 0.55, "(-0.55 , 0.3)");

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLES);

        glVertex2f(0.2, -0.2);
        glVertex2f(0.5, -0.2);
        glVertex2f(0.35, -0.5);

    glEnd();

    desenhaTexto(0.2, -0.6, "(0.35 , -0.3)");

    glFlush();
}

void init() {

    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Triangulos no Plano Cartesiano");

    init();

    glutDisplayFunc(draw);

    glutMainLoop();

    return 0;
}