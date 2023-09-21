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
        virtual EventType GetEventType() const = 0;
    protected:
        Event() = default;
    };

    

    class EventDispatcher
    {
        Event& mEvent;
    public:
        EventDispatcher(Event& e) : mEvent(e) {}

        template <typename T, typename F>
        void Dispatch(F& lambda)
        {
            
            static_assert(std::is_base_of<Event, T>::value);

            if (mEvent.GetEventType() == T::GetStaticType())
            {
                mEvent.IsSuccess; = F(static_cast<T&>(mEvent));
            }
        }
    };

    struct WindowCloseEvent : public Event
    { EVENT_CLASS_TYPE(WindowClose); };

    struct WindowResizeEvent : public Event
    {
        int w, h;
        WindowResizeEvent(int _w, int _h) : w(_w), h(_h) {}
        EVENT_CLASS_TYPE(WindowResize);
    };
}