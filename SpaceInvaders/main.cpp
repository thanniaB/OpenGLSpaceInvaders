
#include <glut.h>
#include <stdio.h>
//#include "marciano.h"

//w=-10.0, z=-80.0
float w=-65.0, z=-80.0, x=-65.0, y=70.0, xx=-65.0, yy=70.0;
float despX = 0;
int disparado=0, score=55, derecha = 0;

struct alien
{
	float x, y;
	int muerto;
};

struct alien aliens[11][5];

struct nave
{
	float w, z;
};

struct nave lanave;


struct disparo
{
	float j,k;
};

struct disparo boom;

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//marcianos(x,y,aliens);
	//nave(w,z);
	x += despX; 
	y = yy;
	

	for(int alto = 0; alto < 5; alto++) //y
	{
		for(int largo = 0; largo < 11; largo++) //x
		{
			glColor3f(1.0, 1.0, 1.0);
			glPointSize(3);
			glLineWidth(3);
			if(aliens[largo][alto].muerto == 1)
			{
					glColor3f(0.0, 0.0, 0.0);
			}
			glBegin(GL_POINTS);
				glVertex2f(x+2, y+1);
				glVertex2f(x+3, y);
				glVertex2f(x+2, y-4);
				glVertex2f(x+1, y-5);
				glVertex2f(x+6, y);
				glVertex2f(x+7, y+1);
				glVertex2f(x+7, y-4);
				glVertex2f(x+8, y-5);
			glEnd();

			glBegin(GL_LINES);
				glVertex2f(x, y);
				glVertex2f(x, y-2);
				glVertex2f(x+1, y-2);
				glVertex2f(x+1, y-3);
				glVertex2f(x+8, y-2);
				glVertex2f(x+8, y-3);
				glVertex2f(x+9, y);
				glVertex2f(x+9, y-2);
			glEnd();

			glBegin(GL_POLYGON);
				glVertex2f(x+2, y-1);
				glVertex2f(x+2, y-3);
				glVertex2f(x+7, y-1);
				glVertex2f(x+7, y-3);
			glEnd();
			
			glBegin(GL_POINTS);
				glVertex2f(x+3, y-2);
				glVertex2f(x+5, y-2);
			glEnd();
			

			x = x + 12 + despX;
		}
		x = -65.0 + despX;
		y = y - 10.0;
	}

	lanave.w=w;
	lanave.z=z;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(w, z);
		glVertex2f(w+4, z+4);
		glVertex2f(w+8, z);
		glEnd();

		if(disparado==1)
		{
			glColor3f(1.0, 1.0, 0.0);
			glBegin(GL_LINES);
				glVertex2f(boom.j, boom.k);
				glVertex2f(boom.j, boom.k+5);
			glEnd();
		}

	glutSwapBuffers();
}

void keyboardFunc(unsigned char key, int a, int b)
{
	if(key == 'a')
	{
		if(w >- 100){
		w = w - 12;
		}
	
	}
	else if(key == 'd')
	{
		if(w < 90)
		w = w + 12;
	}
	/*else if(key == 'w')
	{
		z=z+5;
	}
	else if(key == 's')
	{
		z=z-5;
	}*/

	if(key == 'p')
	{
		disparado = 1;
		boom.j = lanave.w;
		boom.k = lanave.z;
	}
	glutPostRedisplay();
}
/*
void Timer(int extra)
	{
	glutPostRedisplay();
	glutTimerFunc(7000,Timer,0);
	}*/

void TimerMarciano(int extra)
{
	if (despX == 0)
		despX = 10;
	else if (despX == 10)
		despX = -10;
	else
		despX = 0;

	/*
	if(xx<70 && derecha == 1)
		xx=xx+12;
	else {
		yy=yy-10;
		if(derecha == 1)
		{
			derecha = 0;
		}else if(derecha == 0)
		{
			derecha = 1;
		}
	}
	*/
	glutPostRedisplay();
	glutTimerFunc(2000,TimerMarciano,0);
}


void idleFunc()
{
	for(int alto = 0; alto < 5; alto++)
	{
		for(int largo = 0; largo < 11; largo++)
		{
			if(aliens[largo][alto].x == boom.j && aliens[largo][alto].y == boom.k)
			{
				if(aliens[largo][alto].muerto == 0)
				{
					disparado = 0;
					score = score - 1;
					printf("Aliens vivos: %d",score);
				}
				aliens[largo][alto].muerto = 1;
				
			}
		}
	}

	if(disparado == 1)
	{
		boom.k = boom.k + 1;
	//	glutTimerFunc(7000,Timer,0);
		if(boom.k > 100)
		{
			disparado = 0;
		}
	}

	//glutTimerFunc(2000,TimerMarciano,0);

	glutPostRedisplay();
}
void main()
{
	for(int alto = 0; alto < 5; alto++)
	{
		for(int largo = 0; largo < 11; largo++)
		{
			aliens[largo][alto].muerto = 0;
			aliens[largo][alto].x = x;
			aliens[largo][alto].y = y;
			x = x + 12;
		}
		x = -65.0;
		y = y - 10.0;
	}
	glutInitDisplayMode(GL_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Space Invaders");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
	glutDisplayFunc(displayFunc);
	glutIdleFunc(idleFunc);
	glutKeyboardFunc(keyboardFunc);
	glutTimerFunc(2000,TimerMarciano,0);
	glutMainLoop();

}