#ifndef ARGENT_SYSTEM_H
#define ARGENT_SYSTEM_H

#include "../Instance.h"

namespace Ar {

enum class InstanceDriverType {
    eOpenGL,
    eVulkan,
    eDirectX11,
};

/** Your system statically implemented */
class SystemDefault {
public:
    
    /**
     * @brief Returns all supported instance drivers on this device.
     *
     * Returns a list of supported instance drivers types. Use this 
     * information to select a supported driver and create an instance.
     * 
     * @return std::vector<InstanceDriverType> All supported instance drivers on this device.
     */
    static std::vector<InstanceDriverType> GetSupportedDrivers();

    /**
     * @brief Creates an instance to initialize graphics.
     *
     * Creates an instance used for choosing a physical device,
     * rendering, and presentation. Use the instance as a starting
     * off point for the rest of your application.
     * 
     */
    static Instance* CreateInstance(InstanceDriverType driver);
    
};

} // namespace Ar

#endif // ARGENT_SYSTEM_H