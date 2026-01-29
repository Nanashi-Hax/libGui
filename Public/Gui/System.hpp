#pragma once

#include "Gui/Interface.hpp"
#include "Gui/Widget.hpp"

namespace Library::Gui
{
    class RenderSystem
    {
    public:
        void render(Widget* root);
    };

    class FocusSystem
    {
    public:
        void focus(Widget* target);
        void focusNext();
        void focusPrevious();
        
        Widget* current() const noexcept;
        void clear() noexcept;

    private:
        Widget* _focus = nullptr;
    };

    class ClickSystem
    {
    public:
        void click(Widget* target);
    };
}