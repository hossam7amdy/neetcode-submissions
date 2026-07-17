class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        let result = "";
        for(const str of strs) {
            result += `${str.length}#${str}`;
        }
        return result;
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        const result = [];
        
        const process = (str) => {
            if(str.length === 0) return;

            const hashIndex = str.indexOf('#');
            const substrLen = +str.substring(0, hashIndex);
            
            const startIndex = hashIndex + 1;
            const endIndex = startIndex + substrLen;
            const curStr = str.substring(startIndex, endIndex);
            
            result.push(curStr);
            process(str.substring(endIndex));
        }

        process(str);
        return result;
    }
}