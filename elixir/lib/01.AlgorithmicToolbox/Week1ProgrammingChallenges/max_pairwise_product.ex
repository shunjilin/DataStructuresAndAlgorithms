defmodule DataStructuresAndAlgorithms.AlgorithmicToolBox.Week1ProgrammingChallenges.MaxPairwiseProduct do
  @moduledoc """
  # Maximum Pairwise Product Problem
  """

  @doc """
  # Maximum Pairwise Product Problem
  Find the maximum product of two distinct numbers in a sequence of non-negative integers
  indices must be different, value can be the same

  ## Given a list of non negative integers, return the maximum pairwise product

  ## Examples
  iex> import DataStructuresAndAlgorithms.AlgorithmicToolBox.Week1ProgrammingChallenges.MaxPairwiseProduct
  iex> number_list = [7, 5, 14, 2, 8, 8, 10, 1, 2, 3]
  iex> max_pairwise_product(number_list)
  140
  """
  @spec max_pairwise_product(list(non_neg_integer())) :: non_neg_integer()
  def max_pairwise_product(non_negative_integers) do
    if length(non_negative_integers) < 2 do
      raise ArgumentError, message: "Requires at least 2 non-negative integers in list input"
    end

    max_a = Enum.max(non_negative_integers)

    max_b =
      List.delete(non_negative_integers, max_a)
      |> Enum.max()

    max_a * max_b
  end
end
