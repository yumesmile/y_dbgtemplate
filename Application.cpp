
#include <ydb/Application.h>
#include <GLFW/glfw3.h>
#include <exception>
#include <stdexcept>
#include "imgui/imgui.h"
#include <glad/glad.h>

#include "imgui/backends/imgui_impl_opengl3.h"
#include "imgui/backends/imgui_impl_glfw.h"


namespace ydb {

using namespace std;
using namespace ImGui;

static void glfw_error_callback(int error, const char* description) {
	
}

Application::Application() {
	
}

Application::Application(const Config& config) {
    const char* err_msg;

    //glfwSetErrorCallback(nullptr);
	if(!glfwInit()) {
		return;
		throw std::runtime_error(err_msg);
	}

    glfwWindowHint(GLFW_RESIZABLE, _config.resizable);
    glfwWindowHint(GLFW_VISIBLE, _config.visible);
    glfwWindowHint(GLFW_DECORATED, _config.decorated);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, _config.transparent);
	glfwWindowHint(GLFW_SAMPLES, _config.msaa);
	
	float xscale, yscale;
	
	if(_config.fullscreen) {
        GLFWmonitor* monitor = nullptr;
        if (_config.monitor == 0)
            monitor = glfwGetPrimaryMonitor();
        else {
            int  count;
            auto monitors = glfwGetMonitors(&count);
            if (conf.monitor < count)
                monitor = monitors[conf.monitor];
            else
                monitor = glfwGetPrimaryMonitor();
        }
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        if (!mode) {
            glfwGetError(&err_msg);
            throw std::runtime_error(err_msg);
        }
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
        glfwGetMonitorContentScale(monitor, &xscale, &yscale);
        // glfwWindowHint(GLFW_AUTO_ICONIFY, false);
        _window = glfwCreateWindow((int)(mode->width), (int)(mode->height), conf.title.c_str(), monitor, NULL);
    } else {
		glfwGetMonitorContentScale(glfwGetPrimaryMonitor(), &xscale, &yscale);
		_window = glfwCreateWindow((int)(_config.width*xscale), (int)(_config.height*yscale), _config.title.c_str(), NULL, NULL);
    }
	
	glfwMakeContextCurrent(_window);
	// set_vsync
	
	gladLoadGL();
	
	
}

}  // namespace ydb
