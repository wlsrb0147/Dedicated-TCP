// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

#include "Chat.h"

void AMyHUD::BeginPlay()
{
	if (ChatClass)
	{
		Chat = Cast<UChat>(CreateWidget(GetWorld(),ChatClass));
		Chat->AddToViewport(1);
		Chat->SetVisibility(ESlateVisibility::Visible);
	}
}
