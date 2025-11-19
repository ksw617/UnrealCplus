// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));  

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("/Game/StarterContent/Props/SM_Couch.SM_Couch"));

	//StaticMesh가 성공적으로 불러왔다면
	if (SM.Succeeded())
	{
		//해당 매쉬에 해당 오브젝트 넣어주기
		Mesh->SetStaticMesh(SM.Object);
	}

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

