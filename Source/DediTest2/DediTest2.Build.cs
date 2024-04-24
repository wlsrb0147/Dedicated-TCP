// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DediTest2 : ModuleRules
{
	public DediTest2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Networking", "Sockets" });
	}
}
