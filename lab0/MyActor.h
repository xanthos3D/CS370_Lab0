// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"
//#include "Math/Vector.h"

UCLASS()
class LAB0_API AMyActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* OurVisibleComponent;
	
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* particleEffect;

	UPROPERTY(EditAnywhere, Category = "BobbingAndRotatingFactor")
	float zValue;
	UPROPERTY(EditAnywhere, Category = "XFactor")
	float xValue;
	UPROPERTY(EditAnywhere, Category = "YFactor")
	float yValue;
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	//FVector movement;

};
