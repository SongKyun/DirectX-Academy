#include "Core.h"
#include "STLDiffuseSpecularShader.h"

namespace STL
{
	STLDiffuseSpecularShader::STLDiffuseSpecularShader()
		: STLShader()
	{
		vertexShader = VertexShader(TEXT("DiffuseSpecularVertexShader"));
		pixelShader = PixelShader(TEXT("DiffuseSpecularPixelShader"));
	}
}