#pragma once
#include "MLine.h"
#include "MVector.h"

class MPlane
{
public:
	MVector StartingPoint;
	MVector VectorA;
	MVector VectorB;

	MPlane(const MVector& _StartingPoint, const MVector&  _VectorA, const MVector&  _VectorB) : StartingPoint(_StartingPoint), VectorA(_VectorA), VectorB(_VectorB)
	{}

	//It will give you a point where Line will intersect the plane
	MVector GetPointWhileIntersectingWithLine(const MLine& Line) const;
	//Give you point on Plane
	MVector GetPointOnPlane(const float& Alpha1, const float& Alpha2) const;
	void DrawPlane(UWorld* World, const int& PlaneLength = 1000, const int& PointDistance = 200) const;
	
};
