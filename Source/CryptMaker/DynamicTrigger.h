// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "DynamicTrigger.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CRYPTMAKER_API UDynamicTrigger : public UBoxComponent
{
	GENERATED_BODY()
	
	public: 
	UDynamicTrigger();
	protected:
		virtual void BeginPlay()override;
		AActor* GetAcceptableActor()const;
		class UCryptMaker_MoverComponent* Mover;
		UPROPERTY(EditAnywhere)
		bool MoveBack=true;
		UPROPERTY(EditAnywhere)
		AActor* ac;

	public:
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		UFUNCTION(BlueprintCallable)
		void SetMover(AActor* NewMover);
		
};
