#include <GL/glut.h>
#include <stdlib.h>

void desenharTriangulo(
    float x,
    float y,
    float base,
    float altura,
    float r,
    float g,
    float b
) {

    // Define cor
    glColor3f(r, g, b);

    // Desenha triângulo
    glBegin(GL_TRIANGLES);

        // Vértice inferior esquerdo
        glVertex2f(x - base / 2, y);

        // Vértice inferior direito
        glVertex2f(x + base / 2, y);

        // Vértice superior
        glVertex2f(x, y + altura);

    glEnd();
}

void draw() {

    glClear(GL_COLOR_BUFFER_BIT);

    // TRIÂNGULO 1
    desenharTriangulo(
        -0.7f, -0.6f,
        0.3f, 0.4f,
        1.0f, 0.0f, 0.0f
    );

    // TRIÂNGULO 2
    desenharTriangulo(
        -0.2f, -0.5f,
        0.4f, 0.5f,
        0.0f, 1.0f, 0.0f
    );

    // TRIÂNGULO 3
    desenharTriangulo(
        0.3f, -0.6f,
        0.5f, 0.6f,
        0.0f, 0.0f, 1.0f
    );

    // TRIÂNGULO 4
    desenharTriangulo(
        -0.5f, 0.2f,
        0.2f, 0.3f,
        1.0f, 1.0f, 0.0f
    );

    // TRIÂNGULO 5    
    desenharTriangulo(
        0.4f, 0.1f,
        0.6f, 0.5f,
        1.0f, 0.0f, 1.0f
    );

    glutSwapBuffers();
}

void init() {

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Triangulos Isosceles");

    init();

    glutDisplayFunc(draw);

    glutMainLoop();

    return 0;
}