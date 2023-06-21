#include "WindowsManager.h"

#include "Auth/ChooseAuthWindow.h"
#include "Auth/LoginWindow.h"
#include "Auth/RegistrationWindow.h"

#include "Guest/MainWindow.h"

#include "SysAdmin/MainWindow.h"
#include "SysAdmin/ChoosePersonWindow.h"
#include "SysAdmin/EditPersonWindow.h"

#include "SysAdmin/ChooseProductWindow.h"
#include "SysAdmin/EditProductWindow.h"

#include "SysAdmin/ChooseMenuWindow.h"
#include "SysAdmin/EditMenuWindow.h"

#include "Warehouse/MainWindow.h"
#include "Warehouse/ProductsOrderWindow.h"
#include "Warehouse/ProductsViewWindow.h"

#include "Provider/MainWindow.h"

#include "Accountant/MainWindow.h"

#include "Cook/MainWindow.h"

#include "Waiter/MainWindow.h"

void FinalPractice::Main::Windows::WindowsManager::init() noexcept
{
    m_windows.emplace(CHOOSE_AUTH_WND_NAME, std::make_shared<Windows::Auth::ChooseAuthWindow>());
    m_windows.emplace(LOGIN_WND_NAME, std::make_shared<Windows::Auth::LoginWindow>());
    m_windows.emplace(REGISTRATION_WND_NAME, std::make_shared<Windows::Auth::RegistrationWindow>());

    // guest
    m_windows.emplace(GUEST_MAIN_WND_NAME, std::make_shared<Windows::Guest::MainWindow>());
    // -----------------

    // sys admin
    m_windows.emplace(SYS_ADMIN_MAIN_WND_NAME, std::make_shared<Windows::SysAdmin::MainWindow>());
    m_windows.emplace(SYS_ADMIN_CHOOSE_PERSON_WND_NAME, std::make_shared<Windows::SysAdmin::ChoosePersonWindow>());
    m_windows.emplace(SYS_ADMIN_EDIT_PERSON_WND_NAME, std::make_shared<Windows::SysAdmin::EditPersonWindow>());

    m_windows.emplace(SYS_ADMIN_CHOOSE_PRODUCT_WND_NAME, std::make_shared<Windows::SysAdmin::ChooseProductWindow>());
    m_windows.emplace(SYS_ADMIN_EDIT_PRODUCT_WND_NAME, std::make_shared<Windows::SysAdmin::EditProductWindow>());

    m_windows.emplace(SYS_ADMIN_CHOOSE_MENU_WND_NAME, std::make_shared<Windows::SysAdmin::ChooseMenuWindow>());
    m_windows.emplace(SYS_ADMIN_EDIT_MENU_WND_NAME, std::make_shared<Windows::SysAdmin::EditMenuWindow>());
    // -----------------

    // warehouse
    m_windows.emplace(WAREHOUSE_MAIN_WND_NAME, std::make_shared<Windows::Warehouse::MainWindow>());
    m_windows.emplace(WAREHOUSE_PRODUCTS_ORDER_WND_NAME, std::make_shared<Windows::Warehouse::ProductsOrderWindow>());
    m_windows.emplace(WAREHOUSE_PRODUCTS_VIEW_WND_NAME, std::make_shared<Windows::Warehouse::ProductsViewWindow>());
    // -----------------

    // provider
    m_windows.emplace(PROVIDER_MAIN_WND_NAME, std::make_shared<Windows::Provider::MainWindow>());
    // -----------------

    // accountant
    m_windows.emplace(ACCOUNTANT_MAIN_WND_NAME, std::make_shared<Windows::Accountant::MainWindow>());
    // -----------------

    // cook
    m_windows.emplace(COOK_MAIN_WND_NAME, std::make_shared<Windows::Cook::MainWindow>());
    // -----------------

    // waiter
    m_windows.emplace(WAITER_MAIN_WND_NAME, std::make_shared<Windows::Waiter::MainWindow>());
    // -----------------

    setCurrentWindow(getWindow(CHOOSE_AUTH_WND_NAME));
}

void FinalPractice::Main::Windows::WindowsManager::setCurrentWindow(const std::shared_ptr<IWindow>& newWindow)
{
    m_lastWindow = m_currentWindow;
    m_currentWindow = newWindow;
}

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::WindowsManager::getLastWindow() noexcept
{
    return m_lastWindow;
}

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::WindowsManager::getCurrentWindow() noexcept
{
    return m_currentWindow;
}

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::WindowsManager::getWindow(const std::string& windowName) noexcept
{
    return m_windows[windowName];
}
