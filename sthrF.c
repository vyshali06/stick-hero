#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
int d[]={300,200,150,100,75,60,50,250,120,90};
int pw[]={50,70,90,100,120,135,115,60,20,40};
int i,f=1,x,z,z0,t,till,y,j=100,c=0;
void mouse(int btn,int state,int x,int y);
void check(int z0,int z);
void new_pl(int x);
void display();
void update();
int points=0,life=3;

void *fonts[]= 
{
GLUT_BITMAP_9_BY_15,
GLUT_BITMAP_TIMES_ROMAN_10,
GLUT_BITMAP_TIMES_ROMAN_24,
GLUT_BITMAP_HELVETICA_18,
GLUT_BITMAP_HELVETICA_12
};

void output(int x, int y, char *string, void *font)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

void menu1()
{
	glColor3f(0.8,.1,.2);
   output(150, 450, "STICK HERO",fonts[2]);
output(150,300,"SUBMITTED BY",fonts[0]);
	glColor3f(1,0,1);
output(50,275,"VYSHALI ACHARYA",fonts[3]);
output(250,275,"EDNA JOHNSON ",fonts[3]);
glColor3f(0.8,.1,.2);

   output(70,125," Press any key to continue...",fonts[0]);
   glColor3f(0.5,.6,.1);
output(50,250,"(1CR12CS121)",fonts[0]);
output(250,250,"(1CR12CS127)",fonts[0]);
	
} 

void menu2()
{
	glColor3f(0.8,.1,.2);
	output(100, 450, "STICK HERO",fonts[2]);

	glColor3f(0.1,0.1,0.1);	
   	glColor3f(0.5,.6,.1);

	output(300,450,"MENU",fonts[3]);
	glColor3f(0.6,0.3,0.7);
	output(150,350,"1. START",fonts[0]);
	output(150,320,"2. HELP",fonts[0]);
	output(150,290,"3. EXIT",fonts[0]);
	output(150,150,"[B] BACK",fonts[0]);
}

void help()
{
	
	glColor3f(0.8,.1,.2);
	output(150, 420, "HELP",fonts[2]);
	glColor3f(1,0,1);
	output(50,390,"1:Press the Left mouse button ",fonts[0]);
	output(50,370," to make the stick grow",fonts[0]);
	output(50,350,"2:On releasing the left mouse button the",fonts[0]);
	output(50,330," stick hero will move on to the next platform",fonts[0]);
	output(50,310,"3:The right button quits the game",fonts[0]);
	glColor3f(0.6,0.3,0.7);
	output(400,150,"[B] BACK",fonts[0]);
	glColor3f(0.1,0.1,0.1);	
   
   output(70,125," Press  ENTER to continue ...",fonts[0]);
   glColor3f(0.5,.6,.1);

}

void dis()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

gluOrtho2D(0, 499.0,0,499.0);
glMatrixMode(GL_MODELVIEW);
glClearColor(1.0, 1.0, 1.0, 1.0);

glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	if(f==0)
		display();

	else if(f==1)
		menu1();

	else if(f==2)
		menu2();

	else if(f==3)
		help();

		glFlush();
		glutSwapBuffers();
}

void NormalKey(GLubyte key, GLint x, GLint y) 
{
	if(key==27)		exit(0);
	if(f==1)	//menu1 .. cover page
	{		
		//if a key is pressed then goto menu
		f=2;		
		glutPostRedisplay();
	}
	else if(f==2)	//menu
	{
		switch(key)
		{
		case 13:
		case '1':f=0;	break;
		case '2':f=3;	break;
		case 'b':
		case 'B':f=1;	break;
		case '3':	exit(0);		
		}
		glutPostRedisplay();
	}
	else if(f==3)	//help
	{
		if(key=='b'||key=='B')
			f=2;
		else if(key==13)
			f=0;
		glutPostRedisplay();
	}

	else if(f==0)	// main program
	{
		switch ( key )    
		{ 

	 case 'b':	case 'B':
		f=2;
		glutPostRedisplay();
		break;
	 case 'h':	case 'H':
		f=3;
		glutPostRedisplay();
		break;
     default:
	break;
    }
	}
	dis();

}


void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

