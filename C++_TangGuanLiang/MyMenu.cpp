#include "MyMenu.h"
#include "MyTemplates.h"
#include "MyHeaderFile.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

// create 4 vector for 2D and 3D
vector <Point2D> point_2D;
vector <Point3D> point_3D;
vector <Line2D> line_2D;
vector <Line3D> line_3D;

void MyMenu::menu(){
	cout << "Student ID   : 7573947" << endl;
	cout << "Student Name : Tang Guan Liang" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Welcome to Assn3 program!" << endl;
	cout << endl;
	cout << "1. Read in data" << endl;
	cout << "2. Specify filtering criteria (current: " + filterCriteria + ")" << endl;
	cout << "3. Specify sorting criteria (current: " + sortCriteria + ")" << endl;
	cout << "4. Specify sorting order (current: " + sortOrder + ")" << endl;
	cout << "5. View data" << endl;
	cout << "6. Store data" << endl;
	cout << "7. Quit" << endl;
	cout << endl;
	
	// let user select their choice
	int choice;
	cout << "Please enter your choice: " << endl;
	cin >> choice;
	
	switch(choice){
		case 1:
			readAndProcessFile();
			gotData = true;
			break;
		case 2:
			typeOfRecords();
			readData = false;
			break;
		case 3:
			typeOfOrdinateAndValues();
			readData = false;
			break;
		case 4:
			typeOfOrder();
			readData = false;
			break;
		case 5:
			if (gotData == true){
				viewData();
				readData = true;
				hitEnter();
			}else{
				cerr << "Please enter valid file name!" << endl;
				hitEnter();
			}
			break;
		case 6:
			if (gotData == true && readData == true){
				storeData();
			}else{
				cerr << " Data haven't sorted. Please go to option 5 first." << endl;
				hitEnter();
				break;
			}
		case 7:
			cout << "Thanks for using our system. See you next time!" << endl;
			cout << endl;exit(EXIT_SUCCESS);	
		default:
			cerr << "Please enter a number between 1-7" << endl;
			menu();
	}
}

void MyMenu::hitEnter(){
	cout << endl;
	cout << "Press any key to go back to main menu..." << endl;
	cin.clear(); //clear the error flag
	cin.ignore();
	cin.ignore(10000, '\n'); // skip the newline
	menu();
	cout << endl;
}

void MyMenu::readAndProcessFile(){
	// prompt user to enter filename
	cout << "Please enter filename: ";
	cin >> fileName;

	string content;
	ifstream enterFile;
	stringstream iss;

	enterFile.open(fileName);

	// to calculate the number of records in the file
	int count = 0;
	
	// success to open the file
	if (enterFile.is_open()){
		// continue to read the file if it does not reach the end
		while (!enterFile.eof()){
			// read the file line by line and store into content
			getline(enterFile, content);
			
			// to store seperate pieces of data
			string class_name;
			char delimeter;

			// to make a line for coordinate x, y and z
			int x1, y1, z1;
			int x2, y2, z2;
		
			// store the content
			iss.str(content);
			iss >> class_name;

			// if Point2D data is found
			if (class_name == "Point2D," || class_name == "Point2d," || 
			    class_name == "point2D," || class_name == "point2d,") {
				iss >> delimeter >> x1 >> delimeter >> y1;

				// create and store into vector point_2D
				point_2D.push_back(Point2D(x1, y1));
				// sort the vector by x first then y
				sort(point_2D.begin(), point_2D.end());
				// check the vector have duplicate data or not
				point_2D.erase(unique(point_2D.begin(), point_2D.end()), 
					       point_2D.end());

				count++;
			}
			// if Point3D data is found
			if (class_name == "Point3D," || class_name == "Point3d," || 
			    class_name == "point3D," || class_name == "point3d,") {
				iss >> delimeter >> x1 >> delimeter >> y1 >> delimeter >> z1;

				// create and store into vector point_3D
				point_3D.push_back(Point3D(x1, y1, z1));
				// sort the vector by x first then y then z
				sort(point_3D.begin(), point_3D.end());
				// check the vector have duplicate data or not
				point_3D.erase(unique(point_3D.begin(), point_3D.end()), 
					       point_3D.end());

				count++;
			}
			// if Line2D data is found
			if (class_name == "Line2D," || class_name == "Line2d," || 
			    class_name == "line2D," || class_name == "line2d,") {
				iss >> delimeter >> x1 >> delimeter >> y1 >> delimeter 
				>> delimeter >> delimeter >> x2 >> delimeter >> y2;

				// store the value into a temporary object
				Point2D temp1(x1, y1);
				Point2D temp2(x2, y2);

				// create and store into vector line_2D
				line_2D.push_back(Line2D(temp1, temp2));
				// sort the vector by x first then y 
				sort(line_2D.begin(), line_2D.end());
				// check the vector have duplicate data or not
				line_2D.erase(unique(line_2D.begin(), line_2D.end()), 
					       line_2D.end());

				count++;
			}
			// if Line3D data is found
			if (class_name == "Line3D," || class_name == "Line3d," || 
			    class_name == "line3D," || class_name == "line3d,") {
				iss >> delimeter >> x1 >> delimeter >> y1 >> delimeter >> z1 
				>> delimeter >> delimeter >> delimeter >> x2 >> delimeter >> y2
				>> delimeter >> z2;

				// store the value into a temporary object
				Point3D temp1(x1, y1, z1);
				Point3D temp2(x2, y2, z2);

				// create and store into vector line_2D
				line_3D.push_back(Line3D(temp1, temp2));
				// sort the vector by x first then y 
				sort(line_3D.begin(), line_3D.end());
				// check the vector have duplicate data or not
				line_3D.erase(unique(line_3D.begin(), line_3D.end()), 
					       line_3D.end());

				count++;
			}
		}
		cout << endl;
		cout << count << " records read in successfully!" << endl;
		cout << endl;
		cout << "Going back to main menu...." << endl;
		enterFile.close();
		menu();
	}else{
		cerr << "Cannot open this file: " << fileName << endl;
		cout << " Please try again." << endl;
		menu();
	}
}

