#include "Point2D.h"

// These are the constructors that I use for this cpp file
Point2D::Point2D(){
	// declare variables
	x = 0;
	y = 0;
}

Point2D::Point2D(int x, int y){
	this->x = x;
	this->y = y;

	setDistFrOrigin();
}

// Destructor
Point2D::~Point2D(){

}

// access function
int Point2D::getX() const{
	return x;
}

int Point2D::getY() const{
	return y;
}

double Point2D::getScalarValue() const{
	return distFrOrigin;
}

// mutator function
void Point2D::setDistFrOrigin(){
	distFrOrigin = sqrt(pow(x, 2) + pow(y, 2));
}

void Point2D::setX(int x){
	this->x = x;
}

void Point2D::setY(int y){
	this->y = y;
}


// overload function
bool Point2D::operator== (const Point2D& right)const{
	if (x == right.x && y == right.y){
		return true;
	}
	return false;
}

bool Point2D::operator< (const Point2D& right)const{
	bool outcome;

	if (right.x < x){
		outcome = false;
	}else if (x < right.x){
		outcome = true;	
	}else{
		outcome = (y < right.y);
	}
	return outcome;
}

double Point2D::operator- (const Point2D& right)const{
	return (distFrOrigin - right.getScalarValue());
}

ostream& operator<< (ostream& pOut, const Point2D& point_2D){
	pOut << "[" << setw(4) << point_2D.getX() << ", " << setw(4) << point_2D.getY() << "]" 
	     << setw(3) << " " << fixed << setprecision(3) << point_2D.getScalarValue() << endl;
	
	// to prevent the data loss
	return pOut.flush();
}
