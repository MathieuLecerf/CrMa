// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	// ...
	Character = Cast<ACharacter>(GetOwner());
	if (Character == nullptr)return;
	PHand = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(GrabMapping, 1);
		}

		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Started, this, &UGrabber::Grab);
			
			EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Completed, this, &UGrabber::Release);
		}
	}
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ..
	if(PHand==nullptr)return;
	FVector holdLoc = GetComponentLocation()+ GetForwardVector()*150;
	PHand->SetTargetLocationAndRotation(holdLoc,GetComponentRotation());
		
}

void UGrabber::Grab()
{
	
	FHitResult HitRes;
	bool hashit;
	GetGrabby(HitRes,hashit);

	if(hashit)
	{
		UPrimitiveComponent* primcomp = HitRes.GetComponent();
		primcomp->WakeAllRigidBodies();
		if(PHand==nullptr)return;
		UE_LOG(LogTemp,Warning,TEXT("Actor is: %s"), *HitRes.GetActor()->GetActorNameOrLabel());
		PHand->GrabComponentAtLocationWithRotation
		(primcomp,
		NAME_None,
		HitRes.ImpactPoint,
		GetComponentRotation());
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("no"));
	
	}
}

void UGrabber::Release()
{
	UE_LOG(LogTemp,Warning,TEXT("Release"));
	if(PHand==nullptr)return;
	PHand->ReleaseComponent();
}

void UGrabber::GetGrabby(FHitResult& hr, bool& hh)
{
	FVector Start = GetComponentLocation();
	FVector End = Start+GetForwardVector()*maxGrabDistance;
	DrawDebugLine(GetWorld(),Start,End,FColor::Red);
	FCollisionShape Sp = FCollisionShape::MakeSphere(50);
	hh= GetWorld()->SweepSingleByChannel(hr,Start,End,FQuat::Identity,ECC_GameTraceChannel2,Sp);
}