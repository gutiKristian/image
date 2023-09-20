// #define EVENT_CLOSE 1
// #define EVENT_RESIZE 2
// #define EVENT_MOUSECLICK 3

#define BIT(x) 1 << x
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\

namespace core
{
    enum EventType
    {
        None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    class Event
    {
    public:
        bool IsSuccess;
    protected:
        Event() = default;
    };


    template <typename T>
    concept SubEvent = requires(T a)
    {
        std::is_base_of<Event, T>::value;
    };

    class EventDispatcher
    {
        Event mEvent;
    public:
        EventDispatcher(Event& e) : mEvent(e) {}

        template <SubEvent T>
        static void Dispatch(auto& lambda)
        {
            if (mEvent.GetEventType() == T::GetStaticType())
            {
                mEvent.IsSuccess; = (static_cast<T&>(mEvent));
            }
        }
    };
}