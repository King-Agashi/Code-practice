class Solution {
    public void reverseString(char[] s) {
         reverse(  s , 0 , s.length -1 );
    }
    
    static char[] reverse( char[] s , int start , int e ){
        if(start >= e){
            return s;
        }
        swap( s , start , e);
        
        return reverse( s , start+1 , e-1);
    }
    
    static void swap(char[] s , int a, int b){
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
    }
}