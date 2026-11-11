#include <iostream>

#include "sigma_calc.h"

SigmaCalculator::SigmaCalculator() {
    SigmaCalculator::reset_vals();
}

void SigmaCalculator::reset_vals() {
    winning_probs_sum = 0;
    winning_probs_2pow_sum = 0;
    fight_count = 0;
}

void SigmaCalculator::add_winning_prob(double winning_prob) {
    winning_probs_2pow_sum += winning_prob*winning_prob;
    winning_probs_sum += winning_prob;
    fight_count++;
}

double SigmaCalculator::get_sigma_and_reset() {
    winning_probs_2pow_sum /= fight_count;
    winning_probs_sum /= fight_count;

    double sigma_2pow = winning_probs_2pow_sum - 
                        (winning_probs_sum*winning_probs_sum);
    double sigma_val = std::sqrt(sigma_2pow);

    SigmaCalculator::reset_vals();
    return sigma_val;
}
