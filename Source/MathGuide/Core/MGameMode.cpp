// Fill out your copyright notice in the Description page of Project Settings.


#include "MGameMode.h"

#include "MathGuide/MathLib/MLine.h"
#include "MathGuide/MathLib/MMatrix.h"
#include "MathGuide/MathLib/MPlane.h"
#include "MathGuide/MathLib/MVector.h"
#include "MathGuide/Utils/MUtils.h"

void AMGameMode::BeginPlay()
{
	Super::BeginPlay();

	float Values[] = {1, 2, 3};
	float Values1[] = {4, 5, 6};
	const MMatrix Matrix1 = {Values, 1, 3};
	const MMatrix Matrix2 = {Values1, 3, 1};
	std::cout << Matrix1;
	std::cout << Matrix2;

	std::cout << Matrix1 * Matrix2;
}
