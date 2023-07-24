// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicTrigger.h"


void UDynamicTrigger::BeginPlay()
{
    Super::BeginPlay();
}


void UDynamicTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime,TickType, ThisTickFunction);
}