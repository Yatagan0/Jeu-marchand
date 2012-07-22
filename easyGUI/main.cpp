#include <iostream>
#include <stdio.h> // Pour le printf()...

#include <time.h>

#include "GUIgestion.hpp"

using namespace std;

void otherFunction(){
cout<<"Manon is cool"<<endl;
}

void otherFunction2(){
cout<<"Manon is geek"<<endl;
}


/*int main()
{
    cout << "Hello world!" << endl;

    GUIgestion fenetre1("maFenetreDeTest", 300, 200);
    fenetre1.addImage(50, 30, "lena", "lena.jpg");
    fenetre1.addImage(50, 30, "bouton1", "man2.png", BUTTONITEM, otherFunction);
    fenetre1.addImage(150, 40, "bouton2",  "man2.png", BUTTONITEM);
    fenetre1.notVisible("bouton2");

    GUIgestion fenetre2("maFenetreDeTest2", 400, 200);
    fenetre2.addImage(10, 10, "lena", "lena.jpg");
        fenetre2.addImage(50, 30, "bouton1", "man2.png", BUTTONITEM, otherFunction2);

    fenetre1.refresh();
    fenetre2.refresh();
    cvWaitKey(0);
    return 0;
}*/
