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
        float left = 0;
        float top = 0;
        float right = 0;
        float bottom = 0;
    };

    class Layout
    {
    public:
        Layout();
        explicit Layout(Layout* parent);

        Math::Rectangle rectangle();

        void setAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical);
        void setMinSize(float width, float height);
        void setPreferredSize(float width, float height);
        void setMargin(float left, float top, float right, float bottom);

    private:
        Layout* _parent;

        HorizontalAlignment _hAlign = HorizontalAlignment::Center;
        VerticalAlignment _vAlign = VerticalAlignment::Middle;
        SizeHint _sizeHint;
        Margin _margin;
    };
}