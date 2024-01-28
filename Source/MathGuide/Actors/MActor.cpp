// Fill out your copyright notice in the Description page of Project Settings.


#include "MActor.h"

#include "MathGuide/MathLib/MMatrix.h"
#include "MathGuide/MathLib/MVector.h"


// Sets default values
AMActor::AMActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMActor::MTranslate(FVector Vector)
{
	SetActorLocation(Vector + GetActorLocation());
}

void AMActor::MScale(FVector Vector)
{
	const MVector NormalizedVector = ToMVector(Vector);
	float ScaleValues[] = {NormalizedVector.X, 0,0,
					   0, NormalizedVector.Y, 0,
					   0, 0, NormalizedVector.Z};
	const auto ScaleMatrix = MMatrix(ScaleValues, 3, 3);
	const auto PositionMatrix = ToMVector(GetActorLocation()).ToMMatrix();
	const auto ScaledMatrix = ScaleMatrix*PositionMatrix;
	SetActorLocation(ScaledMatrix.ToMVector().ToFVector());
}

void AMActor::MEulerRotatation(FRotator Rotator)
{
	float XrollValues[] = {1,0,0,
					   0,static_cast<float>(FMath::Cos(FMath::DegreesToRadians(Rotator.Roll))),-(float)FMath::Sin(FMath::DegreesToRadians(Rotator.Roll)),
					   0,(float)FMath::Sin(FMath::DegreesToRadians(Rotator.Roll)), (float)FMath::Cos(FMath::DegreesToRadians(Rotator.Roll))};
	const MMatrix XRoll = MMatrix( XrollValues, 3, 3);

	float YrollValues[] = {static_cast<float>(FMath::Cos(FMath::DegreesToRadians(Rotator.Pitch))),0,static_cast<float>(FMath::Sin(FMath::DegreesToRadians(Rotator.Pitch))),
						   0,1,0,
						   -(float)FMath::Sin(FMath::DegreesToRadians(Rotator.Pitch)),0,(float)FMath::Cos(FMath::DegreesToRadians(Rotator.Pitch))};
	MMatrix YRoll = MMatrix(YrollValues, 3, 3);

	float zrollValues[] = {(float)FMath::Cos(FMath::DegreesToRadians(Rotator.Yaw)),-(float)FMath::Sin(FMath::DegreesToRadians(Rotator.Yaw)),0,
						   (float)FMath::Sin(FMath::DegreesToRadians(Rotator.Yaw)),(float)FMath::Cos(FMath::DegreesToRadians(Rotator.Yaw)),0,
						   0,0,1};
	const MMatrix ZRoll = MMatrix(zrollValues, 3, 3);

	const auto RotatedMatrix = XRoll * YRoll * ZRoll * (ToMVector(GetActorLocation()).ToMMatrix());
	SetActorLocation(RotatedMatrix.ToMVector().ToFVector());
}

void AMActor::MQuaternionRotation(FVector RotationVectorAxis, float Angle)
{
	float Q0 = FMath::Cos(FMath::DegreesToRadians(Angle/2)); 
	float SinValue = FMath::Sin(FMath::DegreesToRadians(Angle/2));

	MVector NormalizedVector = ToMVector(RotationVectorAxis).GetNormalizedVector()*SinValue;
	float QuaternionValues[] = {
		1 - 2*NormalizedVector.Y*NormalizedVector.Y - 2*NormalizedVector.Z*NormalizedVector.Z, 2*NormalizedVector.X*NormalizedVector.Y - 2*Q0*NormalizedVector.Z,      2*NormalizedVector.X*NormalizedVector.Z + 2*Q0*NormalizedVector.Y,
		2*NormalizedVector.X*NormalizedVector.Y + 2*Q0*NormalizedVector.Z,     1 - 2*NormalizedVector.X*NormalizedVector.X - 2*NormalizedVector.Z*NormalizedVector.Z,  2*NormalizedVector.Y*NormalizedVector.Z - 2*Q0*NormalizedVector.X,
		2*NormalizedVector.X*NormalizedVector.Z - 2*Q0*NormalizedVector.Y,     2*NormalizedVector.Y*NormalizedVector.Z + 2*Q0*NormalizedVector.X,      1 - 2*NormalizedVector.X*NormalizedVector.X - 2*NormalizedVector.Y*NormalizedVector.Y };

	const MMatrix QuaternionMatrix = {QuaternionValues, 3, 3};
	const MMatrix ActorLocationMatrix = ToMVector(GetActorLocation()).ToMMatrix();
	const auto RotatedMatrix= QuaternionMatrix * ActorLocationMatrix;
	SetActorLocation(RotatedMatrix.ToMVector().ToFVector());

}


// Called when the game starts or when spawned
void AMActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

MVector AMActor::ToMVector(FVector Vector)
{
	return {(float)Vector.X, (float)Vector.Y, (float)Vector.Z};
}
