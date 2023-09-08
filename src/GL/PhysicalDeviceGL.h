#ifndef ARGENT_PHYSICAL_DEVICE_OPENGL_H
#define ARGENT_PHYSICAL_DEVICE_OPENGL_H

#include "StdInc.h"
#include "PhysicalDevice.h"

namespace Ar {

class PhysicalDeviceOpenGL {
public:

    /** Returns zero. */
    [[nodiscard]] virtual uint32_t            GetUID();

    /** Returns the name of the renderer hardware. */
    [[nodiscard]] virtual std::string_view    GetName();
    
    /** Returns the vendor of the renderer hardware. */
    [[nodiscard]] virtual std::string_view    GetVendorName();

protected:

    // The OpenGL Instance should only be creating this.
    PhysicalDeviceOpenGL();
    ~PhysicalDeviceOpenGL();

    friend class InstanceOpenGL;

private:
    std::string _name;
    std::string _vendor;

}

}; // namespace Ar

#endif // ARGENT_PHYSICAL_DEVICE_OPENGL_H