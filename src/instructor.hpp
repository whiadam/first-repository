#pragma once
#include "person.hpp"
#include "csv.hpp"
#include <vector>
#include <nlohmann/json.hpp>
#include "exceptions.hpp"

class Instructor : public Person {
    std::string office_;
    std::vector<std::string> teaches_;
public:
    Instructor(int id, std::string name, std::string email,
               std::string office, std::vector<std::string> teaches = {})
        : Person(id, std::move(name), std::move(email)),
          office_(std::move(office)), teaches_(std::move(teaches)) {
        if (office_.empty()) throw ValidationError("office is required");
    }

    std::string role() const override { return "Instructor"; }

    // JSON
    nlohmann::json to_json() const override {
        return {
            {"role", role()},
            {"id", id_},
            {"name", name_},
            {"email", email_},
            {"office", office_},
            {"teaches", teaches_}
        };
    }

    // YAML
    YAML::Node to_yaml() const override {
        YAML::Node n;
        n["role"] = role();
        n["id"] = id_;
        n["name"] = name_;
        n["email"] = email_;
        n["office"] = office_;
        for (const auto& c : teaches_) n["teaches"].push_back(c);
        return n;
    }

    // CSV
    std::string csv_header() const override {
        return "role,id,name,email,office,teaches";
    }

    std::string csv_row() const override {
        std::string joined;
        for (size_t i = 0; i < teaches_.size(); ++i) {
            if (i) joined += ';';
            joined += teaches_[i];
        }
        return csv_escape(role()) + "," + std::to_string(id_) + "," +
               csv_escape(name_) + "," + csv_escape(email_) + "," +
               csv_escape(office_) + "," + csv_escape(joined);
    }

    // --- ROUND-TRIP JSON PARSING ---
    static Instructor from_json(const nlohmann::json& j) {
        if (!j.contains("id") || !j.contains("name") || !j.contains("email") || !j.contains("office"))
            throw ValidationError("Missing field in Instructor JSON");

        std::vector<std::string> teaches;
        if (j.contains("teaches"))
            teaches = j.at("teaches").get<std::vector<std::string>>();

        return Instructor(j.at("id").get<int>(),
                          j.at("name").get<std::string>(),
                          j.at("email").get<std::string>(),
                          j.at("office").get<std::string>(),
                          teaches);
    }
};
