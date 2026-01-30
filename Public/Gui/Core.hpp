#pragma once

#include "Gui/System.hpp"

namespace Library::Gui
{
    class Core
    {
    public:
        void setRoot(Widget* widget);

        void update();
        void render();

        void focusNext();
        void focusPrevious();

    private:
        RenderSystem _render;
        FocusSystem _focus;
        ClickSystem _click;
    };
}