// Copyright 2021 - Trifolium Digital Limited

#include "BlueprintsAccessToGConfigBPLibrary.h"
#include "BlueprintsAccessToGConfig.h"

#include "Misc/ConfigCacheIni.h"

// Static decl of our Enum to Ini filename map.
TMap<EConfigIniFileNames, FString> UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap;

UBlueprintsAccessToGConfigBPLibrary::UBlueprintsAccessToGConfigBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	if (UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Num() == 0)
	{
		/** Engine */
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GEngineIni, GEngineIni);

		/** Game */
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GGameIni, GGameIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GGameUserSettingsIni, GGameUserSettingsIni);

		/** Editor */
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GEditorIni, GEditorIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GEditorKeyBindingsIni, GEditorKeyBindingsIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GEditorLayoutIni, GEditorLayoutIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GEditorSettingsIni, GEditorSettingsIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GEditorPerProjectIni, GEditorPerProjectIni);

		/** Misc */
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GCompatIni, GCompatIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GLightmassIni, GLightmassIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GScalabilityIni, GScalabilityIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GHardwareIni, GHardwareIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GInputIni, GInputIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GRuntimeOptionsIni, GRuntimeOptionsIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GInstallBundleIni, GInstallBundleIni);
		UBlueprintsAccessToGConfigBPLibrary::IniNameLookupMap.Add(EConfigIniFileNames::GDeviceProfilesIni, GDeviceProfilesIni);
	}
}


////////////////////////////////////////////////////////////////
// GConfig Getters


FString UBlueprintsAccessToGConfigBPLibrary::GetString(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	FString StringValue;
	bWasFound = GConfig->GetString(*SectionName, *PropertyName, StringValue, IniNameLookupMap.FindChecked(ConfigFile));
	return StringValue;
}


FText UBlueprintsAccessToGConfigBPLibrary::GetText(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	FText TextValue;
	bWasFound = GConfig->GetText(*SectionName, *PropertyName, TextValue, IniNameLookupMap.FindChecked(ConfigFile));
	return TextValue;
}


bool UBlueprintsAccessToGConfigBPLibrary::GetBool(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	bool BoolValue;
	bWasFound = GConfig->GetBool(*SectionName, *PropertyName, BoolValue, IniNameLookupMap.FindChecked(ConfigFile));
	return BoolValue;
}


int32 UBlueprintsAccessToGConfigBPLibrary::GetInt(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	int32 IntValue;
	bWasFound = GConfig->GetInt(*SectionName, *PropertyName, IntValue, IniNameLookupMap.FindChecked(ConfigFile));
	return IntValue;
}


float UBlueprintsAccessToGConfigBPLibrary::GetFloat(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	float FloatValue;
	bWasFound = GConfig->GetFloat(*SectionName, *PropertyName, FloatValue, IniNameLookupMap.FindChecked(ConfigFile));
	return FloatValue;
}


TArray<FString> UBlueprintsAccessToGConfigBPLibrary::GetArray(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	TArray<FString> ArrayValue;
	bWasFound = GConfig->GetArray(*SectionName, *PropertyName, ArrayValue, IniNameLookupMap.FindChecked(ConfigFile)) > 0;
	return ArrayValue;
}


FColor UBlueprintsAccessToGConfigBPLibrary::GetColor(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	FColor ColorValue;
	bWasFound = GConfig->GetColor(*SectionName, *PropertyName, ColorValue, IniNameLookupMap.FindChecked(ConfigFile));
	return ColorValue;
}


FVector2D UBlueprintsAccessToGConfigBPLibrary::GetVector2D(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	FVector2D VectorValue;
	bWasFound = GConfig->GetVector2D(*SectionName, *PropertyName, VectorValue, IniNameLookupMap.FindChecked(ConfigFile));
	return VectorValue;
}


FVector UBlueprintsAccessToGConfigBPLibrary::GetVector(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	FVector VectorValue;
	bWasFound = GConfig->GetVector(*SectionName, *PropertyName, VectorValue, IniNameLookupMap.FindChecked(ConfigFile));
	return VectorValue;
}


FVector4 UBlueprintsAccessToGConfigBPLibrary::GetVector4(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	FVector4 VectorValue;
	bWasFound = GConfig->GetVector4(*SectionName, *PropertyName, VectorValue, IniNameLookupMap.FindChecked(ConfigFile));
	return VectorValue;
}


FRotator UBlueprintsAccessToGConfigBPLibrary::GetRotator(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound)
{
	FRotator RotatorValue;
	bWasFound = GConfig->GetRotator(*SectionName, *PropertyName, RotatorValue, IniNameLookupMap.FindChecked(ConfigFile));
	return RotatorValue;
}


////////////////////////////////////////////////////////////////
// GConfig Setters

void UBlueprintsAccessToGConfigBPLibrary::SetString(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FString& StringValue)
{
	GConfig->SetString(*SectionName, *PropertyName, *StringValue, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetText(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FText TextValue)
{
	GConfig->SetText(*SectionName, *PropertyName, TextValue, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetBool(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const bool BoolValue)
{
	GConfig->SetBool(*SectionName, *PropertyName, BoolValue, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetInt(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const int32 IntValue)
{
	GConfig->SetInt(*SectionName, *PropertyName, IntValue, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetFloat(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const float FloatValue)
{
	GConfig->SetFloat(*SectionName, *PropertyName, FloatValue, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetArray(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const TArray<FString>& ArrayValue)
{
	GConfig->SetArray(*SectionName, *PropertyName, ArrayValue, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetColor(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FColor& ColorValue)
{
	GConfig->SetColor(*SectionName, *PropertyName, ColorValue, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetVector2D(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FVector2D& Vector2DValue)
{
	GConfig->SetVector2D(*SectionName, *PropertyName, Vector2DValue, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetVector(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FVector& VectorValue)
{
	GConfig->SetVector(*SectionName, *PropertyName, VectorValue, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetVector4(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FVector4& Vector4Value)
{
	GConfig->SetVector4(*SectionName, *PropertyName, Vector4Value, IniNameLookupMap.FindChecked(ConfigFile));
}


void UBlueprintsAccessToGConfigBPLibrary::SetRotator(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FRotator& RotatorValue)
{
	GConfig->SetRotator(*SectionName, *PropertyName, RotatorValue, IniNameLookupMap.FindChecked(ConfigFile));
}


////////////////////////////////////////////////////////////////
// GConfig Misc

void UBlueprintsAccessToGConfigBPLibrary::Flush(EConfigIniFileNames ConfigFile, const bool bRefreshInConfigSystem)
{
	GConfig->Flush(bRefreshInConfigSystem, IniNameLookupMap.FindChecked(ConfigFile));
}