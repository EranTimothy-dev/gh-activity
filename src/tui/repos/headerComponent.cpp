#include "components.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component_base.hpp>

using namespace ftxui;

Component Header() {
    return Renderer([=] {
        return vbox({
            text("GitHub Dashboard") | color(Color::Blue) | bold,
            separator(),
        });
    });
}
