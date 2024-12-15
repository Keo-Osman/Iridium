#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include "Defines.h"
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "vulkan/vulkan_core.h"

namespace Ird{
    struct VulkanData {
        VkInstance instance;
        VkApplicationInfo appInfo{};
        VkInstanceCreateInfo createInfo{};
    };
    //extern VulkanData irVkData;
    //extern VkInstanceCreateInfo irVkCreateInfo;
    void VulkanInit(){
        u32 extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        IRD_CORE_INFO("Extensions supported: {}", extensionCount);
        /*irVkData.appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        irVkData.appInfo.pApplicationName = "Editor";
        //irVkData.appInfo.applicationVersion = VK_MAKE_API_VERSION(1, 0, 0);
        irVkData.appInfo.pEngineName = "Iridium";
        //irVkData.appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        irVkData.appInfo.apiVersion = VK_API_VERSION_1_0;
        irVkCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        irVkCreateInfo.pApplicationInfo = &irVkData.appInfo;*/


    }
}