//
// Created by stuka on 19.06.2023.
//

#include "ChooseMenuWindow.h"

#include "Menu/MenuManager.h"
#include "Utils.h"
#include "EditMenuWindow.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::SysAdmin::ChooseMenuWindow::show()
{
    int menuNum = 0;
    for(const auto& menu : Menu::MenuManager::getMenus())
    {
        std::cout << std::to_string(menuNum) << ") Название: " << menu->m_name << ", граммовка: " << std::to_string(menu->m_gram)
        << ", описание: " << menu->m_description << ", время приготовления: " << std::to_string(menu->m_cookingTimeSeconds)
        << ", стоимость: " << menu->m_cost << std::endl;

        menuNum++;
    }

    std::cout << "Выберите пункт (номер): ";
    int point = getPoint(0, menuNum);

    switch(EditMenuWindow::m_editMode)
    {
        case EDIT:break;
        case DELETE:
        {
            menuNum = 0;
            for(const auto& menu: Menu::MenuManager::getMenus())
            {
                if(point == menuNum)
                {
                    Menu::MenuManager::removeMenu(menu->m_name);
                }
                menuNum++;
            }

            std::cout << "Блюдо удалено!" << std::endl;

            break;
        }
    }

    Menu::MenuManager::save("menus.txt");

    return WindowsManager::getWindow(SYS_ADMIN_MAIN_WND_NAME);
}
