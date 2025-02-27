#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Args must be 4 , file_name and s1 , s2\n";
        return (1);
    }

    std::string file_name, file_replace, s1, s2, line;
    
    file_name = av[1] , s1 = av[2] , s2 = av[3];

    file_replace = file_name + ".replace";

    std::ifstream source(file_name.c_str() , std::ios::in);
    if (!source)
    {
        std::cerr << "Error on open input file stream" << std::endl;
        return (2);
    }

    std::ofstream dest(file_replace.c_str() , std::ios::out);
    if (!dest)
    {
        std::cerr << "Error on open output file stream" << std::endl;
        return (2);
    }
    
    while (getline(source, line))
    {
        size_t pos = line.find(s1);
        if (pos != std::string::npos)
        {
            line.erase(pos, s1.size());
            line.insert(pos, s2);
        }
        dest << line;
        if (!source.eof())
            dest << std::endl;
    }
    source.close();
    dest.close();
}