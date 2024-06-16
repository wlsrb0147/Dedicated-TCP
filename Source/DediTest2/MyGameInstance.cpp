// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"

void UMyGameInstance::Init()
{
	Super::Init();

	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		StartServer(60006);
	}
}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();
}

bool UMyGameInstance::StartServer(uint16 Port)
{
	// 소켓 서브 시스템으로 소켓 생성, 플랫폼은 소켓 서브시스템
	ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

	Endpoint = new FIPv4Endpoint(FIPv4Address::Any,Port);

	ListenerSocket = SocketSubsystem->CreateSocket(NAME_Stream,TEXT("TCPListener"));

	const bool bBind = ListenerSocket->Bind(Endpoint->ToInternetAddr().Get());

	if (!bBind)
	{
		ListenerSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ListenerSocket);
		return false;
	}

	const bool bListener = ListenerSocket->Listen(8);

	if (!bListener)
	{
		ListenerSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ListenerSocket);
		return false;
	}

	return true;
}

bool UMyGameInstance::ConnectServer()
{
	ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	FSocket* Socket = SocketSubsystem->CreateSocket(NAME_Stream,TEXT("TCPClient"));

	FIPv4Address IP;
	FIPv4Address::Parse(TEXT("127.0.0.1"),IP);

	const TSharedRef<FInternetAddr> Addr = SocketSubsystem->CreateInternetAddr();

	Addr->SetIp(IP.Value);
	Addr->SetPort(60006);

	const bool Connected = Socket->Connect(*Addr);

	if (Connected)
	{
		const TCHAR* SendData = TEXT("Hello, Server!");
		int32 ByteSend = 0;
		Socket->Send((uint8*)TCHAR_TO_UTF8(SendData),FCString::Strlen(SendData)*sizeof(TCHAR),ByteSend);
		return true;
	}

	Socket->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	return false;
}

void UMyGameInstance::StopServer()
{

}

bool UMyGameInstance::AcceptClient()
{
	if (!ListenerSocket) return false;

	TSharedRef<FInternetAddr> ClientAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	bool Pending;

	while (ListenerSocket->HasPendingConnection(Pending) && Pending)
	{
		FSocket* ClientSocket = ListenerSocket->Accept(*ClientAddress, TEXT("Accepted Client Connection"));
		if (ClientSocket)
		{
			ConnectedClients.Add(ClientSocket);
			return true;
		}
	}
	return false;
}

bool UMyGameInstance::SendTextToServer(FString Context)
{
	return false;
}

bool UMyGameInstance::SendTextToAllClient(FString Context)
{
	for (FSocket* ClientSocket :ConnectedClients)
	{
		if (ClientSocket)
		{
			const TCHAR* SendData = *Context;
			int32 BytesSent = 0;
			ClientSocket->Send((uint8*)TCHAR_TO_UTF8(SendData),FCString::Strlen(SendData)*sizeof(TCHAR),BytesSent);
		}
	}
	return true;

	
}
