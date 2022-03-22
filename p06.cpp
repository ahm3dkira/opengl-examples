#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

   glPointSize(10.0);
   glColor3f(1.0f, 0.0f, 0.0f);
   glBegin(GL_LINE_LOOP);
      glVertex2f(-0.5f, -0.5f);
      glVertex2f(0.5f, -0.5f);
      glVertex2f(0.5f, 0.5f);
      
   glEnd();

   glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("My First Window");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}