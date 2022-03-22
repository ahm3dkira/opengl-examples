#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_TRIANGLE_FAN);       
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(0.5, 0.5);
      glVertex2f(-0.5, 0.5);
      glVertex2f(0.5, -0.5);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex2f(-0.5, -0.9);

      




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