// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC.generated.h"
UCLASS()
class GOLDENEGG_API ANPC : public ACharacter
{
	GENERATED_BODY()

protected:	// �������� � �������� ���������, ��� ���� ����������� ������������� � ���������	
		
		//�����, � ������� ����� ������������ �����,����� �������� �������
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
			USphereComponent* BPProximitySphereComp;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
			FString BPnameNPC;
		//��������� ������� ��� ������ ��� �������
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
			FString NpcMessage;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
			UTexture2D* BPFaceNPC;
		UFUNCTION(BlueprintNativeEvent, Category = "Collision")
			void BPProxFun(UPrimitiveComponent* OverlappedComponent,
							AActor* OtherActor,
							UPrimitiveComponent* OtherComp,
							int32 OtherBodyIndex,
							bool bFromSweep,
							const FHitResult &SweepResult);

	    //NPC creating.!.

public:
	// Sets default values for this character's properties
	ANPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
