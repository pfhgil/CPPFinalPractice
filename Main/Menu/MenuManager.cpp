//
// Created by stuka on 19.06.2023.
//

#include "MenuManager.h"
#include "Product/ProductsManager.h"

#include "json.hpp"
#include "fstream"

std::shared_ptr<FinalPractice::Main::Menu::Menu> FinalPractice::Main::Menu::MenuManager::createMenu() noexcept
{
    std::shared_ptr<Menu> newMenu = std::make_shared<Menu>();

    m_menus.push_back(newMenu);

    return newMenu;
}

std::shared_ptr<FinalPractice::Main::Menu::Menu> FinalPractice::Main::Menu::MenuManager::getMenu(const std::string& name) noexcept
{
    return *std::find_if(m_menus.begin(), m_menus.end(), [&](const std::shared_ptr<Menu>& menu)
    { return menu->m_name == name; });
}

bool FinalPractice::Main::Menu::MenuManager::isMenuExists(const std::string& name) noexcept
{
    return std::find_if(m_menus.begin(), m_menus.end(), [&](const std::shared_ptr<Menu>& menu)
    { return menu->m_name == name; }) != m_menus.end();
}

void FinalPractice::Main::Menu::MenuManager::removeMenu(const std::string& name) noexcept
{
    m_menus.remove_if([&](const std::shared_ptr<Menu>& menu){ return menu->m_name == name; });
}

std::list<std::shared_ptr<FinalPractice::Main::Menu::Menu>>& FinalPractice::Main::Menu::MenuManager::getMenus() noexcept
{
    return m_menus;
}

void FinalPractice::Main::Menu::MenuManager::save(const std::string_view& path)
{
    std::ofstream menusFStream(path.data());

    auto menus = nlohmann::json();
    menus["menusNum"] = m_menus.size();

    int currentMenu = 0;
    int currentProduct;
    for(const auto& menu : m_menus)
    {
        currentProduct = 0;
        menus["menus"][currentMenu]["productsNum"] = menu->getProducts().size();
        for(const auto& product : menu->getProducts())
        {
            menus["menus"][currentMenu]["products"][currentProduct]["id"] = product->m_id;

            currentProduct++;
        }

        menus["menus"][currentMenu]["name"] = menu->m_name;
        menus["menus"][currentMenu]["gram"] = menu->m_gram;
        menus["menus"][currentMenu]["description"] = menu->m_description;
        menus["menus"][currentMenu]["cookingTimeSeconds"] = menu->m_cookingTimeSeconds;
        menus["menus"][currentMenu]["cost"] = menu->m_cost;

        currentMenu++;
    }

    menusFStream << menus.dump(4);
}

void FinalPractice::Main::Menu::MenuManager::load(const std::string_view& path)
{
    if(!std::filesystem::exists(path)) return;

    std::ifstream menusFStream(path.data());

    auto menus = nlohmann::json::parse(menusFStream);

    int menusNum = menus["menusNum"];

    for(int i = 0; i < menusNum; i++)
    {
        std::shared_ptr<Menu> newMenu = createMenu();

        int productsNum = menus["menus"][i]["productsNum"];

        for(int k = 0; k < productsNum; k++)
        {
            newMenu->getProducts().push_back(Product::ProductsManager::getProduct(menus["menus"][i]["products"][k]["id"]));
        }

        newMenu->m_name = menus["menus"][i]["name"];
        newMenu->m_gram = menus["menus"][i]["gram"];
        newMenu->m_description = menus["menus"][i]["description"];
        newMenu->m_cookingTimeSeconds = menus["menus"][i]["cookingTimeSeconds"];
        newMenu->m_cost = menus["menus"][i]["cost"];
    }
}
