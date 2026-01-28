#pragma once

#include <vector>
#include <optional>

namespace Library::Gui
{
    template <typename T>
    class Node
    {    
    public:
        explicit Node(T* owner) : _owner(owner), _parent(nullptr) {}

        T* owner() const noexcept { return _owner; }

        Node* parent() const noexcept { return _parent; }

        std::optional<size_t> index() const noexcept
        {
            if(!_parent) return std::nullopt;

            auto& siblings = _parent->_children;
            for(size_t i = 0; i < siblings.size(); i++)
            {
                if(siblings[i] == this) return i;
            }

            return std::nullopt;
        }

        void addChild(Node* child)
        {
            child->_parent = this;
            _children.push_back(child);
        }

        void removeChild(size_t index)
        {
            if(_children.size() <= index) return;
            _children.erase(_children.begin() + index);
        }

        Node* child(size_t index) const noexcept
        {
            if(_children.size() <= index) return nullptr;
            return _children[index];
        }

        Node* previous() const noexcept
        {
            std::optional<size_t> i = index();
            if(!i || i.value() == 0) return nullptr;
            return _parent->child(i.value() - 1);
        }

        Node* next() const  noexcept
        {
            std::optional<size_t> i = index();
            if(!i) return nullptr;
            return _parent->child(i.value() + 1);
        }
    
    private:
        T* _owner;
        Node* _parent;
        std::vector<Node*> _children;
    };
}