void MyMenu::typeOfRecords(){
	cout << endl;
	cout << "[Specifying filtering criteria (current : " + filterCriteria + ") ]" << endl;
	cout << endl;

	cout << "a) Point2D records" << endl;
	cout << "b) Point3D records" << endl;
	cout << "c) Line2D records" << endl;
	cout << "d) Line3D records" << endl;
	cout << endl;

	char record;
	cout << "Please enter your criteria (a-d): " << endl;
	cin >> record;

	switch(record){
		case 'a':
			filterCriteria = "Point2D"; sortCriteria = "x-ordinate";
			cout << "Filtering criteria successfully set to '" + filterCriteria + "'!" 
			<< endl;
			break;
		case 'b':
			filterCriteria = "Point3D"; sortCriteria = "x-ordinate";
			cout << "Filtering criteria successfully set to '" + filterCriteria + "'!"
			<< endl;
			break;
		case 'c':
			filterCriteria = "Line2D"; sortCriteria = "Pt.1";
			cout << "Filtering criteria successfully set to '" + filterCriteria + "'!"
			<< endl;
			break;
		case 'd':
			filterCriteria = "Line3D"; sortCriteria = "Pt.1";
			cout << "Filtering criteria successfully set to '" + filterCriteria + "'!"
			<< endl;
			break;
		default:
			cerr << "Please enter a alphabet between a-d" << endl;
			menu();
			break;
	}	
}

void MyMenu::typeOfOrdinateAndValues(){
	cout << endl;
	cout << "[Specifying sorting criteria (current : " + sortCriteria + ") ]" << endl;
	cout << endl;

	if (filterCriteria == "Line2D" || filterCriteria == "Line3D"){
		cout << "a) Pt.1's (x,y) values" << endl;
		cout << "b) Pt.2's (x,y) values" << endl;
		cout << "c) Length value" << endl;
		cout << endl;

		char ordinateAndValues;
		cout << "Please enter your criteria (a-c): " << endl;
		cin >> ordinateAndValues;

		switch(ordinateAndValues){
			case 'a':
				sortCriteria = "Pt.1";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			case 'b':
				sortCriteria = "Pt.2";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			case 'c':
				sortCriteria = "Length";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			default:
				cerr << "Please enter a alphabet between a-c" << endl;
				menu();
				break;
		}
	}else if (filterCriteria == "Point2D"){
		cout << "a) x-ordinate" << endl;
		cout << "b) y-ordinate" << endl;
		cout << "c) Dist.Fr Origin value" << endl;
		cout << endl;

		char ordinateAndValues;
		cout << "Please enter your criteria (a-c): " << endl;
		cin >> ordinateAndValues;
		
		switch(ordinateAndValues){
			case 'a':
				sortCriteria = "x-ordinate";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			case 'b':
				sortCriteria = "y-ordinate";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			case 'c':
				sortCriteria = "Dist.Fr Origin value";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			default:
				cerr << "Please enter a alphabet between a-c" << endl;
				menu();
				break;
		}
	// if filterCriteria == "Point3D"
	}else{
		cout << "a) x-ordinate" << endl;
		cout << "b) y-ordinate" << endl;
		cout << "c) z-ordinate" << endl;
		cout << "d) Dist.Fr Origin value" << endl;
		cout << endl;
		
		char ordinateAndValues;
		cout << "Please enter your criteria (a-d): " << endl;
		cin >> ordinateAndValues;

		switch(ordinateAndValues){
			case 'a':
				sortCriteria = "x-ordinate";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			case 'b':
				sortCriteria = "y-ordinate";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			case 'c':
				sortCriteria = "z-ordinate";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			case 'd':
				sortCriteria = "Dist.Fr Origin value";
				cout << "Sorting criteria successfully set to '" + sortCriteria + "'!" 					<< endl;
				break;
			default:
				cerr << "Please enter a alphabet between a-d" << endl;
				menu();
				break;
		}
	}
}

