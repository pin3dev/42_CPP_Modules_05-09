/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:56 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/20 14:31:29 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

typedef std::pair<std::string, float> validPairDB;
/**SCRIPT TO BE DEVELOPED
 * 1. Receber a base de dados por um path
 *   1.1 Verificar se pode ser aberta (fatal error: throw open input file) 
 * 2. Criar uma base para guardar a data a ser analisada 
 * 3. Verificar se o arquivo data.csv pode ser aberto (fatal error: throw open data file) 
 * 4. Iniciar e verificação da base de dados (com TRY/CATCH depois de ler a linha)
 *   4.1. ler linha e armazena no std::string line
 *   4.2. limpar linha de espaços em branco (TRY/CATCH)
 *   4.3. se a linha está na formatação correta com regex (fatal error: throw formatação) ✅
 *   4.4. dividir linha em pair <string, float> key, value
 *   4.5. verificar se a data é válida (fatal error: throw data inválida)
 *   4.6. verificar se o valor é válido (fatal error: throw valor inválido)
 *   4.7. enviar pair para a base de dados
 * 5. Iniciar a verificação dos dados input (com TRY/CATCH depois de ler a linha)
 *   5.1. ler linha e armazena no std::string line
 *   5.2. limpar linha de espaços em branco (TRY/CATCH)
 *   5.3. se a linha está na formatação correta com regex (error handling: throw formatação) ✅
 *   5.4. dividir linha em pair <string, float> key, value
 *   5.5. verificar se data é válido (error handling: throw data inválido)
 *   5.6. verificar se valor é válido (error handling: throw valor inválido)
 *   5.7. com pair <string, float> key, value de input válido, procurar na base de dados
 * 
 * PS.: Year não pode: ser negativo, ser maior que 2024
 * PS.: Month não pode: ser negativo, ser maior que 12
 * PS.: Day não pode: ser negativo, ser maior que 31
 * PS.: Value não pode: ser negativo, ser maior que 1000
*/

validPairDB BitcoinExchange::storeDB(std::string &line)
{
    size_t i_del = line.find(DB_SEPARATOR);
    std::string key = line.substr(0, i_del);
    float value = std::stof(line.substr(i_del + 1));
    return make_pair(key, value);
}

/* void BitcoinExchange::DB(void)
{
    std::ifstream	DBfile("cpp_09/data.csv");
    Checker::ck_FileErr(DBfile); //verifica se o arquivo pode ser aberto, e lança uma exceção 
    
    std::string line;
    std::getline(DBfile, line);
    if (line != "date,exchange_rate") //verifica conteúdo inicial do file
        throw (std::runtime_error("Format Error: Invalid first line instruction\n"));
    while (std::getline(DBfile, line))
    {
        ckFormat(line, DB_SEPARATOR, false);
        this->DBdata.insert(storeDB(line));
    }
} */


//THROW EXCEPTIONS
void BitcoinExchange::exchange(std::string &INPUTpath)
{
    try //bloco de testes do DB
    {
        std::ifstream	DBfile("data.csv");
        Checker::ck_FileErr(DBfile); //verifica se o arquivo pode ser aberto, e lança uma exceção 
        
        std::string line;
        std::getline(DBfile, line);
        if (line != "date,exchange_rate") //verifica conteúdo inicial do file
            throw (std::runtime_error("Format Error: Invalid first line instruction\n"));
        while (std::getline(DBfile, line))
        {
            ckFormat(line, DB_SEPARATOR, false);
            this->DBdata.insert(storeDB(line));
        }
    }
    catch(const std::exception& e){std::cerr << "[DB] " << e.what(); return ;}
    try //Bloco de testes do INPUT
    {
        std::ifstream	IMPUTfile(INPUTpath);
        Checker::ck_FileErr(IMPUTfile); //verifica se o arquivo pode ser aberto, e lança uma exceção 
        
        std::string line;
        std::getline(IMPUTfile, line);
        if (line != "date | value") //verifica conteúdo inicial do file
            throw (std::runtime_error("Format Error: Invalid first line instruction\n"));
        while (std::getline(IMPUTfile, line))
        {
            try
            {
                ckFormat(line, INPUT_SEPARATOR, true);
                std::cout << line << " OK" << std::endl;
            }
            catch(const std::exception& e){std::cerr << e.what();}  
        }
        std::cout << this->DBdata.size() << std::endl;
    }
    catch(const std::exception& e){std::cerr << "[INPUT] " << e.what();}
} 

/**
 * @deprecated These functions are not used in the final version of the program
 * 
static void ckDate(std::string &line, const char separator)
{
    int year, month, day;
    char hyphen1, hyphen2;
    size_t i_del = line.find(separator);

    std::istringstream ssdate(line.substr(0, i_del));
    
    ssdate >> year;
    ssdate >> hyphen1;
    ssdate >> month;
    ssdate >> hyphen2;
    ssdate >> day;

    if(ssdate.fail() || ssdate.bad() || hyphen1 != '-' || hyphen2 != '-')
        throw std::runtime_error("Invalid date format");
    if (year <= 0 && month <= 0 && day <= 0 || month > 12 || day > 31 || year > 2024)
        throw std::runtime_error("Invalid value to date");
}
*
static void ckValue(std::string &line, const char separator)
{
    size_t i_del = line.find(separator);
    std::istringstream ssvalue(line.substr(i_del + 1));
    float value;
    ssvalue >> value;
    if(ssvalue.fail() || ssvalue.bad())
        throw std::runtime_error("Invalid value format");
    if (value < 0 || value > 1000)
        throw std::runtime_error("Invalid value to exchange");
}
 * 
void BitcoinExchange::ckFormat(std::string line, const char separator)
{
    bool hPipe = line.find('|') != std::string::npos && line.find_first_of('|') == line.find_last_of('|');
    bool hComma = line.find(',') != std::string::npos && line.find_first_of('|') == line.find_last_of('|');
    
    if (separator == INPUT_SEPARATOR && hPipe)
    {
        ckDate(line, INPUT_SEPARATOR);
        ckValue(line, INPUT_SEPARATOR);
    }
    else if (separator == DB_SEPARATOR && hComma)
    {
        ckDate(line, DB_SEPARATOR);
        ckValue(line, DB_SEPARATOR);
    }
    else
        throw std::runtime_error("Invalid input format");
}
static bool hasOneOrJustOne(const std::string &line, const char char2find, short int max_quantity)
{
    bool has = false;
    if (line.find(char2find) != std::string::npos)
        has = true;
    if (max_quantity == 1)
    {
        if (line.find_first_of(char2find) != line.find_last_of(char2find))
            has = false;
    }
}
static char *hasOne(std::string &line, const char delimiter)
{
    if (line.find(delimiter) != std::string::npos)
        return &line[line.find(delimiter)];
    return NULL;
} */

