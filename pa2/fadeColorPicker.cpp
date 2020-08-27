#include "fadeColorPicker.h"

fadeColorPicker::fadeColorPicker(double fade)
{
    /* your code here */
    fadeFactor = fade;
    
}

HSLAPixel fadeColorPicker::operator()(point p)
{
    /* your code here */
    double distSq = pow(((p.x-p.c.x) * (p.x-p.c.x))+ ((p.y-p.c.y)*(p.y-p.c.y)),0.5);
    HSLAPixel ret;
    ret.l = p.c.color.l * pow(fadeFactor,distSq);
    ret.h = p.c.color.h;
    ret.s = p.c.color.s;
    return ret;

}
