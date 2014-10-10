
#include <glut.h>
#include <stdio.h>

struct alien
{
	float x, y;
	int muerto;
};


void marcianos(int x, int y, struct alien aliens[11][5])
{
	for(int alto = 0; alto < 5; alto++)
	{
		for(int largo = 0; largo < 11; largo++)
		{
			aliens[largo][alto].x=x;
			aliens[largo][alto].y=y;
			printf("%f, %f",aliens[largo][alto].x,aliens[largo][alto].y);
			glColor3f(1.0, 1.0, 1.0);
			glPointSize(3);
			glLineWidth(3);
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

			x = x + 12;
		}
		x = -65.0;
		y = y - 10.0;
	}
}

void nave(int w, int z)
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(w, z);
		glVertex2f(w+4, z+4);
		glVertex2f(w+8, z);
		glEnd();
}