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
// std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> v1,std::vector<std::vector<double>> v2){
//     if (v1.size() != v2[0].size()) {
//         std::cerr << "[ERROR] v1 and v2 vectors have different sizes\n";
//         exit(1);
//     }
//     std::vector<double> res(v1.size(), 0);
//     for (int i = 0; i < v1.size(); i++)
//     {
//         for (int j = 0; j < v1.size(); j++)
//         {
//             res[i] += v1[i] * v2[j];
//         }
//     }
//     return res;
// }