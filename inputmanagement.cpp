// shutdown mid-process by means other than closing GLFW window
bool program_shutdown = false;

// rotation and translation variables
bool rotate_xpos = false;
bool rotate_xneg = false;

bool rotate_ypos = false;
bool rotate_yneg = false;

bool rotate_zpos = false;
bool rotate_zneg = false;

bool move_forward = false;
bool move_backward = false;

bool move_left = false;
bool move_right = false;

bool move_up = false;
bool move_down = false;

bool freecam = false;

float rotation_factor = 50;
float movement_factor = 20;

glm::mat4 store_rotation;
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
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
        rotate_xpos = true;
    }

    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE) {
        rotate_xpos = false;
    }

    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
        rotate_xneg = true;
    }

    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE) {
        rotate_xneg = false;
    }
    // rotate y
    if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
        rotate_ypos = true;
    }

    if (key == GLFW_KEY_UP && action == GLFW_RELEASE) {
        rotate_ypos = false;
    }

    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        rotate_yneg = true;
    }

    if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE) {
        rotate_yneg = false;
    }
    // rotate z
    if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
        rotate_zpos = true;
    }

    if (key == GLFW_KEY_Q && action == GLFW_RELEASE) {
        rotate_zpos = false;
    }

    if (key == GLFW_KEY_E && action == GLFW_PRESS) {
        rotate_zneg = true;
    }

    if (key == GLFW_KEY_E && action == GLFW_RELEASE) {
        rotate_zneg = false;
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
}

void cursor_position_callback(GLFWwindow* window, double xposIn, double yposIn) {
    cursorX = xposIn;
    cursorY = yposIn;
}

