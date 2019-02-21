// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC.h"
#include "Avatar.h"
#include "MyHUD.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BPProximitySphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Proximity Sphere"));
	BPProximitySphereComp->SetSphereRadius(128);//������ �����
	
	BPnameNPC = "Default name"; //��� �� ���������, ����������� � ��������
	NpcMessage = "Default message";//��������� �� ���������, ����������� � ����������
}

void ANPC::BPProxFun_Implementation(UPrimitiveComponent* OverlappedComponent, //�������� 1
	AActor* OtherActor, //�������� 2 - �����, ������� �������� �������
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult &SweepResult) {
	//������. ���� �������,�� ��� ��������� ��� �����������
	//���� ����� � ������� ��������� �����������, ��� �� �����,�� ������ ������ ��������� �� ������� 
	if (Cast<AAvatar>(OtherActor) == nullptr) {
		return;
	}
	APlayerController*PController = GetWorld()->GetFirstPlayerController();
	if (PController) {
		AMyHUD*hud = Cast<AMyHUD>(PController->GetHUD());
		hud->addMessage(Message(BPnameNPC+": "+NpcMessage, 5.f, FColor::White, BPFaceNPC));
	}
}//�����


// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	BPProximitySphereComp->SetHiddenInGame(false); //show in game
	BPProximitySphereComp->OnComponentBeginOverlap.AddDynamic(this, &ANPC::BPProxFun);
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}




