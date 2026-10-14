//
// File: skeleton.h
//
// Copyright (C) 2023 ranstar74. All rights violated.
//
// Part of "Rage Am" Research Project.
//
#pragma once

#include "am/integration/integration.h"
#include "am/integration/script/extensions.h"
#include "am/ui/app.h"
#include "am/ui/extensions.h"
#include "am/ui/imglue.h"

#if defined(AM_STANDALONE) && !defined(AM_TESTBED)
#include "am/uiapps/explorer/explorer.h"
#endif

namespace rageam::ui
{
	/**
	 * \brief Handles visibility & activation shortcuts (in integration mode), dock space and those kind of things.
	 */
	class Skeleton : public App
	{
		void OnStart() override
		{
#if defined(AM_STANDALONE) && !defined(AM_TESTBED)
			// The standalone app otherwise starts with an empty dockspace.
			GetUI()->Windows->Add(new Explorer());
#endif
		}

		void OnUpdate() override
		{
			ImGlue* ui = GetUI();

			if (ImGui::IsKeyPressed(ImGuiKey_F9))
				ui->IsVisible = !ui->IsVisible;

			// We display UI disabled if game viewport is focused (active) in integration mode
#ifdef AM_INTEGRATED
			if (ImGui::IsKeyPressed(ImGuiKey_F10))
			{
				ui->IsDisabled = !ui->IsDisabled;
			}

			// We don't want game controls to mess up with the UI
			if (!ui->IsDisabled)
				scrDisableAllControlsThisFrame();

			bool drawCursor = !ui->IsDisabled;
			graphics::Window::GetInstance()->SetMouseVisible(drawCursor);
#endif

			// Dock space in integration mode will cover all game viewport, we don't want that
			// Title bar covers part of viewport, we have to disable it for now (until we implement custom game viewports)
#ifdef AM_STANDALONE
			ImGui::BeginDockSpace();

			if (ImGui::BeginMenuBar())
			{
#ifndef AM_TESTBED
				if (ImGui::BeginMenu("View"))
				{
					if (ImGui::MenuItem("Explorer"))
					{
						WindowPtr explorer = ui->Windows->GetExistingOrCreateNew<Explorer>();
						ui->Windows->Focus(explorer);
					}

					ImGui::EndMenu();
				}
#endif
				ImGui::EndMenuBar();
			}

			ImGui::End(); // DockSpace
#endif
		}
	};
}
