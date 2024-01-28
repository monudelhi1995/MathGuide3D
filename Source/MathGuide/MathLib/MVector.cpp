#include "MVector.h"

#include "MMatrix.h"
#include "Kismet/KismetMathLibrary.h"

MVector MVector::operator+(const MVector& mVector) const
{
	return {X + mVector.X, Y + mVector.Y, Z + mVector.Z};
}

MVector MVector::operator-(const MVector& mVector) const
{
	return {X - mVector.X, Y - mVector.Y, Z - mVector.Z};
}

MVector MVector::operator*(const MVector& mVector) const
{
	return {X * mVector.X, Y * mVector.Y, Z * mVector.Z};
}

MVector MVector::operator*(const float& Multiplier) const
{
	return {X*Multiplier, Y*Multiplier, Z*Multiplier};
}

FVector MVector::ToFVector() const
{
	return FVector(X, Y, Z);
}

float MVector::GetMagnitude() const
{
	return sqrt(X * X + Y * Y + Z * Z);
}

float MVector::GetAngleBetweenVectors(const MVector& mVector) const
{
	const float MagnitudeMultiplication = GetMagnitude()*mVector.GetMagnitude();
	const float Radian = FMath::Acos(DotProduct(mVector)/MagnitudeMultiplication);
	return FMath::RadiansToDegrees(Radian);
}

float RoundOffValue(float Value)
{
	const int MultipliedValue = Value* 100;
	return (float)MultipliedValue/100;
}

MVector MVector::GetReflectionVector(const MVector& SurfaceNormal, UWorld* World) const
{
	const MVector OppositeVector = (*this)*-1;
	OppositeVector.DrawVector(World, {0,0,0}, FColor::Yellow);
	const float AngleDifference = OppositeVector.GetAngleBetweenVectors(SurfaceNormal);
	MVector ReflectionVector = OppositeVector.RotateVector(AngleDifference*2);
	const float AngleDifferenceBetweenReflectionAndNormal = ReflectionVector.GetAngleBetweenVectors(SurfaceNormal);
	if(RoundOffValue(AngleDifferenceBetweenReflectionAndNormal) == RoundOffValue(AngleDifference))
	{
		ReflectionVector.DrawVector(World, {0,0,0}, FColor::Green);
		return ReflectionVector;
	}
	else
	{
		ReflectionVector = OppositeVector.RotateVector(AngleDifference*-2);
		ReflectionVector.DrawVector(World, {0,0,0}, FColor::Green);
		return ReflectionVector;
	}
	
}

MVector MVector::GetPerpVector() const
{
	return {-Y, X, Z};
}

MVector MVector::GetNormalizedVector() const
{
	return {X / GetMagnitude(), Y / GetMagnitude(), Z / GetMagnitude()};
}

float MVector::DotProduct(const MVector& mVector) const
{
	return {X * mVector.X + Y * mVector.Y + Z * mVector.Z};
}

MVector MVector::CrossProduct(const MVector& mVector) const
{
	//(bz – cy)i + (cx – az)j + (ay – bx)k
	return {(Y * mVector.Z - Z * mVector.Y), (Z * mVector.X - X * mVector.Z), (X * mVector.Y - Y * mVector.X)};
}

MVector MVector::RotateVector(const float& AngleInDegree) const
{
	//x' = x cos θ - y sin θ
	//y' = y cos θ + x sin θ
	const float Radian = FMath::DegreesToRadians(AngleInDegree);
	return {(X*FMath::Cos(Radian) - Y*FMath::Sin(Radian)),(Y*FMath::Cos(Radian) + X * FMath::Sin(Radian)),(Z)};
}

void MVector::DrawVector(UWorld* World, MVector VectorStartPoint, FColor DrawColor, float Thickness) const
{
	DrawDebugLine(World, VectorStartPoint.ToFVector(), (VectorStartPoint + *this).ToFVector(),
	              DrawColor, true, -1, 0, Thickness);
	(VectorStartPoint + *this).DrawPoint(World, DrawColor, Thickness);
}

void MVector::DrawPoint(UWorld* World, FColor DrawColor, float Thickness) const
{
	DrawDebugSphere(World, ToFVector(), 5, 32, DrawColor, true, -1, 0, Thickness);
}

MMatrix MVector::ToMMatrix() const
{
	float MatrixValue[] = {X, Y, Z};
	return {MatrixValue, 3, 1};
}
