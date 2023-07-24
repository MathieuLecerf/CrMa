// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicTrigger.h"


UDynamicTrigger::UDynamicTrigger()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UDynamicTrigger::BeginPlay()
{
    Super::BeginPlay();
}


void UDynamicTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime,TickType, ThisTickFunction);
    if(GetAcceptableActor()!=nullptr)
    UE_LOG(LogTemp,Warning,TEXT("unlock"));
}

AActor* UDynamicTrigger::GetAcceptableActor()const
{
    TArray<AActor*> A;
    GetOverlappingActors(A);
     if(A.Num()>0)
     {
        for(AActor* g : A)
        {
            if(g->ActorHasTag("UN"))
            return g;
        }
     }
     return nullptr;
}