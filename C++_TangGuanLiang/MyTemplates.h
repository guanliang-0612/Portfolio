#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H

struct sortByX{
	template <typename T>
	bool operator() (const T& left, const T& right) const{
		// sort by X in ascending order
		return left.getX() < right.getX();
	}
};

struct sortByY{
	template <typename T>
	bool operator() (const T& left, const T& right) const{
		// sort by Y in ascending order
		return left.getY() < right.getY();
	}
};

struct sortByZ{
	template <typename T>
	bool operator() (const T& left, const T& right) const{
		// sort by Z in ascending order
		return left.getZ() < right.getZ();
	}
};

struct sortByOrigin{
	template <typename T>
	bool operator() (const T& left, const T& right) const{
		// distFrOrigin
		return left.getScalarValue() < right.getScalarValue();
	}
};

// sort by line2D pt1
struct sortByPt1{
	template <typename T>
	bool operator() (const T& left, const T& right) const{
		if (left.getPt1().getX() == right.getPt1().getX()){
			return left.getPt1().getX() == right.getPt1().getX();
		}
		return left.getPt1().getX() < right.getPt1().getX();
	}
};

// sort by line2D pt2
struct sortByPt2{
	template <typename T>
	bool operator() (const T& left, const T& right) const{
		if (left.getPt2().getX() == right.getPt2().getX()){
			return left.getPt2().getX() == right.getPt2().getX();
		}
		return left.getPt2().getX() < right.getPt2().getX();
	}
};

struct sortByLength{
	template <typename T>
	bool operator() (const T& left, const T& right) const{
		return left.getScalarValue() < right.getScalarValue();
	}
};

// function template for the scalar result
template <typename T>
double final_scalar(const T& left, const T& right){
	return fabs(left.getScalarValue() - right.getScalarValue());
}

// function template to confirm is the same object or not
template <typename T>
bool same(const T& left, const T& right){
	if (left == right){
		return true;
	}
	return false;
}
#endif
