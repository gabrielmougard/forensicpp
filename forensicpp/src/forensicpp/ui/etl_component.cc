#include "forensicpp/ui/etl_component.h"

ETLComponent::ETLComponent() : ComponentBase() {
    Add(Container::Vertical({
        etl_container_,
    }));
}

Element ETLComponent::Render() {
    return vbox({
        etl_container_->Render() | flex,
    });
}