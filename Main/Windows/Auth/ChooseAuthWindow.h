#pragma once

#ifndef FINAL_PRACTICE_CHOOSEAUTHWINDOW_H
#define FINAL_PRACTICE_CHOOSEAUTHWINDOW_H

#include "Windows/IWindow.h"

namespace FinalPractice::Main::Windows::Auth
{
    class ChooseAuthWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_CHOOSEAUTHWINDOW_H
