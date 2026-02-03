#pragma once

#include <Math.hpp>

namespace Library::Gui
{
    class Color
    {
    public:
        Math::Color4f local() const noexcept;
        void setLocal(Math::Color4f value);

        Math::Color4f render() const noexcept;
        void setRender(Math::Color4f value);

        Math::Color4f compute(Math::Color4f parent);

    private:
        static Math::Color4f clamp01(Math::Color4f color) noexcept;

        Math::Color4f _local = Math::Color4f(1.0f, 1.0f, 1.0f, 1.0f);
        Math::Color4f _render = Math::Color4f(1.0f, 1.0f, 1.0f, 1.0f);
    };
}
