#include "shapemaker.h"
#include <iostream>
#include <cmath>

using namespace std;

void ShapeMaker::clearCanvas(){
    canvas.clear();
    for(int i=0;i<height;i++){
        canvas.push_back(string(width,' '));
    }
}

ShapeMaker::ShapeMaker(){
    width=21;
    height=21;
    symbol='*';
    clearCanvas();
}

ShapeMaker::ShapeMaker(int w,int h,char s){
    width=w;
    height=h;
    symbol=s;
    clearCanvas();
}

int ShapeMaker::getWidth(){return width;}
int ShapeMaker::getHeight(){return height;}
char ShapeMaker::getSymbol(){return symbol;}

void ShapeMaker::setWidth(int w){width=w;clearCanvas();}
void ShapeMaker::setHeight(int h){height=h;clearCanvas();}
void ShapeMaker::setSymbol(char s){symbol=s;}

void ShapeMaker::printCanvas(){
    for(auto &line:canvas)cout<<line<<endl;
}

void ShapeMaker::drawHLine(){
    clearCanvas();
    int mid=height/2;
    for(int i=0;i<width;i++)canvas[mid][i]=symbol;
    printCanvas();
}

void ShapeMaker::drawVLine(){
    clearCanvas();
    int mid=width/2;
    for(int i=0;i<height;i++)canvas[i][mid]=symbol;
    printCanvas();
}

void ShapeMaker::drawFilledSquare(){
    clearCanvas();
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            canvas[i][j]=symbol;
    printCanvas();
}

void ShapeMaker::drawOpenSquare(){
    clearCanvas();
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            if(i==0||i==height-1||j==0||j==width-1)canvas[i][j]=symbol;
    printCanvas();
}

void ShapeMaker::drawSmileyFace(){
    clearCanvas();
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            canvas[i][j]=symbol;

    canvas[height/3][width/3]=' ';
    canvas[height/3][2*width/3]=' ';
    canvas[height/2][width/2]=' ';
    int mouthY=2*height/3;
    for(int x=width/4;x<3*width/4;x++)canvas[mouthY][x]=' ';
    printCanvas();
}

void ShapeMaker::drawOpenCircle(){
    clearCanvas();
    int cx=width/2;
    int cy=height/2;
    int r=width/2-1;
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++){
            int dx=j-cx;
            int dy=i-cy;
            double dist=sqrt(dx*dx+dy*dy);
            if(dist>r-0.5 && dist<r+0.5)canvas[i][j]=symbol;
        }
    printCanvas();
}

int main(){
    ShapeMaker s1;
    cout<<"H LINE"<<endl;
    s1.drawHLine();
    cout<<"\nV LINE"<<endl;
    s1.drawVLine();
    cout<<"\nFILLED SQUARE"<<endl;
    s1.drawFilledSquare();
    cout<<"\nOPEN SQUARE"<<endl;
    s1.drawOpenSquare();
    cout<<"\nSMILEY FACE"<<endl;
    s1.drawSmileyFace();
    cout<<"\nOPEN CIRCLE"<<endl;
    s1.drawOpenCircle();
    return 0;
}
