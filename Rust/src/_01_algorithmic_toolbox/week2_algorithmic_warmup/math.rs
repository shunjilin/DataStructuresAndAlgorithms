pub fn fibonacci(n: u64) -> u64 {
    let mut pair = (0, 1);
    for _ in 0..n {
        let (a, b) = pair;
        pair = (b, a + b);
    }
    pair.0
}

// return nth fibonacci modulo
pub fn fibonacci_modulo(n: u64, modulo: u64) -> u64 {
    let mut pair = (0, 1);
    for _ in 0..n {
        let (a, b) = pair;
        pair = (b, (a + b) % modulo);
    }
    pair.0
}

// last digit of nth fibonacci
pub fn fibonacci_last_digit(n: u64) -> u64 {
    fibonacci_modulo(n, 10)
}

// greatest common divisor
pub fn gcd(a: u64, b: u64) -> u64 {
    match b {
        0 => a,
        _ => gcd(b, a % b),
    }
}

// least common multiple
pub fn lcm(a: u64, b: u64) -> u64 {
    a * b / gcd(a, b)
}

// returns the period length of fibonacci modulo (Pisano period)
pub fn pisano_period(modulo: u64) -> u64 {
    if modulo == 1 {
        return 1;
    }
    let mut pair = (0, 1);
    let mut sequence_length = 0;
    loop {
        let (a, b) = pair;
        pair = (b, (a + b) % modulo);
        sequence_length += 1;
        if pair == (0, 1) {
            return sequence_length;
        };
    }
}

// returns the modulo of the nth fibonacci (faster version)
// uses fact that fibonacci modulo sequence repeats after
// length of pisano period
pub fn fibonacci_modulo_fast(n: u64, modulo: u64) -> u64 {
    let pisano_period = pisano_period(modulo);
    fibonacci_modulo(n % pisano_period, modulo)
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn get_correct_fibonacci() {
        assert_eq!(fibonacci(50), 12586269025);
    }

    #[test]
    fn get_correct_fibonacci_last_digit() {
        assert_eq!(fibonacci_last_digit(10), 5)
    }

    #[test]
    fn get_correct_gcd() {
        assert_eq!(gcd(28851538, 1183019), 17657)
    }

    #[test]
    fn get_correct_lcm() {
        assert_eq!(lcm(28851538, 1183019), 1933053046)
    }

    #[test]
    fn get_correct_pisano_period() {
        assert_eq!(pisano_period(10), 60)
    }

    #[test]
    fn get_correct_fibonacci_modulo_fast() {
        assert_eq!(fibonacci_modulo_fast(2816213588, 239), 151)
    }

}
