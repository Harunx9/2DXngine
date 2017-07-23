#pragma once
#include "DotTestController.h"
#include <TypeInformation\BaseTypesDefinitions.h>

#ifdef main
DECLARE_TYPE_INFO(DotTestController, UpdateableComponent)
DEFINE_TYPE_INFO(DotTestController);
#else
DECLARE_TYPE_INFO(DotTestController, UpdateableComponent)
#endif
