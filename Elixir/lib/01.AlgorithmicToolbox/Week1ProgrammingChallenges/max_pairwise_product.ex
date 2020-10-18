defmodule DataStructuresAndAlgorithms.AlgorithmicToolBox.Week1ProgrammingChallenges.MaxPairwiseProduct do
  @moduledoc """
  # Maximum Pairwise Product Problem
  """

  @doc """
  # Maximum Pairwise Product Problem

  Given a `list` of `non negative integers`, return the maximum pairwise product, i.e. product between the two largest distinct (different index) numbers in the list

  If success, returns `{:ok, max_pairwise_product}`

  Input must be list of non-negative integers with at least 2 elements, otherwise returns `{:error, :invalid_input}`

  ## Examples
  iex> import DataStructuresAndAlgorithms.AlgorithmicToolBox.Week1ProgrammingChallenges.MaxPairwiseProduct
  iex> number_list = [1, 2, 3, 4, 5, 6]
  iex> max_pairwise_product(number_list)
  {:ok, 30}
  """
  @spec max_pairwise_product(list(non_neg_integer())) ::
          {:ok, non_neg_integer()} | {:error, :invalid_input}
  def max_pairwise_product(non_negative_integers) do
    with :ok <- validate_non_negative_integers(non_negative_integers, 2) do
      max_a = Enum.max(non_negative_integers)

      max_b =
        non_negative_integers
        |> List.delete(max_a)
        |> Enum.max()

      {:ok, max_a * max_b}
    end
  end

  defp validate_non_negative_integers(non_negative_integers, min_length) do
    if is_list(non_negative_integers) and
         Enum.all?(non_negative_integers, fn x -> is_integer(x) and x >= 0 end) and
         length(non_negative_integers) >= min_length do
      :ok
    else
      {:error, :invalid_input}
    end
  end
end
