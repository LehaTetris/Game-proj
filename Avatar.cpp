// Fill out your copyright notice in the Description page of Project Settings.

#include "Avatar.h"
#include "Camera/CameraComponent.h" //UCameraComponent type
#include "Engine/Engine.h"
#include "PickupItem.h"
#define PRINT(string) GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, string)

// Sets default values
AAvatar::AAvatar() :Hp(100), MaxHp(100)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bpCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Avatar Camera Component"));


}
// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	bpCameraComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	bpCameraComponent->SetRelativeLocationAndRotation(FVector(-250.0, 0.0, 100.0), FRotator(-20.0, 0.0, 0.0));


}
// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// ищит приязки осей(bind axit дословно)
void AAvatar::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
    check(InputComponent);
	InputComponent->BindAxis("Forward", this, &AAvatar::MoveW);
	InputComponent->BindAxis("Strafe", this, &AAvatar::MoveD); 

	InputComponent->BindAxis("Yaw", this, &AAvatar::Yaw);
	InputComponent->BindAxis("Pitch", this, &AAvatar::Pitch);
	
	//часть отвчающая за инвентарь
	InputComponent->BindAction("Shift", IE_Pressed, this, &AAvatar::ShiftPressed);
	InputComponent->BindAction("Shift", IE_Released, this, &AAvatar::ShiftReleased);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

}

//Movement back and forth  
void AAvatar::MoveW(float amount)//amount of up-down movement
{	// return if Controller not eet installed or amount ofthe movement is 0
	if (Controller == nullptr || amount == 0) return;

	// If shift is pressed, then we multiply the amount mowement
	if (this->bIsShiftPressed == true) amount *= 4;
		
	FVector fwd = GetActorForwardVector();// Get World direction for Forward vector
	AddMovementInput(fwd, amount);// world direction * amount of up-down
	

}
//Movement right and left
void AAvatar::MoveD(float amount)// amount of right-left movement
{	// return if Controller not yet installed or yhe amount of the movement is 0
	if (Controller == nullptr && amount==0) return;
	FVector right = GetActorRightVector();
	// World direction scaled by amount 
	AddMovementInput(right, amount);
}

//Control the camera right and left
void AAvatar::Yaw(float amount) // amount of up-down rotation 
{	// return if Controller not yet installed or the amount of the movement is 0
	if (Controller == nullptr || amount == 0) return;
	// Calculate delta for this frame from (mouse rotation * amount of movement)
	AddControllerYawInput(MOUSE_ROTATION_ * amount * GetWorld()->GetDeltaSeconds());
}

//Control camera up and down 
void AAvatar::Pitch_Implementation(float amount)//amount of right-left rotation
{	// return if Controller not yet installed or the amount of the movement is 0
	if (Controller == nullptr || amount == 0) return;

	// get camera curent axis: xyz
	FRotator cameraRotation = bpCameraComponent->RelativeRotation;

	// GET the new Y-rotation: current Y + (sensitivity * distance * delta frame per second)
	float pitchY = cameraRotation.Pitch + (MOUSE_ROTATION_ * amount * GetWorld()->GetDeltaSeconds());
	cameraRotation.Pitch = pitchY;//new Y-rotation

	//if in range set new XYZ-rotation for camera
	if (pitchY <= -10.0 && pitchY >= -30.0)
		bpCameraComponent->SetRelativeRotation(cameraRotation);

}


//функция для отображения инвентаря 
void AAvatar::ToggleInventory() 
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, "Showininventory...");
}


void AAvatar::Pickup(APickupItem *item) 
{
	
}
