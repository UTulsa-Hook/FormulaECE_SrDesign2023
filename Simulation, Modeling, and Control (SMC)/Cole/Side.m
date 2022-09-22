rng_hold = rng('shuffle');
a = randn(2,1);
a = randn(3,1);
rng(rng_hold);
a = randn(2,1);