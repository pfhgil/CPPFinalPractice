//
// Created by stuka on 02.06.2023.
//

#include "LoginWindow.h"
#include "Persons/Person.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Auth::LoginWindow::show()
{
    bool isPersonFound = false;

    std::string login;
    std::string password;
    std::shared_ptr<Persons::Person> foundPerson;

    std::cin.sync();

    while(!isPersonFound)
    {
        std::cout << "Введите логин: ";
        std::getline(std::cin, login);

        std::cout << "Введите пароль: ";
        std::getline(std::cin, password);

        foundPerson = Persons::PersonsManager::getPerson(login);

        isPersonFound = foundPerson != nullptr && foundPerson->m_password == std::to_string(std::hash<std::string>()(password));

        std::cout << (isPersonFound ? "Вы вошли в систему!\n" : "Неверный пароль или пользователь не существует\n");
    }

    if(foundPerson)
    {
        switch(foundPerson->m_personType)
        {
            case Persons::PT_GUEST: return WindowsManager::getWindow(GUEST_MAIN_WND_NAME);
            case Persons::PT_SYS_ADMIN: return WindowsManager::getWindow(SYS_ADMIN_MAIN_WND_NAME);
            case Persons::PT_WAREHOUSE: return WindowsManager::getWindow(WAREHOUSE_MAIN_WND_NAME);
            case Persons::PT_PROVIDER: return WindowsManager::getWindow(PROVIDER_MAIN_WND_NAME);
            case Persons::PT_ACCOUNTANT: return WindowsManager::getWindow(ACCOUNTANT_MAIN_WND_NAME);
            case Persons::PT_COOK: return WindowsManager::getWindow(COOK_MAIN_WND_NAME);
            case Persons::PT_WAITER: return WindowsManager::getWindow(WAITER_MAIN_WND_NAME);
        }
    }
    //return std::shared_ptr<IWindow>();
}
