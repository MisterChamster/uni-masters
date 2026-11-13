#pragma once


class SigmaCalculator {
private:
    double winning_probs_2pow_sum;
    double winning_probs_sum;
    int fight_count;


public:
    SigmaCalculator();
    void reset_vals();
    void add_winning_prob(double winning_prob);
    double get_sigma_and_reset();
};
