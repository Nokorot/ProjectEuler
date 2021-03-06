package noko;
import static noko.Prints.print;
import static noko.Utils.sum;

import java.util.ArrayList;
import java.util.List;

// 
public class P68 {
	
	int[] problemForm(Integer[] nums) {
		int l = nums.length/2;
		int[] res = new int[l*3];
		for(int i=0;i<l;i++) {
			res[i*3] = nums[i];
			res[i*3+1] = nums[l+i];
			res[i*3+2] = nums[l+(i+1)%l];
		}
		return res;
	}
	
	boolean isMagic(int[] nums) {
		int s = sum(nums, 0, 3);
		for (int i=1; i<nums.length/3; i++) 
			if (s != sum(nums, i*3, 3))
				return false;
		return true;
	}

	void permutations(List<int[]> perms, List<Integer> nums, List<Integer> pre){
		if (nums.size() == 0) {
			int l = pre.size()/2;
			int k = pre.get(0);
			for(int i=1; i<l; i++)
				if (pre.get(i) < k)
					return;
			int[] h = problemForm(pre.toArray(new Integer[pre.size()]));
			if(isMagic(h)) {
				perms.add(h);
			}
		}
		
		for(int i=0;i<nums.size();i++) {
			List<Integer> sub = new ArrayList<Integer>(nums);
			sub.remove(i);
			
			List<Integer> npre = new ArrayList<Integer>(pre);
			npre.add(nums.get(i));
			
			permutations(perms, sub, npre);
		}
	}	
	
	List<int[]> permutations(List<Integer> nums){
		List<int[]> perms = new ArrayList<int[]>();
		
		for(int i=0;i<nums.size();i++) {
			List<Integer> sub = new ArrayList<Integer>(nums);
			sub.remove(i);
			List<Integer> pre = new ArrayList<Integer>();
			pre.add(nums.get(i));
			permutations(perms, sub, pre);
		}
		return perms;
	}
	
	public P68(String[] args) {
		List<Integer> nums = new ArrayList<Integer>();
		for(int i=0;i<12;i++)
			nums.add(i+1);
		
		for(int[] mr : permutations(nums)) {
			String[] ss = new String[mr.length];
			for(int i=0;i<mr.length;i++) 
				ss[i] = Integer.toString(mr[i]);
			print(String.join("", ss));
		}
		
	}

}
