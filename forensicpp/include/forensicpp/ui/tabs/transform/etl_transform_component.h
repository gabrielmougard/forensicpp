#ifndef UI_ETL_TRANSFORM_COMPONENT_H
#define UI_ETL_TRANSFORM_COMPONENT_H

#include <ftxui/component/component.hpp>

using namespace ftxui;

class ETLTransformComponent : public ComponentBase {
public:
    ETLTransformComponent() = default;
    Element Render() override;
};

#endif // UI_ETL_TRANSFORM_COMPONENT_H