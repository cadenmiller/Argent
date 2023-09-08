#include "InstanceGL.h"

#include "glad/glad.h"

namespace Ar {

InstanceOpenGL::InstanceOpenGL() {

}

InstanceOpenGL::~InstanceOpenGL() {
}

void InstanceOpenGL::GetCapabilities(InstanceCapabilities& capabilities) {

    static const InstanceCapabilities glCapabilities = {
    
        // OpenGL does not have an interface for physical device selection.
        // So users can skip the selection step.
        false // bSelectPhysicalDevice 

    };

    capabilities = glCapabilities; 
}

std::vector<PhysicalDevice*> InstanceOpenGL::GetPhysicalDevices() {
    static const std::vector<PhysicalDevice*> glPhysicalDevices = { _defaultPhysicalDevice.get() };
    return glPhysicalDevices;
}

}