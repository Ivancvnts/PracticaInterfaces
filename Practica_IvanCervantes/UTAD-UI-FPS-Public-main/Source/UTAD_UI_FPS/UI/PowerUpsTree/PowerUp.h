// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PowerUp.generated.h"

class UImage;
class UButton;
class UProgressBar;
/**
 * 
 */
UCLASS(Abstract)
class UTAD_UI_FPS_API UPowerUp : public UUserWidget
{
	GENERATED_BODY()

public:
	
	void SetCanBeObtained();

	
protected:

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	void OnObtained();
	UFUNCTION()
	void OnButtonHovered();
	UFUNCTION()
	void OnButtonPressed();
	UFUNCTION()
	void OnButtonReleased();

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> Button;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;
	
	UPROPERTY(EditAnywhere, Category = "Options")
	TObjectPtr<USoundBase> SoundOnHovered;
	
	UPROPERTY(EditAnywhere, Category = "Options")
	TObjectPtr<UPowerUp> NextPowerUp;
	
	UPROPERTY(EditAnywhere, Category = "Options")
	bool AvailableSinceBeginning;
	
	float ProgressPercent=0;
	bool IsButtonPressed = false;
	bool Obtained = false;
	
};