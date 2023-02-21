
struct UniformBufferObject {
    alignas(16) glm::mat4 model;
    alignas(16) glm::mat4 view;
    alignas(16) glm::mat4 proj;
};

class UBO{
public:
    UniformBufferObject simulationDetails;
    std::string MODEL_PATH;
    std::string TEXTURE_PATH;
};
