//
// Created by stuka on 21.06.2023.
//

#include "MainWindow.h"
#include "Accountant/AccountantLog.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Accountant::MainWindow::show()
{
    // вывод возможных вариантов
    std::cout << "1) Посмотреть все заказанные продукты\n2) Посмотреть все отправленные продукты\n3) Посмотреть проданные блюда" << std::endl;
    std::cout << "Всего продано блюд: " << std::to_string(FinalPractice::Main::Accountant::AccountantLog::getDishesSold()) <<
    ", на сумму: " << std::to_string(FinalPractice::Main::Accountant::AccountantLog::getDishesSoldSum()) << "\n" <<
    "Денег потрачено на закупку продуктов: " << std::to_string(FinalPractice::Main::Accountant::AccountantLog::getMoneySpentOnProducts()) << std::endl;

    // выбор вариантов
    int chosenPoint = getPoint(1, 3);

    switch(chosenPoint)
    {
        case 1:
        {
            // вывод всех заказанных продуктов
            FinalPractice::Main::Accountant::AccountantLog::printOrderedProductsLog();

            break;
        }
        case 2:
        {
            // вывод всех принятых продуктов
            FinalPractice::Main::Accountant::AccountantLog::printAcceptedProductDeliveriesLog();

            break;
        }
        case 3:
        {
            // вывод всех проданных блюд
            FinalPractice::Main::Accountant::AccountantLog::printSoldDishesLog();

            break;
        }
    }

    return WindowsManager::getWindow(ACCOUNTANT_MAIN_WND_NAME);
}
