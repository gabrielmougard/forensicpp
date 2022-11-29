#ifndef UI_ETL_RESULT_COMPONENT_H
#define UI_ETL_RESULT_COMPONENT_H

#include <ftxui/component/component.hpp>

using namespace ftxui;

class ETLResultComponent : public ComponentBase {
public:
    ETLResultComponent() = default;
    Element Render() override;
};

#endif // UI_ETL_RESULT_COMPONENT_H