#ifndef MYMENU_H
#define MYMENU_H
#include "MyHeaderFile.h"

class MyMenu{
	private:
		string fileName;
		
		// set default filtering and sorting criteria
		string filterCriteria = "Point2D";
		string sortCriteria = "x-ordinate";
		string sortOrder = "ASC";
	
	// to avoid user straight to select option 5
	bool gotData = false;
	bool readData = false;

	public:
		// menu function
		void menu();
		// function for choice 1-6
		void readAndProcessFile();
		void typeOfRecords();
		void typeOfOrdinateAndValues();
		void typeOfOrder();
		void viewData();
		void storeData();
		// go back to menu function
		void hitEnter();
};
#endif
