//
// Created by stuka on 13.06.2023.
//

#ifndef FINAL_PRACTICE_PERSONSMANAGER_H
#define FINAL_PRACTICE_PERSONSMANAGER_H

#include <list>

#include "Person.h"

namespace FinalPractice::Main::Persons
{
    class Person;

    class PersonsManager
    {
    private:
        static inline std::list<std::shared_ptr<Person>> m_persons;

    public:
        static inline std::shared_ptr<Person> m_currentPerson;

        template<typename PersonT>
        requires(std::is_base_of_v<Person, PersonT>)
        static std::shared_ptr<PersonT> createPerson()
        {
            std::shared_ptr<PersonT> newPerson = std::make_shared<Person>();
            m_persons.push_back(newPerson);
            return newPerson;
        }

        static void save(const std::string_view&);
        static void load(const std::string_view&);

        static std::shared_ptr<Person> getPerson(const std::string&);

        static std::list<std::shared_ptr<Person>> getPersons() noexcept;
    };
}


#endif //FINAL_PRACTICE_PERSONSMANAGER_H
