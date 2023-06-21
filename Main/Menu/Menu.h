#pragma once

#ifndef FINAL_PRACTICE_MENU_H
#define FINAL_PRACTICE_MENU_H

#include <list>
#include <memory>

#include "Product/Product.h"

namespace FinalPractice::Main::Menu
{
    // ЭТО КЛАСС БЛЮДА, Я ОШИБСЯ В НАЗВАНИИ
    class Menu
    {
    private:
        // продукты в составе
        std::list<std::shared_ptr<Product::Product>> m_products;

    public:
        std::string m_name;
        // граммовка
        std::uint16_t m_gram = 0;
        std::string m_description;
        // время приготовления в секундах
        std::uint16_t m_cookingTimeSeconds = 0;
        float m_cost = 0;

        std::list<std::shared_ptr<Product::Product>>& getProducts() noexcept;
    };
}

#endif //FINAL_PRACTICE_MENU_H
