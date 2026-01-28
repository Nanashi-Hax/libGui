
#include "Gui/System.hpp"
#include "Gui/Interface.hpp"
#include "Gui/Widget.hpp"

namespace Library::Gui
{   
    void RenderSystem::render(Widget* w)
    {
        if(IRenderable* r = dynamic_cast<IRenderable*>(w))
        {
            r->onRender();
        }
    }

    void FocusSystem::focus(Widget* w)
    {
        if(IFocusable* f = dynamic_cast<IFocusable*>(w))
        {
            f->onFocus();
            _focus = w;
        }
    }

    void FocusSystem::focusNext()
    {
        if(_focus == nullptr) return;
        while (true)
        {
            Widget* w = _focus->next();
            IFocusable* f = dynamic_cast<IFocusable*>(w);
            if(f)
            {
                f->onFocus();
                _focus = w;
                break;
            }
        }
    }

    void FocusSystem::focusPrevious()
    {
        if(_focus == nullptr) return;
        while (true)
        {
            Widget* w = _focus->previous();
            IFocusable* f = dynamic_cast<IFocusable*>(w);
            if(f)
            {
                f->onFocus();
                _focus = w;
                break;
            }
        }
    }
    
    bool FocusSystem::canFocus(Widget* w) const
    {
        return dynamic_cast<IFocusable*>(w);
    }

    Widget* FocusSystem::current() const noexcept
    {
        return _focus;
    }

    void FocusSystem::clear() noexcept
    {
        _focus = nullptr;
    }

    void ClickSystem::click(Widget* w)
    {
        if(IClickable* c = dynamic_cast<IClickable*>(w))
        {
            c->onClick();
        }
    }
}