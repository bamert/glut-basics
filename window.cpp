//#include <glut.h>
#include <GLUT/glut.h>
#include <iostream>
#include <cstring>
using namespace std;
const int wheight = 1200;
const int wwidth=400;
uint8_t image[wheight*wwidth*3];
void init(){
  glClearColor(0.0,0.0,0.0,0.0);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,wwidth,0,wheight);
}
/* optionally this can be used to auto-resize the window to its bounds
void resize(int width, int height) {
    // we ignore the params and do:
    glutReshapeWindow( wheight, wwidth);
} 
*/
void display(){
 //glPixelZoom(2,2);
 glClear(GL_COLOR_BUFFER_BIT);
 for(unsigned int i=0;i<wheight*wwidth*3;i+=3) {
    image[i] = 0;
    image[i+1] = 255;
    image[i+2] =  0 ;
  } 
  glDrawPixels(wheight, wwidth,GL_RGB, GL_UNSIGNED_BYTE,image);
  glutSwapBuffers();
  glFlush();
}
int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(wheight,wwidth);
  glutInitWindowPosition(30,30);
  glutCreateWindow("ndb");
    
  //glutReshapeFunc(resize);
  init();
  glutDisplayFunc(display);
  glutMainLoop();
}
