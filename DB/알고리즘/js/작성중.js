백트래킹 = (first, dest, 상태=[], 깊이=0, 해집합=[]) => {
	if ('온전한_순서쌍을_이룸') {
		'성질을_알아보기_위한_변수선언';
		if ('순서쌍이_해를_만족함')
			해집합.push(상태);
		return ;
	}

    for (e of range(first[d], dest[d] + 1)) {
		if ('곧바로_부정되지는_않는_미래인가?') {
			상태.push(e);
			백트래킹(first, dest, 상태, 깊이+1, 해집합);
			상태.pop();
		}
	}
	
	return 해집합;
}

백트래킹([], choices, args);
	