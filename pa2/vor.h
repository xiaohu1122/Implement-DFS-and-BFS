/**
 * @file vor.h
 * Defintion of a vor(onoi) namespace.
 *
 */
#ifndef _VOR_H_
#define _VOR_H_

#include "cs221util/PNG.h"
#include "stack.h"
#include "queue.h"
#include "center.h"
#include "point.h"
#include "animation.h"


#include "dotColorPicker.h"
#include "solidColorPicker.h"
#include "fadeColorPicker.h"
#include <random>
#include <vector>

using namespace cs221util;
using namespace std;

/**
 * filler namespace: specifies a set of functions for creating 
 * artistic effects using voronoi diagrams based on images
 *
 */
namespace filler
{

        /**
         * Performs a voronoi fill based on the given image using the color of 
         * the centers and employing a depth-first-search approach.
         *
         * @param img The image to be simulated
         * @param double density used to determine the number of centers.
         * @param frameFreq How frequently to add a frame to the animation, in
         *  pixels. For instance, if frameFreq == 1, a frame is added when every
         *  pixel is colored. If frameFreq == 10, a frame is added after every 10
         *  pixels are colored.
         * @return An animation that shows the fill progressing over the image.
         */
        animation vorSolidDFS(PNG& img, double density, int frameFreq);

        /**
         * Performs a voronoi fill based on the given image using the color of 
         * the centers and employing a depth-first-search approach. This fill
         * fades the center color using the fade factor, at each level of the 
         * algorithm. 
         *
         * @param img The image to be simulated
         * @param double density used to determine the number of centers.
         * @param double fade factor used to initialize the fade color picker.
         * @param frameFreq How frequently to add a frame to the animation, in
         *  pixels. For instance, if frameFreq == 1, a frame is added when every
         *  pixel is colored. If frameFreq == 10, a frame is added after every 10
         *  pixels are colored.
         * @return An animation that shows the fill progressing over the image.
         */
        animation vorFadeDFS(PNG& img, double density, double fadeFactor, int frameFreq);


        /**
         * Performs a voronoi fill based on the given image using the color of 
         * the centers and employing a breadth-first-search approach.
         *
         * @param img The image to be simulated
         * @param double density used to determine the number of centers.
         * @param frameFreq How frequently to add a frame to the animation, in
         *  pixels. For instance, if frameFreq == 1, a frame is added when every
         *  pixel is colored. If frameFreq == 10, a frame is added after every 10
         *  pixels are colored.
         * @return An animation that shows the fill progressing over the image.
         */
        animation vorSolidBFS(PNG& img, double density, int frameFreq);
        /**
         * Performs a voronoi fill based on the given image using the color of 
         * the centers and employing a breadth-first-search approach. This fill
         * fades the center color using the fade factor, at each level of the 
         * algorithm. 
         *
         * @param img The image to be simulated
         * @param double density used to determine the number of centers.
         * @param double fade factor used to initialize the fade color picker.
         * @param frameFreq How frequently to add a frame to the animation, in
         *  pixels. For instance, if frameFreq == 1, a frame is added when every
         *  pixel is colored. If frameFreq == 10, a frame is added after every 10
         *  pixels are colored.
         * @return An animation that shows the fill progressing over the image.
         */
        animation vorFadeBFS(PNG& img, double density, double fadeFactor, int frameFreq);

        /* The following two functions are given to you as examples of 
         * working fill functions.
        */

        /**
         * Performs a voronoi fill from the given image using a dot pattern,
         * employing a depth-first-search approach.
         *
         * @param img The image to be simulated
         * @param double density
         * @param dotGrid The width of the dot spacing.
         * @param dotSize The radius of the dot.
         * @param frameFreq How frequently to add a frame to the animation, in
         *  pixels. For instance, if frameFreq == 1, a frame is added when every
         *  pixel is colored. If frameFreq == 10, a frame is added after every 10
         *  pixels are colored.
         * @return An animation that shows the fill progressing over the image.
         */
        animation vorDotDFS(PNG& img, double density,
                           int dotGrid, int dotSize, int frameFreq);

        /**
         * Performs a voronoi fill from the given image using a dot pattern,
         * employing a breadth-first-search approach.
         *
         * @param img The image to be simulated
         * @param double density
         * @param dotGrid The width of the dot spacing.
         * @param dotSize The radius of the dot.
         * @param frameFreq How frequently to add a frame to the animation, in
         *  pixels. For instance, if frameFreq == 1, a frame is added when every
         *  pixel is colored. If frameFreq == 10, a frame is added after every 10
         *  pixels are colored.
         * @return An animation that shows the fill progressing over the image.
         */
        animation vorDotBFS(PNG& img, double density,
                           int dotGrid, int dotSize, int frameFreq);


/* 
 * Given in file vor_given.cpp. samples randomly or regularly.  It will
 * generate regular centers for the test cases.
*/

vector<center> randSample(PNG& img, double density);


    /**
     * General filling function: a general helper that should be invoked by
     * all of the public fill functions with the appropriate color picker
     * for that type of fill.
     *
     * @param img Image to do the filling on.
     * @param density Determines how many centers to use in the diagram
     * @param fillColor The colorPicker function object to be used for the fill.
     * @param frameFreq How frequently to add a frame to the animation, in
     *  pixels. For instance, if frameFreq == 1, a frame is added when every
     *  pixel is filled. If frameFreq == 10, a frame is added after every 10
     *  pixels is filled.
     * @return An animation that shows the fill progressing over the image.
     */
    template <template <class T> class OrderingStructure>
    animation vor(PNG& img, double density, colorPicker& fillColor,
                   int frameFreq);

    // helpers:


    /**
     * a helper function to mark a point as processed
     * @param pt the point to be marked
     * @param flag the flag board to store marks
     */
    void proc(point& pt, vector<vector<bool>> & flag);

    /**
     * determing if a given point is processed
     * @param pt given point
     * @param flag the flage board
     * @return will return true if given point is processed
     */
    bool isProc(point& pt, vector<vector<bool>>& flag);

    /**
     * change the color on the image at the specified point
     * @param pt the specified point
     * @param fillColor color picker
     * @param img the image to be changed
     */
    void changeColor(point& pt, colorPicker& fillColor, PNG& img);

    /**
     * euclidean distance
     * @param pt
     * @return return the euclidean distance between the given point
     * and its center
     */
    int euclidean(point& pt);

    /**
     * check if a given point is valid
     * @param curr previously removed point
     * @param pt the given point
     * @param img the Sample img
     * @param flag the flag board
     * @return return true if valid
     */
    bool isValid
    (point& curr, point& pt, PNG& img, vector<vector<bool>>& flag);

    /**
     * find the eight candidate point surrouding the given point
     * store them in a Queue
     * @param curr the given point
     * @return a Queue that store the candidates
     */
    Queue<point> getCandidate(point& curr);
}

#include "vor_given.cpp"
#include "vor.cpp"
#endif
