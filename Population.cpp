#include "Population.hpp"
#include "Settlement.hpp"
#include "Industry.hpp"

Population::Population(const Settlement& parent) : settlement(parent)
{
    need = 0.1f;

    count = 100;

    savings = 1000.0f;
}

void Population::UpdateSavings()
{
    auto& industries = settlement.industries;
    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        savings -= industry->income;

        savings += industry->wages;
    }
}