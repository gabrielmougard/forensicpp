#include "forensicpp/ui/tabs/extract/etl_extract_component.h"

ETLExtractComponent::ETLExtractComponent() : ComponentBase() {
    Add(Container::Vertical({
        data_source_,
        data_summary_,
        search_query_,
    }));
}

Element ETLExtractComponent::Render() {
    return vbox({
        data_source_->Render(),
        data_summary_->Render(),
        search_query_->Render(),
    });
} 