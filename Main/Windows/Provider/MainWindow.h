#pragma once

#ifndef FINAL_PRACTICE_PROVIDER_MAINWINDOW_H
#define FINAL_PRACTICE_PROVIDER_MAINWINDOW_H

#include "Windows/IWindow.h"

namespace FinalPractice::Main::Windows::Provider
{
    class MainWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_PROVIDER_MAINWINDOW_H
