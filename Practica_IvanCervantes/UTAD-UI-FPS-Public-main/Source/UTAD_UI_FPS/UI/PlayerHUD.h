// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

class UAmmoCounter;
class UCrosshair;
class UPlayerHealthBar;
class UReloadBar;

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	/** Show the Minimap and the PlayerHealthBar */
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void ShowNoWeapon();

	/** Show all the widgets */
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void ShowAll();

	/** Hide all the widgets */
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	void UpdateHealthBar(int Health, int MaxHealth);

	void StartSplashAnimation();
protected:

	UFUNCTION()
	void UpdateCurrentAmmo(int newCurrentAmmo);
	UFUNCTION()
	void UpdateTotalAmmo(int newTotalAmmo);
	UFUNCTION()
	void UpdateReloadBar(float percent);
	UFUNCTION()
	void OnFire();
	
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPlayerHealthBar> HealthBar;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UCrosshair> Crosshair;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UReloadBar> ReloadBar;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UAmmoCounter> AmmoCounter;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> BeginSplash;

};
