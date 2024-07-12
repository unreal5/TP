// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gait.h"
#include "LocomotionDirection.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class TP_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
	UCharacterMovementComponent* GetCharacterMovement() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LocationData")
	FVector WorldLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "RotationData")
	FRotator WorldRotaiton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AccelerationData")
	FVector Acceleration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AccelerationData")
	FVector Acceleration2D;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AccelerationData")
	bool IsAccelerating;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "VelocityData")
	FVector CharacterVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "VelocityData")
	FVector CharacterVelocity2D;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "VelocityData")
	float LocomotionAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LocomotionData")
	ELocomotionDirection LocomotionDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GaitData")
	EGait CurrentGait;

private:
	UFUNCTION(meta=(BlueprintThreadSafe))
	void GetLocationData();

	UFUNCTION(meta=(BlueprintThreadSafe))
	void GetRotationData();

	UFUNCTION(meta=(BlueprintThreadSafe))
	void GetVelocityData();

	UFUNCTION(meta=(BlueprintThreadSafe))
	void GetAccelerationData();

	UFUNCTION(meta=(BlueprintThreadSafe))
	ELocomotionDirection CalculateLocomotionDirection(float CurrentLocomotionAngle,
	                                                  ELocomotionDirection CurrentDirection,
	                                                  FLocomotionSettings Settings);
};
