struct PSInput
{
    float4 position : SV_POSITION;
    float3 color : COLOR;
    float2 texCoord : TEXCOORD;
    float3 normal : NORMAL;
};

// 상수 버퍼 (라이트)
cbuffer Light : register(b0)
{
    float3 lightPosition;
    float pad3;
    float3 lightColor;
    float pad2;
    // 이름이 같진 않아도 레이아웃이 같아야 한다.
}

// 텍스처.
Texture2D diffuseMap : register(t0);
SamplerState mapSampler : register(s0);

float4 main(PSInput input) : SV_TARGET
{
	// 샘플링 (표본 추출, 색상 추출).
    float4 mapColor = diffuseMap.Sample(mapSampler, input.texCoord);
    
    // 조명 방향
    float3 lightDirection = normalize(-lightPosition);
   
    // 월드 노멀
    float3 worldNormal = normalize(input.normal);
    
    //디퓨즈 - 램버트(Lambert)
    //조명 밝기 계산 - 노멀과 조명 방향 벡터와의 내적으로 cos(theta) 계산
    //float diffusePower = saturate(dot(worldNormal, -lightDirection));
    
    float diffusePower = dot(worldNormal, -lightDirection);
    //하프 램버트
    diffusePower = pow(diffusePower * 0.5f + 0.5f, 2);
    
    // 조명 밝기에 조명 색상 적용
    float4 diffuse = float4(lightColor * diffusePower, 1);
    
    // 최종 색상 계산
    float4 finalColor = diffuse * mapColor;
    return finalColor;
    
}