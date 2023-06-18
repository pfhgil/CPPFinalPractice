//
// Created by stuka on 02.06.2023.
//

#include "ChooseAuthWindow.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Auth::ChooseAuthWindow::show()
{
    std::cout << "Привет. Войти как:" << std::endl;

    std::cout << "1) Гость" << std::endl;
    std::cout << "2) Авторизоваться" << std::endl;
    std::cout << "3) Зарегистрироваться" << std::endl;

    std::uint8_t point = getPoint(1, 3);

    switch(point)
    {
        case 1: return WindowsManager::getWindow(GUEST_MAIN_WND_NAME);
        case 2: return WindowsManager::getWindow(LOGIN_WND_NAME);
        case 3: return WindowsManager::getWindow(REGISTRATION_WND_NAME);
    }
}
