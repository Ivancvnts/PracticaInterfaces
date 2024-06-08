// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoCounter.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "../TP_WeaponComponent.h"
#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"

void UAmmoCounter::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
	
}

void UAmmoCounter::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UAmmoCounter::UpdateCurrentAmmo(int NewCurrentAmmo)
{
	CurrentAmmo.Get()->SetText(FText::AsNumber(NewCurrentAmmo));
}

void UAmmoCounter::UpdateTotalAmmo(int NewTotalAmmo)
{
	TotalAmmo.Get()->SetText(FText::AsNumber(NewTotalAmmo));
}
