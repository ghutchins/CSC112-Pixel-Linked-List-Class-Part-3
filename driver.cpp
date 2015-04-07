/** 
*  @file driver.cpp
*  @author Georgina Hutchins (hutcgb12)
*  @date 04/24/14
*  @version 1.0
*
*  @brief CSC 112, Lab 12, The PixelLinkList Class
*
*  This driver program tests the linked list PixelLinkList
*    
*  @bug	 No known bugs.
*/



#include <iostream>
#include "pixellinklist.h"
using namespace std;



int main()
{

	cout << "========= constructor & output tests ======== \n"; 
	

	PixelLinkList pList(Pixel(10, 10, 10));
	cout << pList << '\n';


	cout << "========= append and remove tests ======== \n";
	
	pList.append(Pixel(10, 20, 30));
	PixelLinkList pList1(pList);
	cout << "Append:  " << '\n';
	cout << pList1 << '\n';

	pList1.remove(Pixel(20, 20, 20));
	PixelLinkList pList0(pList);
	cout << "Remove:  (return false)  " << '\n';
	cout << pList0 << '\n';
	

	pList1.remove(Pixel(10, 10, 10));
	PixelLinkList test(pList1);
	cout << "Remove:  " << '\n';
	cout << test << '\n';


	cout << "========= operator+ test ======== \n";

	PixelLinkList pList2(Pixel(10, 10, 10));
	pList2.append(Pixel(4, 4, 4));
	PixelLinkList pList3(pList2);
	PixelList list(Pixel(2, 2, 2));
	Pixel p1(1, 2, 3);


	cout << "pList:   " << pList << '\n';
	cout << "pList3:    " << pList3 << '\n';
	cout << "list:    " << list << '\n';
	cout << "p1:      " << p1 << '\n';

	cout << "Addition: " << '\n';
	cout << "pList + pList3:  " << pList + pList3 << '\n';
	cout << "pList3 + list:   " << pList3 + list << '\n';
	cout << "pList3 + p1:     " << pList3 + p1 << '\n';


	cout << "========= assignmemt operator tests ======== \n";
	
	cout << "pList3:  " << pList3 << '\n';
	cout << "pList:   " << pList << '\n';

	cout << "Assignment operator:  " << '\n';
	cout << "pList3 = pList:  " << (pList3 = pList) << '\n';


	return 0;

}
