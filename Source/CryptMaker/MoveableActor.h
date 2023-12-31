// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveableActor.generated.h"

UCLASS()
class CRYPTMAKER_API AMoveableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MainMesh;
	UPROPERTY(EditAnywhere)
	FVector MoveLoc;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
