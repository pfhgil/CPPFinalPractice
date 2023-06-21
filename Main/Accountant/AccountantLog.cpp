//
// Created by stuka on 21.06.2023.
//

#include <json.hpp>
#include <fstream>

#include "AccountantLog.h"

void FinalPractice::Main::Accountant::AccountantLog::addOrderedProduct(const std::shared_ptr<Warehouse::ProductsSet>& productsSet) noexcept
{
    m_orderedProductsLog.push_back(
            "ID: " + std::to_string(productsSet->m_product->m_id) + ", название: " + productsSet->m_product->m_name + ", стоимость (шт.): " +
            std::to_string(productsSet->m_product->m_cost) + ", кол-во: " + std::to_string(productsSet->m_count)
            );

    m_moneySpentOnProducts += productsSet->m_product->m_cost * (float) productsSet->m_count;

    save("accountant_log.txt");
}

void FinalPractice::Main::Accountant::AccountantLog::addAcceptedProductDelivery(
        const std::shared_ptr<Warehouse::ProductsSet>& productsSet) noexcept
{
    m_acceptedProductDeliveriesLog.push_back(
            "ID: " + std::to_string(productsSet->m_product->m_id) + ", название: " + productsSet->m_product->m_name + ", стоимость (шт.): " +
            std::to_string(productsSet->m_product->m_cost) + ", кол-во: " + std::to_string(productsSet->m_count)
    );

    save("accountant_log.txt");
}

void FinalPractice::Main::Accountant::AccountantLog::addSoldDish(const std::shared_ptr<Menu::Menu>& dish) noexcept
{
    m_soldDishesLog.push_back(
            "Название: " + dish->m_name + ", граммовка: " + std::to_string(dish->m_gram) + ", описание: " + dish->m_description +
            ", время приготовления: " + std::to_string(dish->m_cookingTimeSeconds) + ", стоимость: " + std::to_string(dish->m_cost)
            );

    m_dishesSold++;

    m_dishesSoldSum += dish->m_cost;

    save("accountant_log.txt");
}

void FinalPractice::Main::Accountant::AccountantLog::save(const std::string_view& path) noexcept
{
    // поток для записи в файл
    std::ofstream accountantFStream(path.data());

    auto accountant = nlohmann::json();

    // сохранение размеров листов
    accountant["orderedProductsLogSize"] = m_orderedProductsLog.size();
    accountant["acceptedProductDeliveriesLogSize"] = m_acceptedProductDeliveriesLog.size();
    accountant["soldDishesLogSize"] = m_soldDishesLog.size();

    // сохранение других полей
    accountant["dishesSold"] = m_dishesSold;
    accountant["dishesSoldSum"] = m_dishesSoldSum;
    accountant["moneySpentOnProducts"] = m_moneySpentOnProducts;

    // сохранение логов

    int cur = 0;
    for(const auto& str : m_orderedProductsLog)
    {
        accountant["orderedProductsLog"][cur] = str;
        cur++;
    }

    cur = 0;
    for(const auto& str : m_acceptedProductDeliveriesLog)
    {
        accountant["acceptedProductDeliveriesLog"][cur] = str;
        cur++;
    }

    cur = 0;
    for(const auto& str : m_soldDishesLog)
    {
        accountant["soldDishesLog"][cur] = str;
        cur++;
    }

    // записываем в файл
    accountantFStream << accountant.dump(4);
}

void FinalPractice::Main::Accountant::AccountantLog::load(const std::string_view& path) noexcept
{
    // если пути не существует, то ничего не делаем
    if(!std::filesystem::exists(path)) return;

    // поток для чтения из файла
    std::ifstream accountantFStream(path.data());

    auto accountant = nlohmann::json::parse(accountantFStream);

    // загрузка размеров листов
    int orderedProductsLogSize = accountant["orderedProductsLogSize"];
    int acceptedProductDeliveriesLog = accountant["acceptedProductDeliveriesLogSize"];
    int soldDishesLog = accountant["soldDishesLogSize"];

    m_dishesSold = accountant["dishesSold"];
    m_dishesSoldSum = accountant["dishesSoldSum"];
    m_moneySpentOnProducts = accountant["moneySpentOnProducts"];

    // загрузка логов
    for(int i = 0; i < orderedProductsLogSize; i++)
    {
        m_orderedProductsLog.push_back(accountant["orderedProductsLog"][i]);
    }

    for(int i = 0; i < acceptedProductDeliveriesLog; i++)
    {
        m_acceptedProductDeliveriesLog.push_back(accountant["acceptedProductDeliveriesLog"][i]);
    }

    for(int i = 0; i < soldDishesLog; i++)
    {
        m_soldDishesLog.push_back(accountant["soldDishesLog"][i]);
    }
}

int FinalPractice::Main::Accountant::AccountantLog::getDishesSold() noexcept
{
    return m_dishesSold;
}

float FinalPractice::Main::Accountant::AccountantLog::getDishesSoldSum() noexcept
{
    return m_dishesSoldSum;
}

float FinalPractice::Main::Accountant::AccountantLog::getMoneySpentOnProducts() noexcept
{
    return m_moneySpentOnProducts;
}

void FinalPractice::Main::Accountant::AccountantLog::printOrderedProductsLog() noexcept
{
    int cur = 1;
    for(const auto& str : m_orderedProductsLog)
    {
        std::cout << std::to_string(cur) << ") " << str << std::endl;
    }
}

void FinalPractice::Main::Accountant::AccountantLog::printAcceptedProductDeliveriesLog() noexcept
{
    int cur = 1;
    for(const auto& str : m_acceptedProductDeliveriesLog)
    {
        std::cout << std::to_string(cur) << ") " << str << std::endl;
    }
}

void FinalPractice::Main::Accountant::AccountantLog::printSoldDishesLog() noexcept
{
    int cur = 1;
    for(const auto& str : m_soldDishesLog)
    {
        std::cout << std::to_string(cur) << ") " << str << std::endl;
    }
}
