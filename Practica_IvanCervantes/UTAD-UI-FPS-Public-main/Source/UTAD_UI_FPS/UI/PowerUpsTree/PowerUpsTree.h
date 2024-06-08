// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PowerUpsTree.generated.h"

class UButton;
class UPowerUp;
/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UPowerUpsTree : public UUserWidget
{
	GENERATED_BODY()

public:

	bool isOpen = false;
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnButtonPressed();

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPowerUp> Damage1;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPowerUp> Damage2;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPowerUp> Damage3;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPowerUp> Speed1;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPowerUp> Speed2;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPowerUp> Speed3;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPowerUp> Health1;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPowerUp> Health2;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UPowerUp> Health3;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> CloseButton;
	
};
