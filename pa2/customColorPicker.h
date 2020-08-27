/**
 * @file customColorPicker.h
 * Definition of a custom color picker.
 *
 */
#ifndef CUSTOMCOLORPICKER_H
#define CUSTOMCOLORPICKER_H

#include "colorPicker.h"
#include "point.h"
#include "center.h"

/**
 * customColorPicker: a functor that determines the color that should be used
 * given a point p, making the center's hue,saturation and luminance half and
 * the valid neignbours simply returning the new color of the
 * center.
 *
 */
class customColorPicker : public colorPicker
{
  public:
    /**
     * Constructs a new customColorPicker.
     *
     */
    customColorPicker();

    /**
     * Picks the color for point p
    *
     * @param p
     * @return The color of p's center
     */
    virtual HSLAPixel operator()(point p);

};

#endif
