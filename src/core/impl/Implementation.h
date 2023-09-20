#include <functional>
#include <string>

#define CallbackFn std::function<void(int8_t)>

namespace core
{
    class Implementation
    {
    public:
        int mWidth;
        int mHeight;
        std::string mName;
        CallbackFn callback;
        // Member methods
        virtual void CreateWindow() = 0;
        virtual void OnUpdate() = 0;

        virtual ~Implementation() = default;
    protected:
        Implementation(int width, int height, std::string name) : mWidth(width), mHeight(height), mName(std::move(name)) {}
    };
}
