#include "glm/glm.hpp"

struct movement{
    glm::vec3 acceleration = glm::vec3(0);
    glm::vec3 velocity = glm::vec3(0);
    bool jump = false;
};

glm::vec3 update_velcoity(glm::vec3 velocity, glm::vec3 acceleration) {
    velocity = velocity + acceleration;
    return velocity;
}
