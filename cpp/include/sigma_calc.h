#pragma once

class SigmaCalculator {
private:
    double sigma_val;
    double winning_probs_2pow_sum;
    double winning_probs_sum;
    int fight_count;

    void reset_vals();

public:
    SigmaCalculator::SigmaCalculator();
    void add_winning_prob(double winning_prob);
    double calc_sigma();
};
