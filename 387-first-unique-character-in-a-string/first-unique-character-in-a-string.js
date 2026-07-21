/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    const obj = {};
    for(const x in s){
        if(s[x] in obj){
            obj[s[x]]+=1;
        }
        else{
            obj[s[x]]=1;
        }
    }
    console.log(obj)
    for(let i=0;i<s.length;i++){
        if(obj[s[i]]==1)return i;
    }
    return -1;
};