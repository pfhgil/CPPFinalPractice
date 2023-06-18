//
// Created by stuka on 08.06.2023.
//

#include "MainWindow.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Guest::MainWindow::show()
{
    std::cout << "guest main window" << std::endl;
    return WindowsManager::getWindow(LOGIN_WND_NAME);
}
