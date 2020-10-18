defmodule MaxPairwiseProductTest do
  use ExUnit.Case

  import DataStructuresAndAlgorithms.AlgorithmicToolBox.Week1ProgrammingChallenges.MaxPairwiseProduct

  doctest DataStructuresAndAlgorithms.AlgorithmicToolBox.Week1ProgrammingChallenges.MaxPairwiseProduct

  test "returns correct max pairwise product" do
    assert max_pairwise_product([21468, 16859, 82178, 70496, 82939, 44491]) ==
             {:ok, 6_815_761_142}
  end

  test "returns error on invalid input" do
    assert max_pairwise_product([-100, 2, 3]) == {:error, :invalid_input}
  end
end
