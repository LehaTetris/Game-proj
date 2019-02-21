// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"
#include "Avatar.h"
#include "Kismet/GameplayStatics.h"

//TArray<int> x = {s1, s2, s3};
//x.Add(s4); // {s1,s2,s3,s4};

void AMyHUD::DrawHUD() {
	Super::DrawHUD();

	DrawHealthbar();


	//Проходимся по массиву структур; выполняем задом наперед,
	//так что если мы удалим пункт во время итерацииб невозникает никаких проблем
	for (int c = arr.Num() - 1; c >= 0; c--) {
		//фоновое окно для сообщения нужного размера
		float  outputWidth, outputHeight, pad = 10.f;
		GetTextSize(arr[c].message, outputWidth, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f*pad;
		float x = 0.f, y = c * messageH;
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageH);// черный фон
		DrawTexture(arr[c].tex, x, y, messageH, messageH, 0, 0, 1, 1);
		//изображаем сообщение с помощью хадфонт
		DrawText(arr[c].message, arr[c].color, x + pad, y + pad, hudFont);
		// сокращаем время отображения на время прошедшее с последнего кадра
		arr[c].time -= GetWorld()->GetDeltaSeconds();
		//если время сообщения вышло,удаляем его
		if (arr[c].time < 0) {
			arr.RemoveAt(c);
		}
	}
	
}
 
//Добавить еще одну структуру в конец массива 
void AMyHUD::addMessage(Message struct_obj)
{
	arr.Add(struct_obj);
}


void AMyHUD::DrawHealthbar() {
	//изображаем полосу здововья 
	AAvatar*avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	float barWidth = 200, barHeight = 15, barPad = 12, barMargin = 50;
	float percHp = avatar->GetHP() / avatar->GetMaxHP();
	DrawRect(
		FLinearColor(0, 0, 0, 1), 
		Canvas->SizeX - barWidth - barPad - barMargin, 
		Canvas->SizeY - barHeight - barPad - barMargin, 
		barWidth + 2 * barPad,
		barHeight + 2 * barPad);
	DrawRect(
		FLinearColor(1 - percHp, percHp, 0, 1), 
		Canvas->SizeX - barWidth - barMargin,
		Canvas->SizeY - barHeight - barMargin, 
		barWidth*percHp,
		barHeight);
}
