#include "sot.h"
using namespace sot;

int main(int argc, char **argv)
{
    int dim = 10;
    int maxEvals = 501; // Evaluation budget
    setSeedRandom();    // Set the SOT seed ramdomly

    std::shared_ptr<Problem> data(std::make_shared<Ackley>(dim));
    std::shared_ptr<ExpDesign> slhd(std::make_shared<SLHD>(2 * (dim + 1), dim));
    std::shared_ptr<Surrogate> rbf(std::make_shared<CubicRBF>(maxEvals, dim, data->lBounds(), data->uBounds()));
    std::shared_ptr<Sampling> dycors(std::make_shared<DYCORS<>>(data, rbf, 100 * dim, maxEvals - slhd->numPoints()));

    Optimizer opt(data, slhd, rbf, dycors, maxEvals);
    Result res = opt.run();

    std::cout << "Best value found: " << res.fBest() << std::endl;
    std::cout << "Best solution found: " << res.xBest().t() << std::endl;
}