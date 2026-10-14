// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameData/ABCharacterStat.h"
#include "ABHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UABHUDWidget(const FObjectInitializer& ObjectInitializer);
	
	// 스탯이 업데이트 됐을 때.
	void UpdateStat(
		const FABCharacterStat& InBaseStat,
		const FABCharacterStat& InModifierStat
	);
	// HP가 업데이트 됐을 때.
	void UpdateHpBar(float NewCurrentHp);

protected:
	virtual void NativeConstruct() override;

protected:
	// HpBar Widget.
	UPROPERTY()
	TObjectPtr<class UABHpBarWidget> HpBar;

	// Stat Widget.
	UPROPERTY()
	TObjectPtr<class UABCharacterStatWidget> CharacterStat;
};
