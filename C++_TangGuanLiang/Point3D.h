#pragma once
#ifndef POINT3D_H
#define POINT3D_H
#include "MyHeaderFile.h"
#include "Point2D.h"

class Point3D:public Point2D{
	friend ostream& operator<< (ostream& pOut, const Point3D& point_3D);

	protected:
		int z;
		void setDistFrOrigin();
	public:
		Point3D();
		Point3D(int x, int y, int z);
		~Point3D();
		int getZ() const;
		double getScalarValue() const;
		void setZ(int z);
		bool operator== (const Point3D& right)const;
		bool operator< (const Point3D& right)const;
		double operator- (const Point3D& right)const;
};
#endif
