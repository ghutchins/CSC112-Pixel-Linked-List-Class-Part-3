/**  
*  @file    pixelnode.h
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/24/2014  
*  @version 1.0
*
*  @brief CSC 112, Lab 12, The PixelLinkList Class
*
*  @section DESCRIPTION
*
*  The pixelnode.h file contains the declarations for a struct
*  called PixelNode that contains a Pixel object and a pointer
*  to the next node. The Pixel Class stores three unsigned char
*  values for the component colors red, green, and blue, using
*  the RGB model.
*
*  @bug No known bugs
*
*/


#ifndef PIXELNODE_H
#define PIXELNODE_H
#include "pixel.h"
#include <iostream>
#include <cassert>
using namespace std;


struct PixelNode
{
	Pixel value_;		///< Pixel object
	PixelNode* next_;	///< Pointer to the next node
};


#endif



