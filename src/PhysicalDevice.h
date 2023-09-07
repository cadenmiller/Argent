#ifndef ARGENT_GRAPHICS_PHYSICAL_DEVICE
#define ARGENT_GRAPHICS_PHYSICAL_DEVICE

#include "StdInc.h"

namespace Ar {

/** @brief Obtain information about a the graphics card on the system. */
class PhysicalDevice {
public:

    /** @brief Returns the unique identifier of this graphics device on this system. 
     * 
     * Gets the unique identifier for this physical device on this system alone.
     * Useful for configuration files and other ways to choose a specific graphics device.
     *
     * @return uint32_t The unique id of this physical device on this system alone. 
     *
     */
    virtual uint32_t            GetUID();

    /**
     * @brief Returns the name of the physical device listed by the driver.
     * 
     * Gets a human readable name of this physical device. Useful for displaying
     * user selection UI of a graphics device.
     *
     * @return std::string_view The name of this physical device.
     */
    virtual std::string_view    GetName();

    /**
     * @brief Returns the name of the physical devices vendor by the driver.
     *
     * Gets a human readable name of this physical devices vendor. Useful for
     * displaying a vendor name in debug menus or when a user is selecting a
     * physical devices.
     * 
     * @return std::string_view The name of this physical devices vendor. 
     */
    virtual std::string_view    GetVendorName();

protected:

    /* Only an Ar::Instance can create a physical device! */
    PhysicalDevice() = default; 
    ~PhysicalDevice() = default;

    friend class Instance;
};

} // namespace Ar

#endif // ARGENT_GRAPHICS_PHYSICAL_DEVICE