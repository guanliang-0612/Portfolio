#include "Point2D.h"
#include "Point3D.h"

// These are the constructors that I use for this cpp file
Point3D::Point3D(){
	// declare variable
	z = 0;
}

Point3D::Point3D(int x, int y, int z){
	setX(x);
	setY(y);
	this->z = z;

	setDistFrOrigin();
}

// Destructor
Point3D::~Point3D(){

}

// access function
int Point3D::getZ() const{
	return z;
}

double Point3D::getScalarValue() const{
	return distFrOrigin;
}

// mutator function
void Point3D::setDistFrOrigin(){
	distFrOrigin = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void Point3D::setZ(int z){
	this->z = z;
}

// overload function
bool Point3D::operator== (const Point3D& right)const{
	if (x == right.x && y == right.y && z == right.z){
		return true;
	}
	return false;
}

bool Point3D::operator< (const Point3D& right)const{
	if (x == right.x){
		if (y == right.y){
			return z < right.z;
		}
		return y < right.y;
	}
	return x < right.x;
}

double Point3D::operator- (const Point3D& right)const{
	return (distFrOrigin - right.getScalarValue());
}

ostream& operator<< (ostream& pOut, const Point3D& point_3D){
	pOut << "[" << setw(4) << point_3D.getX() << ", " << setw(4) << point_3D.getY() << ", "
	     << setw(4) << point_3D.getZ() << "]" << setw(3) << " " << fixed << setprecision(3)
	     << point_3D.getScalarValue() << endl;
	
	// to prevent the data loss
	return pOut.flush();
}

