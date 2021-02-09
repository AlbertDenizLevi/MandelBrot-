# MandelBrot-
Hello, this is my first project to be ported to github so it lack many of the previous versions and unused code. 
Still the code is commented. 

This program creates stl files of specified mathematical recursive formulas, in this case mandelbrot set that has its c value increasing on real axis.
The output can be changed with many parameters for voxel density and field of calculation. If needed a very small part of the 3D structure can be generated.

Creation of layers, due to excessive memmory use is done incrementally by writing on files. THese files are ppm files and can be opened using visual editors such as photoshop,
but I use inkscape due to its free nature.

After the creation of layers the same program stiches the layers. At the time of writing the bottom layer might be buggy.
