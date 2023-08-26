#ifndef ARGENT_GRAPHICS_H
#define ARGENT_GRAPHICS_H

#include "result.h"
#include "handle.h"

#define AR_GRAPHICS_NAME_SIZE 256

///////////////////////////////
// ArGfxPhysicalDevice
///////////////////////////////

AR_DEFINE_HANDLE(ArGfxPhysicalDevice);

typedef struct ArGfxPhysicalDeviceInfo
{
    char        name[AR_GRAPHICS_NAME_SIZE];
    char        vendorName[AR_GRAPHICS_NAME_SIZE];
    uint32_t    uid;
} ArGfxPhysicalDeviceInfo;

void            arGfxPhysicalDeviceGetInfo(ArGfxPhysicalDevice physicalDevice, ArGfxPhysicalDeviceInfo* pInfo);

///////////////////////////////
// ArGfxInstance
///////////////////////////////

typedef enum ArGfxAPI
{
    ARGENT_GRAPHICS_API_OPENGL = 0
} ArGfxAPI;

typedef struct ArGfxInstanceCreateInfo
{
    ArBool32 useValidation;
    ArGfxAPI api;
} ArGfxInstanceCreateInfo;

AR_DEFINE_HANDLE(ArGfxInstance);

ArResult        arGfxInstanceCreate(const ArGfxInstanceCreateInfo* pCreateInfo, ArGfxInstance* pInstance);
void            arGfxInstanceDestroy(ArGfxInstance instance);
ArResult        arGfxInstanceGetPhysicalDevices(ArGfxInstance instance, uint32_t* pCount, ArGfxPhysicalDevice* pPhysicalDevices);

///////////////////////////////
// ArGfxDevice
///////////////////////////////

AR_DEFINE_HANDLE(ArGfxDevice);

typedef struct ArGfxDeviceCreateInfo
{
    ArBool32 useValidation;
    ArGfxPhysicalDevice physicalDevice;
} ArGfxDeviceCreateInfo;

ArResult        arGfxDeviceCreate(const ArGfxDeviceCreateInfo* pCreateInfo, ArGfxDevice* pDevice);
void            arGfxDeviceDestroy(ArGfxDevice device);

///////////////////////////////
// ArGfxBuffer
///////////////////////////////

AR_DEFINE_HANDLE(ArGfxBuffer);

typedef struct ArGfxBufferCreateInfo
{
    ArSize size; // Size in bytes to allocate.
} ArGfxBufferCreateInfo;

ArResult        arGfxCreateBuffer(ArGfxDevice device, const ArGfxBufferCreateInfo* pCreateInfo, ArGfxBuffer* pBuffer);
void            arGfxDestroyBuffer(ArGfxDevice device, ArGfxBuffer buffer);
ArResult        arGfxUploadBuffer(ArGfxDevice device, ArGfxBuffer buffer, size_t size, const ArByte* pData);


#endif // ARGENT_ENGINE_RENDERER_H