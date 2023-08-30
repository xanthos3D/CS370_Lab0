// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include <cstdlib>

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	zValue = 30.5;
	yValue = 30.5;
	xValue = 30.5;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	OurVisibleComponent->SetupAttachment(RootComponent);
	particleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	particleEffect->SetupAttachment(RootComponent);
	// Create a dummy root component we can attach things to
	
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
	
	float random = FMath::FRandRange(-50.0,50.0);
	NewLocation.Z += DeltaHeight * zValue;//Scale our height by a factor of 20
	//NewLocation.X += DeltaHeight * factor;
	
	NewLocation.Y += DeltaHeight * FMath::FRandRange(-50.0,50.0) * yValue;
	//NewLocation.Y += static_cast<int>(random)* yValue;
	NewLocation.X += DeltaHeight * FMath::FRandRange(-50.0,50.0) * zValue;
	
	float DeltaRotation = DeltaTime * zValue;    //Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
	

	if (GEngine)

	{

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("x: %f y: %f z: %f"), NewLocation.X,NewLocation.Y,NewLocation.Z));
		


	}
}

