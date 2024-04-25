// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUI.h"

#include "Chat.h"
#include "MyHUD.h"
#include "MyPlayerController.h"
#include "Components/Button.h"

void UMainUI::NativeConstruct()
{
	Super::NativeConstruct();
	Controller = Cast<AMyPlayerController>( GetWorld()->GetFirstPlayerController());
	HUD = Cast<AMyHUD>(Controller->GetHUD());
	Chat->SetVisibility(ESlateVisibility::Collapsed);
	
	OpenChatButton->OnClicked.AddDynamic(this,&UMainUI::OnOpenChatButtonClicked);
	CloseChatButton->OnClicked.AddDynamic(this,&UMainUI::OnCloseChatButtonClicked);

	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	Controller->SetInputMode(InputMode);
	Controller->bShowMouseCursor = true;
}

void UMainUI::OnOpenChatButtonClicked()
{
	Chat->SetVisibility(ESlateVisibility::Visible);
	Controller->SetInputMode(FInputModeGameOnly());
	Controller->SetInputMode(InputMode);
	Controller->bShowMouseCursor = true;
}

void UMainUI::OnCloseChatButtonClicked()
{
	Chat->SetVisibility(ESlateVisibility::Collapsed);
	Controller->SetInputMode(FInputModeGameOnly());
	Controller->SetInputMode(InputMode);
	Controller->bShowMouseCursor = true;
}
