#pragma once
#include "CoreMinimal.h"
#include "Gait.generated.h"

UENUM(BlueprintType)
enum class EGait : uint8
{
	Walking = 0 UMETA(DisplayName = "走"),
	Jogging = 1 UMETA(DisplayName = "慢跑"),
};

USTRUCT(BlueprintType)
struct FGaitSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxWalkSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxAcceleration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BrakingDeceleration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BrakingFrictionFactor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bUseSeparateBrakingFriction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BrakingFriction;
};
