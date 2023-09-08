#ifndef ARGENT_GRAPHICS_INSTANCE_H
#define ARGENT_GRAPHICS_INSTANCE_H

#include "StdInc.h"

#include "PhysicalDevice.h"

namespace Ar {

struct InstanceCapabilities {
    bool bSelectPhysicalDevice; /** @brief If this instance requires a physical device select. */
};

class Instance {
public:


    /** 
     * @brief Returns general information about how this instance will function. 
     * 
     * Get information about how to operate this instance. Depending on the driver
     * some operations may not need to be preformed so don't waste cycles doing them.
     * Just check if they need to be done. A common example is with physical devices,
     * OpenGL will automatically select a GPU, whereas newer drivers like Vulkan et al.
     * will require you to select one. 
     *
     * @param[out] capabilities The capabilities and requirements of this instance.
     *
     */
    virtual void GetCapabilities(
            InstanceCapabilities* pCapabilities);

    /**
     * @brief Returns all physical devices in the system.
     *
     * Returns an array of all physical devices on this system. Use this
     * function to select your device.
     *
     * @warning Use @ref GetCapabilities to determine if this instances driver requires
     * a physical device to be chosen.
     * 
     * @return std::vector<PhysicalDevice*> The array of physical devices.
     */
    [[nodiscard]] virtual std::vector<PhysicalDevice*> GetPhysicalDevices();
    
    
    /** 
     * @brief Uses this physical device for all future graphics operations. 
     *
     * Chooses a physical device for graphics operations such as buffer 
     * creation, and rendering. Some drivers require a physical device to
     * be chosen.
     *
     * @return bool True on success and false on failure.
     * 
     */
    [[nodiscard]] virtual bool SelectPhysicalDevice(
            PhysicalDevice* pPhysicalDevice);

};

} // namespace Ar

#endif // ARGENT_GRAPHICS_INSTANCE_H