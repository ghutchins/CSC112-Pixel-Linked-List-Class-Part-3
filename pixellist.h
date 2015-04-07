/**  
*  @file    pixellist.h
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/21/2014  
*  @version 1.0
*
*  @brief CSC 112, Lab 11, The PixelList Class
*
*  @section DESCRIPTION
*
*  The pixellist.h header file contains the class declarations for a
*  class named PixelList that stores a dynamic list of Pixel objects.
*  The Pixel Class  stores three unsigned char values for the 
*  component colors red, green, and blue, using the RGB model.
*
*  @bug No known bugs
*
*/



#ifndef PIXELLIST_H
#define PIXELLIST_H
#include "pixel.h"
#include <iostream>
#include <cassert> 
using namespace std;



class PixelList
{
public: 
	// Null constructor
	PixelList();

	// Function that returns the number of pixels in the list
	int size() const;

	// Copy constructor
	PixelList(const PixelList& list);

	// Pixel constructor that creates a PixelList from a Pixel
	PixelList(const Pixel& p); 	

	// Destructor
	~PixelList();

	// Function that adds a new Pixel with the value pixel to the end of the list
	void append(Pixel pixel);

	// Function that replaces every occurence of oldPixel with new Pixel
	void replace(Pixel oldPixel, Pixel newPixel);	

	// Assignment operator overload
	const PixelList& operator=(const PixelList& rhs);

	// Returns true if all corresponding Pixel objects are equivalent
	friend bool operator==(const PixelList& lhs, const PixelList& rhs);

	// Returns true if any of the corresponding Pixel objects are not equivalent
	friend bool operator!=(const PixelList& lhs, const PixelList& rhs);
	
	// Operator+ overload that adds corresponding Pixel elements, returns PixelList
	friend PixelList operator+(const PixelList& lhs, const PixelList& rhs);

	// Neatly outputs in color
	friend ostream& operator<<(ostream& out, const PixelList& rhs);


	// Declares the PixelLinkList Class as a friend
	friend class PixelLinkList;

private:

	Pixel* list_;	///< Pointer to list of Pixel objects
	int size_;	///< Variable for the number of pixels in the list

};


#endif
	
