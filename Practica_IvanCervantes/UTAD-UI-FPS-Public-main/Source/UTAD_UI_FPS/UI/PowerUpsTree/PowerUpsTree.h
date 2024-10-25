// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PowerUpsTree.generated.h"

class UGridPanel;
class UTextBlock;
class UCanvasPanel;
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
	UFUNCTION()
	void OnPowerUpObtained(int cost);

	TArray<UPowerUp*> PowerUps;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UGridPanel> GridPanel;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> CloseButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UTextBlock> PointsText;

	UPROPERTY(EditAnywhere, Category = "Options")
	int Points = 100;
};
