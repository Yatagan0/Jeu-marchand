#ifndef GUIGESTION_H
#define GUIGESTION_H

#include <vector>
#include <string>
#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <stdio.h>

#include "GUIitem.hpp"
#include "manipulateImages.hpp"

class GUIgestion
{
public:

//void mouseHandler(int event, int x, int y, int flags, void* param);
    GUIgestion(std::string n, int x, int y);
    virtual ~GUIgestion();
    std::vector<GUIitem*> items;
    std::string name;
    int x;
    int y;

    void refresh();

    void addBackground();

    void addImage(int posX, int posY, string name, string imName, int type = IMAGEITEM, void (*function)(GUIitem*)=itemEmptyFunction);
    static void Wrapper_To_Mouse_Call(int event, int x, int y, int flags, void* pt2Object);
    int findItem(int posX, int posY);
    int findItem(string name);
    void notVisible(string name);

protected:
private:
};

#endif // GUIGESTION_H