void MyMenu::typeOfOrder(){
	cout << endl;
	cout << "Specifying sorting order (current: " + sortOrder + ") ]" << endl;
	cout << endl;

	cout << "a) ASC (Ascending order)" << endl;
	cout << "b) DSC (Descending order)" << endl;
	cout << endl;
	
	char order;
	cout << "Please enter your criteria (a-b): " << endl;
	cin >> order;

	switch(order){
		case 'a':
			sortOrder = "ASC";
			cout << "Sorting order successfully set to '" + sortOrder + "'!" << endl;
			break;
		case 'b':
			sortOrder = "DSC";
			cout << "Sorting order successfully set to '" + sortOrder + "'!" << endl;
			break;
		default:
			cerr << "Please enter a alphabet between a or b" << endl;
			menu();
			break;
	}
}

void MyMenu::viewData(){
	cout << "[ View data... ]" << endl;
	cout << "filtering criteria: " + filterCriteria << endl;
	cout << "sorting criteria: " + sortCriteria << endl;
	cout << "sorting order: " + sortOrder << endl;
	cout << endl;

	// print Point2D
	if (filterCriteria == "Point2D"){
		// sortByX
		if (sortCriteria == "x-ordinate"){
			if (sortOrder == "ASC"){
				sort(point_2D.begin(), point_2D.end(), sortByX());
			}
			if (sortOrder == "DSC"){
				sort(point_2D.rbegin(), point_2D.rend(), sortByX());
			}
		}
		// sortByY
		if (sortCriteria == "y-ordinate"){
			if (sortOrder == "ASC"){
				sort(point_2D.begin(), point_2D.end(), sortByY());
			}
			if (sortOrder == "DSC"){
				sort(point_2D.rbegin(), point_2D.rend(), sortByY());
			}
		}
		// sortByOrigin
		if (sortCriteria == "Dist.Fr Origin value"){
			if (sortOrder == "ASC"){
				sort(point_2D.begin(), point_2D.end(), sortByOrigin());
			}
			if (sortOrder == "DSC"){
				sort(point_2D.rbegin(), point_2D.rend(), sortByOrigin());
			}
		}
	
		cout << "    X     Y    Dist.Fr Origin" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < point_2D.size(); i++){
			cout << point_2D[i] << endl;
		}
	}
	// print Point3D
	if (filterCriteria == "Point3D"){
		// sortByX
		if (sortCriteria == "x-ordinate"){
			if (sortOrder == "ASC"){
				sort(point_3D.begin(), point_3D.end(), sortByX());
			}
			if (sortOrder == "DSC"){
				sort(point_3D.rbegin(), point_3D.rend(), sortByX());
			}
		}
		// sortByY
		if (sortCriteria == "y-ordinate"){
			if (sortOrder == "ASC"){
				sort(point_3D.begin(), point_3D.end(), sortByY());
			}
			if (sortOrder == "DSC"){
				sort(point_3D.rbegin(), point_3D.rend(), sortByY());
			}
		}
		// sortByZ
		if (sortCriteria == "z-ordinate"){
			if (sortOrder == "ASC"){
				sort(point_3D.begin(), point_3D.end(), sortByZ());
			}
			if (sortOrder == "DSC"){
				sort(point_3D.rbegin(), point_3D.rend(), sortByZ());
			}
		}
		// sortByOrigin
		if (sortCriteria == "Dist.Fr Origin value"){
			if (sortOrder == "ASC"){
				sort(point_3D.begin(), point_3D.end(), sortByOrigin());
			}
			if (sortOrder == "DSC"){
				sort(point_3D.rbegin(), point_3D.rend(), sortByOrigin());
			}
		}
		cout << "    X     Y     Z    Dist.Fr Origin" << endl;
		cout << "------------------------------------" << endl;

		for (int i = 0; i < point_3D.size(); i++){
			cout << point_3D[i] << endl;
		}
	}
	// print Line2D
	if (filterCriteria == "Line2D"){
		// sortByPt1
		if (sortCriteria == "Pt.1"){
			if (sortOrder == "ASC"){
				sort(line_2D.begin(), line_2D.end(), sortByPt1());
			}
			if (sortOrder == "DSC"){
				sort(line_2D.rbegin(), line_2D.rend(), sortByPt1());
			}
		}
		// sortByPt2
		if (sortCriteria == "Pt.2"){
			if (sortOrder == "ASC"){
				sort(line_2D.begin(), line_2D.end(), sortByPt2());
			}
			if (sortOrder == "DSC"){
				sort(line_2D.rbegin(), line_2D.rend(), sortByPt2());
			}
		}
		// sortByLength
		if (sortCriteria == "Length"){
			if (sortOrder == "ASC"){
				sort(line_2D.begin(), line_2D.end(), sortByLength());
			}
			if (sortOrder == "DSC"){
				sort(line_2D.rbegin(), line_2D.rend(), sortByLength());
			}
		}
	
		cout << " P1-X  P1-Y     P2-X  P2-Y    Length" << endl;
		cout << "--------------------------------------" << endl;

		for (int i = 0; i < line_2D.size(); i++){
			cout << line_2D[i] << endl;
		}
	}
	// print Line3D
	if (filterCriteria == "Line3D"){
		// sortByPt1
		if (sortCriteria == "Pt.1"){
			if (sortOrder == "ASC"){
				sort(line_3D.begin(), line_3D.end(), sortByPt1());
			}
			if (sortOrder == "DSC"){
				sort(line_3D.rbegin(), line_3D.rend(), sortByPt1());
			}
		}
		// sortByPt2
		if (sortCriteria == "Pt.2"){
			if (sortOrder == "ASC"){
				sort(line_3D.begin(), line_3D.end(), sortByPt2());
			}
			if (sortOrder == "DSC"){
				sort(line_3D.rbegin(), line_3D.rend(), sortByPt2());
			}
		}
		// sortByLength
		if (sortCriteria == "Length"){
			if (sortOrder == "ASC"){
				sort(line_3D.begin(), line_3D.end(), sortByLength());
			}
			if (sortOrder == "DSC"){
				sort(line_3D.rbegin(), line_3D.rend(), sortByLength());
			}
		}
	
		cout << " P1-X  P1-Y  P1-Z     P2-X  P2-Y  P2-Z    Length" << endl;
		cout << "--------------------------------------------------" << endl;

		for (int i = 0; i < line_3D.size(); i++){
			cout << line_3D[i] << endl;
		}
	}
}

