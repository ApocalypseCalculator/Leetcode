// 17. Letter Combinations of a Phone Number

// strat: recursion

const mappings = {
    "2": ["a","b","c"],
    "3": ["d","e","f"],
    "4": ["g","h","i"],
    "5": ["j","k","l"],
    "6": ["m","n","o"],
    "7": ["p","q","r","s"],
    "8": ["t","u","v"],
    "9": ["w","x","y","z"],
}

function letterCombinations(digits: string): string[] {
    if(digits.length == 0) return [];
    let result: string[] = [];
    function combinations(idx: number, partial: string) {
        if(idx == digits.length) {
            result.push(partial);
            return;
        }
        mappings[digits[idx]].forEach(letter => {
            combinations(idx+1, partial+letter);
        });
    }
    combinations(0, "");
    return result;
};