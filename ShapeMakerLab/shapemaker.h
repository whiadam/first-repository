#include <vector>
#include <string>

using namespace std;

class ShapeMaker{
private:
    int width;
    int height;
    char symbol;
    vector<string> canvas;

    void clearCanvas();

public:
    ShapeMaker();
    ShapeMaker(int w,int h,char s);

    int getWidth();
    int getHeight();
    char getSymbol();

    void setWidth(int w);
    void setHeight(int h);
    void setSymbol(char s);

    void drawHLine();
    void drawVLine();
    void drawFilledSquare();
    void drawOpenSquare();
    void drawSmileyFace();
    void drawOpenCircle();

    void printCanvas();
};
