//#include <glut.h>
#include <GLUT/glut.h>
#include <iostream>
#include <cstring>
using namespace std;
const int wheight = 1200;
const int wwidth=400;
bool toggle = false;
uint8_t image[wheight*wwidth*3];
void init(){
  glClearColor(0.0,0.0,0.0,0.0);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,wwidth,0,wheight);
}

void resize(int width, int height) {
    // we ignore the params and do:
    glutReshapeWindow( wheight, wwidth);
} 
void displayText( float x, float y, int r, int g, int b, const char *string ) {
	int j = strlen( string );

	glColor3f( r, g, b );
	glRasterPos2f( x, y );
	for( int i = 0; i < j; i++ ) {
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
		//glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, string[i] );
	}
  glRasterPos2f(0,0);//reset!
}
void display(){
 //glPixelZoom(2,2);
 glClear(GL_COLOR_BUFFER_BIT);
 for(unsigned int i=0;i<wheight*wwidth*3;i+=3) {
    image[i] = 0;
    image[i+1] = 255;
    image[i+2] = (toggle == true) ? 255 : 0 ;
    //image[i+3] = 255;
  } 
  glDrawPixels(wheight, wwidth,GL_RGB, GL_UNSIGNED_BYTE,image);
  displayText(50,50,0,0,0,"This is a test-text");
  glutSwapBuffers();
  glFlush();
}

void onMousePress(int button, int state, int x, int y){
 if(state == GLUT_DOWN){
   cout << "toggle status:" << toggle << endl;
   toggle ^=1;
   glutPostRedisplay();
 }
}
int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(wheight,wwidth);
  glutInitWindowPosition(30,30);
  glutCreateWindow("ndb");
    
  glutReshapeFunc(resize);
  init();
  glutDisplayFunc(display);
  glutMouseFunc(onMousePress);
  glutMainLoop();
}
