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
        Math::Vector2 minSize;
        Math::Vector2 preferredSize;
    };

    struct Margin
    {
        float left = 0;
        float top = 0;
        float right = 0;
        float bottom = 0;
    };

    class Layout
    {
    public:
        explicit Layout(Layout* parent);

        Math::Rectangle rectangle();

        void setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical);
        void setMinSize(float width, float height);
        void setPreferredSize(float width, float height);
        void setMargin(float left, float top, float right, float bottom);

    private:
        Layout* _parent;

        HorizontalAlignment _hAlign = HorizontalAlignment::Left;
        VerticalAlignment _vAlign = VerticalAlignment::Up;
        SizeHint _sizeHint;
        Margin _margin;
    };
}