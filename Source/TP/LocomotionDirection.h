#pragma once
#include "CoreMinimal.h"
#include "LocomotionDirection.generated.h"

UENUM(BlueprintType)
enum class ELocomotionDirection : uint8
{
	Forward = 0 UMETA(DisplayName = "Forward"),
	Backward = 1 UMETA(DisplayName = "Backward"),
	Left = 2 UMETA(DisplayName = "Left"),
	Right = 3 UMETA(DisplayName = "Right"),
};

USTRUCT(BlueprintType)
struct FLocomotionSettings
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float FMin = -50.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float FMax = 50.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float BMin = -130.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float BMax = 130.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DeadZone = 20.f;
};
