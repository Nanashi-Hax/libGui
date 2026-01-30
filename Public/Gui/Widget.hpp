#pragma once

#include <optional>
#include <memory>

#include <Math.hpp>
#include "Gui/Layout.hpp"
#include "Gui/Node.hpp"

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

    class Widget
    {
    public:
        Widget();
        virtual ~Widget();

        Widget* parent() const noexcept;
        const std::vector<std::unique_ptr<Widget>>& children() const noexcept;
        std::optional<size_t> index() const noexcept;

        template <typename T>
        T* addChild(std::unique_ptr<T> child);
        void removeChild(size_t index);

        Widget* child(size_t index) noexcept;
        Widget* previous() noexcept;
        Widget* next() noexcept;

        virtual void updateLayout(const Math::Rectangle& parent);

        void setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical);
        void setMinSize(float width, float height);
        void setPreferredSize(float width, float height);
        void setMargin(float left, float top, float right, float bottom);

        virtual IRenderable* renderable();
        virtual IFocusable* focusable();
        virtual IClickable* clickable();

        Math::Rectangle rectangle();
        
    protected:
        Layout& layout();
        const Layout& layout() const;

    private:
        Node<Widget> _node;
        Layout _layout;
    };
}

#include "Gui/Impl/Widget.ipp"