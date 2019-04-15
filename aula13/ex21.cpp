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

	cv::Mat tabuleiro;
    cv::Mat imagemBinaria;

	tabuleiro = cv::imread( "index.png", cv::IMREAD_UNCHANGED );
    
    int erosion_size = 10;

    //EX1

    cv::Mat dilate;

    cv::threshold(originalImage, imagemBinaria, 120,255, cv::THRESH_BINARY);

    cv::threshold(imagemBinaria, imagemBinaria, 120,255, cv::THRESH_BINARY_INV); //negativo

    cv::dilate(imagemBinaria, dilate,cv::getStructuringElement(cv::MORPH_RECT, cv::Size(18,18)));


   // cv::namedWindow( "Negative Image", cv::WINDOW_AUTOSIZE );
    
   // cv::imshow( "Negative Image", imagemBinaria );

   // cv::namedWindow( "dilate Image", cv::WINDOW_AUTOSIZE );
    
    //cv::imshow( "dilate Image", dilate );


    //ex2

    cv::Mat dilate2;

    cv::dilate(imagemBinaria, dilate2,cv::getStructuringElement(cv::MORPH_RECT, cv::Size(11,11)));

    //cv::namedWindow( "arestas Image", cv::WINDOW_AUTOSIZE );
    
    //cv::imshow( "arestas Image",  dilate2 - imagemBinaria);


    //ex3

    cv::Mat dilate3;

    cv::dilate(originalImage, dilate3,cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));

    cv::namedWindow( "original Image", cv::WINDOW_AUTOSIZE );
    cv::imshow( "original Image",  originalImage);

    //cv::namedWindow( "remoção Image", cv::WINDOW_AUTOSIZE );
    //cv::imshow( "remoção Image",  dilate3);


    //ex4

    cv::Mat imagemBinaria2;
    cv::Mat erode;

    cv::threshold(originalImage, imagemBinaria2, 120,255, cv::THRESH_BINARY);
    cv::threshold(imagemBinaria2, imagemBinaria2, 120,255, cv::THRESH_BINARY_INV); //negativo

    cv::erode(imagemBinaria2, erode,cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(11,1)));
    
    //cv::namedWindow( "erode Image", cv::WINDOW_AUTOSIZE );
   // cv::imshow( "erode Image",  erode);


    //ex5

    cv::Mat imagemBinaria3;
    cv::Mat erode2;

    cv::threshold(originalImage, imagemBinaria3, 90,255, cv::THRESH_BINARY);
    cv::threshold(imagemBinaria3, imagemBinaria3, 90,255, cv::THRESH_BINARY_INV); //negativo

    cv::erode(imagemBinaria2, erode2,cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(13,13)));
    cv::erode(erode2, erode2,cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(13,13)));
 
    //cv::namedWindow( "erode Image", cv::WINDOW_AUTOSIZE );
    //cv::imshow( "erode Image",  erode2);

    //EX6
    cv::Mat erode3;

    cv::erode(originalImage, erode3,cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));

    //cv::namedWindow( "erode Image", cv::WINDOW_AUTOSIZE );
    //cv::imshow( "erode Image",  erode3);

    //EX7

    cv::Mat ope;
    cv::Mat ope2;
    cv::morphologyEx(originalImage, ope,cv::MORPH_OPEN,cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(11,11)));
    cv::morphologyEx(originalImage, ope2,cv::MORPH_OPEN,cv::getStructuringElement(cv::MORPH_RECT, cv::Size(9,3)));



    //cv::namedWindow( "open ELLIPSE Image", cv::WINDOW_AUTOSIZE );
    //cv::imshow( "open ELLIPSE Image",  ope);
    //cv::namedWindow( "open RECT Image", cv::WINDOW_AUTOSIZE );
    //cv::imshow( "open RECT Image",  ope2);

    //EX8

    cv::Mat ope3;
    cv::morphologyEx(originalImage, ope3,cv::MORPH_OPEN,cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));

   // cv::namedWindow( "open  Image", cv::WINDOW_AUTOSIZE );
    //cv::imshow( "open  Image",  ope3);


    //EX9

    cv::Mat ope4;
    cv::morphologyEx(originalImage, ope4,cv::MORPH_OPEN,cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));

   // cv::namedWindow( "open  Image", cv::WINDOW_AUTOSIZE );
   // cv::imshow( "open  Image",  ope4);


    //EX10

    cv::Mat close;
    cv::morphologyEx(originalImage, close,cv::MORPH_CLOSE,cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(22,22)));

    cv::namedWindow( "close  Image", cv::WINDOW_AUTOSIZE );
    cv::imshow( "close  Image",  close);








    // Waiting

	cv::waitKey( 0 );

	// Destroy the windows

	cv::destroyAllWindows();

	return 0;
}
