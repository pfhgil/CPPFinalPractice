#pragma once

#ifndef FINAL_PRACTICE_PRODUCTSORDERWINDOW_H
#define FINAL_PRACTICE_PRODUCTSORDERWINDOW_H

#include "Windows/IWindow.h"

namespace FinalPractice::Main::Windows::Warehouse
{
    class ProductsOrderWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_PRODUCTSORDERWINDOW_H
