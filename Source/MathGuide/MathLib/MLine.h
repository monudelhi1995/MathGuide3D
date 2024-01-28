#pragma once
#include "MVector.h"

class MLine
{
public:
	MVector StartingPoint;
	MVector LineVector;
	MVector EndPoint;

	MLine(MVector _StartingPoint, MVector _EndPoint, bool bEndPoint) : StartingPoint(_StartingPoint)
	{
		if(bEndPoint)
		{
			EndPoint = _EndPoint;
			LineVector = EndPoint - StartingPoint;
		}
		else
		{
			LineVector = _EndPoint;
			EndPoint = StartingPoint + LineVector;
		}
	}

	MVector GetPointAtAlpha(float Alpha) const;
	MVector GetPointWhileIntersectingWithLine(const MLine& SecondLine) const;
	void DrawLine(UWorld* World, FColor DrawColor = FColor::Red, float Thickness = 3) const;
	
};
