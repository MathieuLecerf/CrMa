// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicTrigger.h"
#include "CryptMaker_MoverComponent.h"


UDynamicTrigger::UDynamicTrigger()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UDynamicTrigger::BeginPlay()
{
    Super::BeginPlay();
    SetMover(ac);
}


void UDynamicTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime,TickType, ThisTickFunction);

    if(Mover==nullptr)return;
    if(GetAcceptableActor()!=nullptr)
    {
        UE_LOG(LogTemp,Warning,TEXT("unlock"));
        Mover->ShouldMove(true);
    }
    else if(MoveBack)
    {
        UE_LOG(LogTemp,Warning,TEXT("relock"));
        Mover->ShouldMove(false);
    }
}

void UDynamicTrigger::SetMover(AActor* NewMover=nullptr)
{
    if(NewMover == nullptr)
    Mover = GetOwner()->FindComponentByClass<UCryptMaker_MoverComponent>();
    else
    Mover = NewMover->FindComponentByClass<UCryptMaker_MoverComponent>();
}

AActor* UDynamicTrigger::GetAcceptableActor()const
{
    TArray<AActor*> A;
    GetOverlappingActors(A);
     if(A.Num()>0)
     {
        for(AActor* g : A)
        {
            if(g->ActorHasTag("UN")&& !g->ActorHasTag("Grabbed"))
            return g;
        }
     }
     return nullptr;
}