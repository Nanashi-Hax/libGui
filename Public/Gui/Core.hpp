#pragma once

#include "Gui/System.hpp"

namespace Library::Gui
{
    class Core
    {
    public:
        Core();
        virtual ~Core() = default;
        virtual void update() = 0;
        virtual void render() = 0;

    private:
        RenderSystem _render;
        FocusSystem _focus;
        ClickSystem _click;
    };
}