#pragma once

#include <vector>
#include <memory>
#include <optional>

namespace Library::Gui
{
    template<class T>
    class Node {
        friend T;

    private:
        T* parent = nullptr;
        std::vector<std::unique_ptr<T>> children;
        std::optional<size_t> index = 0;
    };
}
