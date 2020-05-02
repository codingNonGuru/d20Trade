#include <iostream>

#include "FlumenCore/Utility/Utility.hpp"

#include "Settlement.hpp"
#include "Industry.hpp"
#include "Market.hpp"
#include "Population.hpp"

Settlement::Settlement() {}

Settlement::Settlement(People people)
{
    population = new Population(*this);

    SetupEconomy();

    population->Setup();
}

void Settlement::Update()
{
    population->UpdateNeed();

    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        industry->UpdateOutput();
    }

    for(auto market = markets.GetStart(); market != markets.GetEnd(); ++market)
    {
        market->UpdatePrice();
    }

    population->UpdateOrder();

    for(auto market = markets.GetStart(); market != markets.GetEnd(); ++market)
    {
        market->UpdateTransaction();
    }

    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        industry->UpdateIncome();
    }

    population->UpdateSavings();

    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        industry->UpdateWorkforce();

        industry->UpdateProductivity();
    }

    Labor labor = 0.0f;
    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        labor += industry->value * industry->market->order;
    }
    //std::cout<<"Labor amount is "<<labor<<"\n";
}

void Settlement::SetupEconomy()
{
    industries.Initialize(Products::GetCount());

    markets.Initialize(Products::GetCount());

    for(auto product = Products::GetFirst(); product != Products::GetLast(); ++product)
    {
        auto industry = industries.Allocate();
        *industry = Industry(this, product);
    }

    for(auto product = Products::GetFirst(); product != Products::GetLast(); ++product)
    {
        auto market = markets.Allocate();
        *market = Market(this, *product);
    }
}

Industry* Settlement::GetIndustry(Product product) const
{
    return industries.Get((int)product);
}

Market* Settlement::GetMarket(Product product) const
{
    return markets.Get((int)product);
}

void Settlement::Print() const
{
    population->Print();

    for(auto market = markets.GetStart(); market != markets.GetEnd(); ++market)
    {
        std::cout<<market->product<<" costs "<<market->averagePrice<<" coins, ";
    }
    std::cout<<"\n";
    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        std::cout<<"The "<<*industry->product<<" industry hires "<<industry->workforce<<" people, ";
    }
    std::cout<<"\n";
    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        std::cout<<*industry->product<<" rentability is "<<industry->rentability<<", ";
    }
    std::cout<<"\n";
    std::cout<<"\n";
    //std::cout<<markets.GetMemorySize() + industries.GetMemorySize()<<"\n";
}