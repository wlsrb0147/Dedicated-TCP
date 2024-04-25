// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.generated.h"

class AMyPlayerController;
class AMyHUD;
class UButton;
class UChat;
/**
 * 
 */
UCLASS()
class DEDITEST2_API UMainUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UChat* GetChat() const {return Chat;}
	///////////////////////////////////////////////////////////////////////////
	UPROPERTY(meta = (BindWidget))
	UChat* Chat;
	
	UPROPERTY(meta = (BindWidget))
	UButton* OpenChatButton;

	UPROPERTY(meta = (BindWidget))
	UButton* CloseChatButton;
	////////////////////////////////////////////////////////////////////////////
	
	UPROPERTY()
	AMyHUD* HUD;

	UPROPERTY()
	AMyPlayerController* Controller;

	FInputModeGameAndUI InputMode;
	
	/////////////////////////////////////////////////////////////////////////////
	UFUNCTION()
	void OnOpenChatButtonClicked();

	UFUNCTION()
	void OnCloseChatButtonClicked();
};
