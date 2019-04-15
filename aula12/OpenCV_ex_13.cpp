/*
 * OpenCV_ex_13.c
 *
 * AVERAGING FILTER
 *
 * J. Madeira - Dec 2012 + Nov 2017
 */


// Visual Studio ONLY - Allowing for pre-compiled header files

// This has to be the first #include

// Remove it, if you are not using Windows and Visual Studio


#include <iostream>


#include "opencv2/core/core.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/highgui/highgui.hpp"


// If you want to "simplify" code writing, you might want to use:

// using namespace cv;

// using namespace std;


// AUXILIARY  FUNCTION

void printImageFeatures( const cv::Mat &image )
{
    std::cout << std::endl;

	std::cout << "Number of rows : " << image.size().height << std::endl;

	std::cout << "Number of columns : " << image.size().width << std::endl;

	std::cout << "Number of channels : " << image.channels() << std::endl;

	std::cout << "Number of bytes per pixel : " << image.elemSize() << std::endl;

	std::cout << std::endl;
}


// MAIN

int main( int argc, char** argv )
{
    if( argc != 2 )
    {
		std::cout << "The name of the image file is missing !!" << std::endl;

        return -1;
    }

	cv::Mat originalImage;

	originalImage = cv::imread( argv[1], cv::IMREAD_UNCHANGED );

	if( originalImage.empty() )
	{
		// NOT SUCCESSFUL : the data attribute is empty

		std::cout << "Image file could not be open !!" << std::endl;

	    return -1;
	}

	if( originalImage.channels() > 1 )
	{
	    // Convert to a single-channel, intensity image

		cv::cvtColor( originalImage, originalImage, cv::COLOR_BGR2GRAY, 1 );
	}

    // Create window

	cv::namedWindow( "Original Image", cv::WINDOW_AUTOSIZE );

    // Display image

	cv::imshow( "Original Image", originalImage );

    // Print some image features

	std::cout << "ORIGINAL IMAGE" << std::endl;

    printImageFeatures( originalImage );

    // 3 x 3 Averaging Filter

    cv::Mat averagedImage_3x3_1;

	cv::blur( originalImage, averagedImage_3x3_1, cv::Size( 3, 3 ) );

	cv::namedWindow( "Averaging Filter 3 x 3 - 1 Iter", cv::WINDOW_AUTOSIZE );

	//cv::imshow( "Averaging Filter 3 x 3 - 1 Iter", averagedImage_3x3_1 );
	
	// 5x5 
	cv::Mat averagedImage_5x5_1;

	cv::blur( originalImage, averagedImage_5x5_1, cv::Size( 5, 5 ) );

	cv::namedWindow( "Averaging Filter 5 x 5 - 1 Iter", cv::WINDOW_AUTOSIZE );

	//cv::imshow( "Averaging Filter 5 x 5 - 1 Iter", averagedImage_5x5_1 );

	//7x7

	cv::Mat averagedImage_7x7_1;

	cv::blur( originalImage, averagedImage_7x7_1, cv::Size( 7, 7 ) );

	cv::namedWindow( "Averaging Filter 7 x 7 - 1 Iter", cv::WINDOW_AUTOSIZE );

	cv::imshow( "Averaging Filter 7 x 7 - 1 Iter", averagedImage_7x7_1 );


	//3x3 2 

	cv::Mat averagedImage_3x3_2;

	cv::blur( averagedImage_7x7_1, averagedImage_3x3_2, cv::Size( 7, 7 ) );

	cv::namedWindow( "Averaging Filter 3 x 3 - 2 Iter", cv::WINDOW_AUTOSIZE );

	cv::imshow( "Averaging Filter 3 x 3 - 2 Iter", averagedImage_3x3_2 );

	//3x3 3 

	cv::Mat averagedImage_3x3_3;

	cv::blur( averagedImage_3x3_2, averagedImage_3x3_3, cv::Size( 7, 7 ) );

	cv::namedWindow( "Averaging Filter 3 x 3 - 3 Iter", cv::WINDOW_AUTOSIZE );

	cv::imshow( "Averaging Filter 3 x 3 - 3 Iter", averagedImage_3x3_3 );

	//3x3 4

	cv::Mat averagedImage_3x3_4;

	cv::blur( averagedImage_3x3_3, averagedImage_3x3_4, cv::Size( 7, 7 ) );

	cv::namedWindow( "Averaging Filter 3 x 3 - 4 Iter", cv::WINDOW_AUTOSIZE );

	cv::imshow( "Averaging Filter 3 x 3 - 4 Iter", averagedImage_3x3_4 );

    // Waiting

	cv::waitKey( 0 );

	// Destroy the windows

	cv::destroyAllWindows();

	return 0;
}
