defmodule DataStructuresAndAlgorithms.AlgorithmicToolBox.Week2AlgorithmicWarmup.Fibonacci do
  @moduledoc """
  # Fibonacci related algorithms
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
    do_fibonacci(n, 0, 1)
  end

  defp do_fibonacci(n, a, b) do
    case n do
      0 -> a
      _ -> do_fibonacci(n - 1, b, a + b)
    end
  end
end
