#pragma once

#include <type_traits>

namespace Library::Gui
{
    template <typename T>
    T* Widget::addChild(std::unique_ptr<T> child)
    {
        static_assert(std::is_base_of_v<Widget, T>);

        if (!child || child->_node.parent) return nullptr;

        T* raw = child.get();

        child->_layout = Layout(&_layout);

        child->_node.parent = this;
        child->_node.index = _node.children.size();
        _node.children.push_back(std::move(child));

        return raw;
    }
}