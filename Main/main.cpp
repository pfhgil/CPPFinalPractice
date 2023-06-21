#include <iostream>

#include <windows.h>

#include "Windows/IWindow.h"
#include "Persons/PersonsManager.h"
#include "Product/ProductsManager.h"
#include "Menu/MenuManager.h"
#include "Warehouse/WarehouseManager.h"
#include "Accountant/AccountantLog.h"
#include "Cart/Guest.h"

int main()
{
    // установка локализации
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");

    // инициализация менеджера окон
    FinalPractice::Main::Windows::WindowsManager::init();
    // загрузка информации о сотрудниках
    FinalPractice::Main::Persons::PersonsManager::load("persons.txt");

    // загрузка информации о продуктах
    FinalPractice::Main::Product::ProductsManager::load("products.txt");

    // загрузка информации о блюдах
    FinalPractice::Main::Menu::MenuManager::load("menus.txt");

    // загрузка информации о складе
    FinalPractice::Main::Warehouse::WarehouseManager::load("warehouse.txt");

    FinalPractice::Main::Accountant::AccountantLog::load("accountant_log.txt");

    FinalPractice::Main::Cart::Guest::load("guest.txt");

    // установка текущего окна
    std::shared_ptr<FinalPractice::Main::Windows::IWindow> currentWindow = FinalPractice::Main::Windows::WindowsManager::getWindow(CHOOSE_AUTH_WND_NAME);

    // цикл показа окон
    while(currentWindow)
    {
        FinalPractice::Main::Windows::WindowsManager::setCurrentWindow(FinalPractice::Main::Windows::WindowsManager::getCurrentWindow()->show());
    }

    return 0;
}
