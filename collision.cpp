//collision struct
struct PhysicalObject {
    glm::vec4 position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    glm::vec3 size = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 position_offset = glm::vec3(0.0f);
};
//collision checking function
std::vector <bool> checkCollision(PhysicalObject obj1, PhysicalObject obj2) {
//pos or neg is in reference to obj1's axes

    bool obj1_collisionXpos = obj1.position_offset.x + obj1.size.x >= obj2.position_offset.x - obj2.size.x;

    bool obj1_collisionYpos = obj1.position_offset.y + obj1.size.y >= obj2.position_offset.y - obj2.size.y;

    bool obj1_collisionZpos = obj1.position_offset.z + obj1.size.z >= obj2.position_offset.z - obj2.size.z;

    bool obj1_collisionXneg = obj1.position_offset.x - obj1.size.x <= obj2.position_offset.x + obj2.size.x;

    bool obj1_collisionYneg = obj1.position_offset.y - obj1.size.y <= obj2.position_offset.y + obj2.size.y;

    bool obj1_collisionZneg = obj1.position_offset.z - obj1.size.z <= obj2.position_offset.z + obj2.size.z;

    std::vector <bool> boolCollision;
    boolCollision.resize(6);
    boolCollision[0] = obj1_collisionXpos;
    boolCollision[1] = obj1_collisionYpos;;
    boolCollision[2] = obj1_collisionZpos;
    boolCollision[3] = obj1_collisionXneg;
    boolCollision[4] = obj1_collisionYneg;
    boolCollision[5] = obj1_collisionZneg;


    return boolCollision;
}

