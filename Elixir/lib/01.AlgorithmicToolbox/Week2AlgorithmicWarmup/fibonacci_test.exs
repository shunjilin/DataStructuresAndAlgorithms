defmodule FibonacciTest do
  use ExUnit.Case

  import DataStructuresAndAlgorithms.AlgorithmicToolBox.Week2AlgorithmicWarmup.Fibonacci

  doctest DataStructuresAndAlgorithms.AlgorithmicToolBox.Week2AlgorithmicWarmup.Fibonacci

  test "returns correct fibonacci" do
    assert fibonacci(30) == {:ok, 832_040}
  end

  test "returns error on invalid input" do
    assert fibonacci(-1) == {:error, :invalid_input}
  end
end
