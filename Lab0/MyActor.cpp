// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include <cstdlib>

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UPROPERTY(EditAnywhere, Category="BobbingAndRotatingFactor");
	factor = 30.5;
	

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	OurVisibleComponent->SetupAttachment(RootComponent);
	
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
	
	FVector NewLocation = GetActorLocation(); // Get Current location of the actor
	FRotator NewRotation = GetActorRotation(); // Get Current rotation of the actor
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	
	int random = rand() % 40;
	NewLocation.Z += DeltaHeight * factor;//Scale our height by a factor of 20
	//NewLocation.X += DeltaHeight * factor;
	NewLocation.Y += DeltaHeight * static_cast<int>(random)* factor;
	NewLocation.X += DeltaHeight * static_cast<int>(random)* factor;
	
	float DeltaRotation = DeltaTime * factor;    //Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
	

	if (GEngine)

	{

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("RunningTime: %f"), RunningTime));

	}
}

