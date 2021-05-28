// Copyright (c) 2021 Caylee Annett All rights reserved
//
// Created by Caylee Annett
// Created on May 2021
// This program properly formats a mailing address and uses a default value

#include <iostream>
#include <string>
#include <algorithm>

std::string AddressFormatting(std::string name, std::string streetNumber,
                              std::string streetName, std::string city,
                              std::string province, std::string postalCode,
                              std::string apartmentNumber = "") {
    // This function formats the address
    std::string address;

    address = name + "\n";
    if (apartmentNumber.size() != 0) {
        address = address + apartmentNumber + "-";
    }
    address = address + streetNumber + " " + streetName + "\n"
        + city + " " + province + "  " + postalCode;

    return address;
}


main() {
    // This function gets the address informations
    std::string nameInput;
    std::string apartmentQuestionInput;
    std::string apartmentNumberInput = "";
    std::string streetNumberInput;
    std::string streetNameInput;
    std::string cityInput;
    std::string provinceInput;
    std::string postalCodeInput;
    std::string mailingAddress;

    // Input
    std::cout << "This program properly formats your mailing address."
        << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter your full name: ";
    getline(std::cin, nameInput);
    std::cout << "Do you live in an apartment (yes/no)?: ";
    getline(std::cin, apartmentQuestionInput);
    if (apartmentQuestionInput == "yes") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, apartmentNumberInput);
    }
    std::cout << "Enter your street number: ";
    getline(std::cin, streetNumberInput);
    std::cout << "Enter your street name and type: ";
    getline(std::cin, streetNameInput);
    std::cout << "Enter your city: ";
    getline(std::cin, cityInput);
    std::cout << "Enter the abbreviation of your province: ";
    getline(std::cin, provinceInput);
    std::cout << "Enter your postal code: ";
    getline(std::cin, postalCodeInput);

    // Call functions
    if (apartmentNumberInput != "") {
        mailingAddress = AddressFormatting(nameInput, streetNumberInput,
                                           streetNameInput, cityInput,
                                           provinceInput, postalCodeInput,
                                           apartmentNumberInput);
    } else {
        mailingAddress = AddressFormatting(nameInput, streetNumberInput,
                                           streetNameInput, cityInput,
                                           provinceInput, postalCodeInput);
    }


    // Output
    std::cout << "" << std::endl;
    std::cout << "Your mailing address is:" << std::endl;
    std::cout << "" << std::endl;
    std::transform(mailingAddress.begin(), mailingAddress.end(),
                   mailingAddress.begin(), ::toupper);
    std::cout << mailingAddress << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Done." << std::endl;
}
