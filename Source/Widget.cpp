#include <Math.hpp>
#include "Gui/Widget.hpp"

namespace Library::Gui
{
    Widget::Widget() {}
    
    Widget::~Widget() = default;

    Widget* Widget::parent() const noexcept
    {
        return _node.parent;
    }

    const std::vector<std::unique_ptr<Widget>>& Widget::children() const noexcept
    {
        return _node.children;
    }

    std::optional<size_t> Widget::index() const noexcept
    {
        return _node.index;
    }

    void Widget::removeChild(size_t index)
    {
        if(_node.children.size() <= index) return;
        
        Widget* child = _node.children[index].get();
        child->_node.parent = nullptr;

        _node.children.erase(_node.children.begin() + index);

        for (size_t i = index; i < _node.children.size(); ++i)
        {
            _node.children[i]->_node.index = i;
        }
    }

    Widget* Widget::child(size_t index) noexcept
    {
        if(_node.children.size() <= index) return nullptr;
        return _node.children[index].get();
    }
    
    Widget* Widget::previous() noexcept
    {
        if (!_node.parent) return nullptr;

        std::optional<size_t> i = _node.index;
        if(!i || i.value() == 0) return nullptr;
        return _node.parent->child(i.value() - 1);
    }

    Widget* Widget::next() noexcept
    {
        if (!_node.parent) return nullptr;

        std::optional<size_t> i = index();
        if(!i) return nullptr;
        return _node.parent->child(i.value() + 1);
    }

    void Widget::updateLayout(const Math::Rectangle& parent)
    {
        auto rect = _layout.compute(parent);
    
        for (auto& c : children())
        {
            c->updateLayout(rect);
        }
    }

    void Widget::updateColor(Math::Color4f parent)
    {
        Math::Color4f renderColor = _color.compute(parent);

        for (auto& c : children())
        {
            c->updateColor(renderColor);
        }
    }

    void Widget::setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical) { _layout.setAlignment(horizontal, vertical); }
    void Widget::setMinSize(float width, float height) { _layout.setMinSize(width, height); }
    void Widget::setPreferredSize(float width, float height) { _layout.setPreferredSize(width, height); }
    void Widget::setMargin(float left, float top, float right, float bottom) { _layout.setMargin(left, top, right, bottom); }
    void Widget::setOffset(float x, float y) { _layout.setOffset(x, y); }

    IRenderable* Widget::renderable() { return nullptr; }
    IFocusable* Widget::focusable() { return nullptr; }
    IAnimatable* Widget::animatable() { return nullptr; }

    Math::Rectangle Widget::rectangle() const { return _layout.rectangle(); }
    
    Math::Color4f Widget::color() const { return _color.render(); }
    void Widget::setColor(Math::Color4f color) { _color.setLocal(color); }

    Math::Rectangle Widget::computeLayout(Math::Rectangle parent) { return _layout.compute(parent); }
}
