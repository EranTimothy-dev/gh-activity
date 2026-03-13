#include "components.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component_base.hpp>

using namespace ftxui;

Component Loading() {
    int frame = 0;
    return Renderer([=]() mutable {
        frame ++;
        return text("Loading...") | color(Color::Yellow) | borderEmpty;
        spinner(0, frame);
    });
}
