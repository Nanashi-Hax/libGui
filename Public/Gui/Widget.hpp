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

        virtual void render() = 0;

        Widget* parent() const noexcept;

        void addChild(std::unique_ptr<Widget> child);
        void removeChild(size_t index);

        Widget* previous() const noexcept;
        Widget* next() const noexcept;

    protected:
        Node<Widget> node;
        Layout layout;
        std::vector<std::unique_ptr<Widget>> children;
    };
}