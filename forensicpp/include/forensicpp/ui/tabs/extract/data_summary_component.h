#ifndef UI_ETL_DATA_SUMMARY_COMPONENT_H
#define UI_ETL_DATA_SUMMARY_COMPONENT_H

#include <ftxui/component/component.hpp>

using namespace ftxui;

class ETLDataSummaryComponent : public ComponentBase {
public:
    ETLDataSummaryComponent() = default;
    Element Render() override;
};

#endif // UI_ETL_DATA_SUMMARY_COMPONENT_H