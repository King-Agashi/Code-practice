class Solution:
    def longestCommonPrefix(self, strList: List[str]) -> str:
      
      def findMinLength(strList):
        return len(min(strList, key = len))
  
      def allContainsPrefix(strList, str, start, end):
          for i in range(0, len(strList)):
              word = strList[i]
              for j in range(start, end + 1):
                  if word[j] != str[j]:
                      return False
          return True
      
      index = findMinLength(strList)
      prefix = ""   

      low, high = 0, index - 1
      while low <= high:
          mid = int(low + (high - low) / 2)
          if allContainsPrefix(strList,   
                               strList[0], low, mid):

              prefix = prefix + strList[0][low:mid + 1]

              low = mid + 1
          else: 
              high = mid - 1

      return prefix