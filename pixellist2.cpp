/**  
*  @file    pixellist2.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/21/2014  
*  @version 1.0 
*
*  @brief CSC 112, Lab 11, The PixelList Class
*
*  @section DESCRIPTION
*
*  The pixellist2.cpp source file contains the other half of the
*  member function definitions for the PixelList class, which
*  stores a dynamic list of Pixel objects.
*
*  @bug No known bugs
*
*/



#include "pixellist.h"
using namespace std;



/**
*  @brief operator= overloads the assignment operator
* 
*  @param rhs is the right hand side of the argument
*
*  @return LHS PixelList after deep copy of RHS has been made and assigned to LHS
*/
const PixelList& PixelList :: operator=(const PixelList& rhs)
{ 
	if(this != &rhs)
	{
		delete[] list_;

		size_ = rhs.size_;
		if(rhs.size_ > 0)
		{
			list_ = new (nothrow) Pixel[rhs.size_];
			assert(list_ != NULL);
			size_ = rhs.size_;
			for(int i = 0; i < size_; i++)
				list_[i] = rhs.list_[i];
		}	
	}
		else
		{
			list_ = 0;
			size_ = 0;
		}

	return *this;
}



/**
*  @brief operator == overloads logical equivalence operator
*
*  @param lhs is the left hand side of the argument
*  @param rhs is the right hand side of the argument 
*
*  @return true if corresponding Pixel objects in lists are equivalent
*  
*/
bool operator==(const PixelList& lhs, const PixelList& rhs)
{
	if(lhs.list_ != rhs.list_)
		return false;
	else
		return true;
}



/**
*  @brief operator != overloads != operator
*
*  @param lhs is the left hand side of the argument
*  @param rhs is the right hand side of the argument 
*
*  @return true if corresponding Pixel objects in lists are not equivalent
*  
*/
bool operator!=(const PixelList& lhs, const PixelList& rhs)
{
	if(lhs.list_ == rhs.list_)
		return false;
	else
		return true;
}



/**
*  @brief operator+ adds corresponding Pixel elements to PixelList
*
*  @param lhs is the left hand side of the argument
*  @param rhs is the right hand side of the argument
*
*  @return PixelList
*/
PixelList operator+(const PixelList& lhs, const PixelList& rhs)
{
	PixelList result;
	if(rhs.size_ > lhs.size_)
	{
		result = rhs;
		for(int i = 0; i < lhs.size_; i++)
			result.list_[i] = result.list_[i] + lhs.list_[i];
	}
	else
	{
		result = lhs;
		for(int i = 0; i < rhs.size_; i++)
			result.list_[i] = result.list_[i] + rhs.list_[i];
	 
	}
		
	return result;
}



