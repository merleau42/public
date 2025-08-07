console.clear();

state = {영화목록: []};
function yts_page(num){
	fetch(`https://yts.mx/api/v2/list_movies.json?page=${num}`)
		.then(res => res.json())
		.then(obj => obj.data.movies.map(mv => ({
			url: mv.url,
			title: mv.title,
			year: mv.year,
			rating: mv.rating,
			genres: mv.genres,
			runtime: mv.runtime,
			image: mv.large_cover_image,
		})))
		.then(movies => state.영화목록 = movies )
		.then(_=> console.log(state.영화목록));
}

yts_page(1);