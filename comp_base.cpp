#include <iostream>
#include <cmath>//for abs()
#include <string>//for to_string()
#include <fstream>//for ppm and 
#include <thread>
#include <mutex>
#include <sstream>
#include <chrono>
#include "complex.h"
#define width 100//aka. real axis, x
#define height 60//aka imaginary axis, y 
#define thickness 80//must be at least 2, z the axis where c in //f()=z^2+c comes from
//#define theforth 100

//#include "mathPrinter.h"
#define highTHRESHOLD 100 //how outwards can a pixel can go without being out of bounds
//#define lowTHRESHOLD -100
#define PIXEL_WEIGHT 20 //how long a pixel has to be tested to concur it stays in bounds //also number of shades of color

using namespace std;
mutex coutMutex;
int mandel(complex number, complex z)//f()=z^2+c
{
	
	int counter=PIXEL_WEIGHT;
	//while(((z.geti()+z.getr())/2)>highTHRESHOLD||(z.geti()+z.getr())<lowTHRESHOLD)
	for (int i = 0; i < PIXEL_WEIGHT && !(((abs(z.geti())+abs(z.getr()))/2)>highTHRESHOLD) ; i++)
	{
		z=z*z+number;
		number=z;//this should not be here for the standard but it was interesting
		counter--;
		//cout << z.getr() << " + " <<z.geti() <<endl; //for debugging calculation
	}
	//if(((abs(z.geti())+abs(z.getr()))/2)>highTHRESHOLD)
	//	return false;//it got out of bounds
	//return true;//it was in bounds
	if(counter==0)//
		return true;//
	else//
		return false;// this is when you want monochrome pictures
	//return counter;//this is when you want grayscale pictures
}

//void picCreate(double z)
//{
//	complex compz;
//	ofstream pic;
//	
//		string s=to_string((int)z) + "th_layer.ppm";
//		pic.open (s);
//		//use the next line and delete the one after if you want to make grayscale images
//		//pic << "P2" << endl << height << " " << width << endl << PIXEL_WEIGHT << endl;//first you have enter the color mode width height and number of colors that will be used on that color mode to make the file
//		pic << "P1" << endl << height << " " << width << endl << endl;
//		compz.seti(z/(thickness/2));
//		coutMutex.lock();
//		cout <<"layer "<< z << " has been initiated" << endl;
//		coutMutex.unlock();
//	
//		for(int x = -(width*1.25)/2; x< (width*0.75)/2;x++)
//		{
//			for(int y = -(height)/2; y<(height)/2; y++)
//			{
//				complex n;
//				n.seti(y/(height/4.0));
//				n.setr(x/(width/4.0));
//				//table.input(x,y,mandel(n));
//				pic << mandel(n,compz) << " ";
//			}
//			pic << endl;
//		}
//		pic.close();
//		coutMutex.lock();
//		cout <<"layer "<< z << " has been completed" << endl;
//		coutMutex.unlock();
//}

void BetterPicCreate(double z)
{
	complex compz;
	ofstream pic;
	
		string s=to_string((int)z) + "th_layer.ppm";
		pic.open (s);
		//use the next line and delete the one after if you want to make grayscale images
		//pic << "P2" << endl << height << " " << width << endl << PIXEL_WEIGHT << endl;//first you have enter the color mode width height and number of colors that will be used on that color mode to make the file
		pic << "P1" << endl << height << " " << width << endl << endl;
		compz.seti(z/(thickness/4.0));
		coutMutex.lock();
		cout <<"layer "<< z << " has been initiated" << endl;
		coutMutex.unlock();
	
		for(int x = -(width*0.55); x< (width*0.45);x++)
		{
			for(int y = -height/2; y<(height/2); y++)
			{
				complex n;
				n.seti(y/(height/4.0));
				n.setr(x/(width/4.0));
				//table.input(x,y,mandel(n));
				pic << mandel(n,compz) << " ";
			}
			pic << endl;
		}
		pic.close();
		coutMutex.lock();
		cout <<"layer "<< z << " has been completed" << endl;
		coutMutex.unlock();
}

