// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridPawn.h"
#include "GridGenerator.h"
#include "GridPlayerController.h"
#include "GridBaseNode.h"
#include "PacmanPawn.generated.h"
//#include "PowerNode.h"
//#include "TimerManager.h"

/**
 * 
 */
UCLASS()
class PACMANGRID_API APacmanPawn : public AGridPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APacmanPawn();
	virtual void Tick(float DeltaTime) override;
	virtual void SetVerticalInput(float AxisValue) override;
	virtual void SetHorizontalInput(float AxisValue) override;
	// called on left mouse click (binding)
	virtual	void OnClick() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
		int32 GetScore();
	UPROPERTY(EditAnywhere)
		int32 score;
	UFUNCTION(BlueprintCallable)
		int32 GetLife();
	UPROPERTY(EditAnywhere)
		int32 life;
	void EatenCoin();
	int GetCoin();
	int coins2;
	int coins3;
	UFUNCTION()
		void GetPowerOff();
	UFUNCTION()
		bool GetPowerMode();
	virtual void SetTargetNode(AGridBaseNode* Node) override;
	void RespawnPacman();
	void DeathManager();

protected:
	virtual void BeginPlay() override;
	virtual void HandleMovement() override;
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	int coins;
	int total_coins;	
	FTimerHandle Timer;
	bool powermode;
	

};
