#include "vectors.hpp"
std::vector<double> subtract(std::vector<double> v1,std::vector<double> v2){
    if (v1.size() != v2.size()) {
        std::cerr << "[ERROR] v1 and v2 vectors have different sizes (sub) \n";
        exit(1);
    }
    std::vector<double> res(v1.size(),0);
    for (int i = 0; i < v1.size(); i++)
    {
        res[i] = v1[i] - v2[i];
    }
    return res;
}
float dot(std::vector<double> v1,std::vector<double> v2){
    float res = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        res += v1[i] * v2[i];
    }
    return res;
}
float sum(std::vector<double> v1){
    float res = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        res += v1[i];
    }
    return res;
}
std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> v1,std::vector<std::vector<double>> v2){
    if (v1[0].size() != v2.size()) {
        std::cerr << "[ERROR] v1 and v2 vectors have different sizes (mult) \n";
        for (int i = 0; i < v1.size(); i++)
        {
            for (int y = 0; y < v1[i].size(); y++)
            {
                std::cout << v1[i][y];
                std::cout << ",";
            }
            std::cout << "\n";
        }
        
        for (int i = 0; i < v2.size(); i++)
        {
            for (int y = 0; y < v2[i].size(); y++)
            {
                std::cout << v2[i][y];
                std::cout << ",";
            }
            std::cout << "\n";
        }
        
        exit(1);
    }
    std::vector<std::vector<double>> res(v1.size(), std::vector<double>(v2[0].size(), 0));
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2[0].size(); j++)
        {
            for (int x = 0; x < v2.size(); x++)
            {
                res[i][j] += v1[i][x] * v2[x][j];
            }
        }
    }
    return res;
}
std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> v){
    std::vector<std::vector<double>> res(v[0].size());
    for (int i = 0; i < v[0].size(); i++)
    {
        res[i] = std::vector<double>(v.size());
        for (int j = 0; j < v.size(); j++)
        {
            res[i][j] = v[j][i];
        }
    }
    return res;
}

std::vector<std::vector<double>> onedTo2d(std::vector<double> v){
    return std::vector<std::vector<double>>(1,v);
}