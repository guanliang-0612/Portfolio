#ifndef LINE2D_H
#define LINE2D_H
#include "MyHeaderFile.h"
#include "Point2D.h"

class Line2D{
	friend ostream& operator<< (ostream& pOut, const Line2D& line_2D);

	protected:
		double length;
		void setLength();
	private:
		Point2D pt1;
		Point2D pt2;
	public:
		Line2D();
		Line2D(Point2D pt1, Point2D pt2);
		~Line2D();
		Point2D getPt1() const;
		Point2D getPt2() const;
		double getScalarValue() const;
		void setPt1(Point2D pt1);
		void setPt2(Point2D pt2);
		bool operator== (const Line2D &right)const;
		bool operator< (const Line2D &right)const;
		double operator- (const Line2D &right)const;
};
#endif
