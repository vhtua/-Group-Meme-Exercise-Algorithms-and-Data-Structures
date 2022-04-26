#pragma once

#include <iostream>
#include <string>
#include <math.h>

void printTable(int r, int c, int w)
{
    std::string temp;
    int space;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cout << "+";

            for (int k = 0; k < w; ++k)
            {
                std::cout << "-";
            }
        }

        std::cout << "+" << std::endl;

        for (int j = 0; j < c; ++j)
        {
            std::cin >> temp;
            space = floor((w - temp.size()) / 2);
            std::cout << "|";

            for (int k = 0; k < space; ++k)
            {
                std::cout << " ";
            }

            std::cout << temp;

            for (int k = 0; k < w - (int)temp.size() - space; ++k)
            {
                std::cout << " ";
            }
        }

        std::cout << "|" << std::endl;
    }

    for (int i = 0; i < c; ++i)
    {
        std::cout << "+";

        for (int j = 0; j < w; ++j)
        {
            std::cout << "-";
        }
    }

    std::cout << "+" << std::endl;
}

void printTable(int* array, int r, int c, int w)
{
    int temp;
    int space;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cout << "+";

            for (int k = 0; k < w; ++k)
            {
                std::cout << "-";
            }
        }

        std::cout << "+" << std::endl;

        for (int j = 0; j < c; ++j)
        {
            temp = array[i * c + j];

            if (temp < 0)
            {
                space = floor((w - 1 - floor(log10(abs(temp)))) / 2);
            }

            else if (temp == 0)
            {
                space = floor(w / 2);
            }

            else
            {
                space = floor((w - floor(log10(temp))) / 2);
            }

            std::cout << "|";

            for (int k = 0; k < space; ++k)
            {
                std::cout << " ";
            }

            std::cout << temp;

            if (temp < 0)
            {
                for (int k = 0; k < w - 2 - space - (int)floor(log10(abs(temp))); ++k)
                {
                    std::cout << " ";
                }
            }

            else if (temp == 0)
            {
                for (int k = 0; k < w - 1 - space; ++k)
                {
                    std::cout << " ";
                }
            }

            else
            {
                for (int k = 0; k < w - 1 - space - (int)floor(log10(temp)); ++k)
                {
                    std::cout << " ";
                }
            }
        }

        std::cout << "|" << std::endl;
    }

    for (int i = 0; i < c; ++i)
    {
        std::cout << "+";

        for (int j = 0; j < w; ++j)
        {
            std::cout << "-";
        }
    }

    std::cout << "+" << std::endl;
}

void printTable(int** array, int r, int c, int w)
{
    int temp;
    int space;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cout << "+";

            for (int k = 0; k < w; ++k)
            {
                std::cout << "-";
            }
        }

        std::cout << "+" << std::endl;

        for (int j = 0; j < c; ++j)
        {
            temp = array[i][j];

            if (temp < 0)
            {
                space = floor((w - 1 - floor(log10(abs(temp)))) / 2);
            }

            else if (temp == 0)
            {
                space = floor(w / 2);
            }

            else
            {
                space = floor((w - floor(log10(temp))) / 2);
            }

            std::cout << "|";

            for (int k = 0; k < space; ++k)
            {
                std::cout << " ";
            }

            std::cout << temp;

            if (temp < 0)
            {
                for (int k = 0; k < w - 2 - space - (int)floor(log10(abs(temp))); ++k)
                {
                    std::cout << " ";
                }
            }

            else if (temp == 0)
            {
                for (int k = 0; k < w - 1 - space; ++k)
                {
                    std::cout << " ";
                }
            }

            else
            {
                for (int k = 0; k < w - 1 - space - (int)floor(log10(temp)); ++k)
                {
                    std::cout << " ";
                }
            }
        }

        std::cout << "|" << std::endl;
    }

    for (int i = 0; i < c; ++i)
    {
        std::cout << "+";

        for (int j = 0; j < w; ++j)
        {
            std::cout << "-";
        }
    }

    std::cout << "+" << std::endl;
}

void printTable(std::string* array, int r, int c, int w)
{
    std::string temp;
    int space;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cout << "+";

            for (int k = 0; k < w; ++k)
            {
                std::cout << "-";
            }
        }

        std::cout << "+" << std::endl;

        for (int j = 0; j < c; ++j)
        {
            temp = array[i * c + j];
            space = floor((w - temp.size()) / 2);
            std::cout << "|";

            for (int k = 0; k < space; ++k)
            {
                std::cout << " ";
            }

            std::cout << temp;

            for (int k = 0; k < w - space - (int)temp.size(); ++k)
            {
                std::cout << " ";
            }
        }

        std::cout << "|" << std::endl;

    }

    for (int i = 0; i < c; ++i)
    {
        std::cout << "+";

        for (int j = 0; j < w; ++j)
        {
            std::cout << "-";
        }
    }

    std::cout << "+" << std::endl;
}

void printTable(std::string** array, int r, int c, int w)
{
    std::string temp;
    int space;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cout << "+";

            for (int k = 0; k < w; ++k)
            {
                std::cout << "-";
            }
        }

        std::cout << "+" << std::endl;

        for (int j = 0; j < c; ++j)
        {
            temp = array[i][j];
            space = floor((w - temp.size()) / 2);
            std::cout << "|";

            for (int k = 0; k < space; ++k)
            {
                std::cout << " ";
            }

            std::cout << temp;

            for (int k = 0; k < w - space - (int)temp.size(); ++k)
            {
                std::cout << " ";
            }
        }

        std::cout << "|" << std::endl;

    }

    for (int i = 0; i < c; ++i)
    {
        std::cout << "+";

        for (int j = 0; j < w; ++j)
        {
            std::cout << "-";
        }
    }

    std::cout << "+" << std::endl;
}