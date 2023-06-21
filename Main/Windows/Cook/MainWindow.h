#pragma once

#ifndef FINAL_PRACTICE_COOK_MAINWINDOW_H
#define FINAL_PRACTICE_COOK_MAINWINDOW_H

#include "Windows/WindowsManager.h"

namespace FinalPractice::Main::Windows::Cook
{
    class MainWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_MAINWINDOW_H
