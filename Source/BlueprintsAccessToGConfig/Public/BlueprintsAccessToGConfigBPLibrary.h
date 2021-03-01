// Copyright 2021 - Trifolium Digital Limited

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintsAccessToGConfigBPLibrary.generated.h"

/**
 * Enum of Global Ini Files, we uses this along with our lookup map
 * to determine which ini is being used for the config action.
 */
UENUM(BlueprintType)
enum class EConfigIniFileNames : uint8
{
	/** Engine */
	GEngineIni				UMETA(DisplayName = "GEngineIni"),

	/** Game */
	GGameIni				UMETA(DisplayName = "GGameIni"),
	GGameUserSettingsIni	UMETA(DisplayName = "GGameUserSettingsIni"),

	/** Editor */
	GEditorIni				UMETA(DisplayName = "GEditorIni"),
	GEditorKeyBindingsIni	UMETA(DisplayName = "GEditorKeyBindingsIni"),
	GEditorLayoutIni		UMETA(DisplayName = "GEditorLayoutIni"),
	GEditorSettingsIni		UMETA(DisplayName = "GEditorSettingsIni"),
	GEditorPerProjectIni	UMETA(DisplayName = "GEditorPerProjectIni"),

	/** Misc */
	GCompatIni				UMETA(DisplayName = "GCompatIni"),
	GLightmassIni			UMETA(DisplayName = "GLightmassIni"),
	GScalabilityIni			UMETA(DisplayName = "GScalabilityIni"),
	GHardwareIni			UMETA(DisplayName = "GHardwareIni"),
	GInputIni				UMETA(DisplayName = "GInputIni"),
	GRuntimeOptionsIni		UMETA(DisplayName = "GRuntimeOptionsIni"),
	GInstallBundleIni		UMETA(DisplayName = "GInstallBundleIni"),
	GDeviceProfilesIni		UMETA(DisplayName = "GDeviceProfilesIni")
};


UCLASS()
class UBlueprintsAccessToGConfigBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	////////////////////////////////////////////////////////////////
	// GConfig Getters

	/** Access to FConfigCacheIni::GetString via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetString"), Category = "GConfig | Getters")
	static FString GetString(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetText via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetText"), Category = "GConfig | Getters")
	static FText GetText(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetBool via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetBool"), Category = "GConfig | Getters")
	static bool GetBool(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetInt via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetInt"), Category = "GConfig | Getters")
	static int32 GetInt(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetFloat via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetFloat"), Category = "GConfig | Getters")
	static float GetFloat(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetArray via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetArray"), Category = "GConfig | Getters")
	static TArray<FString> GetArray(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetColor via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetColor"), Category = "GConfig | Getters")
	static FColor GetColor(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetRotator via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetRotator"), Category = "GConfig | Getters")
	static FRotator GetRotator(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetVector2D via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetVector2D"), Category = "GConfig | Getters")
	static FVector2D GetVector2D(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetVector via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetVector"), Category = "GConfig | Getters")
	static FVector GetVector(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);

	/** Access to FConfigCacheIni::GetVector4 via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::GetVector4"), Category = "GConfig | Getters")
	static FVector4 GetVector4(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& bWasFound);


	////////////////////////////////////////////////////////////////
	// GConfig Setters

	/** Access to FConfigCacheIni::SetString via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetString"), Category = "GConfig | Setters")
	static void SetString(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FString& StringValue);

	/** Access to FConfigCacheIni::SetText via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetText"), Category = "GConfig | Setters")
	static void SetText(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FText TextValue);

	/** Access to FConfigCacheIni::SetBool via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetBool"), Category = "GConfig | Setters")
	static void SetBool(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const bool BoolValue);

	/** Access to FConfigCacheIni::SetInt via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetInt"), Category = "GConfig | Setters")
	static void SetInt(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const int32 IntValue);

	/** Access to FConfigCacheIni::SetFloat via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetFloat"), Category = "GConfig | Setters")
	static void SetFloat(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const float FloatValue);

	/** Access to FConfigCacheIni::SetArray via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetArray"), Category = "GConfig | Setters")
	static void SetArray(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const TArray<FString>& ArrayValue);

	/** Access to FConfigCacheIni::SetColor via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetColor"), Category = "GConfig | Setters")
	static void SetColor(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FColor& ColorValue);

	/** Access to FConfigCacheIni::SetRotator via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetRotator"), Category = "GConfig | Setters")
	static void SetRotator(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FRotator& RotatorValue);

	/** Access to FConfigCacheIni::SetVector2D via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetVector2D"), Category = "GConfig | Setters")
	static void SetVector2D(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FVector2D& Vector2DValue);

	/** Access to FConfigCacheIni::SetVector via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetVector"), Category = "GConfig | Setters")
	static void SetVector(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FVector& VectorValue);

	/** Access to FConfigCacheIni::SetVector4 via blueprints */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::SetVector4"), Category = "GConfig | Setters")
	static void SetVector4(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FVector4& Vector4Value);


	////////////////////////////////////////////////////////////////
	// GConfig Misc

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GConfig::Flush"), Category = "GConfig | Misc")
	static void Flush(EConfigIniFileNames ConfigFile, const bool bRefreshInConfigSystem);


private:

	/** Lookup for EConfigIniFileNames to G*Ini file names. */
	static TMap<EConfigIniFileNames, FString> IniNameLookupMap;
};
