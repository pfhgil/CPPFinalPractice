//
// Created by stuka on 16.06.2023.
//

#include "MainWindow.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::SysAdmin::MainWindow::show()
{
    std::cout << "1) Изменить сотрудника\n2) Изменить продукты\n3) Добавить продукт" << std::endl;

    std::cout << "Введите пункт: ";

    int point = getPoint(1, 3);

    // кроет все варианты
    switch(point)
    {
        case 1: return WindowsManager::getWindow(SYS_ADMIN_CHOOSE_PERSON_WND_NAME);
        case 2: break;
        case 3: break;
    }

    return WindowsManager::getWindow(SYS_ADMIN_MAIN_WND_NAME);
    //return std::shared_ptr<IWindow>();
}
