// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpsTree.h"
#include "PowerUp.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/GridPanel.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UPowerUpsTree::NativeConstruct()
{
	Super::NativeConstruct();
	
	CloseButton->OnPressed.AddDynamic(this, &UPowerUpsTree::OnButtonPressed);

	for(auto widget : GridPanel.Get()->GetAllChildren())
	{
		if(UPowerUp* PowerUp = Cast<UPowerUp>(widget))
		{
			PowerUps.Add(PowerUp);
			PowerUp->OnPowerUpObtained.AddDynamic(this,&UPowerUpsTree::OnPowerUpObtained);
		}
	}

	PointsText.Get()->SetText(FText::FromString("Points: " + FString::FromInt(Points)));
}

void UPowerUpsTree::OnButtonPressed()
{
	SetVisibility(ESlateVisibility::Hidden);
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerController->SetPause(false);
	PlayerController->bShowMouseCursor = false;
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
	isOpen = false;
}

void UPowerUpsTree::OnPowerUpObtained(int cost)
{
	Points -= cost;
	PointsText.Get()->SetText(FText::FromString("Points: " + FString::FromInt(Points)));
}

