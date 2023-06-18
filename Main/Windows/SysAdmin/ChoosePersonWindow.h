#pragma once

#ifndef FINAL_PRACTICE_CHOOSEPERSONWINDOW_H
#define FINAL_PRACTICE_CHOOSEPERSONWINDOW_H

#include "Windows/IWindow.h"
#include "Persons/Person.h"

namespace FinalPractice::Main::Windows::SysAdmin
{
    class ChoosePersonWindow : public IWindow
    {
    public:
        std::shared_ptr<IWindow> show() final;
    };
}

#endif //FINAL_PRACTICE_CHOOSEPERSONWINDOW_H
