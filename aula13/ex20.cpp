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

#include "opencv2/imgcodecs.hpp"


using namespace cv;
using namespace std;


// MAIN

int main( int argc, char** argv )
{

	Mat tabuleiro;
    Mat tabuleiro2;

	tabuleiro = imread( "aula13/index.jpg", cv::IMREAD_UNCHANGED );
    tabuleiro2 = imread( "aula13/checkers.png", cv::IMREAD_UNCHANGED );

    namedWindow( "Tabuleiro", WINDOW_AUTOSIZE );
    namedWindow( "Tabuleiro2", WINDOW_AUTOSIZE );


    
    vector<vector<Point> > squares;
    vector<vector<Point> > squares2;

    Mat imagemBinaria, gray, cdst;
   
    cv::Canny(tabuleiro, gray,50,100,3);

    vector<Vec2f> lines;

    HoughLines(gray, lines, 1, 3.14/180, 250, 0, 0 );

    cout << lines.size();

    for( size_t i = 0; i < lines.size(); i++ )
        {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        cout << pt1;
        line( tabuleiro, pt1, pt2, Scalar(0,0,255), 3, 4);
        }

    imshow( "Tabuleiro",  gray);
    imshow("detected lines", tabuleiro);

	waitKey( 0 );

	// Destroy the windows
    
	destroyAllWindows();

	return 0;
}
