#ifndef MANIPULATEIMAGES_H
#define MANIPULATEIMAGES_H


#include <iostream>
#include <stdio.h>

#include <cv.h>
#include <highgui.h>
#include <string>
using namespace std;
//class manipulateImages
//{
//};

uchar * getPixelPtr(IplImage* im, int i, int j);

void createBlankImage(IplImage* im );

void replacePixel(IplImage* im1, IplImage* im2, int i1, int j1, int i2, int j2);
bool estDansIm(IplImage* im, int i, int j);
bool isBlank(IplImage * im, int x, int y);

void printImage(IplImage* im1, IplImage* im2, int x0, int y0);
void removeImage(IplImage* im1, IplImage * previous, IplImage* im2, int x0, int y0, int w, int h);
void addMessage(IplImage * im, string name1, string name2);
int printMessage(IplImage* im, string text, int x, int y);
void addButtons(IplImage* im, int nb, string* messages);

extern CvFont font;
#endif // MANIPULATEIMAGES_H
