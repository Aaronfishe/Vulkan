#include "glm/glm.hpp"
//adds velocity and acceleration for the player character
struct movement{
    glm::vec3 acceleration = glm::vec3(0);
    glm::vec3 velocity = glm::vec3(0);
    bool jump = false;
};
//carries out the change in velocity due to current acceleration
glm::vec3 update_velocity(glm::vec3 velocity, glm::vec3 acceleration) {
    velocity = velocity + acceleration;
    return velocity;
}
