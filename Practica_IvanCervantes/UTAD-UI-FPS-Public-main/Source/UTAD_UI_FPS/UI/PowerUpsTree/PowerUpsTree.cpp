// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpsTree.h"
#include "PowerUp.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UPowerUpsTree::NativeConstruct()
{
	Super::NativeConstruct();
	
	CloseButton->OnPressed.AddDynamic(this, &UPowerUpsTree::OnButtonPressed);
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

