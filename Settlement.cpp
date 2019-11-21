#include <iostream>

#include "Utility.hpp"

#include "Settlement.hpp"
#include "Industry.hpp"
#include "Market.hpp"
#include "Population.hpp"

Settlement::Settlement() {}

Settlement::Settlement(People people)
{
    population = new Population(*this);

    SetupEconomy();
}

void Settlement::Print()
{
    //std::cout<<"Population: "<<population<<" people\n";

    //std::cout<<"Workforce: "<<industry->workforce<<" people\n";

    //std::cout<<"Demand: "<<demand<<" tons\n";

    //std::cout<<"Offer: "<<offer<<" tons\n";

    //std::cout<<"Price: "<<market->price<<" coins\n";

    //std::cout<<"Value: "<<industry->value<<" coins\n";

    //std::cout<<"Wages: "<<industry->wages<<" coins\n";

    //std::cout<<"Innovation: "<<industry->innovation<<"\n";

    //std::cout<<"Transaction: "<<industry->income<<" coins\n";

    //std::cout<<"Per worker income: "<<industry->income / (float)industry->workforce<<" coins\n";

    //std::cout<<"Industry Savings: "<<industry->savings<<" coins\n";

    //std::cout<<"Population Savings: "<<savings<<" coins\n";
}

void Settlement::Update()
{
    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        industry->UpdateOutput();
    }

    for(auto market = markets.GetStart(); market != markets.GetEnd(); ++market)
    {
        market->Update();
    }

    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        industry->UpdateIncome();
    }

    population->UpdateSavings();

    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        industry->UpdateWorkforce();
    }
}

void Settlement::SetupEconomy()
{
    industries.Initialize(Products::GetCount());

    markets.Initialize(Products::GetCount());

    for(auto product = Products::GetFirst(); product != Products::GetLast(); ++product)
    {
        auto industry = industries.Allocate();
        *industry = Industry(this, *product);
    }

    for(auto product = Products::GetFirst(); product != Products::GetLast(); ++product)
    {
        auto market = markets.Allocate();
        *market = Market(this, *product);
    }
}