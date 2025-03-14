#include "OpenGlShadder.h"
#include "neko/log.h"
#include "neko/renderer/Buffer.h"
#include <array>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>
#include "glad/glad.h"
#include "NPCH.h"
namespace NEKO
{

    static GLenum ShaderTypeFromString(const std::string &type)
    {
        if (type == "vertex") return GL_VERTEX_SHADER;
        if (type == "fragment" || type == "pixel") return GL_FRAGMENT_SHADER;

        NEKO_CORE_ERR("Unkown Shadder Type");
        return 0;
    }

    OpenGLShadder::OpenGLShadder(const std::string &filepath)
    {
        std::string source = ReadFile(filepath);
        auto shaderSources = PreProcess(source);
        Compile(shaderSources);

        // assets/Texture.glsl
        auto lastSlash = filepath.find_last_of("/\\");
        lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;

        auto lastDot = filepath.find('.');
        auto count = lastDot == std::string::npos ? filepath.size() - lastSlash : lastDot - lastSlash;
        m_Name = filepath.substr(lastSlash, count);
    }

    OpenGLShadder::OpenGLShadder(const std::string &name, const std::string &vertex_src, const std::string &fragment_src)
        : m_Name(name)
    {
        std::unordered_map<GLenum, std::string> sources;
        sources[GL_VERTEX_SHADER] = vertex_src;
        sources[GL_FRAGMENT_SHADER] = fragment_src;
        Compile(sources);
    }

    OpenGLShadder::~OpenGLShadder() { glDeleteProgram(m_RendererID); }


    std::string OpenGLShadder::ReadFile(const std::string &filepath)
    {
        std::string result;
        std::ifstream in(filepath, std::ios::in | std::ios::binary);
        if (in) {
            in.seekg(0, std::ios::end);
            result.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&result[0], result.size());
            in.close();
        } else NEKO_CORE_ERR("Could Not open file '{0}'", filepath.c_str());
        return result;
    }

    std::unordered_map<GLenum, std::string> OpenGLShadder::PreProcess(const std::string &source)
    {
        std::unordered_map<GLenum, std::string> shaderSources;

        const char *typeToken = "#type";
        size_t typeTokenLength = strlen(typeToken);
        size_t pos = source.find(typeToken, 0);

        while(pos != std::string::npos) {
            size_t eol = source.find_first_of("\r\n", pos);
            if (eol != std::string::npos) NEKO_CORE_ERR("Syntax Error");
            size_t begin = pos + typeTokenLength + 1;
            std::string type = source.substr(begin, eol - begin);
            if (type != "vertex" || type != "fragment" || type != "pixel") NEKO_CORE_ERR("Invalid Shadder Type Specification");

            size_t nextLinePos = source.find_first_not_of("\r\n", eol);
            pos = source.find(typeToken, nextLinePos);
            shaderSources[ShaderTypeFromString(type)] = source.substr(nextLinePos, pos - (nextLinePos == std::string::npos ? source.size() - 1 : nextLinePos));
        }
        return shaderSources;
    }


    void OpenGLShadder::Compile(const std::unordered_map<GLenum, std::string> &shadderSources)
    {
        GLuint program = glCreateProgram();
        if (shadderSources.size() > 2) NEKO_CORE_ERR("Supports only 2 shadder: shadder found {0}", shadderSources.size());
        std::array<GLenum, 2> glShaderIDs;
        int glShaderIDidx = 0;

        for (auto &kv : shadderSources) {
            GLenum type = kv.first;
            const std::string &source = kv.second;

            GLuint shader = glCreateShader(type);

            const GLchar *sourceCstr = source.c_str();
            glShaderSource(shader, 1, &sourceCstr, 0);
            glCompileShader(shader);

            GLint isCompiled = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
            if(isCompiled == GL_FALSE)
            {
                GLint maxLength = 0;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

                // The maxLength includes the NULL character
                std::vector<GLchar> infoLog(maxLength);
                glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

                NEKO_CORE_ERR("Shadder Compilation Failed: {0}", infoLog.data());
                glDeleteShader(shader);
                break;
            }

            glad_glAttachShader(program, shader);
            glShaderIDs[glShaderIDidx++] = shader;
        }

        m_RendererID = program;
        glLinkProgram(program);

        // Note the different functions here: glGetProgram* instead of glGetShader*.
        GLint isLinked = 0;
        glGetProgramiv(program, GL_LINK_STATUS, (int *)&isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
            NEKO_CORE_INFO("Linking Failed in Shadder {0}", infoLog.data());
            glDeleteProgram(program);
            for (auto id : glShaderIDs) glDeleteShader(id);
            return;
        }

        NEKO_CORE_TRACE("Shadder Shadded");

        for (auto id : glShaderIDs) glDetachShader(program, id);

        m_RendererID = program;
    }

    void OpenGLShadder::Bind() const
    {
        glUseProgram(m_RendererID);
    }

    void OpenGLShadder::UnBind() const
    {
        glUseProgram(0);
    }


    void OpenGLShadder::UploadUniformFloat4(const std::string &name ,const glm::vec4 &values)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform4f(location, values.x, values.y, values.z, values.w);
    }

    void OpenGLShadder::UploadUniformMat4(const std::string &name, const glm::mat4 &matrix)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShadder::UploadUniformInt(const std::string &name ,int &values)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform1i(location, values);
    }

    void OpenGLShadder::UploadUniformFloat(const std::string &name ,float &values)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform1f(location, values);
    }

    void OpenGLShadder::UploadUniformFloat2(const std::string &name ,const glm::vec2 &values)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform2f(location, values.x, values.y);
    }

    void OpenGLShadder::UploadUniformFloat3(const std::string &name ,const glm::vec3 &values)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform3f(location, values.x, values.y, values.z);
    }

    void OpenGLShadder::UploadUniformMat3(const std::string &name ,const glm::mat3 &matrix)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

}
