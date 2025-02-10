// Copyright WillTheWater


#include "Actors/AuraEffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root")));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> EffectToApply)
{
	 UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;
	check(EffectToApply);
	FGameplayEffectContextHandle Handle = TargetASC->MakeEffectContext();
	Handle.AddSourceObject(this);
	FGameplayEffectSpecHandle Spec = TargetASC->MakeOutgoingSpec(EffectToApply, 1.f, Handle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*Spec.Data.Get());
}