//struct voxel
//{
//	ostream x =  "facet normal 1.000000 0.000000 0.000000"<< endl <<"outer loop"<< endl <<"vertex 1.0 1.0 0.0 "<< endl <<"vertex 1.0 1.0 1.0 "<< endl <<"vertex 1.0 0.0 0.0"<< endl <<"endloop"<< endl <<" endfacet"<< endl <<"facet normal 1.0 0.0 0.0"<< endl <<"outer loop"<< endl <<"vertex 1.0 0.0 0.0"<< endl <<"vertex 1.0 1.0 1.0"<< endl <<"vertex 1.0 0.0 1.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<""
//	ostream negx = "facet normal -1.0 0.0 0.0"<< endl <<"outer loop"<< endl <<"vertex 0.0 1.0 1.0"<< endl <<"vertex 0.0 1.0 0.0"<< endl <<"vertex 0.0 0.0 1.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"facet normal -1.0 0.0 0.0"<< endl <<"outer loop"<< endl <<"vertex 0.0 0.0 1.0"<< endl <<"vertex 0.0 1.0 0.0"<< endl <<" vertex 0.0 0.0 0.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<""
//	ostream y = "facet normal 0.0 1.0 0.0"<< endl <<"outer loop"<< endl <<"vertex 1.0 1.0 1.0"<< endl <<"vertex 1.0 1.0 0.0"<< endl <<" 0.0 1.0 1.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"facet normal 0.0 1.0 0.0"<< endl <<" loop"<< endl <<"vertex 0.0 1.0 1.0"<< endl <<"vertex 1.0 1.0 0.0"<< endl <<"vertex 0.0 1.0 0.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<""
//	ostream negy = "facet normal 0.0 -1.0 0.0"<< endl <<"outer loop"<< endl <<"vertex 1.0 0.0 0.0"<< endl <<"vertex 1.0 0.0 1.0"<< endl <<"vertex 0.0 0.0 0.0"<< endl <<"endloop"<< endl <<" endfacet"<< endl <<"facet normal 0.0 -1.0 0.0"<< endl <<"outer loop"<< endl <<"vertex 0.0 0.0 0.0"<< endl <<"vertex 1.0 0.0 1.0"<< endl <<"vertex 0.0 0.0 1.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<""
//	ostream z = "facet normal 0.0 0.0 1.0"<< endl <<"outer loop"<< endl <<"vertex 1.0 1.0 1.0"<< endl <<"vertex 0.0 1.0 1.0"<< endl <<"vertex 1.0 0.0 1.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"facet normal 0.0 0.0 1.0"<< endl <<"outer loop"<< endl <<"vertex 1.0 0.0 1.0"<< endl <<"vertex 0.0 1.0 1.0"<< endl <<"vertex 0.0 0.0 1.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<""
//	ostream negz = "facet normal 0.0 0.0 -1.0"<< endl <<" loop"<< endl <<"vertex 0.0 1.0 0.0"<< endl <<"vertex 1.0 1.0 0.0"<< endl <<"vertex 0.0 0.0 0.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"facet normal 0.0 0.0 -1.0"<< endl <<"outer loop"<< endl <<"vertex 0.0 0.0 0.0"<< endl <<"vertex 1.0 1.0 0.0"<< endl <<"vertex 1.0 0.0 0.0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"
//};

void print(bool nowmat [width][height])
{
	for(int y = 0; y<height; y++)
	{
		for(int x = 0; x<width ;x++)
			cout << nowmat[x][y];
		cout << endl;
	}
}

