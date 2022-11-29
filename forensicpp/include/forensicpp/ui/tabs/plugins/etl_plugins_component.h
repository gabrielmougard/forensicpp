#ifndef UI_ETL_PLUGINS_COMPONENT_H
#define UI_ETL_PLUGINS_COMPONENT_H

#include <ftxui/component/component.hpp>

using namespace ftxui;

class ETLPluginsComponent : public ComponentBase {
public:
    ETLPluginsComponent() = default;
    Element Render() override;
};

#endif // UI_ETL_PLUGINS_COMPONENT_H