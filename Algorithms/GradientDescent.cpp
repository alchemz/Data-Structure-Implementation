#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class GradientDescent {
public:
    vector<double> sumOfGradient(vector<double> &x,  vector<double> &y,  vector<double>&thetas);

    vector<double> step( vector<double>&thetas,  vector<double> &direction, double stepSize);

    double distance( vector<double> &v,  vector<double> &w);

    vector<double> gradientDescent( double stepSize,  vector<double> &x,
         vector<double> &y, double tolerance, int maxIter);

};

vector<double> GradientDescent::sumOfGradient( vector<double> &x,  vector<double> &y,  vector<double>&thetas) {
    int m = x.size();

    double sum = 0;
    double sum1 = 0;
    for (int i = 0; i < m; ++i) {
        sum += thetas[0] + thetas[1] * x[i] - y[i];
        sum1 += (thetas[0] + thetas[1] * x[i] - y[i])*x[i];
    }
    double grad0 = 1.0 / m * sum;
    double grad1 = 1.0 / m * sum1;

    vector<double> result;
    result.push_back(grad0);
    result.push_back(grad1);
    return result;
}

vector<double> GradientDescent::step( vector<double>&thetas,  vector<double> &direction, double stepSize) {
    vector<double> result;
    for (int i = 0; i < direction.size(); ++i) {
        result.push_back(thetas[i] + stepSize * direction[i]);
    }
    return result;
}

double GradientDescent::distance( vector<double> &v,  vector<double> &w) {
    vector<double> subtract;
    for (int i = 0; i < v.size(); ++i) {
        subtract.push_back(pow(v[i] - w[i], 2));
    }
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += subtract[i];
    }
    return sqrt(sum);
}

vector<double> GradientDescent::gradientDescent( double stepSize,  vector<double> &x,
     vector<double> &y, double tolerance = 0.0000001, int maxIter = 10000000) {
    int iterNum = 0;
    vector<double> thetas(3, 0);
    while (true) {
        vector<double> gradients = sumOfGradient(x, y, thetas);
        vector<double> nextThetas = step(thetas, gradients, stepSize);
        if (distance(nextThetas, thetas) < tolerance) 
            break;
        thetas = nextThetas;
        iterNum += 1;

        if (iterNum == maxIter) {
            cout << "Max iteractions exceeded!";
            break;
        }
    }
    return thetas;
}

int main() {
    GradientDescent gradientDescent;
    vector<double> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    vector<double> y;
    y.push_back(5);
    y.push_back(9);
    y.push_back(13);

    double stepSize = 0.001;
    vector<double> result = gradientDescent.gradientDescent(-stepSize, x, y);
    cout << "theta0 = " << result[0] << "; theta1 = " << result[1] << endl;

    //system("pause");
    return 0;
}

//reference:https://blog.csdn.net/liangyihuai/article/details/77341551
