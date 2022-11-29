#include "forensicpp/ui/tabs/extract/search_query_component.h"

ETLSearchQueryComponent::ETLSearchQueryComponent() : ComponentBase() {
    Add(Container::Vertical({
        search_query_input_,
        search_query_button_,
    }));
}

Element ETLSearchQueryComponent::Render() {
    return window(text(L"Search query"), vbox({
        search_query_input_->Render(),
        search_query_button_->Render(),
    }));
}