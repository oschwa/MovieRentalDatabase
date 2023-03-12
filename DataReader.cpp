#ifndef DATAREADER_CPP
#define DATAREADER_CPP

#include "DataReader.h"

DataReader::DataReader()
{

}

void DataReader::read_customer_file(std::ifstream &in_file)
{
    std::string line;
    while (getline(in_file, line))
    {
        //string stream is used to obtain information from line. 
        std::stringstream ss(line);
        
        std::string cust_id;
        ss >> cust_id;

        std::cout << "Customer id: " << cust_id << std::endl;
        
        std::string cust_lname;
        ss >> cust_lname;

        std::cout << "Customer last name: " << cust_lname << std::endl;

        std::string cust_fname;
        ss >> cust_fname;

        std::cout << "Customer first name: " << cust_fname << std::endl;

        //Customer is created in Inventory.
    }
    in_file.close();
}

void DataReader::read_movie_file(std::ifstream &in_file)
{
    std::string line;
    while (getline(in_file, line))
    {
        //movie type is acquired, determines movie subclass object.
        char movie_type = line[0];

        if (movie_type == 'C')
        {
            std::cout << "getline found this: " << line << std::endl; 
            //first, the stock is found.
            std::string stock = "";

            int i = 3;
            while (i <= line.size() && line[i] != ',')
            {
                stock += line[i];
                ++i;
            }

            //stock is converted into integer.
            int int_stock = std::stoi(stock);
            i += 2;

            //next the actor data is found.
            std::string direct_f_name = "";
            std::string direct_l_name = "";

            while (i <= line.size() && line[i] != ' ')
            {  
                direct_f_name += line[i];
                ++i;
            }
            
            ++i;

            while (i <= line.size() && line[i] != ',')
            {  
                direct_l_name += line[i];
                ++i;
            }

            i += 2;

            //Movie title is found.
            std::string title = "";

            while (i <= line.size() && line[i] != ',')
            {
                title += line[i];
                ++i;
            }

            i += 2;

            //Actor first and last name.
            std::string actor_f_name = "";
            std::string actor_l_name = "";

            while (i <= line.size() && line[i] != ' ')
            {  
                actor_f_name += line[i];
                ++i;
            }
            
            ++i;

            while (i <= line.size() && line[i] != ' ')
            {  
                actor_l_name += line[i];
                ++i;
            }

            ++i;

            //Month of release
            std::string month = "";

            while (i <= line.size() && line[i] != ' ')
            {
                month+=line[i];
                ++i;
            }

            int int_month = std::stoi(month);
            
            ++i;
            //year of release
            std::string year = "";
            int int_year;
            while (i <= line.size())
            {  
                year += line[i];
                ++i;
            }

            int_year = std::stoi(year);

            std::cout << "What the algorithm read: " << int_stock << " " << direct_f_name << " "
                << direct_l_name << " " << title << " " << actor_f_name << " " << actor_l_name << " "
                    << int_month << " " << int_year << std::endl;
        }

        else if (movie_type == 'D')
        {
            std::cout << "getline found this: " << line << std::endl; 
            //first, the stock is found.
            std::string stock = "";

            int i = 3;
            while (i <= line.size() && line[i] != ',')
            {
                stock += line[i];
                ++i;
            }

            //stock is converted into integer.
            int int_stock = std::stoi(stock);
            i += 2;

            //next the actor data is found.
            std::string direct_f_name = "";
            std::string direct_l_name = "";

            while (i <= line.size() && line[i] != ' ')
            {  
                direct_f_name += line[i];
                ++i;
            }
            
            ++i;

            while (i <= line.size() && line[i] != ',')
            {  
                direct_l_name += line[i];
                ++i;
            }

            i += 2;

            //Movie title is found.
            std::string title = "";

            while (i <= line.size() && line[i] != ',')
            {
                title += line[i];
                ++i;
            }

            i += 2;

            //year of release
            std::string year = "";
            int int_year;
            while (i <= line.size())
            {  
                year += line[i];
                ++i;
            }

            int_year = std::stoi(year);

            std::cout << int_stock << " " << direct_f_name << " " << direct_l_name 
                << " " << title << " " << year << std::endl;

        }

        else if (movie_type == 'F')
        {
            std::cout << "getline found this: " << line << std::endl; 
            //first, the stock is found.
            std::string stock = "";

            int i = 3;
            while (i <= line.size() && line[i] != ',')
            {
                stock += line[i];
                ++i;
            }

            //stock is converted into integer.
            int int_stock = std::stoi(stock);
            i += 2;

            //next the actor data is found.
            std::string direct_f_name = "";
            std::string direct_l_name = "";

            while (i <= line.size() && line[i] != ' ')
            {  
                direct_f_name += line[i];
                ++i;
            }
            
            ++i;

            while (i <= line.size() && line[i] != ',')
            {  
                direct_l_name += line[i];
                ++i;
            }

            i += 2;

            //Movie title is found.
            std::string title = "";

            while (i <= line.size() && line[i] != ',')
            {
                title += line[i];
                ++i;
            }

            i += 2;

            //year of release
            std::string year = "";
            int int_year;
            while (i <= line.size())
            {  
                year += line[i];
                ++i;
            }

            int_year = std::stoi(year);

            std::cout << int_stock << " " << direct_f_name << " " << direct_l_name 
                << " " << title << " " << year << std::endl;

        }
    }
    in_file.close();
}

