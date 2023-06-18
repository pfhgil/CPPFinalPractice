#include "IWindow.h"

std::uint8_t FinalPractice::Main::Windows::IWindow::getPoint(const std::uint8_t& min, const std::uint8_t& max)
{
    int num = 0;
    while(true)
    {
        try
        {
            std::cin >> num;

            if(!(num >= min && num <= max))
            {
                std::cout << "Number out of bounds (min: " << std::to_string(min) << ", max: " << std::to_string(max) << ")" << std::endl;
                continue;
            }
            return num;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}