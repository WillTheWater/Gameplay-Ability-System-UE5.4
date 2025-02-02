// Copyright WillTheWater


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	
	const UAuraAttributeSet* AuraAS = CastChecked<UAuraAttributeSet>(AttributeSet);
	float Health = AuraAS->GetHealth();
	float MaxHealth = AuraAS->GetMaxHealth();
	OnHealthChanged.Broadcast(Health);
	OnMaxHealthChanged.Broadcast(MaxHealth);
}
