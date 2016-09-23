#include <GL/freeglut.h>

float angulo, aspecto;
float zNear = 0.1, zFar = 200; //glutPerspective
int posX = 0, posY = 80, posZ = 200; // Parametros da gluLookAT

void visualizacao(){
	glMatrixMode(GL_PROJECTION);  //Matriz Projeção
	glLoadIdentity();			  // Zera transformações 
	//configura Perspectiva
	gluPerspective(angulo, aspecto, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);	//muda p/matriz de visualizaçõa
	glLoadIdentity();			//Zera transformação
	gluLookAt(posX, posY, posZ,
		0, 0, 0,
		0, 1, 0);	//vetor "up"
}

void teclado(unsigned char key, int x, int y){

	switch (key)
	{
	case 27: // tecla esc
		exit(0);
		break;
	case 'a':
		angulo++;
		break;
	case 'A':
		angulo--;
		break;
	case 's':
		aspecto++;
		break;
	case 'S':
		aspecto--;
		break;
	case 'x':
		posX++;
		break;
	case 'X':
		posX--;
		break;
	case 'y':
		posY++;
		break;
	case 'z':
		posZ++;
		break;
	case 'Z':
		posZ--;
		break;
	case 'n': //Aumenta o plano de corte mais proximo do observador
		zNear++;
		break;
	case 'N':
		zNear--;
		break;
	case 'f':	//Aumenta o plano de corte mais longe do observador
		zFar++;
		break;
	case 'F':
		zFar--;
		break;
	default:
		break;
	}

	visualizacao();		//Metodo que aplica os novos paramentros
	glutPostRedisplay();	//Força desenho
}

//função chamada quando o tamanho da tela é alterado
void tamanhoJanela(int w, int h){
	if (h == 0){
		h = 1;
	} //evita divisão por zero
	glViewport(0, 0, w, h); //redefini o view port para o tamanho da janela
	aspecto = (float)w / (float)h; //calcula o 'aspect ratio'
	visualizacao();
}

//funcao callback do mouse
void mouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON){	//botão esquerdo moise
		if (state == GLUT_DOWN){		// botão pressionado
			if (angulo >= 10){
				angulo -= 5;
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON){	//botão direito precionado
		if (state == GLUT_DOWN){	//botão pressionado
			if (angulo <= 130){
				angulo += 5;
			}
		}
	}
	visualizacao();
	glutPostRedisplay();
}

void desenha(){
	glClearColor(0.0f, 0.0f, 0.1f, 0.0f);	//define cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);		//limpa tela
	glutWireTeacup(50.0f);				//desenha bule
	glutSwapBuffers();					//renderiza
}

int main(int argc, char** argv){
	glutInit(&argc, argv);		//inicializa biblioteca glut
	glutInitWindowSize(500, 500);		//tamanho da janela
	glutInitWindowPosition(50, 50);		//posição inicial da janela
	glutCreateWindow("Desenha Bule");	//cria janela
	angulo = 45;						//campo de visão (eixo y) inicio é de 45 graus
	glutDisplayFunc(desenha);			// função callback de redesenho
	glutReshapeFunc(tamanhoJanela);		//callback quando tamnho da janela alterada
	glutMouseFunc(mouse);				//Callback para tratamento do mouse
	glutKeyboardFunc(teclado);			//cALLBACK Para tratamento do teclado
	glutMainLoop();						//Loop do glut
}