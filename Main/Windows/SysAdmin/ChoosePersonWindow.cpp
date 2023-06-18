//
// Created by stuka on 17.06.2023.
//

#include "ChoosePersonWindow.h"
#include "Persons/PersonsManager.h"
#include "EditPersonWindow.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::SysAdmin::ChoosePersonWindow::show()
{
    int num = 0;
    for(auto& person : Persons::PersonsManager::getPersons())
    {
        std::cout << std::to_string(num) << ") Login: " << person->m_login << "\n";

        num++;
    }

//
    int chosenPoint = getPoint(0, num);

    num = 0;
    for(auto& person : Persons::PersonsManager::getPersons())
    {
        if(chosenPoint == num)
        {
            EditPersonWindow::m_currentEditablePerson = person;

            break;
        }

        num++;
    }

    return WindowsManager::getWindow(SYS_ADMIN_EDIT_PERSON_WND_NAME);
}
