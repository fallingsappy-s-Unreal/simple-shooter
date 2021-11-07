// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleShooterPlayerController.h"

#include "Blueprint/UserWidget.h"

void ASimpleShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);

	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}

void ASimpleShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromViewport();
	
	if (bIsWinner)
	{
		UUserWidget* Win = CreateWidget(this, WinScreenClass);

		if(Win != nullptr)
		{
			Win->AddToViewport();	
		}
	}
	else
	{
		UUserWidget* Loose = CreateWidget(this, LoseScreenClass);

		if(Loose != nullptr)
		{
			Loose->AddToViewport();	
		}
	}
	
	GetWorldTimerManager().SetTimer(RestartTimerHandle, this, &APlayerController::RestartLevel, RestartDelay);
}
