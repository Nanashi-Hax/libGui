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
            _sizeHint = SizeHint(16.0f, 16.0f, rect.width, rect.height);
        }
    }

    Math::Rectangle Layout::rectangle()
    {
        Math::Rectangle r;

        if(_parent)
        {
            r = _parent->rectangle();
        }
        else
        {
            r = Math::Rectangle{0,0,_sizeHint.preferredWidth,_sizeHint.preferredHeight};
        }

        r.x += _margin.left;
        r.y += _margin.top;
        r.width -= (_margin.left + _margin.right);
        r.height -= (_margin.top + _margin.bottom);

        float w = std::max(_sizeHint.minWidth, std::min(r.width, _sizeHint.preferredWidth));
        float h = std::max(_sizeHint.minHeight, std::min(r.height, _sizeHint.preferredHeight));
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