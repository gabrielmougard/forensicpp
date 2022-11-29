#include "forensicpp/ui/tabs/extract/data_source_component.h"

ETLDataSourceComponent::ETLDataSourceComponent() : ComponentBase() {
    Add(Container::Vertical({
        data_source_container_,
    }));
}

Element ETLCollectionComponent::Render() {
    return paragraphAlignCenter("No registered collections. Add a new collection.");
}

Element ETLNewCollectionComponent::Render() {
    return paragraphAlignCenter("TODO...");
}

Element ETLCollectionParametersComponent::Render() {
    return paragraphAlignCenter("TODO...");
}

Element ETLDataSourceComponent::Render() {
    return window(text(L"Data sources"), vbox({
        data_source_container_->Render() | flex,
    })) | flex;
}