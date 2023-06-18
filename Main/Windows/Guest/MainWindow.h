//
// Created by stuka on 08.06.2023.
//

#pragma once

#ifndef FINAL_PRACTICE_MAINWINDOW_H
#define FINAL_PRACTICE_MAINWINDOW_H

#include "../IWindow.h"

namespace FinalPractice::Main::Windows::Guest
{
    class MainWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_MAINWINDOW_H
