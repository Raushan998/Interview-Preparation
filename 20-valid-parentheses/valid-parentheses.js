/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const arr = [];
    for(const x of s){
        if(x=='(' || x == '[' || x=='{')
           arr.push(x);
        else if(x==')' && arr.at(-1) == '(')
            arr.pop();
        else if(x=='}' && arr.at(-1) == '{'){
            arr.pop();
        }
        else if(x==']' && arr.at(-1) == '['){
            arr.pop();
        }
        else
           return false;
    }
    return arr.length === 0;
};