//
// Created by stuka on 21.06.2023.
//

#include "MainWindow.h"
#include "Cart/Guest.h"
#include "Utils.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Cook::MainWindow::show()
{
    std::cout << "Список блюд, которые можно приготовить" << std::endl;

    int curDish = 0;
    for(const auto& dish : Cart::Guest::m_cart->m_dishes)
    {
        if(dish.second == Cart::CartStatus::PAID)
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

    std::shared_ptr<Menu::Menu> foundDish = Menu::MenuManager::getMenu(chosenDishPair->first);

    std::list<int> productsIDs;

    std::cout << "Введите следующие числа для приготовления блюда: ";
    for(const auto& product : foundDish->getProducts())
    {
        std::cout << product->m_id << ", ";
        productsIDs.push_back(product->m_id);
    }

    std::cout << std::endl;

    int productsIDsStartSize = productsIDs.size();

    for(int i = 0; i < productsIDsStartSize;)
    {
        int id = Utils::getInputNum<int>("Введите ID: ");
        auto iter = std::find(productsIDs.begin(), productsIDs.end(), id);
        if(iter != productsIDs.end())
        {
            productsIDs.erase(iter);
            i++;
            chosenDishPair->second = Cart::CartStatus::PASSED_TO_WAITER;
        }
        else
        {
            std::cout << "Такого ID нет!" << std::endl;
        }
    }

    std::cout << "Заказ передан официанту!" << std::endl;

    Cart::Guest::save("guest.txt");

    return WindowsManager::getWindow(COOK_MAIN_WND_NAME);
}
