#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(1.0f, 1.0f, 1.0f, 0.0f);


   // draw a simple house 2 windows 1 door
   glColor3f(1.0f, 0.0f, 0.0f);

   // roof
   glBegin(GL_TRIANGLES);          
      glVertex2f(-0.35,0.3);
      glVertex2f(0.35,0.3);
      glVertex2f(0,0.8);
   glEnd();

   // body
   glBegin(GL_POLYGON);
      glVertex2f(0.35,0.3);
      glVertex2f(0.35,-0.6);
      glVertex2f(-0.35,-0.6);
      glVertex2f(-0.35,0.3);
   glEnd();

   glColor3f(0.0f, 1.0f, 0.0f);

   // window
   glBegin(GL_POLYGON);
      glVertex2f(0.1,0);
      glVertex2f(0.25,0);
      glVertex2f(0.25,0.15);
      glVertex2f(0.1,0.15);
   glEnd();

   glBegin(GL_POLYGON);
      glVertex2f(-0.1,0);
      glVertex2f(-0.25,0);
      glVertex2f(-0.25,0.15);
      glVertex2f(-0.1,0.15);
   glEnd();

   // door
   glBegin(GL_POLYGON);
      glVertex2f(0.1,-0.16);
      glVertex2f(0.1,-0.6);
      glVertex2f(-0.1,-0.6);
      glVertex2f(-0.1,-0.16);
   glEnd();

   // outline
   glColor3f(0.0f, 0.0f, 0.0f);
   glBegin(GL_LINE_STRIP);
      glVertex2f(0.35,0.3);
      glVertex2f(0.35,-0.6);
      glVertex2f(-0.35,-0.6);
      glVertex2f(-0.35,0.3);
      glVertex2f(0,0.8);
      glVertex2f(0.35,0.3);
      glVertex2f(-0.35,0.3);

   glEnd();

   // x, y axis
   glColor3f(0.5f, 0.5f, 0.5f);
   glBegin(GL_LINES);
      glVertex2f(1,0);
      glVertex2f(-1,0);
      glVertex2f(0,1);
      glVertex2f(0,-1);
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