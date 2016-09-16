#include "GL/freeglut.h"

void Desenha(void){

	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc, char **argv){

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutCreateWindow("Primeira Janela OpenGL");
		glutDisplayFunc(Desenha);
		glutMainLoop();

		return 0;
}