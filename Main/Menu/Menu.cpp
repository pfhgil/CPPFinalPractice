//
// Created by stuka on 19.06.2023.
//

#include "Menu.h"

std::list<std::shared_ptr<FinalPractice::Main::Product::Product>>& FinalPractice::Main::Menu::Menu::getProducts() noexcept
{
    return m_products;
}
