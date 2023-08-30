#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
using namespace std;

class Point {
public:
    vector<double> puntos;
    Point(int dimension) {
        std::random_device rd;
        std::mt19937 gen(rd());
        uniform_real_distribution<double> distribution(0, 1);
        for (int i = 0; i < dimension; i++) {
            puntos.push_back(distribution(gen));
        }
    }
    int size_Point() {
        return puntos.size();
    }
};

vector<Point> create_Space_dimension_X(int dimension) {
    vector<Point> space;
    for (int i = 0; i < 100; i++) {
        space.push_back(Point(dimension));
    }
    return space;
}

double euclidean_distance(Point A, Point B) {
    double distance = 0;
    for (int i = 0; i < A.size_Point(); i++) {
        distance += pow(A.puntos[i] - B.puntos[i], 2);
    }
    return pow(distance, 0.5);
}

vector<double> distance_pair_points(vector<Point> space) {
    vector<double> all_distances;
    vector<Point> copy_space = space;
    for (int i = 99; i >= 0; i--) {
        for (int j = copy_space.size() - 2; j >= 0; j--) {
            all_distances.push_back(euclidean_distance(space[i], copy_space[j]));
        }
        copy_space.pop_back();
    }
    return all_distances;
}

void create_file(vector<double> all_distance, int dimension) {
    string name_file = "dimension_" + to_string(dimension);
    ofstream out_file;

    //crea un archivo con las distancias entre todos los puntos
    out_file.open(name_file, ios::out);
    if (out_file.fail()) {
        cout << "Error";
        exit(1);
    }
    else {
        for (int i = 0; i < all_distance.size(); i++) {
            out_file << all_distance[i] << endl;
        }
        out_file.close();
    }
}

int main(int argc, char* argv[]) {
    /*//La Dimension se pasa por consola
    int dimension = atoi(argv[1]);*/

    int dimensions[8] = {2,10,50,100,500,1000,2000,5000};

    for (int i = 0; i < 8; i++) {
        vector<Point> space = create_Space_dimension_X(dimensions[i]);
        vector<double> all_distance = distance_pair_points(space);
        create_file(all_distance, dimensions[i]);
    }
    

    
    return 0;
}
