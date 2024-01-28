// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MATHGUIDE_API AMGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
};
