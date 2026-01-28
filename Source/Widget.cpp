#include <memory>

#include <Math.hpp>
#include "Gui/Widget.hpp"

namespace Library::Gui
{
    Widget::Widget() : node(this)
    {
        Widget* p = parent();
        if(p)
        {
            layout = (p->layout);
        }
    }
    
    Widget::~Widget() = default;

    Widget* Widget::parent() const noexcept
    {
        if(Node<Widget>* p = node.parent())
        {
            return p->owner();
        }
        return nullptr;
    }

    Widget* Widget::addChild(std::unique_ptr<Widget> child)
    {
        Widget* raw = child.get();
        node.addChild(&child->node);
        children.push_back(std::move(child));
        return raw;
    }
    
    void Widget::removeChild(size_t index)
    {
        node.removeChild(index);
    }

    Widget* Widget::previous() const noexcept
    {
        if(Node<Widget>* n = node.previous())
        {
            return n->owner();
        }
        return nullptr;
    }

    Widget* Widget::next() const noexcept
    {
        if(Node<Widget>* n = node.next())
        {
            return n->owner();
        }
        return nullptr;
    }

    void Widget::setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical)
    {
        layout.setAlignment(horizontal, vertical);
    }

    void Widget::setMinSize(float width, float height)
    {
        layout.setMinSize(width, height);
    }

    void Widget::setPreferredSize(float width, float height)
    {
        layout.setPreferredSize(width, height);
    }

    void Widget::setMargin(float left, float top, float right, float bottom)
    {
        layout.setMargin(left, top, right, bottom);
    }
}