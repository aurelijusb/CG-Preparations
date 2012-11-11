/**
 * Learning tools
 * 
 * @author Aurelijus Banelis
 */

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define KEY_ESCAPE 27
#define KEY_ENTER 13

int rx, ry, rz = 0;

void onKeyPress(unsigned char key, int keyX, int keyY) {
    switch (key) {
        case 'q':
            rx--;
        break;
        case 'w':
            rx++;
        break;
        case 'a':
            ry--;
        break;
        case 's':
            ry++;
        break;
        case 'z':
            rz--;
        break;
        case 'x':
            rz++;
        break;
        case KEY_ENTER:
            rx = 0;
            ry = 0;
            rz = 0;
        break;
    }
    if (rx > 360) { rx -= 360; } else if (rx < 0) { rx += 360; }
    if (ry > 360) { ry -= 360; } else if (ry < 0) { ry += 360; }
    if (rz > 360) { rz -= 360; } else if (rz < 0) { rz += 360; }
    glutPostRedisplay();
    printf("Rot (%d, %d, %d)\n", rx, ry, rz);
}

void drawAxis() {
    // X (by y)
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0.8, 0);
        glVertex3f(0.2, 0.6, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(-0.2, 0.6, 0);
        glVertex3f(0, 0.8, 0);
    glEnd();
    
    
    //Y (by x)
    glColor3f(0, 1, 0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0, 0);
        glVertex3f(0.8, 0, 0);
        glVertex3f(0.6, 0.2, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0.6, -0.2, 0);
        glVertex3f(0.8, 0, 0);
    glEnd();
    
    
    //Z (by XY)
    glColor3f(0.2, 0.2, 1);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 0.8);
        glVertex3f(0.2, 0.2, 0.6);
        glVertex3f(0, 0, 1);
        glVertex3f(-0.2, -0.2, 0.6);
        glVertex3f(0, 0, 0.8);
    glEnd();
}


/*
 * Main drawing loop
 */
void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glRotatef(rx, 1.0, 0, 0);
    glRotatef(ry, 0, 1.0, 0);
    glRotatef(rz, 0, 0, 1.0);
    drawAxis();
    
    glutSwapBuffers();
}

/*
 * Initiating OpenGl
 */
int main(int argc, char **argv) {
    // Init GLUT and create Window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_ALPHA);
    glutInitWindowPosition(1100,400);
    glutInitWindowSize(640,640);
    glutCreateWindow("Tests");    
    
    // Register callbacks
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(onKeyPress);
    
    // Enter GLUT event processing cycle
    glutMainLoop();

    return 0;
}