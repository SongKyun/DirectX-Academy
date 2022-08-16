// ����Ʈ ���̴� - ��ǻ��.
float ComputeLambert(float3 worldNormal, float3 lightDirection)
{
	return saturate(dot(worldNormal, -lightDirection));
}

// ���� ����Ʈ ���̴� - ��ǻ��(���ݻ�)
float ComputeHalfLambert(float3 worldNormal, float3 lightDirection)
{
	float NdotL = dot(worldNormal, -lightDirection);
	NdotL = pow(NdotL * 0.5f + 0.5f, 2);

	return NdotL;
}

// �� ���̴� - ����ŧ��(���ݻ�)
float ComputePhong(float NdotL, float3 worldNormal, float3 lightDirection, float3 cameraDirection, float shiness)
{
	//�ݻ� ���� ���ϱ�
    float3 reflection = reflect(-lightDirection, worldNormal);

	// ����ŧ�� ���ϱ�
	float specularPower = 0.0f;
	
	// ���� ������ �ִ� ��쿡�� ���ݻ� ���
		if (NdotL > 0.0f)
	{
		float RdotV = dot(reflection, cameraDirection);
        specularPower = pow(saturate(RdotV), shiness);
    }

	return specularPower;
}
// �� �� ���̴� ����ŧ��(���ݻ�)
float ComputeBlinnPhong(float NdotL, float3 worldNormal, float3 lightDirection, float3 cameraDirection, float shiness)
{
	//���� ���� ���ϱ�.
	float3 halfVector = normalize((-lightDirection) + (-cameraDirection));

	float specularPower = 0.0f;
	if (NdotL > 0.0f)
	{
		float HdotN = dot(halfVector, worldNormal);
        specularPower = pow(saturate(HdotN), shiness);
    }

	return specularPower;
}