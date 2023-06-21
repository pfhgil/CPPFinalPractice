#pragma once

#ifndef FINAL_PRACTICE_CART_H
#define FINAL_PRACTICE_CART_H

#include "Menu/MenuManager.h"
#include "CartStatus.h"
#include <map>
#include <string>
#include <list>

namespace FinalPractice::Main::Cart
{
    class Cart
    {
    public:
        // выбранные блюда
        std::map<std::string, CartStatus> m_dishes;

        void addDish(const std::shared_ptr<Menu::Menu>&) noexcept;
    };
}

#endif //FINAL_PRACTICE_CART_H
