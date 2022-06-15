// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RRTest : ModuleRules
{
	public RRTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay",
			"HTTP", "Json", "JsonUtilities"
		});
	}
}
