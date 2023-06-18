//
// Created by stuka on 13.06.2023.
//

#include "Person.h"

#include <json.hpp>
#include <fstream>

void FinalPractice::Main::Persons::Person::save(const std::string_view& path)
{
    std::ofstream oFileStream(path.data());

    nlohmann::json j;
    j["name"] = m_login;
    j["password"] = m_password;

    oFileStream << j.dump(4);
}

void FinalPractice::Main::Persons::Person::load(const std::string_view& path)
{
    nlohmann::json j = nlohmann::json::parse(std::ifstream(path.data()));

    std::cout << "user: " << j << std::endl;

    m_login = j["name"];
    m_password = j["password"];
}
