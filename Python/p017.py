
oneWords = ['-', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];
teenWords = ['-', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen'];
tenWords = ['-', 'ten', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety'];
hundred = "hundred";
orderWords = ['-', 'thousand', 'million', 'billion', 'trillion', 'quadrillion', 'quintillion', 'sextillion', 'septillion', 'octillion', 'nonillion', 'decillion', 'undecillion', 'duodecillion', 'tredecillion', 'quattuordecillion', 'quindecillion', 'sexdecillion', 'septen-decillion', 'octodecillion', 'novemdecillion', 'vigintillion'];

import math
import sys

def num2word(n):
	if n == 0:
		return 'zero';
	order = int(math.log(n)/math.log(1e3));
	if (len(orderWords) <= order):
		return 'Err: the number %s is to high!';
	if (order > 0):
		ll = int(1e3**order)
		if (n % ll == 0):
			return " ".join([num2word(n/ll), orderWords[order]]);
		return " ".join([num2word(n/ll), orderWords[order], num2word(n%ll)]);
	if (n < 10):
		return oneWords[n];
	if (n < 20):
		return teenWords[n-9];
	if (n < 100):
		if (n % 10 == 0):
			return tenWords[n/10];
		return " ".join([tenWords[n/10], oneWords[(n%10)]])
	if (n % 100 == 0):
		return " ".join([oneWords[n/100], hundred]);
	return " ".join([oneWords[n/100], hundred, "and", num2word(n % 100)]);


print len("".join(map(num2word, range(1,1001))).replace(" ", "").replace("-", ""));

'''
for n in range(1000):
	print "%3d: %s" % (n, num2word(n));
'''

'''
for n in map(int, sys.argv[1:]):
	print "%3d: %s" % (n, num2word(n));
	'''
