#include "layer/Layer.h"
#include "events.h"

class DummyLayer : public core::Layer
{
public:
    virtual void OnAttach() override {}
    virtual void OnUpdate() override {};
    virtual void OnDetach() override {};
    virtual void OnEvent(core::Event& e) override {};
    virtual void OnResize(int a, int b) override {};
};