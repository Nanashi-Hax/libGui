#pragma once

#include "Gui/Widget.hpp"

namespace Library::Gui
{
    class RenderSystem
    {
    public:
        void update(float width, float height);
        void render();

        void setRoot(Widget* root);

    private:
        void renderRecursive(Widget* root);
        
        Widget* _root = nullptr;
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