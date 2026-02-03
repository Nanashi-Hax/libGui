#pragma once

#include <optional>
#include <memory>

#include <Math.hpp>
#include "Gui/Color.hpp"
#include "Gui/Layout.hpp"
#include "Gui/Node.hpp"

namespace Library::Gui
{
    class IRenderable
    {
    public:
        virtual ~IRenderable() = default;
        virtual void onRender() = 0;
    };

    class IFocusable
    {
    public:
        virtual ~IFocusable() = default;
        virtual void onFocus() = 0;
    };

    class IAnimatable
    {
    public:
        virtual ~IAnimatable() = default;
        virtual void onAnimate(float deltaTime) = 0;
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
        virtual void updateColor(Math::Color4f parent);

        void setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical);
        void setMinSize(float width, float height);
        void setPreferredSize(float width, float height);
        void setMargin(float left, float top, float right, float bottom);
        void setOffset(float x, float y);

        virtual IRenderable* renderable();
        virtual IFocusable* focusable();
        virtual IAnimatable* animatable();

        Math::Rectangle rectangle() const;
        Math::Color4f color() const;

        void setColor(Math::Color4f color);
        
    protected:
        Math::Rectangle computeLayout(Math::Rectangle parent);

    private:
        Node<Widget> _node;
        Layout _layout;
        Color _color;
    };
}

#include "Gui/Impl/Widget.ipp"
