#include "customColorPicker.h"

customColorPicker::customColorPicker()
{

}

HSLAPixel customColorPicker::operator()(point p)
{
   HSLAPixel ret;
   ret.h = p.c.color.h*0.5;
   ret.s = p.c.color.s*0.5;
   ret.l = p.c.color.l*0.5;
   return ret;
}

