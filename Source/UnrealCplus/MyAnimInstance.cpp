// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "MyCharacter.h"

void UMyAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	//auto Pawn = TryGetPawnOwner();
	APawn* Pawn = TryGetPawnOwner();

	if(IsValid(Pawn))
	{
		MyCharacter = Cast<AMyCharacter>(Pawn);
		//if(IsValid(MyCharacter))
		if (MyCharacter) 
		{
			CharacterMovement = MyCharacter->GetCharacterMovement();
		}
	}

}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	//Todo
}
