/*!
 * File:   test_problems.h
 * Author: David Eriksson, dme65@cornell.edu
 *
 * Created on 7/18/16.
 */

#ifndef SOT_TEST_PROBLEMS_H
#define SOT_TEST_PROBLEMS_H

#include <cmath>
#include <memory>
#include "common.h"
#include "problem.h"

//! SOT namespace
namespace sot
{

    //! %Sphere function
    /*!
     * Function: \f$ f(x) = \displaystyle\sum_{i=1}^d x_i^2\f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Sphere
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Sphere : public TestProblem
    {
    protected:
        int mDim;                     /*!< Number of dimensions */
        vec mxLow;                    /*!< Lower variable bounds */
        vec mxUp;                     /*!< Upper variable bounds */
        vec mOptimum;                 /*!< Global minimizer */
        double mMinimum = 0;          /*!< Global minimum value */
        std::string mName = "Sphere"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Sphere(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return arma::sum(x % x);
        }
    };

    //! Sum of Squares function
    /*!
     * Function: \f$f(x) = \displaystyle\sum_{i=1}^d i\, x_i^2\f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class SumSquares
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class SumSquares : public TestProblem
    {
    protected:
        int mDim;                             /*!< Number of dimensions */
        vec mxLow;                            /*!< Lower variable bounds */
        vec mxUp;                             /*!< Upper variable bounds */
        vec mOptimum;                         /*!< Global minimizer */
        double mMinimum = 0;                  /*!< Global minimum value */
        std::string mName = "Sum of Squares"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        SumSquares(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return arma::dot(arma::linspace(1, mDim, mDim), arma::square(x));
        }
    };

    //! %Schwefel22 function
    /*!
     * Function: \f$f(x) = \displaystyle\prod_{i=1}^d |x_i| + \displaystyle\sum_{i=1}^d |x_i|\f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Schwefel22
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Schwefel22 : public TestProblem
    {
    protected:
        int mDim;                         /*!< Number of dimensions */
        vec mxLow;                        /*!< Lower variable bounds */
        vec mxUp;                         /*!< Upper variable bounds */
        vec mOptimum;                     /*!< Global minimizer */
        double mMinimum = 0;              /*!< Global minimum value */
        std::string mName = "Schwefel22"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Schwefel22(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return arma::sum(arma::abs(x)) + arma::prod(arma::abs(x));
        }
    };

    //! %Exponential function
    /*!
     * Function: \f$f(x) = - \exp\left(0.5  \displaystyle\sum_{i=1}^d x_i^2\right)\f$ <br>
     * Domain: \f$ -1 \leq x_i \leq 1 \f$ <br>
     * Minimum value: \f$-1\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Exponential
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Exponential : public TestProblem
    {
    protected:
        int mDim;                          /*!< Number of dimensions */
        vec mxLow;                         /*!< Lower variable bounds */
        vec mxUp;                          /*!< Upper variable bounds */
        vec mOptimum;                      /*!< Global minimizer */
        double mMinimum = -1.0;            /*!< Global minimum value */
        std::string mName = "Exponential"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Exponential(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -1.0 * arma::ones<vec>(dim);
            mxUp = 1.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return -exp(-0.5 * arma::sum(x % x));
        }
    };

    //! %Tablet function
    /*!
     * Function: \f$f(x) = 1e6 x_1^2 + \displaystyle\sum_{i=2}^{d} x_i^2\f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Tablet
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Tablet : public TestProblem
    {
    protected:
        int mDim;                     /*!< Number of dimensions */
        vec mxLow;                    /*!< Lower variable bounds */
        vec mxUp;                     /*!< Upper variable bounds */
        vec mOptimum;                 /*!< Global minimizer */
        double mMinimum = 0.0;        /*!< Global minimum value */
        std::string mName = "Tablet"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Tablet(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return 1e6 * (x(0) * x(0)) + arma::sum(arma::square(x.rows(1, mDim - 1)));
        }
    };

    //! %Step function
    /*!
     * Function: \f$f(x) = \displaystyle\sum_{i=1}^{d} \lfloor x_i+0.5 \rfloor^2\f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Step
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Step : public TestProblem
    {
    protected:
        int mDim;                   /*!< Number of dimensions */
        vec mxLow;                  /*!< Lower variable bounds */
        vec mxUp;                   /*!< Upper variable bounds */
        vec mOptimum;               /*!< Global minimizer */
        double mMinimum = 0.0;      /*!< Global minimum value */
        std::string mName = "Step"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Step(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return arma::sum(arma::square(arma::floor(x + 0.5)));
        }
    };

    //! %Zakharov function
    /*!
     * Function: \f$f(x) = \displaystyle\sum_{i=1}^{d} x_i^2 +
     *           \left(\displaystyle\sum_{i=1}^{d}0.5i\,x_i\right)^2 +
     *           \left(\displaystyle\sum_{i=1}^{d}0.5i\,x_i\right)^4 \f$  <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Zakharov
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Zakharov : public TestProblem
    {
    protected:
        int mDim;                       /*!< Number of dimensions */
        vec mxLow;                      /*!< Lower variable bounds */
        vec mxUp;                       /*!< Upper variable bounds */
        vec mOptimum;                   /*!< Global minimizer */
        double mMinimum = 0.0;          /*!< Global minimum value */
        std::string mName = "Zakharov"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Zakharov(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -5.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            double term1 = arma::sum(arma::square(x));
            double term2 = arma::sum(0.5 * arma::dot(arma::linspace(1, mDim, mDim), x));
            return term1 + std::pow(term2, 2) + std::pow(term2, 4);
        }
    };

    //! %Rosenbrock function
    /*!
     * Function: \f$f(x) = \displaystyle\sum_{i=1}^{d-1} \left[100 (x_i^2 - x_{i+1})^2 + (x_i^2 - 1)^2\right]\f$ <br>
     * Domain: \f$ -2 \leq x_i \leq 2 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [1,\ldots,1]\f$
     *
     * \class Rosenbrock
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Rosenbrock : public TestProblem
    {
    protected:
        int mDim;                         /*!< Number of dimensions */
        vec mxLow;                        /*!< Lower variable bounds */
        vec mxUp;                         /*!< Upper variable bounds */
        vec mOptimum;                     /*!< Global minimizer */
        double mMinimum = 0.0;            /*!< Global minimum value */
        std::string mName = "Rosenbrock"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Rosenbrock(int dim)
        {
            mDim = dim;
            mOptimum = arma::ones<vec>(dim);
            mxLow = -2.0 * arma::ones<vec>(dim);
            mxUp = 2.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            double total = 0.0;
            for (int i = 0; i < mDim - 1; i++)
            {
                total += 100.0 * std::pow(x(i) * x(i) - x(i + 1), 2) + std::pow(x(i) - 1, 2);
            }
            return total;
        }
    };

    //! %Griewank function
    /*!
     * Function: \f$f(x) =  1 + \displaystyle\frac{1}{4000}\displaystyle\sum_{i=1}^{d}x_i^2 -
     *            \displaystyle\prod_{i=1}^d \cos\left(\displaystyle\frac{x_i}{\sqrt{i}}\right)\f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Griewank
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Griewank : public TestProblem
    {
    protected:
        int mDim;                       /*!< Number of dimensions */
        vec mxLow;                      /*!< Lower variable bounds */
        vec mxUp;                       /*!< Upper variable bounds */
        vec mOptimum;                   /*!< Global minimizer */
        double mMinimum = 0.0;          /*!< Global minimum value */
        std::string mName = "Griewank"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Griewank(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return 1.0 + (1.0 / 4000) * arma::sum(x % x) -
                   arma::prod(arma::cos(x / sqrt(arma::linspace(1, mDim, mDim))));
        }
    };

    //! %Schaffer2 function
    /*!
     * Function: \f$f(x) =  \displaystyle\sum_{i=1}^{d-1} \left(x_i^2 + x_{i+1}^2\right)^{0.25}
     *             \left(\sin^2(50(x_i^2+x_{i+1}^2)^{0.1})+1\right)\f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Schaffer2
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Schaffer2 : public TestProblem
    {
    protected:
        int mDim;                         /*!< Number of dimensions */
        vec mxLow;                        /*!< Lower variable bounds */
        vec mxUp;                         /*!< Upper variable bounds */
        vec mOptimum;                     /*!< Global minimizer */
        double mMinimum = 0.0;            /*!< Global minimum value */
        std::string mName = "Schaffer 2"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Schaffer2(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            double total = 0.0;
            for (int i = 0; i < mDim - 1; i++)
            {
                total += std::pow(x(i) * x(i) + x(i + 1) * x(i + 1), 0.25) *
                         (std::pow(std::sin(50 * std::pow(x(i) * x(i) + x(i + 1) * x(i + 1), 0.1)), 2.0) + 1);
            }
            return total;
        }
    };

    //! %Schwefel26 function
    /*!
     * Function: \f$f(x) = -\displaystyle\sum_{i=1}^{d}x_i \sin(\sqrt{|x_i|}) \f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$-418.9829d\f$ <br>
     * Minimizer: \f$ [420.97,\ldots,420.97]\f$
     *
     * \class Schwefel26
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Schwefel26 : public TestProblem
    {
    protected:
        int mDim;                         /*!< Number of dimensions */
        vec mxLow;                        /*!< Lower variable bounds */
        vec mxUp;                         /*!< Upper variable bounds */
        vec mOptimum;                     /*!< Global minimizer */
        double mMinimum;                  /*!< Global minimum value */
        std::string mName = "Schwefel26"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Schwefel26(int dim)
        {
            mDim = dim;
            mOptimum = 420.968746 * arma::ones<vec>(dim);
            mxLow = -500.0 * arma::ones<vec>(dim);
            mxUp = 500.0 * arma::ones<vec>(dim);
            mMinimum = -418.9829 * dim;
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return -arma::dot(x, arma::sin(arma::sqrt(arma::abs(x))));
        }
    };

    //! %Himmelblau function
    /*!
     * Function: \f$f(x) = \displaystyle\frac{1}{d}\displaystyle\sum_{i=1}^d
     *           \left[x_i^4 - 16x_i^2 + 5x_i \right] \f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$-78.33\f$ <br>
     * Minimizer: \f$ [-2.90,\ldots,-2.90]\f$
     *
     * \class Himmelblau
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Himmelblau : public TestProblem
    {
    protected:
        int mDim;                         /*!< Number of dimensions */
        vec mxLow;                        /*!< Lower variable bounds */
        vec mxUp;                         /*!< Upper variable bounds */
        vec mOptimum;                     /*!< Global minimizer */
        double mMinimum = -78.3323;       /*!< Global minimum value */
        std::string mName = "Himmelblau"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Himmelblau(int dim)
        {
            mDim = dim;
            mOptimum = -2.9035 * arma::ones<vec>(dim);
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return (1.0 / mDim) * arma::sum(arma::pow(x, 4) - 16 * arma::square(x) + 5 * x);
        }
    };

    //! %Ackley function
    /*!
     * Function: \f$f(x) = -20\exp\left(-0.2\sqrt{\displaystyle\frac{1}{d}\displaystyle\sum_{i=1}^d x_i^2}\right) -
     *           \exp\left(\displaystyle\frac{1}{d}\displaystyle\sum_{i=1}^d \cos(2\pi x_i)\right)\f$ <br>
     * Domain: \f$ -15 \leq x_i \leq 20 \f$ <br>
     * Minimum value: \f$-20-e\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Ackley
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Ackley : public TestProblem
    {
    protected:
        int mDim;                       /*!< Number of dimensions */
        vec mxLow;                      /*!< Lower variable bounds */
        vec mxUp;                       /*!< Upper variable bounds */
        vec mOptimum;                   /*!< Global minimizer */
        double mMinimum = -20 - exp(1); /*!< Global minimum value */
        std::string mName = "Ackley";   /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Ackley(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -15.0 * arma::ones<vec>(dim);
            mxUp = 20.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return -20.0 * exp(-0.2 * sqrt(arma::sum(arma::square(x)) / double(mDim))) -
                   exp(arma::sum(arma::cos(2.0 * arma::datum::pi * x)) / double(mDim));
        }
    };

    //! %Rastrigin function
    /*!
     * Function: \f$f(x) = \displaystyle\sum_{i=1}^d \left[x_i^2 - \cos(2\pi x_i)\right]\f$ <br>
     * Domain: \f$ -4 \leq x_i \leq 5 \f$ <br>
     * Minimum value: \f$-d\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Rastrigin
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Rastrigin : public TestProblem
    {
    protected:
        int mDim;                        /*!< Number of dimensions */
        vec mxLow;                       /*!< Lower variable bounds */
        vec mxUp;                        /*!< Upper variable bounds */
        vec mOptimum;                    /*!< Global minimizer */
        double mMinimum;                 /*!< Global minimum value */
        std::string mName = "Rastrigin"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Rastrigin(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -4.0 * arma::ones<vec>(dim);
            mxUp = 5.0 * arma::ones<vec>(dim);
            mMinimum = -dim;
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return arma::sum(arma::square(x) - arma::cos(2 * arma::datum::pi * x));
        }
    };

    //! %Michalewicz function
    /*!
     * Function: \f$f(x) = -\displaystyle\sum_{i=1}^d \sin(x_i)
     *           \left[\sin\left(\displaystyle\frac{i x_i^2}{\pi}\right)\right]^{20} \f$ <br>
     * Domain: \f$ 0 \leq x_i \leq \pi \f$ <br>
     * Minimum value: \f$-0.966d\f$ <br>
     * Minimizer: ???
     *
     * \class Michalewicz
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Michalewicz : public TestProblem
    {
    protected:
        int mDim;                          /*!< Number of dimensions */
        vec mxLow;                         /*!< Lower variable bounds */
        vec mxUp;                          /*!< Upper variable bounds */
        vec mOptimum;                      /*!< Global minimizer */
        double mMinimum;                   /*!< Global minimum value */
        std::string mName = "Michalewicz"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Michalewicz(int dim)
        {
            mDim = dim;
            mxLow = arma::zeros<vec>(dim);
            mxUp = arma::datum::pi * arma::ones<vec>(dim);
            mMinimum = -0.966 * dim;
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return -arma::sum(arma::sin(x) % arma::pow(arma::sin(
                                                           ((arma::linspace(1, mDim, mDim) % arma::square(x)) / arma::datum::pi)),
                                                       20));
        }
    };

    //! %Keane function
    /*!
     * Function: \f$f(x) = -\,\displaystyle\frac{\displaystyle\sum_{i=1}^d
     *           \left[ \cos(x_i)^4 - 2\cos(x_i)^2\right]}
     *           {\sqrt{\displaystyle\sum_{i=1}^d ix_i^2}} \f$ <br>
     * Domain: \f$ 1 \leq x_i \leq 10 \f$ <br>
     * Minimum value: ???  <br>
     * Minimizer: ???
     *
     * \class Keane
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Keane : public TestProblem
    {
    protected:
        int mDim;                    /*!< Number of dimensions */
        vec mxLow;                   /*!< Lower variable bounds */
        vec mxUp;                    /*!< Upper variable bounds */
        vec mOptimum;                /*!< Global minimizer */
        double mMinimum;             /*!< Global minimum value */
        std::string mName = "Keane"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Keane(int dim)
        {
            mDim = dim;
            mxLow = arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
            mMinimum = -0.47;
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            double y1 = arma::sum((vec)arma::pow(arma::cos(x), 4.0));
            double y2 = arma::prod((vec)arma::pow(arma::cos(x), 2.0));
            double y3 = arma::sum(arma::linspace(1, mDim, mDim) % arma::square(x));
            return -fabs((y1 - 2.0 * y2) / sqrt(y3));
        }
    };

    //! %Levy function
    /*!
     * Function: \f$f(x) = \sin(\pi w_1)^2 + (w_d-1)^2[1+\sin^2(2\pi w_d)] +
     * \displaystyle\sum_{i=2}^{d-1} (w_i-1)^2[1+10\sin^2(\pi w_i + 1)] \f$
     * where \f$w_i = 1 + \displaystyle\frac{x_i - 1}{4}\f$ <br>
     * Domain: \f$ -5 \leq x_i \leq 5 \f$ <br>
     * Minimum value: \f$0\f$  <br>
     * Minimizer: \f$ [1,\ldots,1]\f$
     *
     * \class Levy
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Levy : public TestProblem
    {
    protected:
        int mDim;                   /*!< Number of dimensions */
        vec mxLow;                  /*!< Lower variable bounds */
        vec mxUp;                   /*!< Upper variable bounds */
        vec mOptimum;               /*!< Global minimizer */
        double mMinimum = 0.0;      /*!< Global minimum value */
        std::string mName = "Levy"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Levy(int dim)
        {
            mDim = dim;
            mOptimum = arma::ones<vec>(dim);
            mxLow = -5.0 * arma::ones<vec>(dim);
            mxUp = 5.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            vec w = 1 + (x - 1) / 4.0;
            double term1 = std::pow(std::sin(arma::datum::pi * w(0)), 2);
            double term3 = std::pow(w(mDim - 1) - 1, 2) * (1 + std::pow(std::sin(2 * arma::datum::pi * w(mDim - 1)), 2));
            vec wMid = w.rows(1, mDim - 2);
            double term2 = arma::sum(arma::square(wMid - 1) %
                                     (1 + 10 * arma::square(arma::sin(arma::datum::pi * wMid + 1))));
            return term1 + term2 + term3;
        }
    };

    //! %Salomon function
    /*!
     * Function: \f$f(x) = 1 - \cos\left(2\pi \sqrt{\displaystyle\sum_{i=1}^d x_i^2}\right) +
     *           0.1\sqrt{\displaystyle\sum_{i=1}^d x_i^2}\f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$0\f$  <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class Salomon
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Salomon : public TestProblem
    {
    protected:
        int mDim;                      /*!< Number of dimensions */
        vec mxLow;                     /*!< Lower variable bounds */
        vec mxUp;                      /*!< Upper variable bounds */
        vec mOptimum;                  /*!< Global minimizer */
        double mMinimum = 0.0;         /*!< Global minimum value */
        std::string mName = "Salomon"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Salomon(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return 1 - cos(2 * arma::datum::pi * sqrt(arma::sum(arma::square(x)))) +
                   0.1 * sqrt(arma::sum(arma::square(x)));
        }
    };

    //! %Schubert3 function
    /*!
     * Function: \f$f(x) = \displaystyle\sum_{i=1}^d \displaystyle\sum_{j=1}^6
     *           \,[j\sin((j+1)\,x_i) + j] \f$ <br>
     * Domain: \f$ -10 \leq x_i \leq 10 \f$ <br>
     * Minimum value: \f$-24.06\f$  <br>
     * Minimizer: ???
     *
     * \class Schubert3
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Schubert3 : public TestProblem
    {
    protected:
        int mDim;                        /*!< Number of dimensions */
        vec mxLow;                       /*!< Lower variable bounds */
        vec mxUp;                        /*!< Upper variable bounds */
        vec mOptimum;                    /*!< Global minimizer */
        double mMinimum = -24.062499;    /*!< Global minimum value */
        std::string mName = "Schubert3"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        Schubert3(int dim)
        {
            mDim = dim;
            mxLow = -10.0 * arma::ones<vec>(dim);
            mxUp = 10.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const { return mxLow; }
        vec uBounds() const { return mxUp; }
        int dim() const { return mDim; }
        double min() const { return mMinimum; }
        vec optimum() const { return mOptimum; }
        std::string name() const { return mName; }
        double eval(const vec &x) const
        {
            double total = 0.0;
            for (int i = 0; i < mDim; i++)
            {
                for (int j = 1; j < 6; j++)
                {
                    total += j * sin((j + 1) * x(i)) + j;
                }
            }
            return total;
        }
    };

    //! %Sine Envelope function
    /*!
     * Function: \f$f(x) = \displaystyle\sum_{i=1}^{d-1} \displaystyle\frac{\sin^2\left(\sqrt{x_i^2 + x_{i+1}^2} - 0.5\right)}
     * {\,[\,0.001(x_i^2 + x_{i+1}^2)+1\,]^2 + 0.5} \f$ <br>
     * Domain: \f$ -20 \leq x_i \leq 20 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class SineEnvelope
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class SineEnvelope : public TestProblem
    {
    protected:
        int mDim;                            /*!< Number of dimensions */
        vec mxLow;                           /*!< Lower variable bounds */
        vec mxUp;                            /*!< Upper variable bounds */
        vec mOptimum;                        /*!< Global minimizer */
        double mMinimum = 0.0;               /*!< Global minimum value */
        std::string mName = "Sine Envelope"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        SineEnvelope(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -20.0 * arma::ones<vec>(dim);
            mxUp = 20.0 * arma::ones<vec>(dim);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            double total = 0.0;
            for (int i = 0; i < mDim - 1; i++)
            {
                total += (std::pow(std::sin(std::sqrt(x(i) * x(i) + x(i + 1) * x(i + 1))), 2.0) - 0.5) /
                             (std::pow(0.001 * (x(i) * x(i) + x(i + 1) * x(i + 1)) + 1, 2.0)) +
                         0.5;
            }
            return total;
        }
    };

    //! %Schoen function
    /*!
     * Function: \f$f(x) = \displaystyle\frac{\displaystyle\sum_{i=1}^k f_i \displaystyle\prod_{j \neq i} \|x - z_j\|^{\alpha}}{
     *           \displaystyle\sum_{i=1}^k \displaystyle\prod_{j \neq i} \|x - z_j\|^{\alpha}} \f$ <br>
     * Domain: \f$ 0 \leq x_i \leq 1 \f$ <br>
     * Minimum value: \f$0\f$ <br>
     * Minimizer: Randomly generated <br> <br>
     *
     * Here \f$z_j \in [0,1]^d\f$ for \f$j=1,\dots,k\f$ are the locations of the stationary points and
     * \f$f_j \in \mathbf{R}\f$ are the values at these stationary points. The locations of \f$z_j\f$
     * are generated uniformly and \f$f_j\f$ are drawn from at \f$U[0,100]\f$ distribution. We
     * force \f$f_1 = 0\f$ so the global minimum value is always 0 and is located at \f$z_1\f$.
     * The exponents \f$\alpha\f$ are drawn from a \f$U[2,3]\f$ distribution.
     *
     * \class Schoen
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class Schoen : public TestProblem
    {
    protected:
        int mDim;                /*!< Number of dimensions */
        vec mxLow;               /*!< Lower variable bounds */
        vec mxUp;                /*!< Upper variable bounds */
        vec mOptimum;            /*!< Global minimizer */
        double mMinimum = 0.0;   /*!< Global minimum value */
        std::string mName;       /*!< Optimization problem name */
        int mk;                  /*!< Number of stationary points */
        vec mf;                  /*!< Values at the stationary points */
        vec mAlpha;              /*!< Exponents */
        mat mZ;                  /*!< Locations of the stationary points */
        double mDistTol = 1e-10; /*!< Distance tolerance for distinguishing points */
    public:
        //! Constructor with k = max(2^dim, 500)
        /*!
         * \param dim Number of dimensions
         */
        Schoen(int dim) : Schoen(dim, fmax(2 ^ dim, 500)) {}
        //! Constructor for given k
        /*!
         * \param dim Number of dimensions
         * \param k Number of stationary points
         */
        Schoen(int dim, int k)
        {
            mName = "Schoen, k = " + std::to_string(k);
            mDim = dim;
            mk = k;
            mxLow = arma::zeros<vec>(dim);
            mxUp = arma::ones<vec>(dim);
            mf = 100 * arma::randu<vec>(k);
            mf(0) = 0;
            mAlpha = 2 + arma::randu<vec>(k);
            mZ = arma::randu<mat>(dim, k);
            mOptimum = this->mZ.col(0);
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            vec dists = squaredPointSetDistance<mat, vec>(x, mZ);
            if (arma::min(dists) < mDistTol)
            { // Just return the closest point
                arma::uword closest;
                double scores = dists.min(closest);
                return mf(closest);
            }
            else
            {
                long double num = 0, den = 0, prodval = 0;
                for (int i = 0; i < mk; i++)
                {
                    prodval = std::pow(std::sqrt(arma::sum(arma::square(mZ.col(i) - x))), mAlpha(i));
                    num += mf(i) / prodval;
                    den += 1 / prodval;
                }
                return num / den;
            }
        }
    };

    //! %Cosine Mixture function
    /*!
     * Function: \f$f(x) = -0.1 \displaystyle\sum_{i=1}^d [\cos(5\pi x_i) + x_i^2]\f$ <br>
     * Domain: \f$ -1 \leq x_i \leq 1 \f$ <br>
     * Minimum value: \f$-0.1d\f$ <br>
     * Minimizer: \f$ [0,\ldots,0]\f$
     *
     * \class CosineMixture
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    class CosineMixture : public TestProblem
    {
    protected:
        int mDim;                             /*!< Number of dimensions */
        vec mxLow;                            /*!< Lower variable bounds */
        vec mxUp;                             /*!< Upper variable bounds */
        vec mOptimum;                         /*!< Global minimizer */
        double mMinimum;                      /*!< Global minimum value */
        std::string mName = "Cosine Mixture"; /*!< Optimization problem name */
    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        CosineMixture(int dim)
        {
            mDim = dim;
            mOptimum = arma::zeros<vec>(dim);
            mxLow = -1.0 * arma::ones<vec>(dim);
            mxUp = 1.0 * arma::ones<vec>(dim);
            mMinimum = -0.1 * dim;
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            return -0.1 * arma::sum(arma::cos(5 * arma::datum::pi * x)) + arma::sum(arma::square(x));
        }
    };

    //! Rotated and translated problem
    /*!
     * Turns a possibly separable problem into a non-separable one. This is done
     * by generating an orthogonal matrix \f$Q\f$ and a vector \f$ t\f$, where
     * \f$ t\f$ is in the domain of \f$ f(x)\f$. We define the new objective function
     *
     *  \f$g(x) = f(x_{opt} + Q (x - t))\f$
     *
     * We can see that \f$g(t) = f(x_{opt})\f$ so t is the global minimum of \f$ g\f$,
     * and we can also see that \f$ g\f$ isn't separable as long as \f$ Q\f$ isn't.
     *
     * \class RotatedProblem
     *
     * \tparam OptProblem The optimization problem (with Problem as a base class)
     * that is rotated and translated into a non-separable optimization problem.
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    template <class OptProb>
    class RotatedProblem : public TestProblem
    {
    protected:
        std::shared_ptr<Problem> mProblem; /*!< Shared pointer to the original optimization problem */
        vec mTranslation;                  /*!< Randomly generated translation */
        mat mRotation;                     /*!< Randomly generated rotation */
        int mDim;                          /*!< Number of dimensions (extracted from mProblem) */
        vec mxLow;                         /*!< Lower variable bounds (extracted from mProblem) */
        vec mxUp;                          /*!< Upper variable bounds (extracted from mProblem) */
        vec mOptimum;                      /*!< Global minimizer (same as mTranslation) */
        double mMinimum;                   /*!< Global minimum value */
        std::string mName;                 /*!< Optimization problem name */

        //! Generates a random translation vector
        void createTranslation()
        {
            mTranslation = mxLow + (mxUp - mxLow) % arma::randu(mDim);
        }
        //! Generates a random rotation matrix
        void createRotation()
        {
            mat Q, R;
            mat X = arma::randn<mat>(mDim, mDim);
            arma::qr(Q, R, X);
            mRotation = Q;
        }

    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        RotatedProblem(int dim)
        {
            mProblem = std::make_shared<OptProb>(dim);
            if (mProblem->optimum().n_elem != mProblem->dim())
            {
                throw std::logic_error("Optimum not specified for: " +
                                       mProblem->name() + " so can't create a rotated version");
            }
            mDim = mProblem->dim();
            mxLow = mProblem->lBounds();
            mxUp = mProblem->uBounds();
            mMinimum = mProblem->min();
            createTranslation();
            createRotation();
            mOptimum = mTranslation;
            mName = "Rotated + Translated " + mProblem->name();
        }
        //! Method that returns the rotation matrix
        /*!
         * \returns Rotation matrix
         */
        mat rotation() const
        {
            return mRotation;
        }
        //! Method that returns the translation vector
        /*!
         * \returns Translation vector
         */
        vec translation() const
        {
            return mTranslation;
        }
        vec lBounds() const
        {
            return mxLow;
        }
        vec uBounds() const
        {
            return mxUp;
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            vec xx = mProblem->optimum() + mRotation * (x - mTranslation);
            return mProblem->eval(xx);
        }
    };

    //! Problem scaled to the unit box
    /*!
     * Turns a box constrained problem into a problem on the unit box. This is convenient
     * when using RBFs since they don't scale well.
     *
     * \class UnitBoxProblem
     *
     * \tparam OptProblem The optimization problem (with Problem as a base class)
     * that is rotated and translated into a non-separable optimization problem.
     *
     * \author David Eriksson, dme65@cornell.edu
     */
    template <class OptProb>
    class UnitBoxProblem : public TestProblem
    {
    protected:
        std::shared_ptr<Problem> mProblem; /*!< Shared pointer to the original optimization problem */
        int mDim;                          /*!< Number of dimensions (extracted from mProblem) */
        vec mxLow;                         /*!< Lower variable bounds (extracted from mProblem) */
        vec mxUp;                          /*!< Upper variable bounds (extracted from mProblem) */
        vec mOptimum;                      /*!< Global minimizer (same as mTranslation) */
        double mMinimum;                   /*!< Global minimum value */
        std::string mName;                 /*!< Optimization problem name */

    public:
        //! Constructor
        /*!
         * \param dim Number of dimensions
         */
        UnitBoxProblem(int dim)
        {
            mProblem = std::make_shared<OptProb>(dim);
            mDim = dim;
            mxLow = mProblem->lBounds();
            mxUp = mProblem->uBounds();
            mMinimum = mProblem->min();
            if (mProblem->optimum().n_elem == dim)
            {
                mOptimum = toUnitBox(mProblem->optimum(), mxLow, mxUp);
            }
            mName = mProblem->name() + " scaled to the unit box";
        }
        vec lBounds() const
        {
            return arma::zeros(mDim);
        }
        vec uBounds() const
        {
            return arma::ones(mDim);
        }
        int dim() const
        {
            return mDim;
        }
        double min() const
        {
            return mMinimum;
        }
        vec optimum() const
        {
            return mOptimum;
        }
        std::string name() const
        {
            return mName;
        }
        double eval(const vec &x) const
        {
            vec xx = fromUnitBox(x, mxLow, mxUp);
            return mProblem->eval(xx);
        }
    };
}

#endif
