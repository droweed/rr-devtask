// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "GameFramework/Actor.h"
#include "RRRestActor.generated.h"

UCLASS()
class RRTEST_API ARRRestActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARRRestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnGetWeatherResponse(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest, TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> HttpResponse, bool bArg);
	UFUNCTION(BlueprintCallable)
	void HTTPGetWeather(FString latitude, FString longitude);

private:
	FHttpModule* Http;
	const FString APIBaseURL = "https://api.ambeedata.com";
	const FString GetWeatherURL = "https://api.ambeedata.com/weather/latest/by-lat-lng?lat=%f&lng=%f";
	const FString WeatherIconsBaseURL = "https://assetambee.s3-us-west-2.amazonaws.com/weatherIcons/PNG/%s.png";
};
