#include <windows.h>
#include <GL/glut.h>
#define PI 3.141516
#include<math.h>


GLfloat cloud_position = 0.0f;
GLfloat cloud_speed = 0.01f;
int wheel_angle=0;


void update(int value)
{
    ///cloud translatoin
    if(cloud_position <-1.5)
        cloud_position = 1.0f;
    cloud_position -= cloud_speed;




glutPostRedisplay();


glutTimerFunc(100, update, 0);
}

void initGL()
{

	glClearColor(0.0f, 0.6f, 0.9f, 0.0f);
}

void circle(float p1, float q1, float r1)
{
    int i;
    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);

    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );


    }
    glEnd ();
}

void cloud(float xc, float yc)
{
    glColor3f(1, 1, 1);
    circle(xc, yc, 0.15f);
    circle(xc-0.13, yc-0.02, 0.12f);
    circle(xc+0.14, yc+0.02, 0.10f);
}

void wheel()
{
    ///outer outer circle
        glColor3ub(150,150,150);
        circle(0,0,0.05);
        ///outer inner circle
        glColor3ub(0,0,0);
        circle(0,0,0.04);
        ///inner lines 1
        glColor3ub(250,250,250);
        glLineWidth(2);
        glBegin(GL_LINES);
        glVertex2f(-0.035,0);
        glVertex2f( 0.035,0);
        glEnd();
        ///inner lines 2
        glPushMatrix();
        glRotatef(45,0,0,1);
            glColor3ub(250,250,250);
            glLineWidth(2);
            glBegin(GL_LINES);
            glVertex2f(-0.035,0);
            glVertex2f( 0.035,0);
            glEnd();
        glPopMatrix();
        ///inner lines 3
        glPushMatrix();
        glRotatef(90,0,0,1);
            glColor3ub(250,250,250);
            glLineWidth(2);
            glBegin(GL_LINES);
            glVertex2f(-0.035,0);
            glVertex2f( 0.035,0);
            glEnd();
        glPopMatrix();
        ///inner lines 4
        glPushMatrix();
        glRotatef(135,0,0,1);
            glColor3ub(250,250,250);
            glLineWidth(2);
            glBegin(GL_LINES);
            glVertex2f(-0.035,0);
            glVertex2f( 0.035,0);
            glEnd();
        glPopMatrix();
        ///inner outer circle
        glColor3ub(150,150,150);
        circle(0,0,0.015);
        ///inner inner circle
        glColor3ub(0,0,0);
        circle(0,0,0.01);
}





void background()
{



    glBegin(GL_QUADS);///left side tree body
	glColor3f(0.5f, 0.0f, 0.0f);

	glVertex2f(-0.43f, -0.06f);
	glVertex2f(-0.43f, -0.215f);
	glVertex2f(-0.41f, -0.215f);
	glVertex2f(-0.41f, -0.06f);
	glEnd();

    glBegin(GL_TRIANGLES);///Greed tree
	glColor3f(0.0f, 0.8f, 0.0f);

	glVertex2f(-0.5f, -0.06f);
	glVertex2f(-0.34f, -0.06f);
	glVertex2f(-0.42f,  0.1f);
    glEnd();

    		glBegin(GL_TRIANGLES);///Greed tree
	glColor3f(0.0f, 0.8f, 0.0f);

	glVertex2f(-0.495f, -0.02f);
	glVertex2f(-0.345f, -0.02f);
	glVertex2f(-0.42f,  0.17f);
    glEnd();

        		glBegin(GL_TRIANGLES);///Greed tree
	glColor3f(0.0f, 0.8f, 0.0f);

	glVertex2f(-0.49f, 0.02f);
	glVertex2f(-0.35f, 0.02f);
	glVertex2f(-0.42f,  0.2f);
    glEnd();


    glBegin(GL_QUADS);///lamp post right
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2f(0.71f, 0.03f);
	glVertex2f(0.71f, -0.215f);
	glVertex2f(0.696f, -0.215f);
	glVertex2f(0.696f, 0.03f);
	glEnd();


    glBegin(GL_QUADS);///lamp post left
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(-0.72f, 0.07f);
	glVertex2f(-0.71f, 0.03f);
	glVertex2f(-0.696f, 0.03f);
	glVertex2f(-0.685f, 0.07f);
	glEnd();

	glBegin(GL_TRIANGLES);///lamp post left
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2f(-0.72f, 0.07f);
	glVertex2f(-0.685f, 0.07f);
	glVertex2f(-0.7f,  0.09f);


	glEnd();




	glBegin(GL_QUADS);///lamp post right
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2f(0.71f, 0.03f);
	glVertex2f(0.71f, -0.215f);
	glVertex2f(0.696f, -0.215f);
	glVertex2f(0.696f, 0.03f);
	glEnd();

				    glBegin(GL_QUADS);///lamp post right
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(0.72f, 0.07f);
	glVertex2f(0.71f, 0.03f);
	glVertex2f(0.696f, 0.03f);
	glVertex2f(0.685f, 0.07f);
	glEnd();

	glBegin(GL_TRIANGLES);///lamp post right
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2f(0.72f, 0.07f);
	glVertex2f(0.685f, 0.07f);
	glVertex2f(0.7f,  0.09f);


	glEnd();

	glBegin(GL_QUADS);///right side tree body
	glColor3f(0.5f, 0.0f, 0.0f);

	glVertex2f(0.43f, -0.06f);
	glVertex2f(0.43f, -0.215f);
	glVertex2f(0.41f, -0.215f);
	glVertex2f(0.41f, -0.06f);
	glEnd();

		glBegin(GL_TRIANGLES);///Green tree
	glColor3f(0.0f, 0.8f, 0.0f);

	glVertex2f(0.5f, -0.06f);
	glVertex2f(0.34f, -0.06f);
	glVertex2f(0.42f,  0.1f);
    glEnd();

    		glBegin(GL_TRIANGLES);///Green tree
	glColor3f(0.0f, 0.8f, 0.0f);

	glVertex2f(0.495f, -0.02f);
	glVertex2f(0.345f, -0.02f);
	glVertex2f(0.42f,  0.17f);
    glEnd();

          		glBegin(GL_TRIANGLES);///Green tree
	glColor3f(0.0f, 0.8f, 0.0f);

	glVertex2f(0.49f, 0.02f);
	glVertex2f(0.35f, 0.02f);
	glVertex2f(0.42f,  0.2f);
    glEnd();


    ///cloud speed
    glPushMatrix();
        glTranslatef(cloud_position,0.0f, 0.0f);
        cloud(0.5f, 0.8f);
        cloud(-0.0f, 0.8f);
    glPopMatrix();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	background();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1080, 720);
	glutCreateWindow("A Busy Street View");
	glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);

	initGL();
	glutMainLoop();
	return 0;
}
