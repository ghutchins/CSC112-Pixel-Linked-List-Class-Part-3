/**  
*  @file    pixellist1.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/21/2014  
*  @version 1.0 
*
*  @brief CSC 112, Lab 11, The PixelList Class
*
*  @section DESCRIPTION
*
*  The pixellist1.cpp source file contains the half of the member
*  function definitions for the PixelList class, which stores
*  a dynamic list of Pixel objects.
*
*  @bug No known bugs
*
*/



#include "pixellist.h"
using namespace std;



/**
*  @brief Null constructor for PixelList
*
*  @return nothing
*/
PixelList :: PixelList()
{
	list_ = 0;
	size_ = 0;
}



/**
*  @brief Member function size returns number of pixels in list
*
*  @return integer size_ for the number of pixels in the list
*/
int PixelList :: size() const
{
	return size_;
}



/**
*  @brief Copy constructor makes deep copy of a PixelList
*
*  @param list is the pointer to the pixel list
*
*  @return nothing
*/
PixelList :: PixelList(const PixelList& list)
{	
	if(list.size_ > 0)
	{
		list_ = new (nothrow) Pixel[list.size_];  ///< Allocate dynamic array
		assert(list_ != NULL);
		size_ = list.size_;

		for(int i = 0; i < size_; i++)
			list_[i] = list.list_[i];	
	}
	else
	{
		list_ = 0;
		size_ = 0;
	}
	

}



/**
*  @brief Pixel constructor creates a PixelList from a Pixel
*
*  @param p is a Pixel object
*
*  @return nothing
*/
PixelList :: PixelList(const Pixel& p)
{		
	list_ = new (nothrow) Pixel(p);	///< Allocates dynamic array
	assert(list_ != NULL);
	size_ = 1;
	
	for(int i = 0; i < size_; i++)
		list_[i] = p;

}
	


/**
*  @brief Destructor properly deletes the pixel list
*
*  @return nothing
*/
PixelList :: ~PixelList()
{
	if(list_)
	{
		delete[] list_;
	}
}



/**
*  @brief append adds a new Pixel with value pixel to the end of the list
*
*  @param pixel is a Pixel object value
*
*  @return void
*/
void PixelList :: append(Pixel pixel)
{
	Pixel* temp = new (nothrow) Pixel[size_ + 1]; ///< Temporary array

	assert(temp != NULL);
	int i;				///< counter
	for(i = 0; i < size_; i++)
		temp[i] = list_[i];
	temp[i] = pixel;
	
	size_++;

	
	if(list_)
		delete[]list_;

	list_ = temp;

}



/**
*  @brief replace replaces every occurence of oldPixel with newPixel
*
*  @param oldPixel is the Pixel value to be replaced
*  @param newPixel is the Pixel value to replace oldPixel
*
*  @return void
*/
void PixelList :: replace(Pixel oldPixel, Pixel newPixel)
{
	for(int i = 0; i < size_; i++)
	{
		if(list_[i] == oldPixel)
			list_[i] = newPixel;
	}	
}



/**
*  @brief operator<< overloads << operator
*
*  @param out is the standard output stream
*  @param rhs is the right hand side of argument 
*
*  @return output stream
*  
*/
ostream& operator<<(ostream& out, const PixelList& rhs)
{
	int i;
	out << "{";
	for(i = 0; i < rhs.size_; i++)
	{
		if(i != rhs.size_ - 1)
			out << rhs.list_[i] << ", ";
		else if(i == rhs.size_ - 1)
			out << rhs.list_[i];
	}
	out << "}";
	return out;
}







