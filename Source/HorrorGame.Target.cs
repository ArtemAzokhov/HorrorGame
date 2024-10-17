// Horror Game. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class HorrorGameTarget : TargetRules
{
	public HorrorGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "HorrorGame" } );
	}
}
