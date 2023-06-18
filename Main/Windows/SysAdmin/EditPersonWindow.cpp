//
// Created by stuka on 17.06.2023.
//

#include <functional>

#include "EditPersonWindow.h"

#include "Windows/WindowsManager.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::SysAdmin::EditPersonWindow::show()
{
    std::cout << "Изменить у сотрудника:\n1) Логин\n2) Пароль\n3) Имя\n4) Фамилия\n5) Отчество\n6) Роль" << std::endl;

    int chosenPoint = getPoint(1, 6);

    switch(chosenPoint)
    {
        case 1:
        {
            std::cout << "Введите новый логин сотрудника: ";
            std::cin >> EditPersonWindow::m_currentEditablePerson->m_login;
            break;
        }
        case 2:
        {
            std::string tmpPassword;

            std::cout << "Введите новый пароль сотрудника: ";
            std::cin >> tmpPassword;

            EditPersonWindow::m_currentEditablePerson->m_password = std::to_string(std::hash<std::string>()(tmpPassword));
            break;
        }
        case 3:
        {
            std::cout << "Введите новое имя сотрудника: ";
            std::cin >> EditPersonWindow::m_currentEditablePerson->m_name;
            break;
        }
        case 4:
        {
            std::cout << "Введите новую фамилию сотрудника: ";
            std::cin >> EditPersonWindow::m_currentEditablePerson->m_surname;
            break;
        }
        case 5:
        {
            std::cout << "Введите новое отчество сотрудника: ";
            std::cin >> EditPersonWindow::m_currentEditablePerson->m_patronymic;
            break;
        }
        case 6:
        {
            std::cout << "Выберите новую роль сотрудника:" << std::endl;
            std::cout << "1) Гость\n";
            std::cout << "2) Сис. Админ.\n";
            std::cout << "3) Складской\n";
            std::cout << "4) Поставщик\n";
            std::cout << "5) Бухгалтер\n";
            std::cout << "6) Повар\n";
            std::cout << "7) Официант\n";

            EditPersonWindow::m_currentEditablePerson->m_personType = static_cast<Persons::PersonType>(getPoint(1, 7) - 1);
            break;
        }
    }

    Persons::PersonsManager::save("persons.txt");

    std::cout << "Вы изменили данные сотрудника!" << std::endl;

    return WindowsManager::getWindow(SYS_ADMIN_MAIN_WND_NAME);
}
