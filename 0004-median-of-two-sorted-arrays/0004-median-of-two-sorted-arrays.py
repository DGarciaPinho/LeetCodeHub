from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        merged = []
        
        i = 0
        j = 0
        
        # junta ordenadamente
        while i < len(nums1) and j < len(nums2):
            
            if nums1[i] < nums2[j]:
                merged.append(nums1[i])
                i += 1
            else:
                merged.append(nums2[j])
                j += 1
        
        # adiciona resto de nums1
        while i < len(nums1):
            merged.append(nums1[i])
            i += 1
        
        # adiciona resto de nums2
        while j < len(nums2):
            merged.append(nums2[j])
            j += 1
        
        total = len(merged)
        
        # se for Ã­mpar
        if total % 2 == 1:
            return merged[total // 2]
        
        # se for par
        else:
            meio1 = merged[total // 2 - 1]
            meio2 = merged[total // 2]
            
            return (meio1 + meio2) / 2
        