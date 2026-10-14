#pragma once

#include "imgui.h"

// Small compatibility type for rageAm's two-color gradient editor.
struct ImGradient
{
	ImVec4 Start;
	ImVec4 End;

	ImGradient(const ImVec4& start, const ImVec4& end)
		: Start(start), End(end)
	{
	}
};
