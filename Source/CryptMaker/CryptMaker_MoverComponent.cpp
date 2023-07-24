// Fill out your copyright notice in the Description page of Project Settings.


#include "CryptMaker_MoverComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UCryptMaker_MoverComponent::UCryptMaker_MoverComponent()
{
	owner = GetOwner();
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCryptMaker_MoverComponent::BeginPlay()
{
	Super::BeginPlay();
	OriginalLoc = owner->GetActorLocation();
	// ...
	
}


// Called every frame
void UCryptMaker_MoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector CurrentLocation = owner->GetActorLocation();
	FVector TL = MoveToLocation+OriginalLoc;
	float speed = FVector::Distance(MoveToLocation,OriginalLoc)/time;
	FVector NewLoc;
	if(MoveNow)
	{
		NewLoc = FMath::VInterpConstantTo(CurrentLocation,TL,DeltaTime,speed);
		owner->SetActorLocation(NewLoc);
	}
	else
	{
		NewLoc = FMath::VInterpConstantTo(CurrentLocation,OriginalLoc,DeltaTime,speed);
		owner->SetActorLocation(NewLoc);
	}
	
}

void UCryptMaker_MoverComponent::ShouldMove(bool move)
{
	MoveNow = move;
}

