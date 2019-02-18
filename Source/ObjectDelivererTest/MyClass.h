// Copyright 2019 ayumax. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MyClass.generated.h"

/**
 * 
 */UCLASS()
class OBJECTDELIVERERTEST_API USampleObject : public UObject
{
	GENERATED_BODY()

public:
	USampleObject();
	~USampleObject();

	
};

UCLASS()
class OBJECTDELIVERERTEST_API UMyClass : public UObject
{
	GENERATED_BODY()

public:
	UMyClass();
	~UMyClass();

	void Start();

	UFUNCTION()
	void OnConnect(UObjectDelivererProtocol* ClientSocket);
	UFUNCTION()
	void OnDisConnect(UObjectDelivererProtocol* ClientSocket);
	UFUNCTION()
	void OnReceive(UObjectDelivererProtocol* ClientSocket, const TArray<uint8>& Buffer);
	UFUNCTION()
	void OnReceiveString(FString ReceivedString);
	UFUNCTION()
	void OnReceiveObject(UObject* ReceivedObject);
};
