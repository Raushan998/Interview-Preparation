/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let str="";
    strs.sort((a, b)=>(a.length-b.length))
    const data = strs[0];
    for(const x in data){
        let flag=true;
        for(let y in strs){
            if(strs[y][x] != data[x]){
                flag=false;
                break
            }
        }
        if(!flag)return str;
        str= str + data[x];
    }
    return str;
};