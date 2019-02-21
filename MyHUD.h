// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/Canvas.h"//Canvas->
#include "Engine/Font.h"//Canvas->
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

struct Message {
	FString message;
	float time;
	FColor color;
	UTexture* tex;
	Message() {
		time = 5.F;// врем по умолчанию
		color = FColor::White;
	}
	Message(FString iMessage, float iTime, FColor iColor, UTexture2D* BPNpcFace) {
		message = iMessage;
		time = iTime;
		color = iColor;
		tex = Cast<UTexture>(BPNpcFace);
	}
};

UCLASS()
class GOLDENEGG_API AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:
	// Шрифт, используемый для изображения текста в HUD.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
		class UFont* hudFont;//My font
		
	// функция, чтобы изобразить HUD!
	virtual void DrawHUD() override;

	void DrawHealthbar();


public:
	//Функция для вывода сообщений
	void addMessage(Message msg);

private:

	//Массив сообщений для отображения
	TArray<Message> arr;
	};

	
	
