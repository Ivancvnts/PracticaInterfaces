// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"
#include "Components/Button.h"
#include "Components/ProgressBar.h"

void UPowerUp::SetCanBeObtained()
{
	Button->SetIsEnabled(true);
}

void UPowerUp::NativeConstruct()
{
	Super::NativeConstruct();
	ProgressBar->SetPercent(0);
	Button->OnHovered.AddDynamic(this, &UPowerUp::OnButtonHovered);
	Button->OnPressed.AddDynamic(this, &UPowerUp::OnButtonPressed);
	Button->OnReleased.AddDynamic(this, &UPowerUp::OnButtonReleased);
	
	Button->SetIsEnabled(AvailableSinceBeginning);
}

void UPowerUp::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if(IsButtonPressed)
	{
		ProgressPercent += 1 * InDeltaTime;
		ProgressBar.Get()->SetPercent(ProgressPercent);
	}
}

void UPowerUp::OnObtained()
{
	if(NextPowerUp)
	{
		NextPowerUp->SetCanBeObtained();
	}
	OnPowerUpObtained.Broadcast(cost);
	Obtained = true;
}

void UPowerUp::OnButtonHovered()
{
	if(SoundOnHovered)
	{
		PlaySound(SoundOnHovered);
	}
}

void UPowerUp::OnButtonPressed()
{
	if(!Obtained)
	{
		if(ProgressPercent < 1)
		{
			IsButtonPressed = true;
		
		}
		else if(ProgressPercent >= 1)
		{
			Button->SetIsEnabled(false);
			OnObtained();
		}
	}
}

void UPowerUp::OnButtonReleased()
{
	if(ProgressPercent >= 1)
	{
		Button->SetIsEnabled(false);
		OnObtained();
	}
	if(ProgressPercent < 1.0f)
	{
		ProgressBar.Get()->SetPercent(0);
		ProgressPercent = 0;
	}
	IsButtonPressed = false;
}
