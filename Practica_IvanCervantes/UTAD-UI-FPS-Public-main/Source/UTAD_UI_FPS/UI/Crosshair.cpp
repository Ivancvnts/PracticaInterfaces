// Fill out your copyright notice in the Description page of Project Settings.


#include "Crosshair.h"

#include "Components/Image.h"

void UCrosshair::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UCrosshair::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UCrosshair::PlayCrosshairAnimation()
{
	PlayAnimation(FireAnimation);
}

void UCrosshair::UpdateCrosshair(bool EnemyInSight)
{
	if(EnemyInSight)
	{
		CrosshairImage.Get()->SetBrushFromTexture(EnemyTexture);
	}
	else
	{
		CrosshairImage.Get()->SetBrushFromTexture(NormalTexture);
	}
}
