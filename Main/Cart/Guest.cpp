//
// Created by stuka on 21.06.2023.
//

#include "Guest.h"
#include <json.hpp>
#include <fstream>

void FinalPractice::Main::Cart::Guest::save(const std::string_view& path) noexcept
{
    // поток для записи в файл
    std::ofstream guestFStream(path.data());

    auto guest = nlohmann::json();

    int curDish = 0;

    guest["cart"]["dishesSize"] = m_cart->m_dishes.size();
    for(const auto& dish: m_cart->m_dishes)
    {
        guest["cart"]["dishes"][curDish]["name"] = dish.first;
        guest["cart"]["dishes"][curDish]["status"] = dish.second;

        curDish++;
    }

    guestFStream << guest.dump(4);
}

void FinalPractice::Main::Cart::Guest::load(const std::string_view& path) noexcept
{
    if(!std::filesystem::exists(path)) return;

    std::ifstream guestFStream(path.data());

    auto guest = nlohmann::json::parse(guestFStream);

    m_cart = std::make_shared<Cart>();

    int dishesSize = guest["cart"]["dishesSize"];
    for(int k = 0; k < dishesSize; k++)
    {
        m_cart->m_dishes.emplace(guest["cart"]["dishes"][k]["name"], guest["cart"]["dishes"][k]["status"]);
    }
}
