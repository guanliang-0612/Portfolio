#include "Line2D.h"

// These are the constructors that I use for this cpp file
Line2D::Line2D(){
	
}

Line2D::Line2D(Point2D pt1, Point2D pt2){
	this->pt1 = pt1;
	this->pt2 = pt2;

	setLength();
}

// Destructor
Line2D::~Line2D(){

}

// access function (get method)
Point2D Line2D::getPt1() const{
	return pt1;
}

Point2D Line2D::getPt2() const{
	return pt2;
}

double Line2D::getScalarValue() const{
	return length;
}

// mutator function (set method)
void Line2D::setLength(){
	length = sqrt(pow((pt1.getX() - pt2.getX()),2) + pow((pt1.getY() - pt2.getY()),2));
}

void Line2D::setPt1(Point2D pt1){
	this->pt1 = pt1;
}

void Line2D::setPt2(Point2D pt2){
	this->pt2 = pt2;
}


// overload function
bool Line2D::operator== (const Line2D &right)const{
	if (pt1.getX() == right.pt1.getX()){
		if (pt1.getY() == right.pt1.getY()){
			return true;
		}
	}
	return false;
}

bool Line2D::operator< (const Line2D &right)const{
	if (pt1.getX() == right.pt1.getX()){
		return pt1.getY() < right.pt1.getY();
	}
	return pt1.getX() < right.pt1.getX();
}

double Line2D::operator- (const Line2D &right)const{
	return (length - right.getScalarValue());
}

ostream& operator<< (ostream& pOut, const Line2D& line_2D){
	pOut << "[" << setw(4) << line_2D.pt1.getX() << ", " << setw(4) << line_2D.pt1.getY() 
	     << "]" << setw(3) << " " << "[" << setw(4) << line_2D.pt2.getX() << ", " << setw(4)
	     << line_2D.pt2.getY() << "]" << setw(3) << " " << fixed << setprecision(3) 
	     << line_2D.getScalarValue() << endl;
	
	// to prevent the data loss
	return pOut.flush();
}