void DataReader::read_command_file(std::ifstream& in_file)
{
    std::string line;
    while (getline(in_file, line))
    {
        //command type is acquired, determines command subclass object.
        char command_type = line[0];

        if (command_type == 'H')
        {
            std::string line_id = "";

            for (int i = 2; i < line.size(); i++)
            {
                line_id += line[i];
            }

            int customer_id = std::stoi(line_id);

            std::cout << "information gathered: " << command_type << " " << customer_id << std::endl;
        }
        else if (command_type == 'B')
        {
            int i = 2;

            std::string line_id = "";
            while (i < line.size() && line[i] != ' ')
            {
                line_id += line[i];
                ++i;
            }

            int customer_id = std::stoi(line_id);

            ++i;

            char product_type = line[i];

            i += 2;

            char movie_type = line[i];

            if (movie_type == 'C')
            {
                i += 2;
                
                std::string s_month = "";
                while (i < line.size() && line[i] != ' ')
                {
                    s_month += line[i];
                    ++i;
                }

                int month = std::stoi(s_month);

                ++i;

                std::string s_year = "";
                while (i < line.size() && line[i] != ' ')
                {
                    s_year += line[i];
                    ++i;
                }

                int year = std::stoi(s_year);

                ++i;

                std::string actor_f_name = "";
                std::string actor_l_name = "";

                while (i < line.size() && line[i] != ' ')
                {
                    actor_f_name += line[i];
                    ++i;
                } 

                ++i;

                while (i < line.size())
                {
                    actor_l_name += line[i];
                    ++i;
                }

                std::cout << "B " << customer_id << "->" << product_type << "->"
                << movie_type << "->" << month << "->" << year << "->" << actor_f_name << "->"
                    << actor_l_name << std::endl;
            }

            else if (movie_type == 'F')
            {
                i += 2;

                std::string title = "";
                while (i < line.size() && line[i] != ',')
                {
                    title += line[i];
                    ++i;
                } 

                i += 2;

                std::string s_year = "";

                while (i < line.size()) 
                {
                    s_year += line[i];
                    ++i;
                }

                int year = std::stoi(s_year);

                std::cout << "B " << customer_id << "->" << product_type << "->"
                << movie_type << "->" << title << "->" << year << std::endl;
            }

            else if (movie_type == 'D')
            {
                i += 2;

                std::string director_name = "";
                while (i < line.size() && line[i] != ',')
                {
                    director_name += line[i];
                    ++i;
                }

                i += 2;

                std::string title = "";
                while (i < line.size() && line[i] != ',')
                {
                    title += line[i];
                    ++i;
                }

                std::cout << "B " << customer_id << "->" << product_type << "->"
                << movie_type << "->" << director_name << "->" << title << std::endl;
            }

            else
            {
                std::cerr << "ERROR: MOVIE GENRE '" << movie_type << "' INVALID." << std::endl;
            }
        }

        else if (command_type == 'R')
        {
            int i = 2;

            std::string line_id = "";
            while (i < line.size() && line[i] != ' ')
            {
                line_id += line[i];
                ++i;
            }

            int customer_id = std::stoi(line_id);

            ++i;

            char product_type = line[i];

            i += 2;

            char movie_type = line[i];

            if (movie_type == 'C')
            {
                i += 2;
                
                std::string s_month = "";
                while (i < line.size() && line[i] != ' ')
                {
                    s_month += line[i];
                    ++i;
                }

                int month = std::stoi(s_month);

                ++i;

                std::string s_year = "";
                while (i < line.size() && line[i] != ' ')
                {
                    s_year += line[i];
                    ++i;
                }

                int year = std::stoi(s_year);

                ++i;

                std::string actor_f_name = "";
                std::string actor_l_name = "";

                while (i < line.size() && line[i] != ' ')
                {
                    actor_f_name += line[i];
                    ++i;
                } 

                ++i;

                while (i < line.size())
                {
                    actor_l_name += line[i];
                    ++i;
                }

                std::cout << "R " << customer_id << "->" << product_type << "->"
                << movie_type << "->" << month << "->" << year << "->" << actor_f_name << "->"
                    << actor_l_name << std::endl;
            }

            else if (movie_type == 'F')
            {
                i += 2;

                std::string title = "";
                while (i < line.size() && line[i] != ',')
                {
                    title += line[i];
                    ++i;
                } 

                i += 2;

                std::string s_year = "";

                while (i < line.size()) 
                {
                    s_year += line[i];
                    ++i;
                }

                int year = std::stoi(s_year);

                std::cout << "R " << customer_id << "->" << product_type << "->"
                << movie_type << "->" << title << "->" << year << std::endl;
            }

            else if (movie_type == 'D')
            {
                i += 2;

                std::string director_name = "";
                while (i < line.size() && line[i] != ',')
                {
                    director_name += line[i];
                    ++i;
                }

                i += 2;

                std::string title = "";
                while (i < line.size() && line[i] != ',')
                {
                    title += line[i];
                    ++i;
                }

                std::cout << "R " << customer_id << "->" << product_type << "->"
                << movie_type << "->" << director_name << "->" << title << std::endl;
            }

            else
            {
                std::cerr << "ERROR: MOVIE GENRE '" << movie_type << "' INVALID." << std::endl;
            }
        }
        
        else if (command_type == 'I')
        {
            std::cout << "INVENTORY LISTED HERE." << std::endl;
        }

        else 
        {
            std::cerr << "ERROR: COMMAND '" << command_type <<"' IS INVALID." << std::endl;
        }
    }
}

#endif //DATAREADER_CPP