int main()
{
	int num_of_threads=2;//thickness is the outer dimension that I use for creating the layers, hence there is a ppm file for each layer
	thread * threads = new thread [num_of_threads];//creates a thread for each file
	
	for(int i=0; i<thickness/num_of_threads;i++)
	{
		for(int a=0; a<num_of_threads;a++)
			threads[a]=thread(BetterPicCreate,i*num_of_threads+a);//each thread also need to know which layer they are and this is why picCreate function has a double z input
		for(int b = 0; b<num_of_threads;b++)
			threads[b].join();
	}
	/*for(int i=0; i<num_of_threads;i++)
		BetterPicCreate(i);*/

	bool nowmat [width][height];
	bool beforemat [width][height];
	bool aftermat [width][height];

	ofstream stl;
	stl.open("file.stl");
	stl << "solid" << endl; 

	//for(int z=-thickness/2;z<thickness/2;z++)
	for(int z= 0 ; z<thickness ; z++)
	{
		if(z==0)//if(z==-thickness/2)
		{
			ifstream now;
			string s=to_string((int)z) + "th_layer.ppm";
			now.open (s);
			getline(now,s);
			getline(now,s);
			getline(now,s);
			for(int x = 0; x<width ;x++)
			{
				for(int y = 0; y<height; y++)
				{
					bool b;
					now >> b;
					nowmat[x][y] = b;
				}
			}
			now.close();
			cout << z << "th_layer.ppm read as a now file" << endl;
		}
		else//nowmat=aftermat;
		{
			for(int x = 0; x<width ;x++)
			{
				for(int y = 0; y<height; y++)
				{
					bool b;
					b=aftermat[x][y];
					nowmat[x][y] = b;
				}
			}
		}
		if(z==0)//if(z==-thickness/2)
		{
			for(int x = 0; x<width ;x++)
				for(int y = 0; y<height; y++)
					beforemat[x][y] = false;
			cout << "empty before matrix created"<< endl;
		}
		else
		{
			/*ifstream before;
			string s=to_string((int)(z-1)) + "th_layer.ppm";
			before.open (s);
			getline(before,s);
			getline(before,s);
			getline(before,s);*/
			for(int x = 0; x<width ;x++)
			{
				for(int y = 0; y<height; y++)
				{
					bool b;
					b = nowmat[x][y];
					beforemat[x][y] = b;
				}
			}
			cout << z-1 << "th_layer.ppm read as a before file" << endl;
			/*before.close();*/
		}
		//if(z==thickness/2-1)
		if(z==thickness-1)
		{
			for(int x = 0; x<width ;x++)
				for(int y = 0; y<height; y++)
					aftermat[x][y] = false;
			cout << "empty after matrix created"<< endl;
		}
		else
		{
			ifstream after;
			string s=to_string((int)(z+1)) + "th_layer.ppm";
			after.open (s);
			getline(after,s);
			getline(after,s);
			getline(after,s);
			for(int x = 0; x<width ;x++)
			{
				for(int y = 0; y<height; y++)
				{
					bool b;
					after >> b;
					aftermat[x][y] = b;
				}
			}
			after.close();
			cout << z+1 << "th_layer.ppm read as a after file" << endl;
		}

		/*cout <<	"printing now matrix" << endl;
		print(nowmat);
		cout << "printing before matrix" << endl;
		print (beforemat);
		cout << "printing after matrix" << endl;
		print(aftermat);
*/

		for(int x = 0; x<width ;x++)
		{
			for(int y = 0; y<height; y++)
			{
				if(nowmat[x][y]==1)
				{
					if(x+1!=width && nowmat[x+1][y]==0)
						stl <<  "facet normal 1.0 0.0 0.0"<< endl <<"outer loop"<< endl <<"vertex "<<x+1<<".0 "<<y+1<<".0 "<<z<<".0 "<< endl <<"vertex "<<x+1<<".0 "<<y+1<<".0 "<<z+1<<".0 "<< endl <<"vertex "<<x+1<<".0 "<<y<<".0 "<<z<<".0"<< endl <<"endloop"<< endl <<" endfacet"<< endl <<"facet normal 1.0 0.0 0.0"<< endl <<"outer loop"<< endl <<"vertex "<<x+1<<".0 "<<y<<".0 "<<z<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y+1<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y<<".0 "<<z+1<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl;
					if(x-1!=-1 && nowmat[x-1][y]==0)	//negx
						stl << "facet normal -1.0 0.0 0.0"<< endl <<"outer loop"<< endl <<"vertex "<<x<<".0 "<<y+1<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x<<".0 "<<y+1<<".0 "<<z<<".0"<< endl <<"vertex "<<x<<".0 "<<y<<".0 "<<z+1<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"facet normal -1.0 0.0 0.0"<< endl <<"outer loop"<< endl <<"vertex "<<x<<".0 "<<y<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x<<".0 "<<y+1<<".0 "<<z<<".0"<< endl <<"vertex "<<x<<".0 "<<y<<".0 "<<z<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl;
					if(y+1!= height && nowmat[x][y+1]==0)	//y 
						stl << "facet normal 0.0 1.0 0.0"<< endl <<"outer loop"<< endl <<"vertex "<<x+1<<".0 "<<y+1<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y+1<<".0 "<<z<<".0"<< endl <<"vertex "<<x<<".0 "<<y+1<<".0 "<<z+1<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"facet normal 0.0 1.0 0.0"<< endl <<"outer loop"<< endl <<"vertex "<<x<<".0 "<<y+1<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y+1<<".0 "<<z<<".0"<< endl <<"vertex "<<x<<".0 "<<y+1<<".0 "<<z<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl;
					if(y-1==-1 && nowmat[x][y]==1 || nowmat[x][y-1]==0)	//negy 
						stl << "facet normal 0.0 -1.0 0.0"<< endl <<"outer loop"<< endl <<"vertex "<<x+1<<".0 "<<y<<".0 "<<z<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x<<".0 "<<y<<".0 "<<z<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"facet normal 0.0 -1.0 0.0"<< endl <<"outer loop"<< endl <<"vertex "<<x<<".0 "<<y<<".0 "<<z<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x<<".0 "<<y<<".0 "<<z+1<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl;
					if(aftermat[x][y]==0)	//z 
						stl << "facet normal 0.0 0.0 1.0"<< endl <<"outer loop"<< endl <<"vertex "<<x+1<<".0 "<<y+1<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x<<".0 "<<y+1<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y<<".0 "<<z+1<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"facet normal 0.0 0.0 1.0"<< endl <<"outer loop"<< endl <<"vertex "<<x+1<<".0 "<<y<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x<<".0 "<<y+1<<".0 "<<z+1<<".0"<< endl <<"vertex "<<x<<".0 "<<y<<".0 "<<z+1<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl;
					if(beforemat[x][y]==1)	//negz 
						stl << "facet normal 0.0 0.0 -1.0"<< endl <<"outer loop"<< endl <<"vertex "<<x<<".0 "<<y+1<<".0 "<<z<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y+1<<".0 "<<z<<".0"<< endl <<"vertex "<<x<<".0 "<<y<<".0 "<<z<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl <<"facet normal 0.0 0.0 -1.0"<< endl <<"outer loop"<< endl <<"vertex "<<x<<".0 "<<y<<".0 "<<z<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y+1<<".0 "<<z<<".0"<< endl <<"vertex "<<x+1<<".0 "<<y<<".0 "<<z<<".0"<< endl <<"endloop"<< endl <<"endfacet"<< endl;
				}
			}
		}

	}
	stl << "endsolid";
	stl.close();

	//for(int x = -width/2; x< width;x++)
	//{
	//	for(int y = -height/2; y<height; y++)
	//		cout << table.reader(x,y);
	//	cout << endl;
	//}

	
	/*for(int x = -width/2; x< width/2;x++)
	{
		for(int y = -height/2; y<height/2; y++)
			pic << table.reader(x,y) << " ";
		pic << endl;
	}*/
	return 0;


}
//for checking if mandel and complex.h is working
	/*complex z;
	z.seti(-0.5);
	z.setr(-0.75);
	cout << mandel(z)<< endl ;*/