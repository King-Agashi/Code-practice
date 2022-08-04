class Solution {
public boolean isNumber(String s) {
        
        boolean hasSign     = false ,
                hasExponent = false ,
                hasDecimal  = false ,
                hasDigits   = false ;
        
        int     expIdx      = -1    ,
                decimalIdx  = -1    ,
                idx         = -1    ;
        
        while(++idx < s.length()) {
            char c = s.charAt(idx);
            
            // Sign Check
            if(c == '+' ||  c == '-') {
                // sign but no exp b4 a!her sign
                if(hasSign && !hasExponent)
                    return false;
                
                // sign is ! directly after the exp
                if(hasExponent && idx != expIdx + 1)
                    return false;
                
                //first sign has to be idx 0 | directly after exp
                if(!hasSign && !hasExponent && idx != 0)
                    return false;
                hasSign = true;
            }
            
            // Decimal Check
            else if(c == '.'){
                
                //already a!her dec
                if(hasDecimal)
                    return false;
                
                hasDecimal = true;
                decimalIdx = idx;
                
                //already a!her exp
                if(expIdx != -1 && decimalIdx > expIdx)
                    return false;
            }
            
            // e/E Check
            else if (c == 'e' || c == 'E') {
                
                // already a!her exp
                if(hasExponent)
                    return false;
                hasExponent = true;
                
                // no digs b4 exp
                if(!hasDigits)
                    return false;
                expIdx = idx;
                
                // dec after exp
                if(decimalIdx != -1 && decimalIdx > expIdx)
                    return false;
            }
            
            // Digit Check
            else if(c >= '0' && c <= '9')
                hasDigits = true;
            
            // Invalid Char
            else
                return false;
        }

        // no digits
        if(!hasDigits)
            return false;

        // sign is last char
        if( hasSign && (
                    s.charAt(s.length() - 1) == '+'
                    ||
                    s.charAt(s.length() - 1) == '-'
            )
        ) {return false;}

        // dec shouldnt be exp
        if( hasDecimal && hasExponent && !
            (( decimalIdx-1 >= 0 && (
                    s.charAt(decimalIdx-1) >= '0' && s.charAt(decimalIdx - 1) <= '9'
            )) || (
                    s.charAt(decimalIdx+1) >= '0' && s.charAt(decimalIdx + 1) <= '9'
                  )
            ))
        {   return false;}

        //exp cant be last char
        if(hasExponent && (expIdx == 0 || expIdx == s.length() - 1)) {
            return false;
        }

        return true;
    }
};