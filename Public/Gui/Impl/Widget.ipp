#pragma once

namespace Library::Gui
{
    template<class T>
    T* Widget::addChild(std::unique_ptr<T> child)
    {
        static_assert(std::is_base_of_v<Widget, T>);
        T* raw = child.get();
        node.addChild(&child->node);
        children.push_back(std::move(child));
        return raw;
    }
}