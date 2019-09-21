import {
  fibonacci,
  fibonacciLastDigit,
  gcd,
  lcm,
  pisanoPeriod,
  fibonacciModuloFast,
  fibonacciSumLastDigit,
  fibonacciPartialSumLastDigit,
  fibonacciSumOfSquaresLastDigit
} from "./math"

describe("math", () => {
  it("returns correct fibonacci", () => {
    expect(fibonacci(50)).toBe(12586269025)
  })

  it("returns correct fibonacci last digit", () => {
    expect(fibonacciLastDigit(10)).toBe(5)
  })

  it("returns correct greatest common divisor", () => {
    expect(gcd(28851538, 1183019)).toBe(17657)
  })

  it("returns correct least common multipler", () => {
    expect(lcm(28851538, 1183019)).toBe(1933053046)
  })

  it("returns correct pisano period", () => {
    expect(pisanoPeriod(10)).toBe(60)
  })

  it("fibonacci modulo fast returns correct fibonnaci modulo", () => {
    expect(fibonacciModuloFast(2816213588, 239)).toBe(151)
  })

  it("returns correct last digit of fibonacci sum", () => {
    expect(fibonacciSumLastDigit(100)).toBe(5)
  })

  it("returns correct last digit of fibonacci partial sum", () => {
    expect(fibonacciPartialSumLastDigit(10, 200)).toBe(2)
  })

  it("returns correct last digit of sum of squares of fibonacci", () => {
    expect(fibonacciSumOfSquaresLastDigit(1234567890)).toBe(0)
    expect(fibonacciSumOfSquaresLastDigit(5)).toBe(0)
  })
})
