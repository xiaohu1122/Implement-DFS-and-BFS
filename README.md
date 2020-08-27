# Implement-DFS-and-BFS
## Goals and Overview
In this PA you will:

learn about Stacks, Queues, and Deques
learn about depth-first-search (DFS) and breadth-first-search (BFS) traversal
learn about some more advanced C++ constructs, including basic templates and inheritance
Getting the Given Code
Download the source files from pa2.zip, and follow the procedures you learned in lab to move them to your home directory on the remote linux machines.

## Part 1: The Stack, Queue, and Deque Classes
### The Deque Class
You will write a class named Deque which is a modification of a doubly ended queue structure. While the standard deque allows for insertion and removal at both ends of a contiguous arrangement of data, our deque will allow insertion and removal at one end, but only removal at the other. For convenience, we will refer to the removal-only end as the left end, and the other as the right.

Your deque should be implemented as follows: The underlying data structure will be a C++ standard vector. Following the convention of the queue we discussed in class, you will allow the data to “float” in the vector, with the following difference: If, upon a removal, you discover that the contiguous block of data (whose size is, say, k) will “fit” in the first k positions of the vector, then you should resize down by making a new vector and copying the k pieces of data into that new vector using the push_back function. Additions to the structure can use the standard vector functions, and can only occur at the “right” side of the contiguous data (i.e. the position of largest index). (Note that in this implementation the structure is not “circular”– we do not wrap the data using the modulo of the array size.)

### The Stack Class
You will write a class named Stack that works just like the stack you heard about in lecture, with the addition of the peek() function. It is declared in the given file stack.h. You will implement it in stack.cpp.

Your Stack class must implement all of the methods mentioned in the given code. Please read the documentation in the header file to see what limitations we have placed on your Stack class and what the running times of each function should be.

### The Queue Class
You will write a class named Queue that works just like the queue you heard about in lecture, with the addition of the peek() function. It is declared in the given file queue.h. You will implement it in queue.cpp.

Your Queue class must implement all of the methods mentioned in the given code. Please read the documentation in the header file to see what limitations we have placed on your Queue class and what the running times of each function should be.

## Part 2: Voronoi Diagrams
This part of the assignment is motivated by the following painting by Georges Seurat. It is a classic example of “pointillism,” wherein compact points of solid color are used to cover a region, revealing an image. Seurat’s most famous work, A Sunday Afternoon on the Island of La Grande Jatte is over two metres tall!

Zoom in on the picture here: https://www.artic.edu/artworks/27992/a-sunday-on-la-grande-jatte-1884

We will be simulating the pointillistic effect using a mathematical construct called a Voronoi Diagram, based on points randomly selected from a photograph.

The process for simulating the artistic effect begins with a photograph. Any one will do, but our examples will be based on this one:
There are many different algorithms we could use to create this image, but the most efficient strategy is to do a breadth first (also known as level order) traversal from each center. That is, we fill level k for all the centers before we fill any center’s level k+1. The figure below illustrates the growth of the fill from each center:
The technique we’re using to partition the image is very similar to a classic flood fill algorithm, run from several points simultaneously. A center’s fill simply stops when it runs into any region of the image that has already been colored.

For this part of the assignment, you will be writing a number of functions that execute a space partitioning fill on a PNG image. The Voronoi Diagram is achieved when we use a breadth first approach, but we could also use a depth first approach. In addition, instead of filling the partitions with a solid color, we can add simple patterns or textures to the fill regions. We will implement two different fill algorithms (breadth and depth) and three different fill patterns, described below.

## Functors
Your first task in this part of the project is to implement the mechanism by which colors are selected for the fill pattern. To do this, you will create function objects (or “functors”) which will be passed into the fill algorithm and applied to pixels in a PNG. Specifically you will be making two new functors, each of which will be derived classes of the abstract base class called colorPicker, which is provided and described in the given code file colorPicker.h. We have also given you an example functor so you can see how things are supposed to work. Our functor is called dotColorPicker. The colorPicker base class has one purely virtual function that you must implement in your derived classes, but you may add others if you wish. In particular, you should expect your derived class constructors to initialize the functor with situation-dependent variables.

The purpose of any colorPicker is to take an image point containing its (x,y) coordinates as a parameter to operator(), and to return the color that point p should be in the fill. So in the examples above, the colorPicker is simply returning the color of the nearest center.

Your task is to implement the solidColorPicker, fadeColorPicker, and customColorPicker function objects. Refer to the given code for implementation details: they must overwrite the abstract operator()!

### solidColorPicker 
The first pattern will be a solid color the same as the point’s center. Its behavior is described in the given code, and sample images are given in soln_images.

### fadeColorPicker 
The second fill pattern will fade to black as the points get farther from the center. Again, the specification is described in the given code.

### customColorPicker 
The third exercise will be a fill pattern of your own creation!! You must create files customColorPicker.h and customColorPicker.cpp to change the pixels in the fill using some interesting pattern you design. You’ll also give us the .gif images created by your custom work. Note that we’ll leave it to you to figure out how to change your Makefile, vor.h, and vor.cpp to accommdate the new color picker.

## The Fill Algorithms
The animations in the .gif images above are the result of breadth-first-search (BFS) and depth-first-search (DFS), respectively, both with a solid fill. We have given you the dot fill functions as an example for the others.

You will be implementing both DFS and BFS, each with the three different fill patterns described above.

You must implement all of the functions inside the filler namespace. Refer to the documentation in the header file for implementation details.
