#pragma once

#include "Gui/Interface.hpp"
#include "Gui/Widget.hpp"

namespace Library::Gui
{
    class RenderSystem
    {
    public:
        RenderSystem(Widget* target);
        Widget* target();

        void render();

    private:
        Widget* _target = nullptr;
    };

    class FocusSystem
    {
    public:
        void focus(Widget* w);
        void focusNext();
        void focusPrevious();
        
        bool canFocus(Widget* w) const;
        Widget* current() const noexcept;
        void clear() noexcept;

    private:
        Widget* _focus = nullptr;
    };

    class ClickSystem
    {
    public:
        void click(Widget* w);
    };
}