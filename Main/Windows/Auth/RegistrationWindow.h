//
// Created by stuka on 08.06.2023.
//

#pragma once

#ifndef FINAL_PRACTICE_REGISTRATIONWINDOW_H
#define FINAL_PRACTICE_REGISTRATIONWINDOW_H

#include "../IWindow.h"

namespace FinalPractice::Main::Windows::Auth
{
    class RegistrationWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_REGISTRATIONWINDOW_H
