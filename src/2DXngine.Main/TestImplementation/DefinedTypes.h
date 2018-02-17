#pragma once
#include "DotTestController.h"
#include <TypeInformation/BaseTypesDefinitions.h>
#include "TestMouseCoordsComponent.h"

#ifdef main
DECLARE_TYPE_INFO(DotTestController, UpdateableComponent)
DECLARE_TYPE_INFO(TestMouseCoordsComponent, UpdateableComponent)

DEFINE_TYPE_INFO(DotTestController);
DEFINE_TYPE_INFO(TestMouseCoordsComponent);
#else
DECLARE_TYPE_INFO(DotTestController, UpdateableComponent)
DECLARE_TYPE_INFO(TestMouseCoordsComponent, UpdateableComponent)
#endif
