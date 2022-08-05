class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Integer> map = new HashMap<>();
        Set<Character> set = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            int dif = c1 - c2;
            boolean isFound = map.containsKey(c1);
            if ((isFound && dif != map.get(c1)) || (!isFound && set.contains(c2))) {
                return false;
            }

            map.put(c1, dif);
            set.add(c2);
        }

        return true;
    }
}