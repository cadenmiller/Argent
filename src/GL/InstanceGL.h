#ifndef ARGENT_GRAPHICS_OPENGL_INSTANCE_H
#define ARGENT_GRAPHICS_OPENGL_INSTANCE_H

#include "PhysicalDeviceGL.h"
#include "Instance.h"

namespace Ar {

class InstanceOpenGL final : public Instance  {
public:
    

    /** Returns OpenGLs capabilities and requirements to get up and running. */
    virtual void GetCapabilities(InstanceCapabilities& capabilities);

    /** Returns a single faux physical device because OpenGL chooses one for us. */
    [[nodiscard]] virtual std::vector<PhysicalDevice*> GetPhysicalDevices();

    /** Almost non operational as OpenGL doesn't have physical devices. */
    [[nodiscard]] virtual bool SelectPhysicalDevice(PhysicalDevice* pPhysicalDevice);
 

protected:

    // Only the System should be creating this.
    InstanceOpenGL();
    ~InstanceOpenGL();

    friend class System;

private:

    std::unique_ptr<PhysicalDeviceOpenGL> _defaultPhysicalDevice;

};

} // namespace Ar

#endif // ARGENT_GRAPHICS_OPENGL_INSTANCE_H