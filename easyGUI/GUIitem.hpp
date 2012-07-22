#ifndef GUIITEM_H
#define GUIITEM_H

#include <cv.h>
#include <highgui.h>
#include <iostream>

#include <string>

#define IMAGEITEM 0
#define BUTTONITEM 1
#define SLIDERITEM 2
#define TEXT_ITEM 2

using namespace std;

//void itemEmptyFunction();

class GUIitem
{
    public:
        GUIitem(string n, string imName, int x0, int y0, int t = IMAGEITEM, void (*function)(GUIitem*)=NULL);
        virtual ~GUIitem();

        string name;
        int posX;
        int sizeX;
        int posY;
        int sizeY;
int type;
bool visible;

        IplImage* im;

        void (*itemFunction)(GUIitem* item);

        bool isInItem(int x, int y);
        void execute();
    protected:
    private:
};

void itemEmptyFunction(GUIitem* item);
#endif // GUIITEM_H
