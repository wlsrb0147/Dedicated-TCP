// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

struct FIPv4Endpoint;
/**
 * 
 */
UCLASS()
class DEDITEST2_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Shutdown() override;

	bool StartServer(uint16 Port);
	bool ConnectServer();
	void StopServer();

	bool AcceptClient();
	
	bool SendTextToServer(FString Context);
	bool SendTextToAllClient(FString Context);
protected:

public:
	FSocket* ListenerSocket;
	FIPv4Endpoint* Endpoint;
	TArray<FSocket*> ConnectedClients;
};
