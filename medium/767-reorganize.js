// 767. Reorganize String

// I cheesed it by sorting the frequency array every time I added a character to the result string
// since the problem constraint is < 500 chars, it should be fine

/**
 * @param {string} s
 * @return {string}
 */
var reorganizeString = function(s) {
    let characters = new Map();
    for(let i = 0; i < s.length; i++) {
        if(characters.has(s.charAt(i))) {
            characters.set(s.charAt(i), characters.get(s.charAt(i)) + 1)
        }
        else {
            characters.set(s.charAt(i), 1)
        }
    }
    let chararr = Array.from(characters, ([char, count]) => ({ char, count }));
    let result = "";
    while(true) {
        chararr.sort((a,b) => {
            return b.count - a.count
        }); //sort from high to low (frequency)
        if(chararr.length == 0) break;
        if(result.length == 0) {
            result += chararr[0].char;
            chararr[0].count--;
            if(chararr[0].count == 0) {
                chararr.shift();
            }
        }
        else {
            let lastchar = result.charAt(result.length-1);
            if(chararr[0].char == lastchar) {
                // go next
                if(chararr.length == 1) {
                    return ""; // gg there its not possible
                }
                else {
                    result += chararr[1].char;
                    chararr[1].count--;
                    if(chararr[1].count == 0) {
                        chararr.splice(1,1);
                    }
                }
            }
            else {
                result += chararr[0].char;
                chararr[0].count--;
                if(chararr[0].count == 0) {
                    chararr.shift();
                }
            }
        }
    }
    return result;
};