/**  
*  @file    pixel.h
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/08/2014  
*  @version 1.0
*
*  @brief CSC 112, Lab 10, The Pixel Class
*
*  @section DESCRIPTION
*
*  The pixel.h header file contains the class declarations for a 
*  class named Pixel that stores three unsigned char values for the 
*  component colors red, green, and blue, using the RGB model.
*
*  @bug No known bugs
*
*/



#ifndef PIXEL_H
#define PIXEL_H
#define BLUE   "\033[34m"
#define RED    "\033[31m" 
#define GREEN  "\033[32m" 
#define NORM "\033[0m" 
#include <iostream>
using namespace std;



class Pixel
{
public:
	// Default constructor
	Pixel(int r = 255, int g = 255, int b = 255);
	
	// Accessor function for component color red
	unsigned char red() const;

	// Accessor function for component color green		
	unsigned char green() const;

	// Accessor function for component color blue
	unsigned char blue() const;

	// Function to set red, answer true if clipping not required
	bool setRed(int color);

	// Function to set green, answer true if clipping not required
	bool setGreen(int color);

	// Function to set blue, answer true if clipping not required
	bool setBlue(int color);
	
	// Function that returns grayscale value of Pixel	
	unsigned char grayscale() const;

	// Returns true if the corresponding component colors of Pixel object are equivalent
	bool operator==(const Pixel& rhs);

	// Returns true if the corresponding component colors of Pixel are not equivalent
	bool operator!=(const Pixel& rhs);

	// Returns Pixel object representing sum of two Pixel objects
	Pixel operator+(const Pixel& rhs);
	
	// Neatly outputs in color	
	friend ostream& operator<<(ostream& out, const Pixel& rhs);


private:
	unsigned char red_;	///< Value for component color red
	unsigned char green_;	///< Value for component color green
	unsigned char blue_;	///< Value for componenent color blue


};

#endif 

