// Copyright (c), Firelight Technologies Pty, Ltd. 2012-2021.

#include "FMODStudioStyle.h"
#include "EditorStyle/Public/Interfaces/IEditorStyleModule.h"
#include "Modules/ModuleManager.h"
#include "Styling/SlateStyleRegistry.h"

#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(Style.RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)
#define BOX_BRUSH(RelativePath, ...) FSlateBoxBrush(Style.RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)

//////////////////////////////////////////////////////////////////////////
// FFMODStudioStyle

TSharedPtr<FSlateStyleSet> FFMODStudioStyle::StyleInstance = NULL;

void FFMODStudioStyle::Initialize()
{
    if (!StyleInstance.IsValid())
    {
        StyleInstance = Create();
    }
}

void FFMODStudioStyle::Shutdown()
{
    FSlateStyleRegistry::UnRegisterSlateStyle(StyleInstance->GetStyleSetName());
    ensure(StyleInstance.IsUnique());
    StyleInstance.Reset();
}

TSharedRef<FSlateStyleSet> FFMODStudioStyle::Create()
{
    TSharedRef<FSlateStyleSet> StyleRef = MakeShared<FSlateStyleSet>(TEXT("FMODStudioStyle"));
    FSlateStyleSet &Style = StyleRef.Get();

    const FVector2D Icon20x20(20.0f, 20.0f);
    const FVector2D Icon40x40(40.0f, 40.0f);

    Style.Set("ClassIcon.FMODAmbientSound", new IMAGE_BRUSH("Icons/AssetIcons/AmbientSound_16x", FVector2D(16.0f, 16.0f)));
    Style.Set("ClassThumbnail.FMODAmbientSound", new IMAGE_BRUSH("Icons/AssetIcons/AmbientSound_64x", FVector2D(64.0f, 64.0f)));

    Style.Set("ClassIcon.FMODAudioComponent", new IMAGE_BRUSH("Icons/ActorIcons/SoundActor_16x", FVector2D(16.0f, 16.0f)));

    Style.Set("ClassIcon.FMODAsset", new IMAGE_BRUSH("Icons/ActorIcons/SoundActor_16x", FVector2D(16.0f, 16.0f)));

    FSlateStyleRegistry::RegisterSlateStyle(Style);

    return StyleRef;
}

//////////////////////////////////////////////////////////////////////////

#undef IMAGE_BRUSH
