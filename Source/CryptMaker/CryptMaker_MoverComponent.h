// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CryptMaker_MoverComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTMAKER_API UCryptMaker_MoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCryptMaker_MoverComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	AActor* owner;
	
	bool MoveNow= false;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere)
	FVector MoveToLocation;
	UPROPERTY(EditAnywhere)
	float time= 4.0f;
	void ShouldMove(bool move);
	FVector OriginalLoc;
		
};
