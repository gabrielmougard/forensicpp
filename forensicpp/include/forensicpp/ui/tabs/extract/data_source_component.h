#ifndef UI_ETL_DATA_SOURCE_COMPONENT_H
#define UI_ETL_DATA_SOURCE_COMPONENT_H

#include <ftxui/component/component.hpp>

using namespace ftxui;

class ETLCollectionComponent : public ComponentBase {
public:
    ETLCollectionComponent() = default;
    Element Render() override;
};

class ETLNewCollectionComponent : public ComponentBase {
public:
    ETLNewCollectionComponent() = default;
    Element Render() override;
};

class ETLCollectionParametersComponent : public ComponentBase {
public:
    ETLCollectionParametersComponent() = default;
    Element Render() override;
};

class ETLDataSourceComponent : public ComponentBase {
public:
    ETLDataSourceComponent();
    Element Render() override;
private:
    int tab_selected_ = 0;
    std::vector<std::wstring> tab_entries_ = {
        L"Collections",
        L"New collection",
        L"Parameters",
    };
    Component menu_data_source_ = Menu(&tab_entries_, &tab_selected_, MenuOption::HorizontalAnimated());
    
    Component collections_content_ = Make<ETLCollectionComponent>();
    Component new_collection_content_ = Make<ETLNewCollectionComponent>();
    Component collection_parameters_content_ = Make<ETLCollectionParametersComponent>();
    
    Component data_source_content_ = Container::Tab(
        {
            collections_content_,
            new_collection_content_,
            collection_parameters_content_,
        },
        &tab_selected_);
    Component data_source_container_ = Container::Vertical({
        menu_data_source_,
        data_source_content_,
    });
};

#endif // UI_ETL_DATA_SOURCE_COMPONENT_H