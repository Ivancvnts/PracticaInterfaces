// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHealthBar.h"

#include "Components/ProgressBar.h"

void UEnemyHealthBar::UpdateEnemyHealthBarValue(int Value, int MaxValue)
{
	float Health = Value;
	float MaxHealth = MaxValue;

	HealthBar->SetPercent(Health/MaxHealth);
}