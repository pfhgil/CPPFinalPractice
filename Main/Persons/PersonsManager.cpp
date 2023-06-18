//
// Created by stuka on 13.06.2023.
//

#include "PersonsManager.h"
#include "SysAdmin.h"
#include "json.hpp"
#include "fstream"
#include <list>

void FinalPractice::Main::Persons::PersonsManager::save(const std::string_view& path)
{
    std::ofstream personsFStream(path.data());

    auto persons = nlohmann::json::array();

    persons[0]["personsNum"] = m_persons.size();

    int cur = 1;
    for(auto& m_person : m_persons)
    {
        persons[cur]["login"] = m_person->m_login;
        persons[cur]["password"] = m_person->m_password;

        persons[cur]["name"] = m_person->m_name;
        persons[cur]["surname"] = m_person->m_surname;
        persons[cur]["patronymic"] = m_person->m_patronymic;

        persons[cur]["personType"] = m_person->m_personType;

        cur++;
    }

    personsFStream << persons.dump(4);
}

void FinalPractice::Main::Persons::PersonsManager::load(const std::string_view& path)
{
    if(!std::filesystem::exists(path)) return;

    std::ifstream personsFStream(path.data());
    auto persons = nlohmann::json::parse(personsFStream);

    int personsNum = persons[0]["personsNum"];

    for(int i = 1; i < personsNum + 1; i++)
    {
        std::shared_ptr<Person> newPerson = std::make_shared<Person>();
        newPerson->m_login = persons[i]["login"];
        newPerson->m_password = persons[i]["password"];

        newPerson->m_name = persons[i]["name"];
        newPerson->m_surname = persons[i]["surname"];
        newPerson->m_patronymic = persons[i]["patronymic"];

        newPerson->m_personType = persons[i]["personType"];

        m_persons.push_back(newPerson);
    }
}

std::shared_ptr<FinalPractice::Main::Persons::Person> FinalPractice::Main::Persons::PersonsManager::getPerson(const std::string& name)
{
    for(auto& person : m_persons)
    {
        if(name == person->m_login)
        {
            return person;
        }
    }

    return nullptr;
}

std::list<std::shared_ptr<FinalPractice::Main::Persons::Person>> FinalPractice::Main::Persons::PersonsManager::getPersons() noexcept
{
    return m_persons;
}
