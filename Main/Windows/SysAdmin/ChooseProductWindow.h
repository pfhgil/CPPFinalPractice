#pragma once

#ifndef FINAL_PRACTICE_CHOOSEPRODUCTWINDOW_H
#define FINAL_PRACTICE_CHOOSEPRODUCTWINDOW_H

#include "Windows/IWindow.h"

namespace FinalPractice::Main::SysAdmin
{
    class ChooseProductWindow : public Windows::IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_CHOOSEPRODUCTWINDOW_H
