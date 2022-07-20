#ifndef MARQUEE_HPP
#define MARQUEE_HPP

#include <windows.h>
#include <string>

class Marquee {
    private:
        const short DEFAULT_VELOCITY{7};
        std::string message{};
        size_t xLimitLeft{};
        size_t xLimitRight{};
        SHORT yHight{};
        short velocity{};
        
        void renderMarquee(SHORT x);
        void renderMarquee(const std::string &substring, SHORT x);
        void clearMarquee(SHORT x);

    public:
        Marquee(const std::string &initialMessage, size_t initialXLimitleft, size_t initialXLimitRight);
        void setPosition(SHORT y);
        void setVelocity(short velocity);
        void print();
};

#endif