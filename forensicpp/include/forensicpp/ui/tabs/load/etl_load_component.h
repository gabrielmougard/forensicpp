#ifndef UI_ETL_LOAD_COMPONENT_H
#define UI_ETL_LOAD_COMPONENT_H

#include <ftxui/component/component.hpp>

using namespace ftxui;

class ETLLoadComponent : public ComponentBase {
public:
    ETLLoadComponent() = default;
    Element Render() override;
};

#endif // UI_ETL_LOAD_COMPONENT_H