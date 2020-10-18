defmodule DataStructuresAndAlgorithms.AlgorithmicToolBox.Week2AlgorithmicWarmup.Fibonacci do
  @moduledoc """
  # Fibonacci related algorithms
  """

  defp fibonacci(a, b, n) do
    case n do
      0 -> a
      _ -> fibonacci(b, a + b, n - 1)
    end
  end

  @doc """
  # Fibonacci Number

  Given a non-negative integer n, compute the Fibonacci Number Fn, where Fn = Fn-1 + Fn-2 and F0 = 0, F1 = 1

  Returns {:ok, fibonacci_number} on success, {:error, :invalid_input} on invalid input

  ## Examples
  iex> fibonacci(10)
  {:ok, 55}
  """
  @spec fibonacci(non_neg_integer()) :: {:ok, non_neg_integer()} | {:error, :invalid_input}
  def fibonacci(n) when is_integer(n) and n >= 0 do
    {:ok, fibonacci(0, 1, n)}
  end

  def fibonacci(_) do
    {:error, :invalid_input}
  end
end
