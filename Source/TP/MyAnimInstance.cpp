// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

#include "KismetAnimationLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UMyAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	GetLocationData();
	GetRotationData();
	GetVelocityData();
	GetAccelerationData();
}

UCharacterMovementComponent* UMyAnimInstance::GetCharacterMovement() const
{
	APawn* Pawn = TryGetPawnOwner();

	return Pawn != nullptr ? Cast<UCharacterMovementComponent>(Pawn->GetMovementComponent()) : nullptr;
}

void UMyAnimInstance::GetLocationData()
{
	const auto OwningActor = GetOwningActor();
	if (!OwningActor) return;


	WorldLocation = OwningActor->GetActorLocation();
}

void UMyAnimInstance::GetVelocityData()
{
	const auto CharMovementComponent = GetCharacterMovement();
	if (!CharMovementComponent) return;

	CharacterVelocity = CharMovementComponent->Velocity;
	CharacterVelocity2D = FVector(CharacterVelocity.X, CharacterVelocity.Y, 0.0f);

	LocomotionAngle = UKismetAnimationLibrary::CalculateDirection(CharacterVelocity2D, WorldRotaiton);

	LocomotionDirection = CalculateLocomotionDirection(LocomotionAngle, LocomotionDirection, FLocomotionSettings{});
}

void UMyAnimInstance::GetRotationData()
{
	const auto OwningActor = GetOwningActor();
	if (!OwningActor) return;

	WorldRotaiton = OwningActor->GetActorRotation();
}

void UMyAnimInstance::GetAccelerationData()
{
	const auto CharMovementComponent = GetCharacterMovement();
	if (!CharMovementComponent) return;


	Acceleration = CharMovementComponent->GetCurrentAcceleration();
	Acceleration2D = FVector(Acceleration.X, Acceleration.Y, 0.0f);
	IsAccelerating = !Acceleration.IsNearlyZero();
}

ELocomotionDirection UMyAnimInstance::CalculateLocomotionDirection(float CurrentLocomotionAngle,
                                                                   ELocomotionDirection CurrentDirection,
                                                                   FLocomotionSettings Settings)
{
	switch (CurrentDirection)
	{
	case ELocomotionDirection::Forward:
		Settings.FMax += Settings.DeadZone;
		Settings.FMin -= Settings.DeadZone;
		break;
	case ELocomotionDirection::Backward:
		Settings.BMax -= Settings.DeadZone;
		Settings.BMin += Settings.DeadZone;
		break;
	default:
		break;
	}

	// InRange_FloatFloat: Returns true if Value is in the range [A, B], false otherwise. Includes the boundaries.
	// 因此，不在[-135,+135]范围内，则是后退方向
	if (!UKismetMathLibrary::InRange_FloatFloat(CurrentLocomotionAngle, Settings.BMin, Settings.BMax, true, true))
	{
		return ELocomotionDirection::Backward;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(CurrentLocomotionAngle, Settings.FMin, Settings.FMax, true, true))
	{
		return ELocomotionDirection::Forward;
	}
	else
	{
		return CurrentLocomotionAngle > 0.0f ? ELocomotionDirection::Right : ELocomotionDirection::Left;
	}
}
