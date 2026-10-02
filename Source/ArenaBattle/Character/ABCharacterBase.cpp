// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterBase.h"
#include "Character/ABCharacterControlData.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
AABCharacterBase::AABCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 맵(TMap) 설정.
	static ConstructorHelpers::FObjectFinder<UABCharacterControlData> ShoulderDataRef(
		TEXT("/Game/ArenaBattle/CharacterContorl/ABC_Shoulder.ABC_Shoulder")
	);

	if (ShoulderDataRef.Succeeded())
	{
		CharacterControlManager.Add(
			ECharacterControlType::Shoulder,
			ShoulderDataRef.Object
		);
	}

	static ConstructorHelpers::FObjectFinder<UABCharacterControlData> QuaterDataRef(
		TEXT("/Game/ArenaBattle/CharacterContorl/ABC_Quater.ABC_Quater")
	);

	if (QuaterDataRef.Succeeded())
	{
		CharacterControlManager.Add(
			ECharacterControlType::Quater,
			QuaterDataRef.Object
		);
	}

}

// Called when the game starts or when spawned
void AABCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AABCharacterBase::SetCharacterControlData(const UABCharacterControlData* InCharacterControlData)
{
	bUseControllerRotationYaw = InCharacterControlData->bUseControllerRotationYaw;

	GetCharacterMovement()->bUseControllerDesiredRotation = InCharacterControlData->bUseControllerDesiredRotation;

	GetCharacterMovement()->bOrientRotationToMovement = InCharacterControlData->bOrientRotationToMovement;

	GetCharacterMovement()->RotationRate = InCharacterControlData->RotationRate;

}

// Called every frame
void AABCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AABCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

