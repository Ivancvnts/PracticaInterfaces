// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Crosshair.h"
#include "AmmoCounter.h"
#include "PlayerHealthBar.h"
#include "ReloadBar.h"
#include "Kismet/GameplayStatics.h"
#include "UTAD_UI_FPS/TP_WeaponComponent.h"
#include "UTAD_UI_FPS/UTAD_UI_FPSCharacter.h"


void UPlayerHUD::ShowNoWeapon()
{
	//Hide the widgets that are related to the weapon,
	ReloadBar->Hide();
	AmmoCounter->Hide();
	Crosshair->Hide();
}

void UPlayerHUD::ShowAll()
{
	//Show all widgets related to weapon
	ReloadBar->Show();
	AmmoCounter->Show();
	Crosshair->Show();
	
	AUTAD_UI_FPSCharacter* Player = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	UTP_WeaponComponent* WeaponComponent =  Player->GetAttachedWeaponComponent();
	WeaponComponent->OnCurrentAmmoChange.AddDynamic(this, &UPlayerHUD::UpdateCurrentAmmo);
	WeaponComponent->OnFire.AddDynamic(this, &UPlayerHUD::OnFire);
	WeaponComponent->OnTotalAmmoChange.AddDynamic(this, &UPlayerHUD::UpdateTotalAmmo);
	WeaponComponent->OnReload.AddDynamic(this, &UPlayerHUD::UpdateReloadBar);
	
}

void UPlayerHUD::Hide()
{
	
}

void UPlayerHUD::UpdateCurrentAmmo(int newCurrentAmmo)
{
	AmmoCounter->UpdateCurrentAmmo(newCurrentAmmo);
}

void UPlayerHUD::UpdateTotalAmmo(int newTotalAmmo)
{
	AmmoCounter->UpdateTotalAmmo(newTotalAmmo);
}

void UPlayerHUD::UpdateReloadBar(float percent)
{
	ReloadBar->UpdateReloadBarValue(percent);
}

void UPlayerHUD::OnFire()
{
	Crosshair->PlayCrosshairAnimation();
}

void UPlayerHUD::UpdateHealthBar(int Health, int MaxHealth)
{
	HealthBar->UpdatePlayerHealthBar(Health,MaxHealth);
}

void UPlayerHUD::StartSplashAnimation()
{
	PlayAnimation(BeginSplash);
}
