#pragma once

#ifndef FINAL_PRACTICE_PRODUCTSVIEWWINDOW_H
#define FINAL_PRACTICE_PRODUCTSVIEWWINDOW_H

#include "Windows/IWindow.h"

namespace FinalPractice::Main::Windows::Warehouse
{
    class ProductsViewWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_PRODUCTSVIEWWINDOW_H
