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

    auto persons = nlohmann::json();

    persons["personsNum"] = m_persons.size();

    int curPerson = 0;
    for(auto& m_person : m_persons)
    {
        persons["persons"][curPerson]["login"] = m_person->m_login;
        persons["persons"][curPerson]["password"] = m_person->m_password;

        persons["persons"][curPerson]["name"] = m_person->m_name;
        persons["persons"][curPerson]["surname"] = m_person->m_surname;
        persons["persons"][curPerson]["patronymic"] = m_person->m_patronymic;

        persons["persons"][curPerson]["personType"] = m_person->m_personType;

        curPerson++;
    }

    personsFStream << persons.dump(4);
}

void FinalPractice::Main::Persons::PersonsManager::load(const std::string_view& path)
{
    if(!std::filesystem::exists(path)) return;

    std::ifstream personsFStream(path.data());
    auto persons = nlohmann::json::parse(personsFStream);

    int personsNum = persons["personsNum"];

    for(int i = 0; i < personsNum; i++)
    {
        std::shared_ptr<Person> newPerson = std::make_shared<Person>();
        newPerson->m_login = persons["persons"][i]["login"];
        newPerson->m_password = persons["persons"][i]["password"];

        newPerson->m_name = persons["persons"][i]["name"];
        newPerson->m_surname = persons["persons"][i]["surname"];
        newPerson->m_patronymic = persons["persons"][i]["patronymic"];

        newPerson->m_personType = persons["persons"][i]["personType"];

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

std::list<std::shared_ptr<FinalPractice::Main::Persons::Person>>& FinalPractice::Main::Persons::PersonsManager::getPersons() noexcept
{
    return m_persons;
}
