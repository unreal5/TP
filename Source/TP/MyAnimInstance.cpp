// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

#include "KismetAnimationLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

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

void UMyAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	GetLocationData();
	GetRotationData();
	GetVelocityData();
	GetAccelerationData();
}
