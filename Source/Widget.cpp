#include <memory>

#include <Math.hpp>
#include "Gui/Widget.hpp"

namespace Library::Gui
{
    Widget::Widget() : node(this), layout(this->parent()->layout) {}
    Widget::~Widget() = default;

    Widget* Widget::parent() const noexcept
    {
        return node.parent()->owner();
    }

    void Widget::addChild(std::unique_ptr<Widget> child)
    {
        children.push_back(std::move(child));
        node.addChild(&child->node);
    }
    
    void Widget::removeChild(size_t index)
    {
        node.removeChild(index);
    }

    Widget* Widget::previous() const noexcept
    {
        return node.previous()->owner();
    }

    Widget* Widget::next() const noexcept
    {
        return node.next()->owner();
    }
}