#include "NPCH.h"
#include "RenderCommand.h"

#include "neko/platform/opengl/OpenGLRendererAPI.h"

namespace NEKO
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
