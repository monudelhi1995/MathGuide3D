// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MActor.generated.h"

UCLASS()
class MATHGUIDE_API AMActor : public AActor
{
	GENERATED_BODY()

public:
	AMActor();
	UFUNCTION(BlueprintCallable) void MTranslate(FVector Vector);
	UFUNCTION(BlueprintCallable) void MScale(FVector Vector);
	UFUNCTION(BlueprintCallable) void MEulerRotatation(FRotator Rotator);
	UFUNCTION(BlueprintCallable) void MQuaternionRotation(FVector RotationVectorAxis, float Angle);
	
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	class MVector ToMVector(FVector Vector);


};
