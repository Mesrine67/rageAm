# Dear ImGui source pin

The source files in this directory are copied from the Dear ImGui `docking`
branch at commit `2b662b1ab98fc74c89249630cd5ed0db34b7584d` (2024-02-20).
That commit reports version `1.90.4 WIP` and includes the docking and
multi-viewport APIs used by rageAm.

Upstream: https://github.com/ocornut/imgui

The project-specific compatibility adapter is kept in
`projects/app/src/am/ui/imgui_gradient.h`, with the widget changes in
rageAm's UI code. One whitespace-only cleanup removes a trailing space from
the bundled `imstb_rectpack.h` comment; no Dear ImGui behavior was changed.
