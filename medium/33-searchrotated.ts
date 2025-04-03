// 33. Search in Rotated Sorted Array

// strat: binary search for pivot, then binary search for target

function search(nums: number[], target: number): number {
    if(nums.length == 1) {
        return target == nums[0] ? 0 : -1;
    }
    let start = 0;
    let end = nums.length-1;
    let k = 0;
    while(true) {
        if(start == end) {
            k = nums.length - start;
            break;
        }
        let mid = Math.floor((start+end)/2)
        if(nums[mid] < nums[end]) {
            end = mid;
        }
        else {
            start = mid+1;
        }
    }

    if(k == nums.length) {
        k = 0;
    }

    let bsStart = 0;
    let bsEnd = nums.length - 1;

    function getArrIdx(index: number) {
        if(index >= k) {
            return index-k;
        }
        else {
            return nums.length - k + index;
        }
    }
    
    while(true) {
        if(bsStart == bsEnd) {
            if(nums[getArrIdx(bsStart)] == target) {
                return getArrIdx(bsStart);
            }
            else {
                return -1;
            }
        }
        let mid = Math.floor((bsStart+bsEnd)/2)

        if(nums[getArrIdx(mid)] < target) {
            bsStart = mid+1;
        }
        else {
            bsEnd = mid;
        }
    }
};