void MyMenu::storeData(){
	string filename;
	cout << "Please enter file name: ";
	cin >> filename;

	// store the result into a file
	ofstream storeData;
	storeData.open(filename);
	
	if (filterCriteria == "Point2D"){
		storeData << "    X     Y    Dist.Fr Origin\n"
			  << "------------------------------\n";

		for (int i = 0; i < point_2D.size(); i++){
			storeData << point_2D[i];
		}
		
		cout << point_2D.size() << " records output successfully!" << endl;
	}
	if (filterCriteria == "Point3D"){
		storeData << "    X     Y     Z    Dist.Fr Origin\n"
			  << "------------------------------------\n";

		for (int i = 0; i < point_3D.size(); i++){
			storeData << point_3D[i];
		}
		
		cout << point_3D.size() << " records output successfully!" << endl;
	}
	if (filterCriteria == "Line2D"){
		storeData << " P1-X  P1-Y     P2-X  P2-Y    Length\n"
			  << "--------------------------------------\n";

		for (int i = 0; i < line_2D.size(); i++){
			storeData << line_2D[i];
		}
		
		cout << line_2D.size() << " records output successfully!" << endl;
	}
	if (filterCriteria == "Line3D"){
		storeData << " P1-X  P1-Y  P1-Z     P2-X  P2-Y  P2-Z    Length\n"
			  << "--------------------------------------------------\n";

		for (int i = 0; i < line_3D.size(); i++){
			storeData << line_3D[i];
		}
		
		cout << line_3D.size() << " records output successfully!" << endl;
	}
	storeData.close();				
}

