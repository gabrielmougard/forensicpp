#ifndef UI_ETL_EXTRACT_COMPONENT_H
#define UI_ETL_EXTRACT_COMPONENT_H

#include <ftxui/component/component.hpp>

#include "forensicpp/ui/tabs/extract/data_source_component.h"
#include "forensicpp/ui/tabs/extract/data_summary_component.h"
#include "forensicpp/ui/tabs/extract/search_query_component.h"

using namespace ftxui;

class ETLExtractComponent : public ComponentBase {
public:
    ETLExtractComponent();
    Element Render() override;
private:
    Component data_source_ = Make<ETLDataSourceComponent>();
    Component data_summary_ = Make<ETLDataSummaryComponent>();
    Component search_query_ = Make<ETLSearchQueryComponent>();
};

#endif // UI_ETL_EXTRACT_COMPONENT_H