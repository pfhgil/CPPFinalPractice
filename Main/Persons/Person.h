#pragma once

#ifndef FINAL_PRACTICE_PERSON_H
#define FINAL_PRACTICE_PERSON_H

#include <iostream>
#include <memory>
#include "PersonsManager.h"
#include "PersonType.h"

namespace FinalPractice::Main::Persons
{
    class PersonsManager;

    class Person : public std::enable_shared_from_this<Person>
    {
    public:
        std::string m_login;
        std::string m_password;

        std::string m_name;
        std::string m_surname;
        std::string m_patronymic;

        PersonType m_personType = PersonType::PT_GUEST;

        virtual void save(const std::string_view&);
        virtual void load(const std::string_view&);
    };
}

#endif //FINAL_PRACTICE_PERSON_H
