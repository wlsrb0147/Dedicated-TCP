// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "MyGameInstance.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance()))
	{
		if (GetWorld()->GetFirstPlayerController() == this)
		{
			if (GameInstance->ConnectServer())
			{
				GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT("Connect Success"));
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT("Connect Failed"));
			}
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT("There's no GameInstance"));
	}
}
