// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthBar.h"
#include "Kismet/GameplayStatics.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Components/ProgressBar.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"

#define BLINK_ANIMATION_TIME 0.5f
#define BLINK_THRESHOLD 0.25f

void UPlayerHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if(bIsLowHealth)
	{
		BlinkTimer += InDeltaTime;
		if (BlinkTimer >= BLINK_ANIMATION_TIME)
		{
			LowHealthBlink();
		}
	}
}

void UPlayerHealthBar::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
	Green = GetColorAndOpacity();
}

void UPlayerHealthBar::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerHealthBar::UpdatePlayerHealthBar(int NewHealth, int MaxHealth)
{
	if(NewHealth < 50)
	{
		bIsLowHealth = true;
	}
	
	float Health = NewHealth;
	float MHealth = MaxHealth;
	if(NewHealth <= 0)
	{
		HealthBar->SetPercent(0.f);
		return;
	}
		
	float Percent = Health/MHealth;
	HealthBar->SetPercent(Percent);
}

void UPlayerHealthBar::LowHealthBlink()
{
	FProgressBarStyle Style = HealthBar.Get()->GetWidgetStyle();
	
	if(bBlinkTurningRed)
	{
		Style.FillImage.TintColor = FColor::Green;
		bBlinkTurningRed = false;
	}
	else
	{
		Style.FillImage.TintColor = FColor::Red;
		bBlinkTurningRed = true;
	}
	
	HealthBar->SetWidgetStyle(Style);
	BlinkTimer = 0.f;
}
