#pragma once

#ifndef FINAL_PRACTICE_ACCOUNTANTLOG_H
#define FINAL_PRACTICE_ACCOUNTANTLOG_H

#include <list>
#include <string>
#include <set>

#include "Warehouse/ProductsSet.h"
#include "Menu/Menu.h"

namespace FinalPractice::Main::Accountant
{
    class AccountantLog
    {
    private:
        // лог отправленных заявок на продукты
        static inline std::list<std::string> m_orderedProductsLog;
        // лог принятых заявок (отправлено на склад)
        static inline std::list<std::string> m_acceptedProductDeliveriesLog;

        // лог проданных блюда (название, цена)
        static inline std::list<std::string> m_soldDishesLog;

        // блюд продано
        static inline int m_dishesSold = 0;
        // на какую сумму продали все блюда
        static inline float m_dishesSoldSum = 0.0f;

        // сколько всего денег потратили на закупку продуктов
        static inline float m_moneySpentOnProducts = 0.0f;

    public:
        // добавить заказанный продукт
        static void addOrderedProduct(const std::shared_ptr<Warehouse::ProductsSet>&) noexcept;

        // добавить заказанный продукт
        static void addAcceptedProductDelivery(const std::shared_ptr<Warehouse::ProductsSet>&) noexcept;

        // добавить проданное блюдо
        static void addSoldDish(const std::shared_ptr<Menu::Menu>&) noexcept;

        // сохранение логов
        static void save(const std::string_view&) noexcept;
        // загрузка логов
        static void load(const std::string_view&) noexcept;

        // вывод лога заказанных продуктов
        static void printOrderedProductsLog() noexcept;

        // вывод лога принятых заявок
        static void printAcceptedProductDeliveriesLog() noexcept;

        // вывод лога проданных блюд
        static void printSoldDishesLog() noexcept;

        static int getDishesSold() noexcept;

        static float getDishesSoldSum() noexcept;

        static float getMoneySpentOnProducts() noexcept;
    };
}

#endif //FINAL_PRACTICE_ACCOUNTANTLOG_H
