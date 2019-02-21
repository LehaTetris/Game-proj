// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupItem.h"
#include "Avatar.h"
#include "Kismet/GameplayStatics.h"// UGameplayStatics::GetPlayerPawn();
#include "MyHUD.h"//myHudObj_ = Cast<AMyHUD>();
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"//PController->GetHUD();

// Sets default values
APickupItem::APickupItem()
{	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Name = "UNKNOWN ITEM";//неизвестный предмет 
	Quantity = 0;
	//задайм объект анриал
	ProxSphere = CreateDefaultSubobject<USphereComponent>("ProxSpher");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	// деалаем корневым объектом Mesh
	RootComponent = Mesh; 
	ProxSphere->SetupAttachment(Mesh);
	//Mesh->
	Mesh->SetSimulatePhysics(true);
	
}

// Called when the game starts or when spawned
void APickupItem::BeginPlay()
{
	Super::BeginPlay();
	//код для запуска APickupItem::Prox(),когда єта сфера близости 
	//пересекается с другим актором
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::Prox);

	AAvatar* const avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickupItem::Prox_Implementation(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult) {	// Called when the game starts or when spawned
	
	
	//body of fun
	AAvatar* avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	avatar->Pickup(this);
}