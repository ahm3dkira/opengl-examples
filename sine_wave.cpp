#include<GL/glut.h>
#include <cstring>
#include<math.h>
#define NumberOfCycles 4
#define AnimationIncrement 0.01
GLfloat alpha = AnimationIncrement; //For animated objects below. Global var initialized here
void Draw()
{
glLoadIdentity();//essential, or transofmations accumulating in CM will distort rendered objects progressively
glScalef(0.3, 0.3, 0.3);  //This allows coordinates below to exceed the default 1 in each direction
glClearColor(1, 1, 0, 1.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.2, 0.2, 0.4);
glTranslatef(-2, 0, 0);//Pull graphics -2 to the left


//Draw circle made-up of (360) litte line segments, each faces an angle=1deg
glBegin(GL_LINE_LOOP);//Connect pairs of generated points sequentially, start @ (1,0),(0.99,0.01)
for (int i = 0; i < 359; i++) glVertex2f(cos(i * 3.14 / 180), sin(i * 3.14 / 180));
glEnd();

//Draw arm inside above circle. Since 'display' will be executed many times, 
//each time the line has a different position,it will look as if it is rotating.
//For every alpha, the line will be at a different position.
glLineWidth(5);
glBegin(GL_LINES);
glVertex2f(0, 0);//Draw line between origin and point below (alpha is updated at end of 'display')
glVertex2f(cos(alpha * 3.14 / 180), sin(alpha * 3.14 / 180));  //(x,y)
glEnd();

//Draw 2 axes for circle: vertical then horizontal 
glLineWidth(1);
glColor3f(0, 0, 0);
glBegin(GL_LINES);
glVertex2f(0, 1.1);
glVertex2f(0, -1.1);
glVertex2f(-1.1, 0);
glVertex2f(1.1, 0);
glEnd();

// Draw (RED) stem ocillating up and down inside above circle in RED
glLineWidth(4);
glColor3f(1, 0, 0);
glBegin(GL_LINES);
glVertex2f(0, 0);
glVertex2f(0, sin(alpha * 3.14 / 180));//Same alpha as above, as they should be in sync
glEnd();

glTranslatef(1.2, 0, 0);

//Draw 2 axes for sine wave: vertical then horizontal
glLineWidth(1);
glColor3f(0, 0, 0);
glBegin(GL_LINES);
glVertex2f(0, 0);
glVertex2f(0, 2);
glVertex2f(0, 0);
glVertex2f(5, 0);
glEnd();

//Draw Sine wave in RED
glPointSize(4);
glColor3f(1, 0, 0);
glBegin(GL_POINTS);
for (int i = 0; i < alpha; i++)
glVertex2f(i / 360.0, cos(i * 2 * 3.14 / 360));
glEnd();

char string[14] = { "sin t" };
int StrLength = strlen(string);
glColor3f(0, 0, 1);

for (int i = 0; i < StrLength; i++)
{
glRasterPos2f(-0.2 + i * .1, 2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
}

glRasterPos2f(4, -0.2);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 't');

glFlush();
glutPostRedisplay();//Trigger glutDisplayFunc to re-execute (display), redrawing the window
alpha < NumberOfCycles * 360 ? alpha += AnimationIncrement : alpha = 0;//alpha serves as an angle. Starts 0 at beg of animation, and is increment by 0.05 indefinitely
}


int main(int iArgc, char** cppArgv) {
glutInit(&iArgc, cppArgv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(200, 200);
glutCreateWindow("Sine Wave");
glutDisplayFunc(Draw);
glutMainLoop();
return 0;
}