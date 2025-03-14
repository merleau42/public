백트래킹 = (state, choices, args, 해집합=[]) => {
	if ('순서쌍이_해를_만족함 || 온전한_순서쌍을_이룸') {
		console.log(state);
		해집합.push(state);
		return;
	}
	
    for (choice of choices) {
		state.push(choice);
		if ('조기탈락을_면함')
			백트래킹(state, choices, args, 해집합);
		state.pop();
	}

	return 해집합;
}

백트래킹([], choices, args)
