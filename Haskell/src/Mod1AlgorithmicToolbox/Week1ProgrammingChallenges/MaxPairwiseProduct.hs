module Mod1AlgorithmicToolbox.Week1ProgrammingChallenges.MaxPairwiseProduct where

import Data.List

-- | The 'maxPairwiseProduct' returns the maximum pairwise product of a list of non-negative integers
maxPairwiseProduct :: [Int] -> Int
maxPairwiseProduct numbers = let [first, second] = take 2 $ sortBy (flip compare) numbers in first * second
