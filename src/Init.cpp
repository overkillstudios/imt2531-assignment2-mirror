#include <overkill/Init.hpp>

namespace overkill
{

void Init::loadConfig() 
{
    auto filestring = Util::fileToString(C::Configpath);
    Parser p(filestring);


    LOG_INFO("Loading %s", C::Configpath)



    //
    // OPENGL CONFIG
    //


    // int   C::GLVersionMajor 
    if (auto[key, GLVersionMajor, err] = p.nextKeyInteger(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::GLVersionMajor = GLVersionMajor;
    }

    // int   C::GLVersionMinor
    if (auto[key, GLVersionMinor, err] = p.nextKeyInteger(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::GLVersionMinor = GLVersionMinor;
    }


    //
    // WINDOW CONFIG
    //

    // int   C::WinWidth     
    if (auto[key, WinWidth, err] = p.nextKeyInteger(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::WinWidth = WinWidth;
    }

    // int   C::WinHeight 
    if (auto[key, WinHeight, err] = p.nextKeyInteger(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::WinHeight = WinHeight;
    }

    // char  C::WinName[MaxString]    
    if (auto[key, WinName, err] = p.nextKeyString(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        strcpy(C::WinName, WinName.data());
    }       


    // glm::vec4 C::ClearColor  
    if (auto[key, ClearColor, err] = p.nextKeyColor(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::ClearColor = ClearColor;
    }
    



    //
    // CAMERA CONFIG
    //


    // float C::FOV           
    if (auto[key, FOV, err] = p.nextKeyFloat(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::FOV = FOV;
    }       

    // float C::MaxFOV   
    if (auto[key, MaxFOV, err] = p.nextKeyFloat(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::MaxFOV = MaxFOV;
    }              
    // float C::MinFOV 
    if (auto[key, MinFOV, err] = p.nextKeyFloat(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::MinFOV = MinFOV;
    }                
    // float C::ZoomSensitivity 
    if (auto[key, ZoomSensitivity, err] = p.nextKeyFloat(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::ZoomSensitivity = ZoomSensitivity;
    }       
    // float C::LookSensitivity 
    if (auto[key, LookSensitivity, err] = p.nextKeyFloat(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::LookSensitivity = LookSensitivity;
    }       
    // float C::PanSensitivity  
    if (auto[key, PanSensitivity, err] = p.nextKeyFloat(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::PanSensitivity = PanSensitivity;
    }       
    // float C::NearClip   
    if (auto[key, NearClip, err] = p.nextKeyFloat(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::NearClip = NearClip;
    }            
    // float C::FarClip      
    if (auto[key, FarClip, err] = p.nextKeyFloat(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::FarClip = FarClip;
    }          
    // float C::CameraOffset    
    if (auto[key, CameraOffset, err] = p.nextKeyFloat(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::CameraOffset = CameraOffset;
    }


    //
    // ASSETS CONFIG
    //

    // char C::TexturesFolder[MaxString]   
    if (auto[key, TexturesFolder, err] = p.nextKeyString(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        strcpy(C::TexturesFolder, TexturesFolder.data());
    }       
 

    // char C::ShadersFolder[MaxString] 
    if (auto[key, ShadersFolder, err] = p.nextKeyString(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        strcpy(C::ShadersFolder, ShadersFolder.data());
    }       

    // char C::MaterialsFolder[MaxString] 
    if (auto[key, MaterialsFolder, err] = p.nextKeyString(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        strcpy(C::MaterialsFolder, MaterialsFolder.data());
    }       

    // char C::ModelsFolder[MaxString]   
    if (auto[key, ModelsFolder, err] = p.nextKeyString(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        strcpy(C::ModelsFolder, ModelsFolder.data());
    }       

    // char C::ScenesFolder[MaxString]    
    if (auto[key, ScenesFolder, err] = p.nextKeyString(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        strcpy(C::ScenesFolder, ScenesFolder.data());
    }       
 

    //
    // SHADERS CONFIG
    //
    // unsigned int C::MAX_LIGHTS
    if (auto[key, MAX_LIGHTS, err] = p.nextKeyInteger(); err) {
        LOG_WARN("config.yml error on key --> %s...", key.data());
        return;
    } else {
        C::MAX_LIGHTS = unsigned(MAX_LIGHTS);
    }
}


auto Init::GLFW(
    const int openglMajor,
    const int openglMinor,
    const int wwidth,
    const int wheight,
    const char* wname) -> GLFWwindow*
{
    if (!glfwInit()){
        glfwTerminate();
        exit(-1); //(Init::logtag, "Failed to init GLFW");
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, openglMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, openglMinor);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(wwidth, wheight, wname, NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL) {
        glfwTerminate();
        exit(-1); // LOG_ERROR(Init::logtag, "Failed to open GLFW window");
    }
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSwapInterval(1);
    //q  glfwSetKeyCallback(window, key_callback);

    glfwSetKeyCallback(window, Input::OnInputKey); //set upp callbacks
    glfwSetCursorPosCallback(window, Input::OnCursorHover);
    glfwSetScrollCallback(window, Input::OnScrollChange);
    glfwSetMouseButtonCallback(window, Input::OnMouseClick);

    return window;
}

void Init::GLEW()
{
#ifndef WIN32
    glewExperimental = GL_TRUE;  // Intel cpu graphics support for macOS/linux
#endif

    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        exit(-1); // LOG_ERROR(Init::logtag, "Failed to init GLEW");
    }
}

void Init::OpenGL(const glm::vec4 background)
{
    GLCall(glEnable(GL_PROGRAM_POINT_SIZE));
    GLCall(glClearColor(background.x, background.y, background.z, background.w));

    GLCall(glEnable(GL_CULL_FACE));
    GLCall(glFrontFace(GL_CCW)); // the direction in which faces are defined (determins back/front): GL_CCW | GL_CW
    GLCall(glCullFace(GL_BACK));// the face side to cull away: GL_FRONT | GL_BACK | GL_FRONT_AND_BACK

    GLCall(glEnable(GL_BLEND));
    GLCall(glEnable(GL_DEPTH_TEST)); //enabled to avoid ugly artifacts that depend on the angle of view and drawing order
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    GLPrintMaxConstants(); 
}


} // ::overkill
