// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Crosshair.generated.h"

class UImage;
class UWidgetAnimation;
/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UCrosshair : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void PlayCrosshairAnimation();

	void UpdateCrosshair(bool EnemyInSight);

private:
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> FireAnimation;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UImage> CrosshairImage;

	UPROPERTY(EditAnywhere, Category = "Crosshair")
	TObjectPtr<UTexture2D> NormalTexture;
	UPROPERTY(EditAnywhere, Category = "Crosshair")
	TObjectPtr<UTexture2D> EnemyTexture;
};
