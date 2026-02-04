#pragma once

#include <Math.hpp>

namespace Library::Gui
{
    enum class HorizontalAlignment
    {
        Left,
        Center,
        Right
    };

    enum class VerticalAlignment
    {
        Up,
        Middle,
        Down
    };

    struct SizeHint
    {
        SizeHint() : minWidth(0.0f), minHeight(0.0f), preferredWidth(0.0f), preferredHeight(0.0f) {}

        SizeHint(float minWidth, float minHeight, float preferredWidth, float preferredHeight)
        :
        minWidth(minWidth), minHeight(minHeight), preferredWidth(preferredWidth), preferredHeight(preferredHeight) {}

        float minWidth;
        float minHeight;
        float preferredWidth;
        float preferredHeight;
    };

    struct Margin
    {
        Margin() : left(0), top(0), right(0), bottom(0) {}
        Margin(float m) : left(m), top(m), right(m), bottom(m) {}
        Margin(float x, float y) : left(x), top(y), right(x), bottom(y) {}
        Margin(float left, float top, float right, float bottom) : left(left), top(top), right(right), bottom(bottom) {}
        float left;
        float top;
        float right;
        float bottom;
    };

    class Layout
    {
    public:
        Layout();
        Layout(float width, float height);

        Math::Rectangle compute(const Math::Rectangle& parent);
        const Math::Rectangle& rectangle() const;

        void setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical);
        void setMinSize(float width, float height);
        void setPreferredSize(float width, float height);
        void setMargin(float left, float top, float right, float bottom);
        void setOffset(float x, float y);

    private:
        HorizontalAlignment _hAlign = HorizontalAlignment::Left;
        VerticalAlignment _vAlign = VerticalAlignment::Up;
        SizeHint _sizeHint;
        Margin _margin;
        Math::Vector2f _offset;

        Math::Rectangle _rect;
    };
}