//
// Created by stuka on 08.06.2023.
//

#include "MainWindow.h"
#include "Menu/MenuManager.h"
#include "Cart/Guest.h"
#include "Accountant/AccountantLog.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Guest::MainWindow::show()
{
    std::cout << "1) Выбрать блюдо в корзину\n2) Оплатить корзину\n3) Просмотреть корзину" << std::endl;

    int chosenPoint = getPoint(1, 3);

    switch(chosenPoint)
    {
        case 1:
        {
            // вывод всех блюд
            int curDish = 0;
            for(const auto& dish : Menu::MenuManager::getMenus())
            {
                std::cout << std::to_string(curDish + 1) << ") Название: " << dish->m_name << ", граммовка: " << std::to_string(dish->m_gram)
                          << ", описание: " << dish->m_description << ", время приготовления: " << std::to_string(dish->m_cookingTimeSeconds)
                          << ", стоимость: " << dish->m_cost << std::endl;

                curDish++;
            }

            std::cout << "Выберите пункт (номер): ";
            int point = getPoint(1, curDish);

            // выбранное блюдо
            std::shared_ptr<Menu::Menu> chosenDish;

            // поиск соответствующего блюда
            curDish = 1;
            for(const auto& menu: Menu::MenuManager::getMenus())
            {
                if(point == curDish)
                {
                    chosenDish = menu;
                    break;
                }
                curDish++;
            }

            Cart::Guest::m_cart->addDish(chosenDish);
            Cart::Guest::save("guest.txt");

            std::cout << "Заказ сделан! Блюдо: " << chosenDish->m_name << std::endl;

            break;
        }
        case 2:
        {
            for(auto& dish : Cart::Guest::m_cart->m_dishes)
            {
                // если заказ ещё не был оплачен
                if(dish.second != Cart::CartStatus::PAID)
                {
                    dish.second = Cart::CartStatus::PAID;
                    // добавляем блюдо как проданное
                    Accountant::AccountantLog::addSoldDish(Menu::MenuManager::getMenu(dish.first));
                }
            }
            Cart::Guest::save("guest.txt");

            break;
        }
        case 3:
        {
            int curDish = 0;
            for(const auto& dish : Cart::Guest::m_cart->m_dishes)
            {
                std::cout << std::to_string(curDish + 1) << ") Название блюда: " << dish.first << ", статус: " << Cart::cartStatusToString(dish.second) << std::endl;
            }

            break;
        }
    }

    return WindowsManager::getWindow(GUEST_MAIN_WND_NAME);
}
