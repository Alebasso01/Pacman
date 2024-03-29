// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhantomPawn.h"
#include "PacmanPawn.h"
#include "Blinky.h"
#include "Inky.generated.h"

/**
 * 
 */
UCLASS()
class PACMANGRID_API AInky : public APhantomPawn
{
	GENERATED_BODY()
	virtual AGridBaseNode* GetPlayerRelativeTarget() override;

public:
	AInky();
	virtual void Tick(float DeltaTime) override;
	void SetGhostTarget();
	UPROPERTY(EditAnywhere)
		TEnumAsByte<EGhostId> EGhostId = Inky;	
	void TeleportInky();
private:
	UPROPERTY(VisibleAnywhere)
		class ABlinky* Blinky;
};
