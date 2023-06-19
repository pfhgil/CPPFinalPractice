#pragma once

#ifndef FINAL_PRACTICE_EDITMENUWINDOW_H
#define FINAL_PRACTICE_EDITMENUWINDOW_H

#include "Windows/IWindow.h"
#include "Menu/Menu.h"
#include "Windows/EditMode.h"

namespace FinalPractice::Main::Windows::SysAdmin
{
    class EditMenuWindow : public IWindow
    {
    public:
        static inline EditMode m_editMode = EditMode::CREATE;
        static inline std::shared_ptr<Menu::Menu> m_currentEditableMenu;

        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_EDITMENUWINDOW_H
