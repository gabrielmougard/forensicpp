#include "forensicpp/ui/main_component.h"

MainComponent::MainComponent() : ComponentBase() {
    Add(Container::Vertical({
        main_group_,
    }));
}

Element MainComponent::Render() {
    return vbox({
        text("Forensick") | bold | hcenter,
        main_group_->Render() | flex,
    });
}