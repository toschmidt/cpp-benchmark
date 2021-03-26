def exp(base: int, exp_min: int, exp_max: int, exp_step: int):
    l = []
    for i in list(range(exp_min, exp_max + 1, exp_step)):
        l.append(pow(base, i))
    return l
