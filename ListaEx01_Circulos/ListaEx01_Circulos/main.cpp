// desenho de circulo em opengl
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898 
#define janela_altura 400
#define janela_largura 600

void display(void);
void tela(GLsizei w, GLsizei h);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);	// suporte a janelas

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// PADRAO DE CORES

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela
	glutInitWindowPosition(100, 100); // posicao que surge a janela
	glutCreateWindow("circulo"); // cria janela

	//glutFullScreen();
	glutReshapeFunc(tela);  // configura a tela
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar

	return(0);
}

void desenhar()
{
	GLfloat circ_pnt = 10;
	GLfloat ang, raioX = 80.0f, raioY = 80.0f;

	glColor3f(1.0, 0.0, 0.0);  // cor
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
		printf("%f   %f\n", cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();
}

void display()
{
	glMatrixMode(GL_MODELVIEW);  //coordenadas de desenho
	glLoadIdentity();

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // cor do fundo
	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPESA

	// Especificar o local aonde o desenho acontece: bem no centro da janela
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);

	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();

	glFlush();  // execute o desenho

}

void tela(GLsizei w, GLsizei h)
{


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// cria a janela (esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);


	glMatrixMode(GL_MODELVIEW);

}

