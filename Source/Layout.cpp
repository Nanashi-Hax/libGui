#include "Gui/Layout.hpp"
#include <Math.hpp>
#include <algorithm>

namespace Library::Gui
{
    Layout::Layout() : _parent(nullptr) {}

    Layout::Layout(Layout* parent) : _parent(parent)
    {
        if(parent)
        {
            Math::Rectangle rect = _parent->rectangle();
            _sizeHint = SizeHint(0.0f, 0.0f, rect.width, rect.height);
        }
    }

    void Layout::setParent(Layout* parent)
    {
        this->_parent = parent;
    }

    Math::Rectangle Layout::rectangle()
    {
        Math::Rectangle parent;

        if (_parent)
        {
            parent = _parent->rectangle();
        }
        else
        {
            parent =
            {
                0,
                0,
                _sizeHint.preferredWidth,
                _sizeHint.preferredHeight
            };
        }

        float ax = parent.x + _margin.left;
        float ay = parent.y + _margin.top;

        float aw = parent.width  - (_margin.left + _margin.right);
        float ah = parent.height - (_margin.top  + _margin.bottom);

        float w = std::clamp
        (
            _sizeHint.preferredWidth,
            _sizeHint.minWidth,
            aw
        );

        float h = std::clamp
        (
            _sizeHint.preferredHeight,
            _sizeHint.minHeight,
            ah
        );

        float x = ax;
        float y = ay;

        switch (_hAlign)
        {
            case HorizontalAlignment::Left: break;
            case HorizontalAlignment::Center:
            {
                x += (aw - w) * 0.5f;
                break;
            }
            case HorizontalAlignment::Right:
            {
                x += (aw - w);
                break;
            }
        }

        switch (_vAlign)
        {
            case VerticalAlignment::Up: break;
            case VerticalAlignment::Middle:
            {
                y += (ah - h) * 0.5f;
                break;
            }
            case VerticalAlignment::Down:
            {
                y += (ah - h);
                break;
            }
        }

        return { x, y, w, h };
    }

    void Layout::setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical)
    {
        _hAlign = horizontal;
        _vAlign = vertical;
    }

    void Layout::setMinSize(float width, float height)
    {
        _sizeHint.minWidth = width;
        _sizeHint.minHeight = height;
    }

    void Layout::setPreferredSize(float width, float height)
    {
        _sizeHint.preferredWidth = width;
        _sizeHint.preferredHeight = height;
    }

    void Layout::setMargin(float left, float top, float right, float bottom)
    {
        _margin.left = left;
        _margin.top = top;
        _margin.right = right;
        _margin.bottom = bottom;
    }
}