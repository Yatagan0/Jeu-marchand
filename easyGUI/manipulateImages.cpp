#import "manipulateImages.hpp"


uchar * getPixelPtr(IplImage* im, int i, int j)
{
    return ((uchar *)(im->imageData + i*im->widthStep + j*im->nChannels));
}

void createBlankImage(IplImage* im )
{
    for(int i = 0; i<im->height; i++)
    {
        for(int j = 0; j<im->width; j++)
        {
            uchar* ptr = ((uchar *)(im->imageData + i*im->widthStep + j*im->nChannels));
            for(int k = 0; k<im->nChannels; k++)
            {
                ptr[k] = 255;
            }
        }
    }
}

void replacePixel(IplImage* im1, IplImage* im2, int i1, int j1, int i2, int j2)
{
    uchar * ptr, *ptr2;
    if(estDansIm(im1, i1, j1) && estDansIm(im2, i2, j2))
    {
        ptr = getPixelPtr(im1, i1, j1);
        ptr2 = getPixelPtr(im2, i2, j2);
        bool blanc = true;
        for(int i = 0; i<im1->nChannels; i++)
        {

            if(ptr2[i] != 255)
            {
                blanc = false;
            }
        }
        if(!blanc)
        {
            for(int i = 0; i<im1->nChannels; i++)
            {

                ptr[i] = ptr2[i];
            }
        }
    }
}

bool estDansIm(IplImage* im, int i, int j)
{
    bool enX = (i>= 0) && (i<im->height);
    bool enY = (j>=0) && (j<im->width);
    return enX&&enY;
}

bool isBlank(IplImage * im, int x, int y)
{
    bool blank = true;
    uchar * ptr =getPixelPtr(im, x, y);
    for(int i = 0; i<im->nChannels; i++)
    {
        if(ptr[i] != 255)
            blank = false;
    }
    return blank;
}

void printImage(IplImage* im1, IplImage* im2, int x0, int y0)
{
    /*  for(int i = 0; i<min(im2->height, im1->height-x0); i++)
      {
          for(int j = 0; j<min(im2->width, im1->width - y0); j++)
          {
              replacePixel(im1, im2, i+x0, j+y0, i, j);
          }
      }*/
//cout<<"printImage"<<endl;
//cout<<"printImage h "<<im2->height<<endl;
    for(int i = 0; i<im2->height; i++)
    {
        for(int j = 0; j<im2->width; j++)
        {
          //  cout<<"printImage "<<i<<" "<<j<<endl;
            if(estDansIm(im1, i+x0, j+y0))
                replacePixel(im1, im2, i+x0, j+y0, i, j);
        }
    }

}


void removeImage(IplImage* im1, IplImage * previous, IplImage* im2, int x0, int y0, int w, int h)
{

    for(int i = 0; i<h; i++)
    {
        for(int j = 0; j<w; j++)
        {
            if(!isBlank(previous, i, j))
            {
                replacePixel(im1, im2, i+x0, j+y0, i+x0, j+y0);
            }
        }
    }
}

void addMessage(IplImage * im, string name1, string name2)
{

    int y = 20;
    string toText = name1+" :";
    //cvPutText (im,toText.c_str(),cvPoint(20,y), &font, cvScalar(20,20,20));

    y += 30;


    char text[] = "Bonjour, que puis-je pour vous ? Guillaume est un gentil garçon mais il pique un peu.";
    printMessage(im, text, 20, y);
}

int printMessage(IplImage* im, string text2, int x, int y)
{
    char*  text = new char [text2.size()+1];
    strcpy (text, text2.c_str());

    string toText = "";
    int taille = 0;

    //char str[] ="- This, a sample string.";
    char * pch;
// printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (text," ");
    while (pch != NULL)
    {

        taille += strlen(pch) + 1;
        if(taille > 42)
        {
            //    cvPutText (im,toText.c_str(),cvPoint(x,y), &font, cvScalar(20,20,20));
            y+= 25;
            toText = "";
            taille = strlen(pch) + 1;
        }

        toText = toText + (string)pch+" ";
        pch = strtok (NULL, " ");
    }
//   cvPutText (im,toText.c_str(),cvPoint(x,y), &font, cvScalar(20,20,20));
    y+= 30;
    return y;
}

void addButtons(IplImage* im, int nb, string* messages)
{
    int y = im->height - 30;

    for(int i = 0; i<nb; i++)
    {
        int x = i*(im->width)/nb+(im->width)/(2*nb);
        printMessage(im, messages[i], x, y);
    }
}
