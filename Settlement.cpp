#include <iostream>

#include "Utility.hpp"

#include "Settlement.hpp"
#include "Industry.hpp"
#include "Market.hpp"
#include "Population.hpp"

Settlement::Settlement()
{
    population = new Population(*this);

    industry = new Industry(*this);

    market = new Market(*this);
}

void Settlement::Print()
{
    //std::cout<<"Population: "<<population<<" people\n";

    std::cout<<"Workforce: "<<industry->workforce<<" people\n";

    //std::cout<<"Demand: "<<demand<<" tons\n";

    //std::cout<<"Offer: "<<offer<<" tons\n";

    std::cout<<"Price: "<<market->price<<" coins\n";

    std::cout<<"Value: "<<industry->value<<" coins\n";

    std::cout<<"Wages: "<<industry->wages<<" coins\n";

    //std::cout<<"Innovation: "<<industry->innovation<<"\n";

    std::cout<<"Transaction: "<<industry->income<<" coins\n";

    std::cout<<"Per worker income: "<<industry->income / (float)industry->workforce<<" coins\n";

    std::cout<<"Industry Savings: "<<industry->savings<<" coins\n";

    //std::cout<<"Population Savings: "<<savings<<" coins\n";
}

void Settlement::Update()
{
    industry->UpdateOutput();

    market->Update();

    industry->UpdateIncome();

    population->UpdateSavings();

    industry->UpdateWorkforce();
}