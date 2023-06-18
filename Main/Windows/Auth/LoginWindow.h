#pragma once

#ifndef FINAL_PRACTICE_LOGINWINDOW_H
#define FINAL_PRACTICE_LOGINWINDOW_H

#include "Windows/IWindow.h"

namespace FinalPractice::Main::Windows::Auth
{
    class LoginWindow : public Windows::IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_LOGINWINDOW_H
