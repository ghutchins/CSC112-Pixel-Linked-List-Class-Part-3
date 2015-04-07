/**  
*  @file    pixel.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/08/2014  
*  @version 1.0 
*
*  @brief CSC 112, Lab 10, The Pixel Class
*
*  @section DESCRIPTION
*
*  The pixel.cpp source file contains the member function definitions
*  for the Pixel class, which stores three unsigned char values for
*  the component colors red, green, and blue.
*  
*  @bug No known bugs
*
*/



#include "pixel.h"
using namespace std;



/**
*  @brief Default constructor for Pixel
*
*  @param r is integer value for component color red
*  @param g is integer value for component color green
*  @param b is integer value for component color blue
*
*  @return nothing
*/
Pixel :: Pixel(int r, int g, int b)
{
	if(r > 255)
		r = 255;
	if(r < 0)
		r = 0;
	red_ = r;
	
	if(g > 255)
		g = 255;
	if(g < 0)
		g = 0;
	green_ = g;
	
	if(b > 255)
		b = 255;
	if(b < 0)
		b = 0;
	blue_ = b;

}



/**
*  @brief Accessor function for red
*
*  @return unsigned char red_ for color component red
*/
unsigned char Pixel :: red() const
{
	return red_;
}



/**
*  @brief Accessor function for green
*
*  @return unsigned char green_ for color component green
*/
unsigned char Pixel :: green() const
{
	return green_;
}



/**
*  @brief Accessor function for blue
*
*  @return unsigned char blue_ for color component blue
*/
unsigned char Pixel :: blue() const
{
	return blue_;
}



/**
*  @brief Sets component color red
*
*  @param color is an integer for the corresponding color
*
*  @return true if value is in range, false if clipping was required
*/
bool Pixel :: setRed(int color)
{		
	if(color > 255)
	{
		color = 255;
		red_ = color;
		return 0;
	}
	else if(color < 0)
	{
		color = 0;
		red_ = color;
		return 0;
	}
	else
	{
		red_ = color;
		return 1;
	}

}



/**
*  @brief Sets component color green
*
*  @param color is an integer for the corresponding color
*
*  @return true if value is in range, false if clipping was required
*/
bool Pixel :: setGreen(int color)
{
	if(color > 255)
	{
		color = 255;
		green_ = color;
		return 0;
	}
	else if(color < 0)
	{
		color = 0;
		green_ = color;
		return 0;
	}
	else
	{
		green_ = color;
		return 1;
	}

}



/**
*  @brief Sets component color blue
*
*  @param color is an integer for the corresponding color
*
*  @return true if value is in range, false if clipping was required
*/
bool Pixel :: setBlue(int color)
{	
	if(color > 255)
	{
		color = 255;
		blue_ = color;
		return 0;
	}
	else if(color < 0)
	{
		color = 0;
		blue_ = color;
		return 0;
	}
	else
	{
		blue_ = color;
		return 1;
	}
	
}




/**
*  @brief Grayscale is an unsigned char that represents the grayscale
*  version of the color stored in the Pixel class
*
*  @return unsigned char value, the grayscale value of the Pixel
*/
unsigned char Pixel :: grayscale() const
{
	
	 unsigned char value = (0.2989)*(red_) + (0.5870)*(green_) + (0.1140)*(blue_); ///< Variable for the grayscale value
	
	return value;

}



/**
*  @brief Operator == overloads logical equivalence operator
*
*  @param rhs is the right hand side of argument 
*
*  @return true if corresponding component colors of Pixel are equivalent
*  
*/
bool Pixel :: operator==(const Pixel& rhs)
{
	if((red_ != rhs.red_) || (green_ != rhs.green_) || (blue_ != rhs.blue_))
		return false;
	else
		return true;
}



/**
*  @brief Operator != overloads != operator
*
*  @param rhs is the right hand side of argument 
*
*  @return true if corresponding component colors of Pixel are not equivalent
*  
*/
bool Pixel :: operator!=(const Pixel& rhs)	
{
	if((red_ == rhs.red_) || (green_ == rhs.green_) || (blue_ == rhs.blue_))
		return false;
	else
		return true;
}



/**
*  @brief Operator+ concatenates Pixel objects
*
*  @param rhs is the right hand side of argument 
*
*  @return Pixel object representing sum of two Pixel objects
*  
*/
Pixel Pixel :: operator+(const Pixel& rhs)
{
	Pixel lhs = *this;	///< Variable for left hand side Pixel object
	Pixel temp;		///< Pixel object for the sum 	

	Pixel addRed;		///< Sum of red before clipping
	Pixel addGreen;		///< Sum of green before clipping
	Pixel addBlue;		///< Sum of blue before clipping
	
	addRed.red_ = (lhs.red_ + rhs.red_);

	if(lhs.red_ > 127 && rhs.red_ > 127)
		addRed.red_ = 255;
	if(lhs.red_ < 0 || rhs.red_ < 0)
		addRed.red_ = 0;
	
	temp.red_ = addRed.red_;

	addGreen.green_ = (lhs.green_ + rhs.green_);

	if(lhs.green_ > 127 && rhs.green_ > 127)
		addGreen.green_ = 255;
	if(lhs.green_ < 0 || rhs.green_ < 0)
		addGreen.green_ = 0;

	temp.green_ = addGreen.green_;

	addBlue.blue_ = (lhs.blue_ + rhs.blue_);
	if(lhs.blue_ > 127 && rhs.blue_ > 127)
		addBlue.blue_ = 255;
	if(lhs.blue_ < 0 || rhs.blue_ < 0)
		addBlue.blue_ = 0;
	
	temp.blue_ = addBlue.blue_;
	
	return temp;

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
ostream& operator<<(ostream& out, const Pixel& rhs)
{
	out << '[' << RED << (int)rhs.red_ << NORM << ", " << GREEN << (int) rhs.green_ << NORM << ", " << BLUE << (int)rhs.blue_ << NORM << ']';

	return out;
}




