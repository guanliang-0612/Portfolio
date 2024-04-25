#include "Line3D.h"

// These are the constructors that I use for this cpp file
Line3D::Line3D(){
	
}

Line3D::Line3D(Point3D pt1, Point3D pt2) : Line2D(pt1, pt2), pt1(pt1), pt2(pt2){
	this->pt1 = pt1;
	this->pt2 = pt2;

	setLength();
}

// Destructor
Line3D::~Line3D(){

}

// access function (get method)
Point3D Line3D::getPt1() const{
	return pt1;
}

Point3D Line3D::getPt2() const{
	return pt2;
}

double Line3D::getScalarValue() const{
	return length;
}

// mutator function (set method)
void Line3D::setLength(){
	length = sqrt(pow((pt1.getX() - pt2.getX()),2) + pow((pt1.getY() - pt2.getY()),2)
		     + pow((pt1.getZ() - pt2.getZ()),2));
}

void Line3D::setPt1(Point3D pt1){
	this->pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2){
	this->pt2 = pt2;
}


// overload function
bool Line3D::operator== (const Line3D &right)const{
	if (pt1.getX() == right.pt1.getX() && pt1.getY() == right.pt1.getY() && 
	    pt1.getZ() == right.pt1.getZ()){
		return true;
	}
	return false;
}

bool Line3D::operator< (const Line3D &right)const{
	if (pt1.getX() == right.pt1.getX()){
		if (pt1.getY() == right.pt1.getY()){
			return pt1.getZ() < right.pt1.getZ();
		}
		return pt1.getY() < right.pt1.getY();
	}
	return pt1.getX() < right.pt1.getX();
}

double Line3D::operator- (const Line3D &right)const{
	return (length - right.getScalarValue());
}

ostream& operator<< (ostream& pOut, const Line3D& line_3D){
	pOut << "[" << setw(4) << line_3D.pt1.getX() << ", " << setw(4) << line_3D.pt1.getY()
	     << ", " << setw(4) << line_3D.pt1.getZ() << "]" << setw(3) << " " << "[" << setw(4) 
	     << line_3D.pt2.getX() << ", " << setw(4) << line_3D.pt2.getY() << ", " << setw(4)
	     << line_3D.pt2.getZ() << "]" << setw(3) << " " << fixed << setprecision(3) 
	     << line_3D.getScalarValue() << endl;
	
	// to prevent the data loss
	return pOut.flush();
}
