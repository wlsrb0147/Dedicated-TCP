// Fill out your copyright notice in the Description page of Project Settings.


#include "Chat.h"

#include "Components/Button.h"
#include "Components/EditableTextBox.h"

void UChat::OnSendButtonClicked()
{
	FString Context = ContextBox->GetText().ToString();
	FString ID = IDBox->GetText().ToString();

	if (Context != "" && ID != "")
	{
		UE_LOG(LogTemp,Warning,TEXT("Null 아님"))
	}
}

void UChat::NativeConstruct()
{
	Super::NativeConstruct();

	if (SendButton)
	{
		SendButton->OnClicked.AddDynamic(this,&UChat::OnSendButtonClicked);
	}
}
