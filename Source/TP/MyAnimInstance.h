// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LocomotionData")
	FLocomotionSettings LocomotionSettings;

private:
	UFUNCTION(BlueprintCallable, Category = "动画相关函数", meta=(BlueprintThreadSafe))
	void GetLocationData();

	UFUNCTION(BlueprintCallable, Category = "动画相关函数", meta=(BlueprintThreadSafe))
	void GetRotationData();

	UFUNCTION(BlueprintCallable, Category = "动画相关函数", meta=(BlueprintThreadSafe))
	void GetVelocityData();

	UFUNCTION(BlueprintCallable, Category = "动画相关函数", meta=(BlueprintThreadSafe))
	void GetAccelerationData();

	UFUNCTION(BlueprintCallable, Category = "动画相关函数", meta=(BlueprintThreadSafe))
	void CalculateLocomotionDirection(float CurrentLocomotionAngle, ELocomotionDirection CurrentDirection,
	                                  FLocomotionSettings Settings);

public:
};
