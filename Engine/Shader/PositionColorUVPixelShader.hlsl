struct PSInput
{
	float4 position : SV_POSITION;
	float3 color : COLOR;
	float2 texCoord : TEXCOORD;
};

// 텍스처.
Texture2D map : register(t0);
Texture2D map2 : register(t1);
Texture2D map3 : register(t2);
SamplerState mapSampler : register(s0);

float4 main(PSInput input) : SV_TARGET
{
	// 샘플링 (표본 추출, 색상 추출).
	float4 mapColor1 = map.Sample(mapSampler, input.texCoord);
	float4 mapColor2 = map2.Sample(mapSampler, input.texCoord);
	float4 mapColor3 = map3.Sample(mapSampler, input.texCoord);
	
	//return float4(input.color, 1);
	// 1-x: one minus.
	return (mapColor1 * 0.2) + (1 - mapColor2);
}