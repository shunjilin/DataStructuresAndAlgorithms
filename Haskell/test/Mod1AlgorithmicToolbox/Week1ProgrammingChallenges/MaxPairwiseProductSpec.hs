module Mod1AlgorithmicToolbox.Week1ProgrammingChallenges.MaxPairwiseProductSpec where

import Mod1AlgorithmicToolbox.Week1ProgrammingChallenges.MaxPairwiseProduct
import Test.Hspec

spec :: Spec
spec = do
  describe "MaxPairwiseProduct" $ do
    it "Returns correct max pairwise product from list of non-negative integers" $ do
      maxPairwiseProduct [21468, 16859, 82178, 70496, 82939, 44491] `shouldBe` 6815761142