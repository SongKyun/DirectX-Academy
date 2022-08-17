// 램버트 쉐이더 - 디퓨즈.
float ComputeLambert(float3 worldNormal, float3 lightDirection)
{
	return saturate(dot(worldNormal, -lightDirection));
}

// 하프 램버트 쉐이더 - 디퓨즈(난반사).
float ComputeHalfLambert(float3 worldNormal, float3 lightDirection)
{
	float NdotL = dot(worldNormal, -lightDirection);
	NdotL = pow(NdotL * 0.5f + 0.5f, 2);

	return NdotL;
}

// 퐁 쉐이더 - 스페큘러(정반사).
float ComputePhong(float NdotL, float3 worldNormal, float3 lightDirection, float3 cameraDirection, float shiness)
{
	// 반사 벡터 구하기.
    float3 reflection = reflect(-lightDirection, worldNormal);

	// 스페큘러 구하기.
	float specularPower = 0.0f;
	
	// 빛의 강도가 있는 경우에만 정반사 계산.
	if (NdotL > 0.0f)
	{
		float RdotV = dot(reflection, cameraDirection);
        specularPower = pow(saturate(RdotV), shiness);
    }

	return specularPower;
}

// 블린-퐁 쉐이더 - 스페큘러(정반사).
float ComputeBlinnPhong(float NdotL, float3 worldNormal, float3 lightDirection, float3 cameraDirection, float shiness)
{
	// 하프 벡터 구하기.
	float3 halfVector = normalize((-lightDirection) + (-cameraDirection));

	float specularPower = 0.0f;
	if (NdotL > 0.0f)
	{
		float HdotN = dot(halfVector, worldNormal);
        specularPower = pow(saturate(HdotN), shiness);
    }

	return specularPower;
}

// 림 라이트.
float4 ComputeRimPower(float3 rimColor, float3 worldNormal, float3 cameraDirection, float rimConstant)
{
    float3 rim = abs(dot(-cameraDirection, worldNormal));
    rim = pow(1 - rim, rimConstant) * rimColor;
	
    return float4(rim, 1);
}