//ADDING PIXELS
void add_pixels()
{
	++j;
	glColor3f(1.0,0.0,0.0);
	glPointSize(5);
	glBegin(GL_POINTS);
		glVertex2i((pw[z0]-4),j);
	glEnd();
	glFlush();
	c++;
	usleep(10000);
}
void hor_pl(int z0,int z)
{	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(x,0);
	glVertex2i(x,100);
	glVertex2i(x+pw[z0],100);
	glVertex2i(x+pw[z0],0);
	glEnd();
	glFlush();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(y,0);
	glVertex2i(y,100);
	glVertex2i(y+pw[z],100);
	glVertex2i(y+pw[z],0);
	glEnd();
	glFlush();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);                             
          	glVertex2f(pw[z0]-23, 102);
   		glVertex2f(pw[z0]-23, 130);
  		glVertex2f(pw[z0]-5, 130);
   		glVertex2f(pw[z0]-5, 102);
     	glEnd();
	glFlush();
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-24,123);
		glVertex2i(pw[z0]-24,127);
		glVertex2i(pw[z0]-4,127);
		glVertex2i(pw[z0]-4,123);
	glEnd();
	glFlush();
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-10,121);
		glVertex2i(pw[z0]-10,123);
		glVertex2i(pw[z0]-8,123);
		glVertex2i(pw[z0]-8,121);
	glEnd();
	glFlush();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-23,100);
		glVertex2i(pw[z0]-23,102);
		glVertex2i(pw[z0]-20,102);
		glVertex2i(pw[z0]-20,100);
	glEnd();
	glFlush();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-8,100);
		glVertex2i(pw[z0]-8,102);
		glVertex2i(pw[z0]-5,102);
		glVertex2i(pw[z0]-5,100);
	glEnd();
	glFlush();
	int v;
	for(v=pw[z0]-4;v<(c+pw[z0]+4);v++)
	{
		glColor3f(1.0,0.0,0.0);
		glPointSize(5);
		glBegin(GL_POINTS);
			glVertex2i(v,100);
		glEnd();
		glFlush();
	}	
	check(z0,z);	
}
void moveman()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(x,0);
	glVertex2i(x,100);
	glVertex2i(x+pw[z0],100);
	glVertex2i(x+pw[z0],0);
	glEnd();
	glFlush();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(y,0);
	glVertex2i(y,100);
	glVertex2i(y+pw[z],100);
	glVertex2i(y+pw[z],0);
	glEnd();
	glFlush();
	glColor3f(1.0,0.0,0.0);
		glLineWidth(5);
		glBegin(GL_LINES);
			glVertex2i(x+pw[z0]-4,100);
			glVertex2i(c+pw[z0]+4,100);
		glEnd();
		glFlush();
	glMatrixMode(GL_MODELVIEW);
   
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(t,0,0);
  	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);                             
          	glVertex2f(pw[z0]-23, 102);
   		glVertex2f(pw[z0]-23, 130);
  		glVertex2f(pw[z0]-5, 130);
   		glVertex2f(pw[z0]-5, 102);
     	glEnd();
	glFlush();
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-24,123);
		glVertex2i(pw[z0]-24,127);
		glVertex2i(pw[z0]-4,127);
		glVertex2i(pw[z0]-4,123);
	glEnd();
	glFlush();
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-10,121);
		glVertex2i(pw[z0]-10,123);
		glVertex2i(pw[z0]-8,123);
		glVertex2i(pw[z0]-8,121);
	glEnd();
	glFlush();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-23,100);
		glVertex2i(pw[z0]-23,102);
		glVertex2i(pw[z0]-20,102);
		glVertex2i(pw[z0]-20,100);
	glEnd();
	glFlush();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-8,100);
		glVertex2i(pw[z0]-8,102);
		glVertex2i(pw[z0]-5,102);
		glVertex2i(pw[z0]-5,100);
	glEnd();
	glFlush();
	glPopMatrix();
		update();
	usleep(50000);
    glutSwapBuffers();
	while(t<till)
	{
		moveman();
	}
}

void check(int z0,int z)
{
	if(y<=(pw[z0]+c)&&(pw[z0]+c)<=(pw[z]+y))
	{
		points+=10;
		t=0;
		till=c;
		moveman();
		new_pl(z);
	}
	else
	{
		if((--life)==0)
		{
			printf("GAME OVER \n");
			printf("TOTAL SCORE : %d\n",points);
			glColor3f(0.8,.1,.2);
			output(50, 450, "GAME OVER",fonts[2]);
			glFlush();
			glutPostRedisplay();
			sleep(4);
			exit(0);
		}
		else
		{
			points+=5;
			printf("One life LOST! Number of lifes left=%d\n",life);
			glColor3f(0.8,.1,.2);
			output(50, 450, "One life LOST!",fonts[2]);
			glFlush();
			glutPostRedisplay();
			sleep(1);
			new_pl(z);
		}
	}
}

