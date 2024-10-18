// Horror Game. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class HorrorGameEditorTarget : TargetRules
{
	public HorrorGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        ExtraModuleNames.AddRange( new string[] { "HorrorGame" } );
	}
}
