struct VertexShaderOutput
{
	float4 position: SV_POSITION;
};

struct VertexShaderInput
{
	float4 position : POSITIONTO;
};

VertexShaderOutput main(VertexShaderInput input)
{
	VertexShaderOutout output;
	output.position = input.position;
	return output;
}