// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Avatar.generated.h"

UCLASS()// ������ ��� ������ � ������
class GOLDENEGG_API AAvatar : public ACharacter
{
	GENERATED_BODY()

private:


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shift")
		bool bIsShiftPressed = false;

public:	
	// Sets default values for this character's properties
	AAvatar();
	TMap<FString, int> Backpack;//����� ��� �������
	TMap<FString, UTexture2D*> Icons;//������ ��� ��������� � �������
	bool inventoriShowing;//���� ��������� ��������� ������������
	void Pickup(class APickupItem *item);//������� ���� ������ ������� ����� �������
	// Called every framew
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

		//virtual void Apawn::SetupPlayerInputComponent()
		//����������� ����� � ������ Apawn
	void MoveW(float);
	void MoveD(float);
	void ShiftPressed() {
		bIsShiftPressed = true;
	}
	void ShiftReleased() {
		bIsShiftPressed = false;
	}
	void Yaw(float);

//______Pitch______

	UFUNCTION(BlueprintNativeEvent, Category = "Pitch",meta=(DisplayName="Mouse Up Down"))
	void Pitch(float amount);

//________________
	const float GetMaxHP() const {
		return MaxHp;
	}

	const float GetHP() const {
		return Hp;
	}

	
	void ToggleInventory(); //������� ��� ����������� ��������� 


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Hp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float MaxHp;
	// Camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* bpCameraComponent;

private:
	// mouse sensitivity
	const float MOUSE_ROTATION_ = 50.0;
};
