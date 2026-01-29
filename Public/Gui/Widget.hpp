#pragma once

#include <optional>
#include <memory>

#include <Math.hpp>
#include "Gui/Layout.hpp"
#include "Gui/Node.hpp"
#include "Gui/Interface.hpp"

namespace Library::Gui
{
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

        void setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical);
        void setMinSize(float width, float height);
        void setPreferredSize(float width, float height);
        void setMargin(float left, float top, float right, float bottom);

        virtual IRenderable* renderable();
        virtual IFocusable* focusable();
        virtual IClickable* clickable();

    protected:
        Math::Rectangle rectangle();

    private:
        Node<Widget> _node;
        Layout _layout;
    };
}

#include "Gui/Impl/Widget.ipp"