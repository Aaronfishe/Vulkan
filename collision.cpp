
struct PhysicalObject {
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 size = glm::vec3(0.0f, 0.0f, 0.0f);
};

bool CheckCollision(PhysicalObject obj1, PhysicalObject obj2) {
    bool collisionX = obj1.position.x + obj1.size.x >= obj2.position.x && obj2.position.x + obj2.size.x >= obj1.position.x;

    bool collisionY = obj1.position.y + obj1.size.y >= obj2.position.y && obj2.position.y + obj2.size.y >= obj1.position.y;

    bool collisionZ = obj1.position.z + obj1.size.z >= obj2.position.z && obj2.position.z + obj2.size.z >= obj1.position.z;

    return collisionX && collisionY && collisionZ;
}

