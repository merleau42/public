백트래킹 = (state, choices, args, completed, unrejectd, 해집합=[]) => {
	if (completed = '순서쌍이_해를_만족함 || 온전한_순서쌍을_이룸') {
		해집합.push([...state]);
		return;
	}
	
    for (choice of choices) {
		if (unrejectd = '곧바로_부정되지는_않는_미래인가?') {
			state.push(choice);
			백트래킹(state, choices, args, 해집합);
			state.pop();
		}
	}

	return 해집합;
}

백트래킹([], choices, args, completed, unrejectd);
