#pragma once
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "csv.hpp"
#include <span>
#include <string>
#include <iostream>

inline void write_csv(std::span<const Person*> people, std::ostream& out) {
    // Superset header
    out << "role,id,name,email,grad_year,office,courses,teaches\n";

    for (const auto* p : people) {
        std::string grad_year, office, courses, teaches;

        if (auto s = dynamic_cast<const Student*>(p)) {
            grad_year = std::to_string(s->to_json().at("grad_year").get<int>());
            courses = s->csv_row().substr(s->csv_row().find_last_of(',')+1); 
        }
        if (auto i = dynamic_cast<const Instructor*>(p)) {
            office = i->to_json().at("office").get<std::string>();
            teaches = i->csv_row().substr(i->csv_row().find_last_of(',')+1);
        }

        out << csv_escape(p->role()) << ","
            << p->id() << ","
            << csv_escape(p->name()) << ","
            << csv_escape(p->email()) << ","
            << grad_year << ","
            << csv_escape(office) << ","
            << csv_escape(courses) << ","
            << csv_escape(teaches)
            << "\n";
    }
}
