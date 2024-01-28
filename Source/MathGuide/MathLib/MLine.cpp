#include "MLine.h"

#include "Kismet/KismetMathLibrary.h"

MVector MLine::GetPointAtAlpha(float Alpha) const
{
	return {UKismetMathLibrary::VLerp(StartingPoint.ToFVector(), EndPoint.ToFVector(), Alpha)};
}

MVector MLine::GetPointWhileIntersectingWithLine(const MLine& SecondLine) const
{
	const MVector VectorToLine2 = SecondLine.StartingPoint - StartingPoint;
	const MVector Line2PerpVector = SecondLine.LineVector.GetPerpVector();
	const float IntersectingAlpha = VectorToLine2.DotProduct(Line2PerpVector) / LineVector.DotProduct(Line2PerpVector);
	return GetPointAtAlpha(IntersectingAlpha);
}

void MLine::DrawLine(UWorld* World, FColor DrawColor, float Thickness) const
{
	DrawDebugLine(World, StartingPoint.ToFVector(), (StartingPoint + LineVector).ToFVector(),
			  DrawColor, true, -1, 0, Thickness);
}
