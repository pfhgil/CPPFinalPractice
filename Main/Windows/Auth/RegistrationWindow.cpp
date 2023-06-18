//
// Created by stuka on 08.06.2023.
//

#include <functional>

#include "RegistrationWindow.h"

#include "Persons/PersonsManager.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Auth::RegistrationWindow::show()
{
    std::string login;
    std::string password = "no";
    std::string passwordConfirmation;

    bool personExists = true;

    std::cin.sync();

    while(personExists)
    {
        std::cout << "Введите логин: ";
        std::getline(std::cin, login);

        personExists = Persons::PersonsManager::getPerson(login) != nullptr;

        if(personExists)
        {
            std::cout << "Пользователь уже существует!" << std::endl;
        }
    }

    while(password != passwordConfirmation)
    {
        std::cout << "Введите пароль: ";
        std::getline(std::cin, password);

        std::cout << "Введите подтверждение пароля: ";
        std::getline(std::cin, passwordConfirmation);

        if(password != passwordConfirmation)
        {
            std::cout << "Пароли не совпадают!" << std::endl;
        }
    }

    Persons::PersonsManager::m_currentPerson = Persons::PersonsManager::createPerson<Persons::Person>();
    Persons::PersonsManager::m_currentPerson->m_login = login;
    Persons::PersonsManager::m_currentPerson->m_password = std::to_string(std::hash<std::string>()(password));

    Persons::PersonsManager::save("persons.txt");

    return WindowsManager::getWindow(LOGIN_WND_NAME);
    //std::cout << "this is registration window" << std::endl;
}
