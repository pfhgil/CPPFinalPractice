#pragma once

#ifndef FINAL_PRACTICE_MENUMANAGER_H
#define FINAL_PRACTICE_MENUMANAGER_H

#include "Menu.h"

namespace FinalPractice::Main::Menu
{
    class MenuManager
    {
    private:
        static inline std::list<std::shared_ptr<Menu>> m_menus;

    public:
        static std::shared_ptr<Menu> createMenu() noexcept;

        static void save(const std::string_view&);
        static void load(const std::string_view&);

        static std::shared_ptr<Menu> getMenu(const std::string& name) noexcept;
        static void removeMenu(const std::string& name) noexcept;
        static bool isMenuExists(const std::string& name) noexcept;

        static std::list<std::shared_ptr<Menu>> getMenus() noexcept;
    };
}

#endif //FINAL_PRACTICE_MENUMANAGER_H
