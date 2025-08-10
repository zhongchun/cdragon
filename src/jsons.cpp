#include "jsons.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

void test_json() {
  std::cout << "Testing json..." << std::endl;
  // 1. Create a json object
  json j_obj;
  j_obj["name"] = "Alice";
  j_obj["age"] = 30;
  j_obj["is_student"] = false;
  j_obj["height"] = 1.75;
  j_obj["null_value"] = nullptr;

  // 2. Create a nested json object
  json address;
  address["city"] = "Beijing";
  address["zipcode"] = "100000";

  json phone_numbers = json::array();
  phone_numbers.push_back("123-3456-0000");
  phone_numbers.push_back("272-9999-0000");

  j_obj["address"] = address;
  j_obj["phone_numbers"] = phone_numbers;

  // 3. Serialization
  std::string json_str = j_obj.dump(4);
  std::cout << "Serialization result: \n" << json_str << std::endl;

  // 4. Deserialization
  std::string input_str = R"(
    {
      "name": "Bob",
      "age": 25,
      "hobbies": ["reading", "coding"]
    }
  )";
  try {
    json j_input = json::parse(input_str);
    std::cout << "Deserialization result: \n" << j_input.dump(4) << std::endl;
  } catch (const json::parse_error& e) {
    std::cerr << "Failed to parse: " << e.what() << std::endl;
    return;
  }

  // 5. Access and modify json data
  std::string name = j_obj["name"].get<std::string>();
  int age = j_obj["age"].get<int>();
  bool is_student = j_obj["is_student"].get<bool>();
  std::cout << "Name: " << name << ", age: " << age
            << ", is student: " << (is_student ? "yes" : "no") << std::endl;

  j_obj["age"] = 31;
  j_obj["is_student"] = true;

  std::string city = j_obj["address"]["city"].get<std::string>();
  std::cout << "City: " << city << std::endl;

  std::string first_phone = j_obj["phone_numbers"][0].get<std::string>();
  std::cout << "First phone: " << first_phone << std::endl;

  j_obj["phone_numbers"].push_back("333-4444-0000");

  std::string json_str_modified = j_obj.dump(4);
  std::cout << "Serialization Modified: " << json_str_modified << std::endl;
}
