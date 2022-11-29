#ifndef UI_MAIN_COMPONENT_H
#define UI_MAIN_COMPONENT_H

#include <ftxui/component/component.hpp>
#include <ftxui/component/receiver.hpp>

#include "forensicpp/ui/etl_component.h"
#include "forensicpp/ui/etl_result_component.h"

using namespace ftxui;

class MainComponent : public ComponentBase {
public:
    MainComponent();
    Element Render() override;
private:

    Component etl_component_ = Make<ETLComponent>();
    Component etl_result_component_ = Make<ETLResultComponent>();

    int main_group_split_position_ = Terminal::Size().dimx / 2;
    Component main_group_ = ResizableSplitLeft(
        etl_component_, etl_result_component_, &main_group_split_position_);
};

#endif // UI_MAIN_COMPONENT_H