# MandelBrot-
Hello, this is my first project to be ported to github so it lacks many of the previous versions and unused code. 
Still the code is commented. 

This program creates stl files (3D files that are easily 3d printed) of specified mathematical recursive formulas, in this case mandelbrot set that has its c value increasing on real axis. This causes the famous shape to warp, and these warped versions are sandwiched on top of eachother to make a 3d structure.

The output can be changed with many parameters for voxel density and field of calculation. If needed a very small part of the 3D structure can be generated.

Creation of layers, due to excessive memory use, is done incrementally by writing on ppm files. You might need to increase your heap to use the program if you make the layers (real and imaginary axis plane) too big. Keep it at around 400x400 for stability. These files are ppm files and can be opened using visual editors such as photoshop, but I use inkscape due to its free nature. A normal zoomed out text editor also suffices if images are not in grayscale mode.

After the creation of layers the same program stiches the layers. At the time of writing the bottom layer might be buggy.
