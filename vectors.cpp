#include "vectors.hpp"
std::vector<double> substract(std::vector<double> v1,std::vector<double> v2){
    if (v1.size() != v2.size()) {
        std::cerr << "[ERROR] v1 and v2 vectors have different sizes\n";
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
        std::cerr << "[ERROR] v1 and v2 vectors have different sizes\n";
        exit(1);
    }
    std::vector<std::vector<double>> res(v1.size(), std::vector<double>(v2[0].size(), 0));
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2[0].size(); j++)
        {
            for (int x = 0; x < v1.size(); x++)
            {
                std::cout << i;
                std::cout << "/";
                std::cout << j;
                std::cout << "\n";
                res[i][j] += v1[i][x] * v2[x][j];
            }
        }
    }
    return res;
}
std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> v){
    std::vector<std::vector<double>> res(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        res[i] = std::vector<double>(v[i].size());
        for (int j = 0; j < v[i].size(); j++)
        {
            res[i][j] = v[j][i];
        }
    }
    return res;
}