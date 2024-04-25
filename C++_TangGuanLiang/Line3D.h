#ifndef LINE3D_H
#define LINE3D_H
#include "MyHeaderFile.h"
#include "Point3D.h"
#include "Line2D.h"

class Line3D : public Line2D{
	friend ostream& operator<< (ostream& pOut, const Line3D& line_3D);

	protected:
		double length;
		void setLength();
	private:
		Point3D pt1;
		Point3D pt2;
	public:
		Line3D();
		Line3D(Point3D pt1, Point3D pt2);
		~Line3D();
		Point3D getPt1() const;
		Point3D getPt2() const;
		double getScalarValue() const;
		void setPt1(Point3D pt1);
		void setPt2(Point3D pt2);
		bool operator== (const Line3D &right)const;
		bool operator< (const Line3D &right)const;
		double operator- (const Line3D &right)const;
};
#endif
