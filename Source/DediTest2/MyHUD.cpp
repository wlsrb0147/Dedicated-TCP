// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

#include "Chat.h"
#include "MainUI.h"

void AMyHUD::BeginPlay()
{
	if (MainUIClass)
	{
		MainUI = Cast<UMainUI>(CreateWidget(GetWorld(),MainUIClass));
		MainUI->AddToViewport(1);
		MainUI->SetVisibility(ESlateVisibility::Visible);
		Chat = MainUI->GetChat();
	}
}
