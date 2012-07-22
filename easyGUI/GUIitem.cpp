#include "GUIitem.hpp"


GUIitem::GUIitem(string n, string imName, int x0, int y0, int t, void (*function)(GUIitem* ))
{
    posX = x0;
    posY = y0;
    type = t;
    name = n;

im = cvLoadImage(imName.c_str());
    sizeX = im->width;
    sizeY = im->height;
    visible = true;

if(function != NULL)
    itemFunction = function;
   /* cvNamedWindow("fenetre", CV_WINDOW_AUTOSIZE);
    cvShowImage("fenetre", man);
    cvWaitKey(0);*/
    //ctor
}

GUIitem::~GUIitem()
{
    //dtor
}

bool GUIitem::isInItem(int x, int y){
return (x >= posX) && (x<posX+sizeX) &&(y >= posY) && (y<posY+sizeY);
}

void GUIitem::execute(){
   // cout<<"executing"<<endl;
itemFunction(this);
}

void itemEmptyFunction(GUIitem * item){
 cout<<"I'm an empty function"<<endl;
}
