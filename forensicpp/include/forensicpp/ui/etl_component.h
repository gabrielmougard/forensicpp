#ifndef UI_ETL_COMPONENT_H
#define UI_ETL_COMPONENT_H

#include <ftxui/component/component.hpp>

#include "forensicpp/ui/tabs/extract/etl_extract_component.h"
#include "forensicpp/ui/tabs/transform/etl_transform_component.h"
#include "forensicpp/ui/tabs/load/etl_load_component.h"
#include "forensicpp/ui/tabs/plugins/etl_plugins_component.h"

using namespace ftxui;

class ETLComponent : public ComponentBase {
public:
    ETLComponent();
    Element Render() override;
private:
    int tab_index_ = 0;
    std::vector<std::string> tab_entries_ = {
        "Extract", "Transform", "Load", "Plugins",
    };
    Component tab_selection_ =
        Menu(&tab_entries_, &tab_index_, MenuOption::HorizontalAnimated());

    Component extract_component_ = Make<ETLExtractComponent>();
    Component transform_component_ = Make<ETLTransformComponent>();
    Component load_component_ = Make<ETLLoadComponent>();
    Component plugins_component_ = Make<ETLPluginsComponent>();
    
    Component tab_content_ = Container::Tab(
    {
      extract_component_,
      transform_component_,
      load_component_,
      plugins_component_,
    },
    &tab_index_);

    Component etl_container_ = Container::Vertical({
        tab_selection_,
        tab_content_,
    });
};

#endif // UI_ETL_COMPONENT_H