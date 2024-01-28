#include "MUtils.h"
void MUtils::DM(const FString& Message)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, Message);
}
