#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <chrono>
#include <regex>
namespace fs = std::filesystem;
std::vector<int**> lista_matriz;
std::string directorio = "./bonus";
std::string directorio1 = "./data";
std::vector<std::string> lectura_files(std::string direct){
    std::vector<std::string> txt_files;
    for (const auto& entry : fs::directory_iterator(direct)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            txt_files.push_back(entry.path().filename().string());
        }
    }
    return txt_files;
}
std::vector<int> lectura_text(std::string archivo){
    std::vector<int> lineas;
    std::string texto;
    std::regex patron("\\d+");
    std::smatch coincidencias;
    std::ifstream file_detect(archivo);
    if (!file_detect.is_open()) {
        std::cerr << "Error: Could not open file '" << archivo << "'" << std::endl;
    }
    while(std::getline(file_detect, texto)){
        std::string::const_iterator inicio(texto.cbegin());
        while (std::regex_search(inicio, texto.cend(), coincidencias, patron)) {
            lineas.push_back(std::stoi(coincidencias[0]));
            inicio = coincidencias[0].second;
        }
    }
    
    return lineas;
}
std::vector<int**> calculo_matriz(std::vector<int> lista_numeros){
    std::vector<int**> lista_matriz;
    int tamanio_x, tamanio_y, i;
    i = 1;
    while(i < lista_numeros.size()){
        tamanio_y = lista_numeros[i]; tamanio_x = lista_numeros[i+1];
        int** matriz = new int*[tamanio_y];
        for(int o = 0; o < tamanio_x; o++){
            matriz[o] = new int[tamanio_x];
        };i=3;
        for(int y = 0; y < tamanio_y; y++){
            for(int x = 0; x < tamanio_x; x++){
                matriz[y][x] = lista_numeros[i];
                std::cout << matriz[y][x];
                i++;
            }
            i++;
        };
        lista_matriz.push_back(matriz);
    };
    return lista_matriz;
}
int main(int argc, char* argv[]){
    std::vector<std::string> lista_archivos = lectura_files(directorio1);
    for(std::string hola : lista_archivos){
        std::string frase_co = directorio1 + "/" + hola;
        std::vector<int> lista_numeros = lectura_text(frase_co);
        lista_matriz = calculo_matriz(lista_numeros);
    };
    return 0;

}