void new_pl(int x)
{
		x=0;int u;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2i(x,0);
		glVertex2i(x,100);
		glVertex2i(x+pw[z],100);
		glVertex2i(x+pw[z],0);
		glEnd();
		glFlush();
		z0=z;
		int c;c=rand()%10;
		y=0+pw[z]+d[c];
		z=rand()%10;
		if((y+pw[z])>500)
		{
			y=y/2;
			if(pw[z]>50)
			{
				pw[z]-=50;
			}
		}
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2i(y,0);
		glVertex2i(y,100);
		glVertex2i(y+pw[z],100);
		glVertex2i(y+pw[z],0);
		glEnd();
		glFlush();
		for(u=0;u<c;u++)
		{
			glColor3f(1.0,0.0,0.0);
			glPointSize(5);
			glBegin(GL_POINTS);
				glVertex2i(u,(pw[z0]-4));
			glEnd();
			glFlush();
		}
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_POLYGON);                             
          		glVertex2f(pw[z0]-23, 102);
   			glVertex2f(pw[z0]-23, 130);
  			glVertex2f(pw[z0]-5, 130);
   			glVertex2f(pw[z0]-5, 102);
	     	glEnd();
		glFlush();
		glColor3f(1.0f,0.0f,0.0f);
		glBegin(GL_POLYGON);
			glVertex2i(pw[z0]-24,123);
			glVertex2i(pw[z0]-24,127);
			glVertex2i(pw[z0]-4,127);
			glVertex2i(pw[z0]-4,123);
		glEnd();
		glFlush();
		glColor3f(1.0f,1.0f,1.0f);
		glBegin(GL_POLYGON);
			glVertex2i(pw[z0]-10,121);
			glVertex2i(pw[z0]-10,123);
			glVertex2i(pw[z0]-8,123);
			glVertex2i(pw[z0]-8,121);
		glEnd();
		glFlush();
			glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-23,100);
		glVertex2i(pw[z0]-23,102);
		glVertex2i(pw[z0]-20,102);
		glVertex2i(pw[z0]-20,100);
	glEnd();
	glFlush();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-8,100);
		glVertex2i(pw[z0]-8,102);
		glVertex2i(pw[z0]-5,102);
		glVertex2i(pw[z0]-5,100);
	glEnd();
	glFlush();
}

void mouse(int btn,int state,int x,int y)
{
	switch(btn)
	{
		case GLUT_LEFT_BUTTON:
					if(state == GLUT_DOWN)
					{
						glutIdleFunc(add_pixels);
						break;
					}
					if(state == GLUT_UP)
					{	
						hor_pl(z0,z);
						c=0;j=100;
						glutIdleFunc(NULL);
						break;
					}
		case GLUT_RIGHT_BUTTON:
					if( state == GLUT_DOWN )
					{
						exit(0);
					}
	}
}


void update()
{
    t+=5;	
}

void display()
{
	z0=rand()%10;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(0,100);
	glVertex2i(0+pw[z0],100);
	glVertex2i(0+pw[z0],0);
	glEnd();
	glFlush();
	int c;c=rand()%10;
	x=0+pw[z0]+d[c];
	z=rand()%10;
	if((x+pw[z])>500)
	{
		x=x/2;
		if(pw[z]>50)
		{
			pw[z]=pw[z]-50;
		}
	}
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(x,0);
	glVertex2i(x,100);
	glVertex2i(x+pw[z],100);
	glVertex2i(x+pw[z],0);
	glEnd();
	glFlush();
	
  	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);                             
          	glVertex2f(pw[z0]-23, 102);
   		glVertex2f(pw[z0]-23, 130);
  		glVertex2f(pw[z0]-5, 130);
   		glVertex2f(pw[z0]-5, 102);
     	glEnd();
	glFlush();
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-24,123);
		glVertex2i(pw[z0]-24,127);
		glVertex2i(pw[z0]-4,127);
		glVertex2i(pw[z0]-4,123);
	glEnd();
	glFlush();
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-10,121);
		glVertex2i(pw[z0]-10,123);
		glVertex2i(pw[z0]-8,123);
		glVertex2i(pw[z0]-8,121);
	glEnd();
	glFlush();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-23,100);
		glVertex2i(pw[z0]-23,102);
		glVertex2i(pw[z0]-20,102);
		glVertex2i(pw[z0]-20,100);
	glEnd();
	glFlush();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(pw[z0]-8,100);
		glVertex2i(pw[z0]-8,102);
		glVertex2i(pw[z0]-5,102);
		glVertex2i(pw[z0]-5,100);
	glEnd();
	glFlush();
	glutMouseFunc(mouse);
	y=x;
	x=0;
}

void myInit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,449,0,449);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(500,500);
        glutInitWindowPosition(0,0);
        glutCreateWindow("STICK HERO");
        glutDisplayFunc(dis);
	glutKeyboardFunc(NormalKey);
        myInit();
        glutMainLoop();
	return 0;
}
