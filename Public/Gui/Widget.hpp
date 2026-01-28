#pragma once

#include <memory>

#include <Math.hpp>
#include "Gui/Layout.hpp"
#include "Gui/Node.hpp"

namespace Library::Gui
{
    class Widget
    {
    public:
        Widget();
        virtual ~Widget();

        Widget* parent() const noexcept;

        Widget* addChild(std::unique_ptr<Widget> child);
        void removeChild(size_t index);

        Widget* previous() const noexcept;
        Widget* next() const noexcept;

        void setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical);
        void setMinSize(float width, float height);
        void setPreferredSize(float width, float height);
        void setMargin(float left, float top, float right, float bottom);

    protected:
        Node<Widget> node;
        Layout layout;
        std::vector<std::unique_ptr<Widget>> children;
    };
}