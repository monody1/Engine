/**
 * Copyright (c) 2020, chen.zr. All rights reserved.
 * 
 * @author chen.zr
 * @date 2020-09-07
 */

#include <glm/glm.hpp>
#include <vulkan/vulkan.hpp>
#include <vector>
#include <set>
#include <optional>
#include <cstring>
#include <GLFW/glfw3.h>
#include <algorithm>
// #include <iostream>
#include "baseApplication.hpp"
#include "vulkan/vulkan_core.h"
#include "utils.hpp"


namespace engine{

    struct QueueFamilyIndices{
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;

        bool IsComplete(){
            return graphicsFamily.has_value() && presentFamily.has_value();
        }
    };

    struct SwapChainSupportDetails{
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> format;
        std::vector<VkPresentModeKHR> presentMode;
    };

    #if MY_DEBUG
        static const bool enableValidationLayers = true;
        // std::cout << "My_Debug" << std::endl;
    #else
        static const bool enableValidationLayers = false;
        // std::cout << "No_debug" << std::endl;
    #endif

    class VulkanApplication: public BaseApplication
    {
    private:
        /* data */
    public:
        VulkanApplication(const GfxConfiguration& config): BaseApplication(config){};
        int Initialize() override;
        void Finalize() override;
        void Tick() override;

        bool IsQuit() override;

        void InitVulkan();
        void DrawFrame();
    private:
        void CreateInstance();
        void SetupDebugCallback();
        void CreateSurface();
        void PickPhysicalDevice();
        void CreateLogicalDevice();
        void CreateSwapChain();
        void CreateImageViews();
        void CreateRenderPass();
        void CreateGraphicsPipeline();
        void CreateFrameBuffers();
        void CreateCommandPool();
        void CreateCommandBuffers();
        void CreateSemaphores();
        void CleanUpVulkan();

        //vk help func
        bool IsDeviceSuitable(VkPhysicalDevice device);
        bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
        bool CheckValidationLayerSupport();
        void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        VkShaderModule CreateShaderModule(char* buffer, size_t bufferSize);

        std::vector<const char*> GetRequiredExtensions();
        QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
        SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);

        VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
        VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
        VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

        
        //Glfw help func
        static void CloseCallback(GLFWwindow* window);

        //Vk func prototype
        VkResult CreateDebugUtilsMessengerEXT(
            VkInstance instance, 
            const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, 
            const VkAllocationCallbacks* pAllocator, 
            VkDebugUtilsMessengerEXT* pDebugMessenger
        );
        
        static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,
            const VkDebugUtilsMessengerCallbackDataEXT*      pCallbackData,      
            void*                                            pUserData
        );

        void DestroyDebugUtilsMessengerEXT(
            VkInstance instance, 
            VkDebugUtilsMessengerEXT debugMessenger, 
            const VkAllocationCallbacks* pAllocator
        );
    
        VkInstance m_instance;
            VkDebugUtilsMessengerEXT m_debugMessenger;
        VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
        VkDevice m_device;
            VkQueue m_graphicsQueue;
            VkQueue m_presentQueue;
        VkSurfaceKHR m_surface;

        VkSwapchainKHR m_swapChain;
            VkExtent2D m_swapChainExtent;
            VkFormat m_swapChainImageFormat;
            std::vector<VkImage> m_swapChainImages;
        
        VkRenderPass m_renderPass;
        VkPipelineLayout m_pipelineLayout;
        VkPipeline m_graphicsPipeline;
        VkCommandPool m_commandPool;
            std::vector<VkCommandBuffer> m_commandBuffers;

        VkSemaphore m_imageAvailableSemaphore;
        VkSemaphore m_renderFinishedSemaphore;

        std::vector<VkImageView> m_imageViews;
        std::vector<VkFramebuffer> m_swapChainFramebuffers;

        GLFWwindow * m_pWindow = nullptr;

        const std::vector<const char*> m_kValidationLayers = {
            // "VK_LAYER_LUNARG_STANDARD_VALIDATION" has been deprecated
            "VK_LAYER_KHRONOS_validation",
            // "VK_LAYER_LUNARG_api_dump"
        };

        const std::vector<const char*> m_kDeviceExtensions = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
        };
    };
}
