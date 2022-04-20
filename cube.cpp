//OGL_3DCubeSophsticated_160510.cpp.  Uses arrays, keyboard interaction, controlled animation
#include <GL/glut.h>
float ver[8][3] =//array to hold cube's 8 vertices
{
{ -0.5, 0.5, 0.5 },// LUF (Left Upper Front)
{ -0.5, -0.5, 0.5 },// LLF (Left Lower Front)
{ 0.5, -0.5, 0.5 },// RLF (Right Lower Front)
{ 0.5, 0.5, 0.5 },// RUF 
{ -0.5, 0.5, -0.5 },// LUB (Left Upper Back)
{ -0.5, -0.5, -0.5 },// LLB 
{ 0.5, -0.5, -0.5 },// RLB
{ 0.5, 0.5, -0.5 },// RUB
};
GLfloat color[8][3] =//array to hold color of cube's 6faces
{
{ 0.0, 0.0, 1.0 },//BLeft
{ 1.0, 0.0, 1.0 },//MRight
{ 0.0, 1.0, 0.0 },//GUpper
{ 1.0, 0.5, 0.0 },//OrangeLower
{ 1.0, 0.0, 0.0 },//RFront
{ 1.0, 1.0, 0.0 },//YBack
};
double rotate_y = 0;//For use in animation through keyboard
double rotate_x = 0;

//Function to draw cube: Every call draws a face
void quad(int clr, int ver1, int ver2, int ver3, int ver4)
{
glColor3fv(color[clr]);
glBegin(GL_QUADS);
glVertex3fv(ver[ver1]);
glVertex3fv(ver[ver2]);
glVertex3fv(ver[ver3]);
glVertex3fv(ver[ver4]);
glEnd();
}

void specialKeys(int key, int x, int y)
{
if (key == GLUT_KEY_RIGHT)rotate_y += 5;//right arrow
else if (key == GLUT_KEY_LEFT)rotate_y -= 5;//left arrow
else if (key == GLUT_KEY_UP)rotate_x -= 5;//up arrow
else if (key == GLUT_KEY_DOWN)rotate_x += 5;//down arrow
glutPostRedisplay();//Re-execte drawing, having rotated
}

void display()
{
glClearColor(1, 1, 1, 1);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2.0, 2.0, -2.0, 2.0, -2, 2);//Clipping vol.  Defualt z: 0, 1 (i.e. from z=0 to z=-1)
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(rotate_x, 1.0, 0.0, 0.0);//Keyboard controlled rotation
glRotatef(rotate_y, 0.0, 1.0, 0.0);

GLint LUF = 0, LLF = 1, RLF = 2, RUF = 3, LUB = 4, LLB = 5, RLB = 6, RUB = 7; // ver indices
//We call quad 6 times to draw 6 surfaces.  The arguments are indices into the arrays above
quad(0, LUF, LLF, LLB, LUB);//Draw left faceB
quad(1, RUF, RLF, RLB, RUB);//Draw right faceM
quad(2, LUF, RUF, RUB, LUB);//Draw upper faceG
quad(3, LLF, RLF, RLB, LLB);//Draw lower faceO
quad(4, LUF, RUF, RLF, LLF);//Draw front faceR
quad(5, LUB, RUB, RLB, LLB);//Draw back faceY
glutSwapBuffers();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
glutInitWindowSize(480, 480);
glutCreateWindow("Cube Sophsticated");
glutDisplayFunc(display);
glutSpecialFunc(specialKeys);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
}

