// Copyright WillTheWater

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UENUM(BlueprintType)
enum class EEffectApllicationPolicy : uint8
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy : uint8
{
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> EffectToApply);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Effects")
	bool bDestroyOnEffectRemoval = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Effects")
	EEffectApllicationPolicy InstantEffectApplicationPolicy = EEffectApllicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Effects")
	EEffectApllicationPolicy DurationEffectApplicationPolicy = EEffectApllicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Effects")
	EEffectApllicationPolicy InfiniteEffectApplicationPolicy = EEffectApllicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Effects")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemoveOnEndOverlap;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gameplay Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gameplay Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gameplay Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;
private:
};
