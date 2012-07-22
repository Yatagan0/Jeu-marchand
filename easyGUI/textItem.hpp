#ifndef TEXTITEM_H
#define TEXTITEM_H

#include <string>

#include "GUIitem.hpp"

using namespace std;

class textItem : public GUIitem
{
    public:
        textItem(string n, string imName, string text, int x0, int y0);
        virtual ~textItem();
    protected:
    private:
};

#endif // TEXTITEM_H
