// Copyright 2019 ayumax. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "ObjectDelivererProtocol.generated.h"

class UObjectDelivererProtocol;

DECLARE_DELEGATE_OneParam(FObjectDelivererProtocolConnected, UObjectDelivererProtocol*);
DECLARE_DELEGATE_OneParam(FObjectDelivererProtocolDisconnected, UObjectDelivererProtocol*);
DECLARE_DELEGATE_TwoParams(FObjectDelivererProtocolReceiveData, UObjectDelivererProtocol*, const TArray<uint8>&);

class UPacketRule;

UCLASS(BlueprintType, Blueprintable)
class OBJECTDELIVERER_API UObjectDelivererProtocol : public UObject
{
	GENERATED_BODY()

public:
	UObjectDelivererProtocol();
	~UObjectDelivererProtocol();

	/**
	 * start communication protocol.
	 */
	virtual void Start();

	/**
	 * close communication protocol.
	 */
	virtual void Close();

	/**
	 * send the data to the connection destination.
	 * @param DataBuffer - databuffer
	 */
	virtual void Send(const TArray<uint8>& DataBuffer);

	virtual void BeginDestroy() override;
	void SetPacketRule(UPacketRule* PacketRule);
	virtual void RequestSend(const TArray<uint8>& DataBuffer);

protected:
	void DispatchConnected(UObjectDelivererProtocol* ConnectedObject);
	void DispatchDisconnected(UObjectDelivererProtocol* DisconnectedObject);
	void DispatchReceiveData(UObjectDelivererProtocol* FromObject, const TArray<uint8>& Buffer);

	UPROPERTY(Transient)
	UPacketRule* PacketRule;

public:
	FObjectDelivererProtocolConnected Connected;
	FObjectDelivererProtocolDisconnected Disconnected;
	FObjectDelivererProtocolReceiveData ReceiveData;
};
