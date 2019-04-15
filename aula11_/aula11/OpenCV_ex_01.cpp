/*
 * OpenCV_ex_01.cpp
 *
 * Simple example - Opening and displaying an image
 *
 * J. Madeira - Nov 2012 + Nov 2017
 */


// Visual Studio ONLY - Allowing for pre-compiled header files

// This has to be the first #include

// Remove it, if you are not using Windows and Visual Studio


// The remaining #includes

#include <iostream>

// Basic OpenCV functionalities

#include "opencv2/core/core.hpp"

#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"

// If you want to "simplify" code writing, you might want to use:

// using namespace cv;

// using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
    // To store an image

	Mat image;
	Mat Binary;
	Mat BinaryInv;
	Mat Trunc;
	Mat ToZero;
	Mat ToZeroInv;
	// Read an image from file

	// Note the flag : IMREAD_UNCHANGED

	// Question : which other flags can be used ?

	image = imread( argv[1], IMREAD_UNCHANGED );

	if( image.empty() )
	{
	    // NOT SUCCESSFUL : the data attribute is empty

	    std::cout << "Image file could not be open !!" << std::endl;

	    return -1;
	}

	// Create a window to display the image

    // WINDOW_AUTOSIZE : image size determines window size

	// Question : can the window be resized by the user ?

	// Question : which other flags can be used ?

	namedWindow( "Display window", WINDOW_AUTOSIZE );
	namedWindow("Binary", WINDOW_AUTOSIZE);
	namedWindow("BinaryInv", WINDOW_AUTOSIZE);
	namedWindow("Trunc", WINDOW_AUTOSIZE);
	namedWindow("ToZero", WINDOW_AUTOSIZE);
	namedWindow("ToZeroInv", WINDOW_AUTOSIZE);
	
    // Display the image

    

	threshold(image, Binary, 128, 255, THRESH_BINARY);
	threshold(image, BinaryInv, 128, 255, THRESH_BINARY_INV);
	threshold(image, Trunc, 128, 255, THRESH_TRUNC);
	threshold(image, ToZero, 128, 255, THRESH_TOZERO);
	threshold(image, ToZeroInv, 128, 255, THRESH_TOZERO_INV);
	

	imshow( "Display window", image );
	imshow("Binary", Binary);
	imshow("BinaryInv", BinaryInv);
	imshow("Trunc", Trunc);
	imshow("ToZero", ToZero);
    imshow("ToZeroInv", ToZeroInv);
    
    // Wait for a pressed key

    waitKey( 0 );

	// Destroy the window --- Actually not needed in such a simple program

	destroyWindow( "Display window" );

	return 0;
}
