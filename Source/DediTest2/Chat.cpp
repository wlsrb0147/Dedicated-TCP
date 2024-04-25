// Fill out your copyright notice in the Description page of Project Settings.


#include "Chat.h"

#include "Components/Button.h"

void UChat::OnSendButtonClicked()
{
}

void UChat::NativeConstruct()
{
	Super::NativeConstruct();

	if (SendButton)
	{
		SendButton->OnClicked.AddDynamic(this,&UChat::OnSendButtonClicked);
	}
}
