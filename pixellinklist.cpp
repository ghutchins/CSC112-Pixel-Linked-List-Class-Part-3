/**  
*  @file    pixellinklist.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/24/2014  
*  @version 1.0 
*
*  @brief CSC 112, Lab 12, The PixelLinkList Class
*
*  @section DESCRIPTION
*
*  The pixellinklist.cpp source file contains the member 
*  function definitions for the linked list PixelLinkList, 
*  which stores a list of PixelNodes
*  
*
*  @bug No known bugs
*
*/



#include "pixellinklist.h"
using namespace std;



/**
*  @brief Null constructor for PixelLinkList
*
*  @return nothing
*/
PixelLinkList :: PixelLinkList()
{
	head_ = 0;
}



/**
*  @brief Member function size returns number of elements (PixelNodes) in list
*  
*  @return integer size for number of elements in PixelLinkList
*/
int PixelLinkList :: size() const
{
	int size;		//counter for size (number of PixelNode elements)
	
	PixelNode* cursor = head_;
	while(cursor != 0)
	{
		size++;
		cursor = cursor -> next_;
	}

	return size;
}



/**
*  @brief Pixel constructor converts a Pixel to a PixelLinkList
* 
*  @param p is a Pixel object
*
*  @return nothing
*/
PixelLinkList :: PixelLinkList(const Pixel& p)
{
	head_ = new (nothrow) PixelNode;	///< pointer to first PixelNode element
	assert(head_ != 0);
	head_ -> value_ = p;
	head_ -> next_ = 0;
}	



/**
*  @brief PixelList constructor converts a PixelList to a PixelLinkList
*
*  @param plist is a PixelList
*
*  @return nothing
*/
PixelLinkList :: PixelLinkList(const PixelList& plist)
{
	if(plist.size() == 0)
		head_ = 0;
	else
	{
		head_ = 0;
		for(int i = 0; i < plist.size(); i++)
			append (plist.list_[i]);
	}
}



/**
*  @brief Copy constructor makes a deep copy of a PixelLinkList
*
*  @param pList is a PixelLinkList
*
*  @return nothing
*/
PixelLinkList :: PixelLinkList(const PixelLinkList& pList)
{
	if(pList.head_ == 0)
		head_ = 0;
	else
	{
		head_ = new (nothrow) PixelNode;   ///< pointer to first PixelNode element
		assert (head_ != 0);
		head_ -> value_ = pList.head_ -> value_;

		PixelNode* slist = pList.head_;	
		PixelNode* dlist = head_;	
		
		slist = slist -> next_;

		while(slist != 0)
		{
			dlist -> next_ = new (nothrow) PixelNode;  ///< Create PixelNode
			assert(dlist -> next_ != 0);
			dlist = dlist -> next_;	
			dlist -> value_ = slist -> value_;
			slist = slist -> next_;
		}

		dlist -> next_ = 0;
	}
}
	


/**
*  @brief Destructor properly deletes the PixelLinkList
*
*  @return nothing
*/ 
PixelLinkList :: ~PixelLinkList()
{
	if(head_ == 0)
		return;
	PixelNode* previous = head_;
	PixelNode* cursor = head_;
	while(cursor != 0)
	{
		cursor = cursor -> next_;
		previous -> next_ = 0;
		delete previous;
		previous = cursor;
	}
}



/**
*  @brief append adds Pixel object as the last node of the PixelLinkList
*
*  @param p is a Pixel object
*
*  @return void
*/
void PixelLinkList :: append(const Pixel& p)
{
	if(head_ == 0)
	{
		head_ = new (nothrow) PixelNode;  ///< Starting node in list
		assert(head_ != 0);
		head_ -> value_ = p;
		head_ -> next_ = 0;
	}
	else
	{
		PixelNode* cursor = head_;
		while(cursor -> next_ != 0)
			cursor = cursor -> next_;
		cursor -> next_ = new (nothrow) PixelNode;///< New node to advance to for append
		assert(cursor -> next_ != 0);
		cursor = cursor -> next_;
		cursor -> value_ = p;
		cursor -> next_ = 0;
	}
}
		
	

/**
*  @brief remove removes the first occurence of Pixel object from list
*
*  @param p is the Pixel object to be removed
*
*  @return true if Pixel object p was successfully removed
*/		
bool PixelLinkList :: remove(const Pixel& p)
{
	if(head_ == 0)
		return false;

	PixelNode* current = head_;
	PixelNode* previous;

	if(head_ -> value_ == p)
	{
		head_ = head_ -> next_;
		current -> next_ = 0;
		delete current;
		return true;
	}
	else
	{
		while(current != 0)
		{
			if(current -> value_ == p)
			{
				previous -> next_ = current -> next_;
				current -> next_ = 0;
				delete current;
				return true;
			}
			
			previous = current;
			current = current -> next_;
		}
	}
	
	return false;
}



/**
*  @brief operator= overloads the assignment operator
*
*  @param rhs is the right hand side of the argument
*
*  @return LHS PixelLinkList after deep copy of RHS has been made and assigned to LHS
*/
const PixelLinkList& PixelLinkList :: operator=(const PixelLinkList & rhs)
{
	if(this != &rhs)
	{
		PixelNode* previous = head_;
		PixelNode* cursor = head_;
		while(cursor != 0)
		{
			cursor = cursor -> next_;
			previous -> next_ = 0;
			delete previous;
			previous = cursor;
		}
		
		PixelLinkList temp(rhs); 
		head_ = temp.head_;
		temp.head_ = 0; 
	}

	return *this;
}
		


/**
*  @brief operator+ concatenates PixelLinkList with PixelLinkList, PixelList, or
*  Pixel object
*
*  @param lhs is the left hand side of the argument
*  @param rhs is the right hand side of the argument
*
*  @return concatenated PixelLinkList
*/
PixelLinkList operator+(const PixelLinkList& lhs, const PixelLinkList& rhs)
{
	PixelLinkList result;		///< Resulting PixelLinkList after concatenation
	PixelNode* c = rhs.head_;	///< rhs element to concatenate

	while(c != 0)
	{
		result.append(c -> value_);
		c = c -> next_;
	}
	
	c = lhs.head_;

	while(c != 0)
	{
		result.append(c -> value_);
		c = c -> next_;
	}

	return result;		
	
}



/**
*  @brief operator<< overloads << operator
*
*  @param out is the standard output stream
*  @param rhs is the right hand side of arugment
*
*  @return output stream
*/
ostream& operator<<(ostream& out, const PixelLinkList& rhs)
{
	PixelNode* cursor = rhs.head_;

	out << "{";
	if(cursor == 0)
	{
		out << "empty list" << '\n';
	}
	else
	{
		while(cursor != 0)
		{
			out << cursor -> value_ << ", (" << cursor -> next_ << ")";
			cursor = cursor -> next_;
			if(cursor)
				cout << "-> ";
		}
	}
	out << "}";
	return out;
}





