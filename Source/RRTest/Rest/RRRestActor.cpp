// Fill out your copyright notice in the Description page of Project Settings.


#include "RRRestActor.h"

#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"


// Sets default values
ARRRestActor::ARRRestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Http = &FHttpModule::Get();
}

// Called when the game starts or when spawned
void ARRRestActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARRRestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARRRestActor::HTTPGetWeather(FString latitude, FString longitude)
{
	if(latitude.IsEmpty() || longitude.IsEmpty())
	{
		return;
	}
	
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnGetWeatherResponse);

	// set request URL
	Request->SetURL(*FString::Printf(TEXT("https://api.ambeedata.com/weather/latest/by-lat-lng?lat=%s&lng=%s"), *latitude, *longitude));
	Request->SetVerb("GET");

	// Headers
	Request->SetHeader("Content-Type", "application/json");
	Request->SetHeader("x-api-key", "e6a23bd7f85c1073b327017c73e651acd13b9e559edb6cf3838be88b650a01c5");

	// Execute http request
	Request->ProcessRequest();
}

void ARRRestActor::OnGetWeatherResponse(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest,
	TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> HttpResponse, bool bArg)
{
	TSharedPtr<FJsonObject> JsonObject;

	if(HttpResponse->GetResponseCode() == 200)
	{
		// TODO - parse response body
	}
	const FString ResultBody = HttpResponse->GetContentAsString();

	UE_LOG(LogTemp, Display, TEXT("%s"), *ResultBody);	
}
