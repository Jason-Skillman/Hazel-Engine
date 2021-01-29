#pragma once

enum class ShaderDataType {
	None = 0,
	Float,
	Float2,
	Float3,
	Float4,
	Mat3,
	Mat4,
	Int,
	Int2,
	Int3,
	Int4,
	Bool
};

static uint32_t ShaderDataTypeSize(ShaderDataType type) {
	switch (type) {
		case ShaderDataType::Float:
			return 4;
		case ShaderDataType::Float2:
			return 4 * 2;
		case ShaderDataType::Float3:
			return 4 * 3;
		case ShaderDataType::Float4:
			return 4 * 4;
		case ShaderDataType::Mat3:
			return 4 * 3 * 3;
		case ShaderDataType::Mat4:
			return 4 * 4 * 4;
		case ShaderDataType::Int:
			return 4;
		case ShaderDataType::Int2:
			return 4 * 2;
		case ShaderDataType::Int3:
			return 4 * 3;
		case ShaderDataType::Int4:
			return 4 * 4;
		case ShaderDataType::Bool:
			return 1;
		default:
			HZ_CORE_ASSERT(false, "Unknown ShaderDataType: {0}", type);
			return 0;
	}
}

static uint32_t ShaderDataTypeCount(ShaderDataType type) {
	switch(type) {
	case ShaderDataType::Float:
		return 1;
	case ShaderDataType::Float2:
		return 2;
	case ShaderDataType::Float3:
		return 3;
	case ShaderDataType::Float4:
		return 4;
	case ShaderDataType::Mat3:
		return 3 * 3;
	case ShaderDataType::Mat4:
		return 4 * 4;
	case ShaderDataType::Int:
		return 1;
	case ShaderDataType::Int2:
		return 2;
	case ShaderDataType::Int3:
		return 3;
	case ShaderDataType::Int4:
		return 4;
	case ShaderDataType::Bool:
		return 1;
	default:
		HZ_CORE_ASSERT(false, "Unknown ShaderDataType: {0}", type);
		return 0;
	}
}
