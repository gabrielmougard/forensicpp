#ifndef UI_ETL_SEARCH_QUERY_COMPONENT_H
#define UI_ETL_SEARCH_QUERY_COMPONENT_H

#include <ftxui/component/component.hpp>

#include <iostream>

using namespace ftxui;

class ETLSearchQueryComponent : public ComponentBase {
public:
    ETLSearchQueryComponent();
    Element Render() override;
private:
    std::string search_query_content_ = "";
    Component search_query_input_ = Input(&search_query_content_, "Enter query...");
    Component search_query_button_ = Button("Search", [&] {
        std::cout << "Search: " << search_query_content_ << std::endl;
    }, ButtonOption::Animated(Color::Green));
};

#endif // UI_ETL_SEARCH_QUERY_COMPONENT_H