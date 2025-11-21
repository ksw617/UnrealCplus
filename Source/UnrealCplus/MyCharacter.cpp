// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone"));

	//StaticMesh가 성공적으로 불러왔다면
	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.0, 0.0, -90.0), FRotator(0.0, -90.0, 0.0));
	}

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	CameraBoom->SetupAttachment(RootComponent);
	FollowCamera->SetupAttachment(CameraBoom);


	CameraBoom->SetRelativeLocationAndRotation(FVector(0.0, 0.0, 100.0), FRotator(-25.0, 0.0, 0.0));
	CameraBoom->TargetArmLength = 400.f;

	static ConstructorHelpers::FClassFinder<UAnimInstance> AI(TEXT("/Script/Engine.AnimBlueprint'/Game/Animation/ABP_Player.ABP_Player_C'"));
	if (AI.Succeeded())
	{
		GetMesh()->SetAnimClass(AI.Class);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("ForwardBackward"), this, &AMyCharacter::KeyUpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::KeyLeftRight);

	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::KeyAttack);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
}

void AMyCharacter::KeyUpDown(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value, false);
}

void AMyCharacter::KeyLeftRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value, false);
}

void AMyCharacter::KeyAttack()
{
	UE_LOG(LogTemp, Log, TEXT("Attack"));

}

