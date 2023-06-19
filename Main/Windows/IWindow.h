#pragma once

#ifndef FINAL_PRACTICE_IWINDOW_H
#define FINAL_PRACTICE_IWINDOW_H

#include <iostream>
#include <memory>

#include "WindowsManager.h"

namespace FinalPractice::Main::Windows
{
    class WindowsManager;

    class IWindow
    {
    private:
        std::uint8_t m_currentPoint = 0;

    public:
        virtual std::shared_ptr<IWindow> show() = 0;

        virtual std::uint8_t getPoint(const std::int8_t& min, const std::int8_t& max);
    };
}

#endif //FINAL_PRACTICE_IWINDOW_H
