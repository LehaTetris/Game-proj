// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/*
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

class GOLDENEGG_API AMyHUD : public AHUD
{
	GENERATED_BODY()
protected:
	// Шрифт, используемый для изображения текста в HUD.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
	class UFont* hudFont;//My font
	// Добавьте эту функцию, чтобы изобразить HUD!
	virtual void DrawHUD() override;
	//Массив сообщений для отображения
	TArray<Message> messages;
	//Функция для вывода сообщений
	void addMessage(Message msg);
};

*/

/*
#include "MyHUD.h"

void AMyHUD::DrawHUD() {
	Super::DrawHUD();
	DrawLine(200, 300, 400, 500, FLinearColor::Blue);
	DrawText("Hello bitches!", FColor::White, 1, 1, hudFont);
}

struct Message {
	FString message;
	float time;
	FColor color;
	Message() {
		time = 5.F;
		color = FColor::White;
	}
	Message(FString iMessage, float iTime, FColor iColor) {
		message = iMessage;
		time = iTime;
		color = iColor;
	}
};

*/