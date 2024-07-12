// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DirectionAnim.h"
#include "Animation/AnimInstance.h"
#include "AnimInst_BaseLayer.generated.h"

/**
 * 
 */
UCLASS()
class TP_API UAnimInst_BaseLayer : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FDirectionAnim CycleAnimation_Walk;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FDirectionAnim CycleAnimation_Jogging;
};
