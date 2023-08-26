#ifndef ARGENT_GRAPHICS_INSTANCE_H
#define ARGENT_GRAPHICS_INSTANCE_H

#include "utility/handle.h"
#include "container/array.h"

#include "physical_device.h"

namespace Argent {
namespace Graphics {

using namespace Argent::Container;
using namespace Argent::Utility;

class Instance {
public:
    virtual Array<Handle<PhysicalDevice>> GetPhysicalDevices(uint32_t* pCount);
};

} // namespace Graphics
} // namespace Argent

#endif // ARGENT_GRAPHICS_INSTANCE_H