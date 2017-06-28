#pragma once

namespace StdTexShader {
    const char *vertexSource =
        "#version 330 core\n"
        "layout (location = 0) in vec4 vertexPos;\n"
        "layout (location = 1) in vec4 vertexColor;\n"
        "out vec2 fragmentTexCoord;\n"
        "out vec4 fragmentColor;\n"
        "uniform mat4 projection;\n"
        "void main(void)\n"
        "{\n"
        "gl_Position = projection * vec4(vertexPos.x, vertexPos.y, 0.0f, 1.0f);\n"
        "fragmentTexCoord = vec2(vertexPos.w, vertexPos.z);\n"
        "fragmentColor = vertexColor;\n"
        "}\n";

    const char *fragmentSource =
        "#version 330 core\n"
        "layout (location = 0) out vec4 color;\n"
        "in vec2 fragmentTexCoord;\n"
        "in vec4 fragmentColor;\n"
        "uniform sampler2D tex;\n"
        "uniform float global_alpha;\n"
        "void main(void)\n"
        "{\n"
        "color = vec4(fragmentColor.x, fragmentColor.y, fragmentColor.z, global_alpha * fragmentColor.w) * texture(tex, fragmentTexCoord);\n"
        "}";
}
