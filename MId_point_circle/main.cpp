#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x=0,y,x2,y2,p;
int dx=0,dy=0,r;
void display(void)
{

glClear (GL_COLOR_BUFFER_BIT);
glEnd();

    glColor3f (0.0, 0.0, 1.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    p=1-r;
    while((x<=y)){
        if(p<0){
          x=x+1;
          y=y;
            printf("x= %0.2f y= %0.2f\n",x,y);
            p=p+(2*x)+1;
            }


            else{
            x=x+1;
            y=y-1;
            printf("x= %0.2f y= %0.2f\n",x,y);
            p=p+(2*x)+1-(2*y);
            }
            glVertex3f (((x/100)), ((y/100)), 0.0);
            glVertex3f (((y/100)), ((x/100)), 0.0);
            glVertex3f ((-(x/100)), (-(y/100)), 0.0);
            glVertex3f ((-(x/100)), ((y/100)), 0.0);
            glVertex3f (((x/100)), (-(y/100)), 0.0);
            glVertex3f (((y/100)), (-(x/100)), 0.0);
            glVertex3f ((-(y/100)), (-(x/100)), 0.0);
            glVertex3f ((-(y/100)), ((x/100)), 0.0);
        }
glEnd();
glFlush ();
}
void init (void)
{

glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

}

int main(int argc, char** argv)
{

    printf("Enter radius Of the circle: ");
    scanf("%d",&r);
    y=r;
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Mid Point Circle Algorithm");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
