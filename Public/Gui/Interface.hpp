#pragma once

namespace Library::Gui
{
    class IRenderable
    {
    public:
        virtual void onRender() = 0;
    };

    class IFocusable
    {
    public:
        virtual void onFocus() = 0;
    };

    class IClickable
    {
    public:
        virtual void onClick() = 0;
    };
}