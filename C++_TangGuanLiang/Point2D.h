#pragma once
#ifndef POINT2D_H
#define POINT2D_H
#include "MyHeaderFile.h"

class Point2D{
	friend ostream& operator<< (ostream& pOut, const Point2D& point_2D);

	protected:
		int x;
		int y;
		double distFrOrigin;
		void setDistFrOrigin(double);
	public:
		Point2D();
		Point2D(int x, int y);
		~Point2D();
		int getX() const;
		int getY() const;
		double getScalarValue() const;
		void setDistFrOrigin();
		void setX(int x);
		void setY(int y);
		bool operator== (const Point2D& right)const;
		bool operator< (const Point2D& right)const;
		double operator- (const Point2D& right)const;
};
#endif
