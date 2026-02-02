#include "Gui/Core.hpp"
#include "Gui/Widget.hpp"

namespace Library::Gui
{
    void Core::setRoot(Widget* widget)
    {
        _render.setRoot(widget);
        _focus.focus(widget);
    }

    void Core::update(float width, float height)
    {
        _render.update(width, height);
    }

    void Core::render()
    {
        _render.render();
    }
    
    void Core::focusNext()
    {
        _focus.focusNext();
    }

    void Core::focusPrevious()
    {
        _focus.focusPrevious();
    }
}