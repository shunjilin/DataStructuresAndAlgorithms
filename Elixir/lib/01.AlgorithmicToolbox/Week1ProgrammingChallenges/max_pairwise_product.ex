defmodule DataStructuresAndAlgorithms.AlgorithmicToolBox.Week1ProgrammingChallenges.MaxPairwiseProduct do
  @moduledoc """
  # Maximum Pairwise Product Problem
  """

  @doc """
  # Maximum Pairwise Product

  Given a `list` of `integers`, return the maximum pairwise product, i.e. product between the two largest distinct (different index) numbers in the list

  ## Examples

  iex> max_pairwise_product([21468, 16859, 82178, 70496, 82939, 44491])
  6_815_761_142

  iex> max_pairwise_product([10, 9, 8, 7, 6])
  90
  """
  @spec max_pairwise_product(list(integer())) :: integer()
  def max_pairwise_product(numbers) do
    {largest, second_largest} =
      Enum.reduce(numbers, {0, 0}, fn number, {largest, second_largest} = max_pair ->
        cond do
          number > largest -> {number, largest}
          number > second_largest -> {largest, number}
          true -> max_pair
        end
      end)

    largest * second_largest
  end
end
