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

std::list<std::shared_ptr<FinalPractice::Main::Menu::Menu>> FinalPractice::Main::Menu::MenuManager::getMenus() noexcept
{
    return m_menus;
}

void FinalPractice::Main::Menu::MenuManager::save(const std::string_view& path)
{
    std::ofstream menusFStream(path.data());

    auto menus = nlohmann::json::array();
    menus[0]["menusNum"] = m_menus.size();

    int currentMenu = 1;
    int currentProduct;
    for(const auto& menu : m_menus)
    {
        currentProduct = 0;
        menus[currentMenu]["productsNum"] = menu->getProducts().size();
        for(const auto& product : menu->getProducts())
        {
            menus[currentMenu][currentProduct]["id"] = product->m_id;
            menus[currentMenu][currentProduct]["name"] = product->m_name;
            menus[currentMenu][currentProduct]["cost"] = product->m_cost;

            currentProduct++;
        }

        menus[currentMenu]["name"] = menu->m_name;
        menus[currentMenu]["gram"] = menu->m_gram;
        menus[currentMenu]["description"] = menu->m_description;
        menus[currentMenu]["cookingTimeSeconds"] = menu->m_cookingTimeSeconds;
        menus[currentMenu]["cost"] = menu->m_cost;

        currentMenu++;
    }

    menusFStream << menus.dump(4);
}

void FinalPractice::Main::Menu::MenuManager::load(const std::string_view& path)
{
    if(!std::filesystem::exists(path)) return;

    std::ifstream menusFStream(path.data());

    auto menus = nlohmann::json::parse(menusFStream);

    int menusNum = menus[0]["menusNum"];

    for(int i = 1; i < menusNum + 1; i++)
    {
        std::shared_ptr<Menu> newMenu = createMenu();

        int productsNum = menus[i]["productsNum"];

        std::shared_ptr<Product::Product> newProduct = Product::ProductsManager::createProduct();

        for(int k = 0; k < productsNum; k++)
        {
            newProduct->m_id = menus[i][k]["id"];
            newProduct->m_name = menus[i][k]["name"];
            newProduct->m_cost = menus[i][k]["cost"];
        }

        newMenu->m_name = menus[i]["name"];
        newMenu->m_gram = menus[i]["gram"];
        newMenu->m_description = menus[i]["description"];
        newMenu->m_cookingTimeSeconds = menus[i]["cookingTimeSeconds"];
        newMenu->m_cost = menus[i]["cost"];
    }
}
