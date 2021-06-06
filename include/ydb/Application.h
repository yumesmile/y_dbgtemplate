#include <string>
#include <GLFW/glfw3.h>
#include <imgui.h>

namespace ydb {

using namespace std;

class Application {
public:
    struct Config {
        std::string title             = "mahi-gui";  ///< window title
        int         width             = 640;         ///< window width in pixels
        int         height            = 480;         ///< window height in pixels
        int         monitor           = 0;           ///< monitor the window will be on
        bool        fullscreen        = false;       ///< should the window be fullscreen?
        bool        resizable         = true;        ///< should the window be resizable?
        bool        visible           = true;        ///< should the window be visible?
        bool        decorated         = true;        ///< should the window have a title bar, close button, etc.?
        bool        transparent       = false;       ///< should the window area be transparent?
        bool        center            = true;        ///< should the window be centered to the monitor?
        int         msaa              = 4;           ///< multisample anti-aliasing level (0 = none, 2, 4, 8, etc.)
        bool        nvg_aa            = true;        ///< should NanoVG use anti-aliasing?
        bool        vsync             = true;        ///< should VSync be enabled?
        bool        dpi_aware         = false;       ///< does the application scale for high DPI? (WIP, DO NOT USE!!!)
        bool        gl_forward_compat = true;        ///< should GLFW_OPENGL_FORWARD_COMPAT be set? Always set on Mac.
        // Color background       = {0, 0, 0, 1};    ///< OpenGL clear color, i.e. window background color
    };

    Application();
    
    Application(const Config& config);

private:
    GLFWwindow*   _window;
    ImGuiContext* _imcontext;
    Config        _config;
};

}  // namespace ydb
