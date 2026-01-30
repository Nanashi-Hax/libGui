#include "Gui/Core.hpp"
#include "Gui/Widget.hpp"

namespace Library::Gui
{
    void Core::setRoot(Widget* widget)
    {
        _render.setRoot(widget);
        _focus.focus(widget);
    }

    void Core::update()
    {
        _render.update();
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