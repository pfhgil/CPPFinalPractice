#pragma once

#ifndef FINAL_PRACTICE_PERSONTYPE_H
#define FINAL_PRACTICE_PERSONTYPE_H

namespace FinalPractice::Main::Persons
{
    enum PersonType
    {
        PT_GUEST, // гость (посетитель)
        PT_SYS_ADMIN, // системный администратор
        PT_WAREHOUSE, // складской
        PT_PROVIDER, // поставщик
        PT_ACCOUNTANT, // бухгалтер
        PT_COOK, // повар
        PT_WAITER // официант
    };
}

#endif //FINAL_PRACTICE_PERSONTYPE_H
