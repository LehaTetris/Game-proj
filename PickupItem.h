// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/StaticMeshComponent.h"
#pragma once
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupItem.generated.h"
//APickupItem::Prox
UCLASS()
class GOLDENEGG_API APickupItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupItem();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		FString Name;//имя получаемого предмета 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		int32 Quantity;//как много получаем

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		USphereComponent* ProxSphere;//сфера для подбора предмета 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		UStaticMeshComponent* Mesh;//сетка предмета?

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UTexture2D* Icon;//значок в интерфейсе

	//когда что-то попадает в сферу,функция запускается
	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void Prox(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);	// Called when the game starts or when spawned
	
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
