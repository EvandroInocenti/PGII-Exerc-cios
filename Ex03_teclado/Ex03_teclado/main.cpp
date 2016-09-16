#include "GL/freeglut.h"

void Desenha(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void Inicializa(){
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void teclado(unsigned char key, int x, int y){

	static bool telaCheia = false;

	if (key == 'q' || key == 'Q' || key == 27){
		exit(0);
	}
}

int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Primeira Janela OpenGL");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(Desenha);
	Inicializa();
	glutKeyboardFunc(&teclado);
	glutMainLoop();

	return 0;
}