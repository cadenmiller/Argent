#ifndef ARGENT_GRAPHICS_PHYSICAL_DEVICE
#define ARGENT_GRAPHICS_PHYSICAL_DEVICE

#include <stdint.h>

namespace Argent {
namespace Graphics {

class PhysicalDevice {
public:
    virtual const char* GetName();
    virtual const char* GetVendorName();
    virtual uint32_t    GetUID();
};

} // namespace Graphics
} // namespace Argent

#endif // ARGENT_GRAPHICS_PHYSICAL_DEVICE