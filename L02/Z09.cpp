#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct TempData
{
    std::string date;
    std::string time;
    double sound_speed_mps;
    double temp_sound;
    double air_pressure;
    double temp;
    double humidity;
    double compas;
    double uv_speed;
    double wind_speed_mps;
    double direction;
    double height;
    double room113_temp;
};
void print_temp_data(const std::vector<TempData>& data) {
    for (int i = 0; i < size(data); i++) {
        {std::cout << data[i].date
            << " \t" << data[i].time
            << " \t" << data[i].sound_speed_mps
            << " \t" << data[i].temp_sound
            << " \t" << data[i].air_pressure
            << " \t" << data[i].temp
            << " \t" << data[i].humidity
            << " \t" << data[i].compas
            << " \t" << data[i].uv_speed
            << " \t" << data[i].wind_speed_mps
            << " \t" << data[i].direction
            << " \t" << data[i].height
            << " \t" << data[i].room113_temp
            << std::endl;
        }
    }
}

void sort_temp(std::vector<TempData>& data) {
    bool change;
    do {
        change = false;
        for (int i = 0; i < data.size() - 1; i++) {
            if (data[i].temp > data[i + 1].temp) {
                TempData temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;
                change = true;
            }
        }
    } while (change == true);
}
int main()
{
    std::ifstream file("temp02-2020.csv");
    if (not file.good())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::vector<TempData> temp_data;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream line_stream(line);
        std::string date;
        std::getline(line_stream, date, ',');
        std::string time;
        std::getline(line_stream, time, ',');
        std::string buffer;
        std::getline(line_stream, buffer, ',');
        double sound_speed_mps = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double temp_sound = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double air_pressure = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double temp = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double humidity = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double compas = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double uv_speed = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double wind_speed_mps = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double direction = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double height = std::stod(buffer);
        std::getline(line_stream, buffer, ',');
        double room113_temp = std::stod(buffer);
        std::string table_id;
        std::getline(line_stream, table_id);

        TempData interim{ date,
                                    time,
                                    sound_speed_mps,
                                    temp_sound,
                                    air_pressure,
                                    temp,
                                    humidity,
                                    compas,
                                    uv_speed,
                                    wind_speed_mps,
                                    direction,
                                    height,
                                    room113_temp 
        };
        temp_data.emplace_back(interim);
    }

    sort_temp(temp_data);
    print_temp_data(temp_data);

    std::cout << "Highest temp: " << temp_data[temp_data.size() - 1].temp << std::endl;
    std::cout << "Lowest temp: " << temp_data[0].temp << std::endl;
    double median_temp;
    if (temp_data.size() % 2 == 0) {
        median_temp = (temp_data[temp_data.size() / 2].temp + temp_data[(temp_data.size() / 2) - 1].temp) / 2;
    }
    else {
        median_temp = temp_data[(temp_data.size() - 1) / 2].temp;
    }
    std::cout << "Median temp: " << median_temp << std::endl;
}