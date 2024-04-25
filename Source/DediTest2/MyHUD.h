// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

class UMainUI;
class UChat;
/**
 * 
 */
UCLASS()
class DEDITEST2_API AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainUI> MainUIClass;

	UPROPERTY()
	UMainUI* MainUI;
	
	UPROPERTY()
	UChat* Chat;

	
};
