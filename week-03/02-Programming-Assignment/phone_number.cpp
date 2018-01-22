//
// Created by avtomato on 1/8/18.
//

#include <sstream>
#include <phone_number.h>


PhoneNumber::PhoneNumber(const string &international_number) {
    stringstream phone_stream(international_number);
    string country_code, city_code, local_number;
    if (phone_stream) {
        getline(phone_stream, country_code, '-');
        getline(phone_stream, city_code, '-');
        getline(phone_stream, local_number, '\n');
    }
    if (country_code[0] != '+' || country_code.size() < 2) {
        throw invalid_argument("");
    }
    string tmp;
    for (int i = 1; i < country_code.size(); ++i) {
        tmp += country_code[i];
    }
    country_code_ = tmp;
    if (city_code.empty()) {
        throw invalid_argument("");
    }
    city_code_ = city_code;
    if (local_number.empty()) {
        throw invalid_argument("");
    }
    local_number_ = local_number;
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_+ "-" + city_code_ + "-" + local_number_;
}