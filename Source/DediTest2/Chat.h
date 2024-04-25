// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Chat.generated.h"

class UButton;
class UEditableTextBox;
class UWrapBox;
/**
 * 
 */
UCLASS()
class DEDITEST2_API UChat : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UWrapBox* ContentBox;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* IDBox;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* ContextBox;

	UPROPERTY(meta = (BindWidget))
	UButton* SendButton;

	UFUNCTION(BlueprintCallable)
	void OnSendButtonClicked();

protected:
	virtual void NativeConstruct() override;
};
