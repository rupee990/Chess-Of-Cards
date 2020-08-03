// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CardChess : ModuleRules
{
	public CardChess(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "Paper2D" });
	}
}
