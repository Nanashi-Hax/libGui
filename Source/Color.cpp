#include "Gui/Color.hpp"

namespace Library::Gui
{
    Math::Color4f Color::local() const noexcept
    {
        return _local;
    }

    void Color::setLocal(Math::Color4f value)
    {
        _local = Math::Color4f(clamp01(value));
    }

    Math::Color4f Color::render() const noexcept
    {
        return _render;
    }

    void Color::setRender(Math::Color4f color)
    {
        _render = clamp01(color);
    }

    Math::Color4f Color::compute(Math::Color4f parent)
    {
        _render = clamp01(parent * _local);
        return _render;
    }

    Math::Color4f Color::clamp01(Math::Color4f color) noexcept
    {
        if (color.r < 0.0f) color.r = 0.0f;
        if (color.r > 1.0f) color.r = 1.0f;

        if (color.g < 0.0f) color.g = 0.0f;
        if (color.g > 1.0f) color.g = 1.0f;

        if (color.b < 0.0f) color.b = 0.0f;
        if (color.b > 1.0f) color.b = 1.0f;

        if (color.a < 0.0f) color.a = 0.0f;
        if (color.a > 1.0f) color.a = 1.0f;
        return color;
    }
}
