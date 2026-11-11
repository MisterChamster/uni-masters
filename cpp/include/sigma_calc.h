#pragma once

class SigmaCalculator {
private:
    double winning_probs_2pow_sum;
    double winning_probs_sum;
    int fight_count;

    void reset_vals();

public:
    SigmaCalculator();
    void add_winning_prob(double winning_prob);
    double get_sigma_and_reset();
};
