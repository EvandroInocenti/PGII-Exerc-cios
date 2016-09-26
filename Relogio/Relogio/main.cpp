#include <math.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592
#define janela_altura 700
#define janela_largura 1200

float coordX = 0;
float coordY = -200;
GLfloat raio1 = 200;
GLfloat raio2 = 200;
GLfloat ang = 2 * PI;


void visualizacao();
void janela(GLsizei w, GLsizei h);
void teclado(unsigned char key, int x, int y);
void ponteiro();
void numeros();
void desenhar();
void animacao(int valor);
void DesenhaTexto(void *font, char *string);


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela
	glutInitWindowPosition(100, 100); // posicao que surge a janela
	glutCreateWindow("Relógio"); // cria janela
	glutReshapeFunc(janela);
	glutDisplayFunc(visualizacao);
	glutKeyboardFunc(teclado);
	glutTimerFunc(1000, animacao, 1);

	glutMainLoop();
	return(0);

}

void visualizacao(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.1f, 0.0f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	numeros();
	desenhar();

	glFlush();  // execute o desenho
}
void janela(GLsizei w, GLsizei h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char key, int x, int y){
	switch (key){
		case 27: 
			exit(0);
			break;
		case 'a':
			//antihorário
			break;

		default:
			break;

	}
	visualizacao();
	glutPostRedisplay();
}

void desenhar(){
	glColor3f(1.0, 0.0, 0.0);
	GLfloat circ_pnt = 300;
	GLfloat angCirc, raioX = 230.0f, raioY = 230.0f;
	GLfloat ang = 2 * PI;

	ponteiro();

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circ_pnt; i++){
		angCirc = (ang*i) / circ_pnt;
		glVertex2f(cos(angCirc)*raioX, sin(angCirc)*raioY);
		//printf("%f   %f\n", cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();
}

void ponteiro(){

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 0.0);
	glVertex2f(coordX, coordY);
	printf("%f   %f\n", coordX, coordY);
	glEnd();
}
void numeros(){

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(-10, 190);
	DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "12");
	glRasterPos2f(190, -10);
	DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "3");
	glRasterPos2f(10, -190);
	DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "6");
	glRasterPos2f(-190, 10);
	DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "9");
}

void animacao(int valor){

	coordX = cos(ang)*raio1;
	coordY = sin(ang)*raio2;

	//if (coordX >= 0.0 && coordX <= 210.0){
		//coordX += 20.0;
		//coordY -= 20.0;
//	}
	glutPostRedisplay();
	glutTimerFunc(1000, animacao, 1);
	
}

void DesenhaTexto(void *font, char *string)
{
	// Exibe caractere a caractere
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}
