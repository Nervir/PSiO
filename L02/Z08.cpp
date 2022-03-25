#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct ExchangeRate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};

void print_exchange_rates(const std::vector<ExchangeRate>& exchange_rates) {
    for (int i = 0; i < size(exchange_rates); i++) {
        {std::cout << exchange_rates[i].date
            << ", " << exchange_rates[i].usd
            << ", " << exchange_rates[i].eur
            << ", " << exchange_rates[i].table_id
            << std::endl;
        }
    }
}

void sort_usd(std::vector<ExchangeRate>& exchange_rates) {
    bool change;
    do {
        change = false;
        for (int i = 0; i < exchange_rates.size() - 1; i++) {
            if (exchange_rates[i].usd > exchange_rates[i + 1].usd) {
                ExchangeRate temp = exchange_rates[i + 1];
                exchange_rates[i + 1] = exchange_rates[i];
                exchange_rates[i] = temp;
                change = true;
            }
        }
    } while (change == true);
}

void sort_eur(std::vector<ExchangeRate>& exchange_rates) {
    bool change;
    do {
        change = false;
        for (int i = 0; i < exchange_rates.size() - 1; i++) {
            if (exchange_rates[i].eur > exchange_rates[i + 1].eur) {
                ExchangeRate temp = exchange_rates[i + 1];
                exchange_rates[i + 1] = exchange_rates[i];
                exchange_rates[i] = temp;
                change = true;
            }
        }
    } while (change == true);
}

int binary_search_usd(const double& number, std::vector<ExchangeRate>& exchange_rates) {
    int list_start = 0;
    int list_end = exchange_rates.size() - 1;
    while (list_start <= list_end) {
        int index = list_start + ((list_end - list_start) / 2);
        if (number == exchange_rates[index].usd) {
            return index;
        }
        else if (number < exchange_rates[index].usd) {
            list_end = index - 1;
        }
        else if (number > exchange_rates[index].usd) {
            list_start = index + 1;
        }
    }
    return -1;
}

int main()
{
    std::ifstream file("kursy_usd_eur.csv");
    if (not file.good())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<ExchangeRate> exchange_rates;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream line_stream(line);
        std::string date;
        std::getline(line_stream, date, ',');
        std::string buffer;
        std::getline(line_stream, buffer, ',');
        double usd = std::stod(buffer);

        std::getline(line_stream, buffer, ',');
        double eur = std::stod(buffer);

        std::string table_id;
        std::getline(line_stream, table_id);

        ExchangeRate exchange_rate{ date, usd, eur, table_id };
        exchange_rates.emplace_back(exchange_rate);
    }

    sort_usd(exchange_rates);

    for (int i = 0; i < 10; i++) {
        std::cout << exchange_rates[i].date << exchange_rates[i].usd << std::endl;
    }
    std::cout << std::endl;

    std::cout << binary_search_usd(3.9011, exchange_rates) << std::endl << std::endl;

    sort_eur(exchange_rates);

    for (int i = exchange_rates.size() - 1; i > exchange_rates.size() - 11; i--) {
        std::cout << exchange_rates[i].date << exchange_rates[i].usd << std::endl;
    }

    
}