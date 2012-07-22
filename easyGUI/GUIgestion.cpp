#include "GUIgestion.hpp"

IplImage* displayedImage;



void GUIgestion::Wrapper_To_Mouse_Call(int event, int x, int y, int flags, void* pt2Object)
{
    switch(event)
    {
    case CV_EVENT_LBUTTONDOWN:
        // explicitly cast to a pointer to TClassA
        GUIgestion* mySelf = (GUIgestion*) pt2Object;

        int myItemInd = mySelf->findItem(x, y);
       // cout << "I'm in !"<<endl;
        //cout << "Clic en " <<mySelf->name.c_str()<<endl;
        cout << "item n " <<myItemInd<<endl;
        if(myItemInd == -1)
            break;

        GUIitem* theItem = mySelf->items[myItemInd];
        switch(theItem->type)
        {
        case BUTTONITEM:
          //  cout << "it's a button"<<endl;
            theItem->execute();
            break;
        }
        break;
    }


    // call member
    //  mySelf->Display(string);
}

GUIgestion::GUIgestion(std::string n, int xx, int yy)
{
    items.clear();
    name = n;
    x = xx;
    y = yy;
    cvNamedWindow(name.c_str(), CV_WINDOW_AUTOSIZE);
    refresh();

    //ctor
}

GUIgestion::~GUIgestion()
{
    //dtor
}

void GUIgestion::refresh()
{
    cvReleaseImage(&displayedImage);
    displayedImage = cvCreateImage(cvSize(x, y), 8, 3 );
    createBlankImage(displayedImage);
    for(int i =0; i<items.size(); i++)
    {
        GUIitem* it = items[i];
       // cout << "Image en " <<it->posX <<", "<<it->posY<< endl;
        if(it->visible)
        printImage(displayedImage, it->im, (int)items[i]->posY, (int)items[i]->posX);
    }
    cvShowImage(name.c_str(), displayedImage);
    cvSetMouseCallback(name.c_str(),Wrapper_To_Mouse_Call,this);
    cvWaitKey(33);
}

void GUIgestion::addBackground()
{
    //dtor
}

void GUIgestion::addImage(int posX, int posY, string name, string imName, int type, void (*function)(GUIitem* ))
{
    GUIitem* newItem = new GUIitem(name, imName, posX, posY, type, function);
    items.push_back(newItem);
    //dtor
}

int GUIgestion::findItem(int posX, int posY)
{
    for(int i = items.size() -1; i>=0; i--)
    {
        // cout<<"test item "<<i<<endl;
        if(items[i]->visible && items[i]->isInItem(posX, posY))
            return i;
    }
    //cout<<"item not found"<<endl;
    return -1;
}

int GUIgestion::findItem(string name)
{
    for(int i = items.size() -1; i>=0; i--)
    {
        // cout<<"test item "<<i<<endl;
        if(items[i]->name == name)
            return i;
    }
    //cout<<"item not found"<<endl;
    return -1;
}


void GUIgestion::notVisible(string name){
int i = findItem(name);
items[i]->visible = false;
}
