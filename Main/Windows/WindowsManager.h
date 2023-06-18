#pragma once

#ifndef FINAL_PRACTICE_WINDOWSMANAGER_H
#define FINAL_PRACTICE_WINDOWSMANAGER_H

#define CHOOSE_AUTH_WND_NAME "ChooseAuthWindow"
#define LOGIN_WND_NAME "LoginWindow"
#define REGISTRATION_WND_NAME "RegistrationWindow"

#define GUEST_MAIN_WND_NAME "Guest/MainWindow"

#define SYS_ADMIN_MAIN_WND_NAME "SysAdmin/MainWindow"
#define SYS_ADMIN_CHOOSE_PERSON_WND_NAME "SysAdmin/ChoosePersonWindow"
#define SYS_ADMIN_EDIT_PERSON_WND_NAME "SysAdmin/EditPersonWindow"

#define SYS_ADMIN_CHOOSE_PRODUCT_WND_NAME "SysAdmin/ChooseProductWindow"
#define SYS_ADMIN_EDIT_PRODUCT_WND_NAME "SysAdmin/EditProductWindow"

#include <map>
#include <string>

#include "IWindow.h"

namespace FinalPractice::Main::Windows
{
    class IWindow;

    class WindowsManager
    {
    private:
        static inline std::map<std::string, std::shared_ptr<IWindow>> m_windows;
        static inline std::shared_ptr<IWindow> m_lastWindow = nullptr;
        static inline std::shared_ptr<IWindow> m_currentWindow = nullptr;

    public:
        static void init() noexcept;

        static void setCurrentWindow(const std::shared_ptr<IWindow>&);

        static std::shared_ptr<IWindow> getLastWindow() noexcept;
        static std::shared_ptr<IWindow> getCurrentWindow() noexcept;
        static std::shared_ptr<IWindow> getWindow(const std::string& windowName) noexcept;
    };
}

#endif //FINAL_PRACTICE_WINDOWSMANAGER_H
