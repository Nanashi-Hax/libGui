#pragma once

#include "Gui/System.hpp"
#include "Gui/Widget.hpp"

namespace Library::Gui
{
    class Core
    {
    public:
        Core(Widget* root);
        virtual void update() = 0;
        virtual void render() = 0;

    private:
        RenderSystem _render;
        FocusSystem _focus;
        ClickSystem _click;
    };
}