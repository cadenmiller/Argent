#include "PhysicalDeviceGL.h"

#include "glad/glad.h"

namespace Ar {

PhysicalDeviceOpenGL::PhysicalDeviceOpenGL() {

    // Get basic information about the GPU here.
    _name = glGetString(GL_VENDOR);
    _vendor = glGetString(GL_VENDOR);

}

PhysicalDeviceOpenGL::~PhysicalDeviceOpenGL() {
}

uint32_t PhysicalDeviceOpenGL::GetUID() {
    return 0; // OpenGL does not have any identifier for any GPU except by name.
}

std::string_view PhysicalDeviceOpenGL::GetName() {
    return _name;
}

std::string_view PhysicalDeviceOpenGL::GetVendorName() {
    return _vendor;
}

} // namespace Ar