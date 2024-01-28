#pragma once
#include <iostream>
class MMatrix;
using namespace std;

class MVector
{
public:
	float X,Y,Z;

	MVector() { X = Y = Z = 0; }
	MVector(float _X, float _Y, float _Z) : X(_X), Y(_Y), Z(_Z)	{}
	MVector(const FVector& Vector) : X(Vector.X), Y(Vector.Y), Z(Vector.Z){}

	friend ostream& operator<<(ostream& stream, const MVector& mVector)
	{
		stream  << " X- "<< mVector.X << " Y- " << mVector.Y << " Z- " << mVector.Z;
		UE_LOG(LogTemp, Warning, TEXT("X - %f Y - %f Z - %f"),mVector.X, mVector.Y, mVector.Z );
		return stream;
	}

	FVector ToFVector() const;
	float GetMagnitude() const;
	float GetAngleBetweenVectors(const MVector& mVector) const;
	MVector GetReflectionVector(const MVector& SurfaceNormal, UWorld* World) const;
	MVector GetPerpVector() const;
	MVector GetNormalizedVector() const;
	float DotProduct(const MVector& mVector) const;
	MVector CrossProduct(const MVector& mVector) const;
	MVector RotateVector(const float& AngleInDegree) const;
	MVector operator+(const MVector& mVector) const;
	MVector operator-(const MVector& mVector) const;
	MVector operator*(const MVector& mVector) const;
	MVector operator*(const float& Multiplier) const;
	void DrawVector(UWorld* World, MVector VectorStartPoint = { 0,0,0}, FColor DrawColor = FColor::Red, float Thickness = 3) const;
	void DrawPoint(UWorld* World, FColor DrawColor = FColor::Red, float Thickness = 5) const;
	MMatrix ToMMatrix() const;
};
