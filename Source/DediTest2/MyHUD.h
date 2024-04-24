// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

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
	TSubclassOf<UChat> ChatClass;
	
	UPROPERTY()
	UChat* Chat;
};
