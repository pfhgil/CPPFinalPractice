#pragma once

#ifndef FINAL_PRACTICE_SYS_ADMIN_MAINWINDOW_H
#define FINAL_PRACTICE_SYS_ADMIN_MAINWINDOW_H

#include "Windows/IWindow.h"

namespace FinalPractice::Main::Windows::SysAdmin
{
    class MainWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_SYS_ADMIN_MAINWINDOW_H
