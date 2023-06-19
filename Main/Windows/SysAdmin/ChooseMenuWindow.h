#pragma once

#ifndef FINAL_PRACTICE_CHOOSEMENUWINDOW_H
#define FINAL_PRACTICE_CHOOSEMENUWINDOW_H

#include "Windows/IWindow.h"

namespace FinalPractice::Main::Windows::SysAdmin
{
    class ChooseMenuWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_CHOOSEMENUWINDOW_H
