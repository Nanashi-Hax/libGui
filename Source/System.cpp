#include "Gui/System.hpp"
#include "Gui/Widget.hpp"
#include "Math.hpp"

namespace Library::Gui
{   
    void RenderSystem::update(float width, float height)
    {
        if (!_root) return;
        _root->updateLayout(Math::Rectangle(0.0f, 0.0f, width, height));
    }

    void RenderSystem::render()
    {
        if (!_root) return;
        renderRecursive(_root);
    }

    void RenderSystem::setRoot(Widget* widget)
    {
        _root = widget;
    }

    void RenderSystem::renderRecursive(Widget* w)
    {
        if (auto r = w->renderable()) r->onRender();
        for (auto& c : w->children()) renderRecursive(c.get());
    }

    void FocusSystem::focus(Widget* target)
    {
        if(IFocusable* f = target->focusable())
        {
            f->onFocus();
            _focus = target;
        }
    }

    void FocusSystem::focusNext()
    {
        if(_focus == nullptr) return;
        Widget* w;
        while (true)
        {
            w = _focus->next();
            IFocusable* f = w->focusable();
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
        Widget* w;
        while (true)
        {
            w = _focus->previous();
            IFocusable* f = w->focusable();
            if(f)
            {
                f->onFocus();
                _focus = w;
                break;
            }
        }
    }

    Widget* FocusSystem::current() const noexcept
    {
        return _focus;
    }

    void FocusSystem::clear() noexcept
    {
        _focus = nullptr;
    }

    void AnimateSystem::animate(float deltaTime)
    {
        if (!_root) return;
        animateRecursive(_root, deltaTime);
    }

    void AnimateSystem::setRoot(Widget* widget)
    {
        _root = widget;
    }

    void AnimateSystem::animateRecursive(Widget* w, float deltaTime)
    {
        if (auto a = w->animatable()) a->onAnimate(deltaTime);
        for (auto& c : w->children()) animateRecursive(c.get(), deltaTime);
    }
}