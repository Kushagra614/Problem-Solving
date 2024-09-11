class Solution {
public:
    // Step 1: Function to convert Roman numeral to integer
    int value(char r) {
        if (r == 'I') return 1;
        if (r == 'V') return 5;
        if (r == 'X') return 10;
        if (r == 'L') return 50;
        if (r == 'C') return 100;
        if (r == 'D') return 500;
        if (r == 'M') return 1000;
        return 0; // default case, though this shouldn't be hit
    }

    int romanToInt(string s) {
        int result = 0;
        
        // Step 2: Iterate through the Roman numeral string
        for (int i = 0; i < s.size(); i++) {
            // Step 3: Get the value of the current Roman numeral
            int current = value(s[i]);

            // Step 4: If the current value is less than the next one, subtract it
            if (i + 1 < s.size() && current < value(s[i + 1])) {
                result -= current;
            } else {
                // Otherwise, add the current value
                result += current;
            }
        }

        return result; // Final result
    }
};
