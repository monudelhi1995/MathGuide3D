#include "MPlane.h"

MVector MPlane::GetPointWhileIntersectingWithLine(const MLine& Line) const
{
	const MVector VectorToLine = Line.StartingPoint - StartingPoint;
	const MVector PlaneNormal = VectorA.CrossProduct(VectorB);
	const float LineAlpha = -PlaneNormal.DotProduct(VectorToLine) / PlaneNormal.DotProduct(Line.LineVector);
	return Line.GetPointAtAlpha(LineAlpha);
}

MVector MPlane::GetPointOnPlane(const float& Alpha1, const float& Alpha2) const
{
	return StartingPoint + VectorA * Alpha1 + VectorB * Alpha2;
}

void MPlane::DrawPlane(UWorld* World, const int& PlaneLength, const int& PointDistance) const
{
	const MVector TempVectorA = VectorA.GetNormalizedVector();
	const MVector TempVectorB = VectorB.GetNormalizedVector();

	for(int i = 0; i<=PlaneLength; i=i+PointDistance)
	{
		for(int j = 0; j<=PlaneLength; j=j+PointDistance)
		{
			const MVector DrawnPoint = StartingPoint + TempVectorA * i + TempVectorB * j;
			DrawnPoint.DrawPoint(World);
		}
	}
}
