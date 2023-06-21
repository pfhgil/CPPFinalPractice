//
// Created by stuka on 20.06.2023.
//

#include "MainWindow.h"
#include "Utils.h"
#include "Windows/WindowsManager.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Warehouse::MainWindow::show()
{
    std::cout << "1) Просмотреть склад\n2) Заказать товары" << std::endl;

    int point = getPoint(1, 2);

    switch(point)
    {
        case 1:
        {
            return WindowsManager::getWindow(WAREHOUSE_PRODUCTS_VIEW_WND_NAME);
        }
        case 2:
        {
            return WindowsManager::getWindow(WAREHOUSE_PRODUCTS_ORDER_WND_NAME);
        }
    }

    //return std::shared_ptr<IWindow>();
}
