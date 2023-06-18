//
// Created by stuka on 16.06.2023.
//

#include "MainWindow.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::SysAdmin::MainWindow::show()
{
    std::cout << "1) Изменить сотрудника\n2) Изменить продукт\n3) Добавить продукт\n4) Удалить продукт" << std::endl;

    std::cout << "Введите пункт: ";

    int point = getPoint(1, 3);

    // кроет все варианты
    switch(point)
    {
        case 1: return WindowsManager::getWindow(SYS_ADMIN_CHOOSE_PERSON_WND_NAME);
        case 2: return WindowsManager::getWindow(SYS_ADMIN_CHOOSE_PRODUCT_WND_NAME);
        case 3: return WindowsManager::getWindow(SYS_ADMIN_EDIT_PRODUCT_WND_NAME);
    }

    return WindowsManager::getWindow(SYS_ADMIN_MAIN_WND_NAME);
    //return std::shared_ptr<IWindow>();
}
