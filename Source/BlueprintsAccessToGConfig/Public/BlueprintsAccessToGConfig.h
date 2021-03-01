// Copyright 2021 - Trifolium Digital Limited

#pragma once

#include "Modules/ModuleManager.h"

class FBlueprintsAccessToGConfigModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
