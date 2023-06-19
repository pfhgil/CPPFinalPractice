#include <iostream>

#include <windows.h>

#include "Windows/IWindow.h"
#include "Persons/PersonsManager.h"
#include "Product/ProductsManager.h"
#include "Menu/MenuManager.h"

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");

    FinalPractice::Main::Windows::WindowsManager::init();
    FinalPractice::Main::Persons::PersonsManager::load("persons.txt");

    FinalPractice::Main::Product::ProductsManager::load("products.txt");

    FinalPractice::Main::Menu::MenuManager::load("menus.txt");

    std::shared_ptr<FinalPractice::Main::Windows::IWindow> currentWindow = FinalPractice::Main::Windows::WindowsManager::getWindow(CHOOSE_AUTH_WND_NAME);

    while(currentWindow)
    {
        FinalPractice::Main::Windows::WindowsManager::setCurrentWindow(FinalPractice::Main::Windows::WindowsManager::getCurrentWindow()->show());
    }

    return 0;
}
