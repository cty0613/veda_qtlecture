#include "model.h"
#include <vector>

model::model(QObject *parent)
    : QObject{parent}
{}


int model::getValue(int index) const {
    std::vector<int> currents = {value0, value1, value2};
    return currents[index];
}

void model::setValue(int index, int v){
    std::vector<int> currents = {value0, value1, value2};
    if (currents[index] != v){
        emit valueChanged(index, v);
    }


}
