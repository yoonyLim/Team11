// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_AnimInstance.h"

UCPP_AnimInstance::UCPP_AnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
}

void UCPP_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Character = Cast<APlayerState>(Pawn);
		if (Character)
		{
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}
