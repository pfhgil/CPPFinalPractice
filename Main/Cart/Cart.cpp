//
// Created by stuka on 21.06.2023.
//

#include "Cart.h"
#include "Restaurant.h"

void FinalPractice::Main::Cart::Cart::addDish(const std::shared_ptr<Menu::Menu>& dish) noexcept
{
    //m_dishes.push(dish);

    m_dishes.emplace(dish->m_name, CartStatus::BUILDING);

    Restaurant::m_money += dish->m_cost;
}
