#pragma once

#ifndef FINAL_PRACTICE_GUEST_H
#define FINAL_PRACTICE_GUEST_H

#include <list>
#include <memory>

#include "Cart.h"

namespace FinalPractice::Main::Cart
{
    class Guest
    {
    public:
        // корзина пользователя
        static inline std::shared_ptr<Cart> m_cart = std::make_shared<Cart>();

        // сохранение пользователя
        static void save(const std::string_view&) noexcept;
        // загрузка пользователя
        static void load(const std::string_view&) noexcept;
    };
}

#endif //FINAL_PRACTICE_GUEST_H
