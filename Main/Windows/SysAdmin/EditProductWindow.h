#pragma once

#ifndef FINAL_PRACTICE_EDITPRODUCTWINDOW_H
#define FINAL_PRACTICE_EDITPRODUCTWINDOW_H

#include "Windows/IWindow.h"
#include "Product/Product.h"
#include "Windows/EditMode.h"

namespace FinalPractice::Main::Windows::SysAdmin
{
    class EditProductWindow : public IWindow
    {
    public:
        static inline std::shared_ptr<Product::Product> m_currentEditablePerson;

        static inline EditMode m_editMode = EditMode::CREATE;

        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_EDITPRODUCTWINDOW_H
