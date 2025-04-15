#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

float A,B,C;
const float cubeWidth = 20;
const int width = 160;
const int height = 44;
float zBuffer[width*height];
char buf[width*height];
int colorBuf[width*height];
int backgroundAscii = ' ';
int distanceFromcam = 100;
float K1 = 40;
float x,y,z;
float ooz;
int xp,yp;
int idx;

float cacluteX(int i,int j,int k){
  return j*sin(A)*sin(B)*cos(C)
        - k*cos(A)*sin(B)*cos(C)
        + j*cos(A)*sin(C)
        + k*sin(A)*sin(C)
        + i*cos(B)*cos(C);
}

float cacluteY(int i,int j,int k) {
  return j*cos(A)*cos(C)
         + k*sin(A)*cos(C)
         - j*sin(A)*sin(B)*sin(C)
         + k*cos(A)*sin(B)*sin(C)
         - i*cos(B)*sin(C);
}

float cacluteZ(int i,int j,int k) {
  return k*cos(A)*cos(B)
         - j*sin(A)*cos(B)
         + i*sin(B);
}

void cacluteForPoint(float i,float j,float k,int c,int ch){
  x = cacluteX(i, j, k);
  y = cacluteY(i, j, k);
  z = cacluteZ(i, j, k) + distanceFromcam;
  ooz = 1/z;
  xp = (int)(width/2 + K1*ooz*x*2);
  yp = (int)(height/2 + K1*ooz*y);
  idx = xp+yp*width;

  if(idx >= 0 && idx < width*height){
    if(ooz > zBuffer[idx]){
      zBuffer[idx] = ooz;
      buf[idx] = ch;
      colorBuf[idx] = c;
    }
  }
}

int main(){
  printf("\x1b[2j");
  while (1){
    memset(buf,backgroundAscii,sizeof(buf));
    memset(zBuffer, 0, sizeof(zBuffer));
    memset(colorBuf, 37, sizeof(colorBuf));
    for(float i=-cubeWidth/2;i<cubeWidth/2;i+=0.15){
      for(float j=-cubeWidth/2;j<cubeWidth/2;j+=0.15){
        cacluteForPoint(i,j,-cubeWidth/2,31,'@');
        cacluteForPoint(cubeWidth/2,i,j,32,'$');
        cacluteForPoint(-cubeWidth/2,i,j,33,'.');
        cacluteForPoint(i,j,cubeWidth/2,34,';');
        cacluteForPoint(i,-cubeWidth/2,j,35,'&');
        cacluteForPoint(i,cubeWidth/2,j,36,'*');
      }
    }

    printf("\x1b[H");
    for(int k=0;k<width*height;k++){
      if (k % width == 0) 
        putchar(10);
      else 
        printf("\x1b[%dm%c", colorBuf[k], buf[k]);
    }
    printf("\x1b[0m");
    A += 0.005;
    B += 0.005;
    C += 0.02;
    usleep(16000);
  }
  return 0;
}
