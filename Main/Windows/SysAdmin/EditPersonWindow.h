#pragma once

#ifndef FINAL_PRACTICE_EDITPERSONWINDOW_H
#define FINAL_PRACTICE_EDITPERSONWINDOW_H

#include "Windows/IWindow.h"
#include "Persons/Person.h"

namespace FinalPractice::Main::Windows::SysAdmin
{
    class EditPersonWindow : public IWindow
    {
    public:
        static inline std::shared_ptr<Persons::Person> m_currentEditablePerson;

        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_EDITPERSONWINDOW_H
