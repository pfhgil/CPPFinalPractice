//
// Created by stuka on 21.06.2023.
//

#include "MainWindow.h"
#include "Cart/Guest.h"
#include "Utils.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Waiter::MainWindow::show()
{
    std::cout << "Список блюд, которые можно отнести" << std::endl;

    int curDish = 0;
    for(const auto& dish : Cart::Guest::m_cart->m_dishes)
    {
        if(dish.second == Cart::CartStatus::PASSED_TO_WAITER)
        {
            std::cout << std::to_string(curDish + 1) << ") Название: " << dish.first << std::endl;

            curDish++;
        }
    }

    int chosenDish = getPoint(1, curDish);

    // выбранное блюдо
    std::pair<const std::string, Cart::CartStatus>* chosenDishPair;

    // поиск соответствующего блюда
    curDish = 1;
    for(auto& dish: Cart::Guest::m_cart->m_dishes)
    {
        if(chosenDish == curDish)
        {
            chosenDishPair = &dish;
            break;
        }

        if(dish.second == Cart::CartStatus::PAID)
        {
            curDish++;
        }
    }

    chosenDishPair->second = Cart::CartStatus::COMPLETED;

    Cart::Guest::save("guest.txt");

    return WindowsManager::getWindow(WAITER_MAIN_WND_NAME);
}
