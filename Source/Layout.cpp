#include "Gui/Layout.hpp"
#include <Math.hpp>
#include <algorithm>

namespace Library::Gui
{
    Layout::Layout(Layout* parent) : _parent(parent) {}

    Math::Rectangle Layout::rectangle()
    {
        Math::Rectangle r;

        if(_parent)
        {
            r = _parent->rectangle();
        }
        else
        {
            r = Math::Rectangle{0,0,_sizeHint.preferredSize.x,_sizeHint.preferredSize.y};
        }

        r.x += _margin.left;
        r.y += _margin.top;
        r.width -= (_margin.left + _margin.right);
        r.height -= (_margin.top + _margin.bottom);

        float w = std::max(_sizeHint.minSize.x, std::min(r.width, _sizeHint.preferredSize.x));
        float h = std::max(_sizeHint.minSize.y, std::min(r.height, _sizeHint.preferredSize.y));
        r.width = w;
        r.height = h;

        switch(_hAlign)
        {
            case HorizontalAlignment::Left: break;
            case HorizontalAlignment::Center: r.x += (r.width - w)/2; break;
            case HorizontalAlignment::Right: r.x += (r.width - w); break;
        }

        switch(_vAlign)
        {
            case VerticalAlignment::Up: break;
            case VerticalAlignment::Middle: r.y += (r.height - h)/2; break;
            case VerticalAlignment::Down: r.y += (r.height - h); break;
        }

        return r;
    }

    void Layout::setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical)
    {
        _hAlign = horizontal;
        _vAlign = vertical;
    }

    void Layout::setMinSize(float width, float height)
    {
        _sizeHint.minSize = Math::Vector2(width, height);
    }

    void Layout::setPreferredSize(float width, float height)
    {
        _sizeHint.preferredSize = Math::Vector2(width, height);
    }

    void Layout::setMargin(float left, float top, float right, float bottom)
    {
        _margin.left = left;
        _margin.top = top;
        _margin.right = right;
        _margin.bottom = bottom;
    }
}