#include <overkill/Util.hpp>

namespace overkill 
{

auto Util::fileToString(const std::string& filepath) -> std::string
{
    std::ifstream infile(filepath);

    if (!infile) {
        LOG_ERROR("file not found: %s", filepath.data());
    }
    std::stringstream ss;
    ss << infile.rdbuf();
    return ss.str();
}


void Util::everyTwoSeconds(float t)
{
    static float twoSecondTick = 0.0f;
    static float twoSecondTickShader = 1.0f;
    if (t - twoSecondTick > 2.0f) 
    {
        //Watcher::scanFiles();
        MaterialSystem::reload();
        twoSecondTick += 2;
    }

    if (t - twoSecondTickShader > 2.0f) {

        ShaderSystem::reload();
        twoSecondTickShader += 2;
    }
};

//TODO move it
auto Util::packNormal(float x, float y, float z) -> GLint
{
    float magnitude = sqrt(x * x + y * y + z * z);
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
    const auto DISCARDMASK = 1023;
    const auto MAX = 511;        //01 1111 1111
    return  ((GLint(z * MAX) & DISCARDMASK ) << 20) | ((GLint(y * MAX) & DISCARDMASK ) << 10) |  (GLint(x * MAX) & DISCARDMASK );
}

auto Util::packUV(float u, float v) -> GLshort
{
    const auto MAX = 127;
    const auto CLAMPER = 255;

    return (GLint(v * MAX) & CLAMPER) << 8 |
           (GLint(u * MAX) & CLAMPER);
}

void Util::printMatrix(const glm::mat4& m, const std::string & name)
{
    printf("%s\t 4x4\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n", 
        name.c_str(),
        m[0][0], m[0][1], m[0][2], m[0][3],
        m[1][0], m[1][1], m[1][2], m[1][3], 
        m[2][0], m[2][1], m[2][2], m[2][3], 
        m[3][0], m[3][1], m[3][2], m[3][3]);
}

}
