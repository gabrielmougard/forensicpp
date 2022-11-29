#include "forensicpp/ui/tabs/extract/data_summary_component.h"

Element ETLDataSummaryComponent::Render() {
    return window(
        text(L"Data summary"),
        paragraphAlignCenter("No data summary. Select a data source first.")) | flex; 
}