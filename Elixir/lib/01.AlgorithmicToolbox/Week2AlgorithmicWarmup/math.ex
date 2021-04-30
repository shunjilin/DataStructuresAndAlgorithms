defmodule DataStructuresAndAlgorithms.AlgorithmicToolBox.Week2AlgorithmicWarmup.Math do
  @moduledoc """
  # Math related algorithms
  """

  @doc """
  # Fibonacci Number

  Given a non-negative integer n, compute the Fibonacci Number Fn, where Fn = Fn-1 + Fn-2 and F0 = 0, F1 = 1

  ## Examples
  iex> fibonacci(10)
  55

  iex> fibonacci(30)
  832_040
  """
  @spec fibonacci(non_neg_integer()) :: non_neg_integer()
  def fibonacci(n) do
    do_fibonacci(n)
  end

  defp do_fibonacci(n, a \\ 0, b \\ 1) do
    case n do
      0 -> a
      _ -> do_fibonacci(n - 1, b, a + b)
    end
  end

  @doc """
  # Last Digit of a Fibonacci Number

  ## Examples
  iex> fibonacci_last_digit(3)
  2

  iex> fibonacci_last_digit(331)
  9
  """
  @spec fibonacci_last_digit(non_neg_integer()) :: non_neg_integer()
  def fibonacci_last_digit(n) do
    n
    |> do_fibonacci()
    |> Integer.mod(10)
  end
end
