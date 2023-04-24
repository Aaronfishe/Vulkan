// shutdown mid-process by means other than closing GLFW window
bool program_shutdown = false;

// rotation and translation variables
bool trans_xneg = false;
bool trans_xpos = false;

bool trans_ypos = false;
bool trans_yneg = false;

bool trans_zpos = false;
bool trans_zneg = false;

bool move_forward = false;
bool move_backward = false;

bool move_left = false;
bool move_right = false;

bool move_up = false;
bool move_down = false;

bool freecam = false;

bool toggle = false;

bool reset = false;

float rotation_factor = 50;
float movement_factor = 20;

glm::mat4 store_rotation;
glm::vec3 cameraPos = glm::vec3(0.0f, -30.0f, 10.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
bool ubo_first_time = true;

// Camera rotation
float cursorX = 0.0f;
float cursorY = 0.0f;
float lastX;
float lastY;
float mouseSensitivity = 0.1f;
bool first_mouse = true;

float yaw = -90.0f;
float pitch = 0.0f;

// Delta time calculations
float deltaTime = 0.0f;
float lastFrameTime = 0.0f;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // rotate x
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
        trans_xneg = true;
    }

    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE) {
        trans_xneg = false;
    }

    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
        trans_xpos = true;
    }

    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE) {
        trans_xpos = false;
    }
    // rotate y
    if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
        trans_zneg = true;
    }

    if (key == GLFW_KEY_UP && action == GLFW_RELEASE) {
        trans_zneg = false;
    }

    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        trans_zpos = true;
    }

    if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE) {
        trans_zpos = false;
    }
    // rotate z
    if (key == GLFW_KEY_I && action == GLFW_PRESS) {
        trans_ypos = true;
    }

    if (key == GLFW_KEY_I && action == GLFW_RELEASE) {
        trans_ypos = false;
    }

    if (key == GLFW_KEY_K && action == GLFW_PRESS) {
        trans_yneg = true;
    }

    if (key == GLFW_KEY_K && action == GLFW_RELEASE) {
        trans_yneg = false;
    }
    // Z translation
    if (key == GLFW_KEY_D && action == GLFW_PRESS) {
        move_right = true;
    }

    if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
        move_right = false;
    }

    if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        move_left = true;
    }

    if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
        move_left = false;
    }
    // X tranlsaton
    if (key == GLFW_KEY_W && action == GLFW_PRESS) {
        move_forward = true;
    }

    if (key == GLFW_KEY_W && action == GLFW_RELEASE) {
        move_forward = false;
    }

    if (key == GLFW_KEY_S && action == GLFW_PRESS) {
        move_backward = true;
    }

    if (key == GLFW_KEY_S && action == GLFW_RELEASE) {
        move_backward = false;
    }
// Y translation
    if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS) {
        move_up = true;
    }

    if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_RELEASE) {
        move_up = false;
    }

    if (key == GLFW_KEY_LEFT_CONTROL && action == GLFW_PRESS) {
        move_down = true;
    }

    if (key == GLFW_KEY_LEFT_CONTROL && action == GLFW_RELEASE) {
        move_down = false;
    }
// Button for exit if mouse is inaccessible
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        program_shutdown = true;
    }

    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
        if (freecam) {
            freecam = false;
        }
        else {
            freecam = true;
        }
    }

    if (key == GLFW_KEY_T && action == GLFW_PRESS) {
        if (toggle) {
            toggle = false;
        }
        else {
            toggle = true;
        }
    }

    if (key== GLFW_KEY_R && action == GLFW_PRESS) {
        reset = true;
    }
}

void cursor_position_callback(GLFWwindow* window, double xposIn, double yposIn) {
    cursorX = xposIn;
    cursorY = yposIn;
}

