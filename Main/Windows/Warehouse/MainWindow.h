#pragma once

#ifndef FINAL_PRACTICE_WAREHOUSE_MAINWINDOW_H
#define FINAL_PRACTICE_WAREHOUSE_MAINWINDOW_H

#include "Windows/IWindow.h"

namespace FinalPractice::Main::Windows::Warehouse
{
    class MainWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_WAREHOUSE_MAINWINDOW_H
