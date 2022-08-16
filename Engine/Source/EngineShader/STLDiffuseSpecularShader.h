#pragma once

#include <Core/Core.h>
#include "STLShader.h"

namespace STL
{
    class ENGINE_API STLDiffuseSpecularShader : public STLShader
    {
    public:
        STLDiffuseSpecularShader();
        ~STLDiffuseSpecularShader() = default;
    };
}