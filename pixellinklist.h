/**  
*  @file    pixellinklist.h
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/24/2014  
*  @version 1.0
*
*  @brief CSC 112, Lab 12, The PixelLinkList Class
*
*  @section DESCRIPTION
*
*  The pixellinklist.h header file contains the class declarations for
*  a linked list called PixelLinkList that stores a list of PixelNodes.

 a
*  class named PixelList that stores a dynamic list of Pixel objects.
*  The Pixel Class  stores three unsigned char values for the 
*  component colors red, green, and blue, using the RGB model.
*
*  @bug No known bugs
*
*/


#ifndef PIXELLINKLIST_H
#define PIXELLINKLIST_H
#include "pixelnode.h"
#include "pixellist.h"
#include "pixel.h"
#include <iostream>
#include <cassert>
using namespace std;


class PixelLinkList
{
public:
	// Null constructor
	PixelLinkList();

	// Member function returns number of PixelNode elements in PixelLinkList
	int size() const;

	// Pixel constructor converts a Pixel to a PixelLinkList
	PixelLinkList(const Pixel& p);

	// PixelList constructor converts a PixelList to a PixelLinkList
	PixelLinkList(const PixelList& plist);

	// Copy constructor
	PixelLinkList(const PixelLinkList& pList);
	
	// Destructor
	~PixelLinkList();
	
	// Function appends a Pixel p as the last node of the PixelLinkList
	void append(const Pixel& p);

	// Function removes the first occurence of Pixel p from the list
	bool remove(const Pixel& p);

	// Assignment operator overload
	const PixelLinkList& operator=(const PixelLinkList& rhs);

	// Operator+ overload that returns concatenated PixelLinkList
	friend PixelLinkList operator+(const PixelLinkList& lhs, const PixelLinkList& rhs);

	// Neartly outputs the elements of the PixelLinkList
	friend ostream& operator<<(ostream& out, const PixelLinkList& rhs);

private:
	PixelNode* head_;	///< Pointer to first element in PixelLinkList

};

#endif

