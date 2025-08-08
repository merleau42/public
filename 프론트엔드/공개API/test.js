state = {영화목록: []};
function yts20(num){
	return fetch(`https://yts.mx/api/v2/list_movies.json?page=${num}`)
		.then(res => res.json())
		.then(obj => obj.data.movies.map((mv, i) => ({
			url: mv.url,
			title: mv.title,
			year: mv.year,
			rating: mv.rating,
			genres: mv.genres,
			runtime: mv.runtime,
			image: mv.large_cover_image,
			API: `(${num}, ${i})`
		})))
		.then(movies => state.영화목록 = movies );
}

function sample(){
	return fetch(`https://yts.mx/api/v2/list_movies.json?page=1&quality=1080p`)
		.then(res => res.json())
		.then(json => console.log(json.data.movies.map(mv => mv.title),  json.data.movies[0]))
}


sample();

[
	'Solids by the Seashore',
	'Say God Bye',
	'Little Tornadoes',
	'Dreaming the Reality',
	'Straight Through Crew',
	'The Blessing and the Curse',
	"Clayburn Cox: So Here's the Thing",
	'Horatio Gould: Sweet Prince',
	'The Bones',
	'The Waterboyz',
	'Night Carnage',
	"Rock 'n' Roll Guns for Hire: The Story of the Sidemen",
	'Normandie - Niémen',
	'Dean',
	'The Pickup',
	'Karate Warrior 3',
	'Surviving the Tunisia Beach Attack',
	"Don't Tell",
	'Doar cu buletinul la Paris',
	'Hercules Returns'
  ];

  [
	'Little Tornadoes',
	'Dreaming the Reality',
	'Straight Through Crew',
	'The Blessing and the Curse',
	"Clayburn Cox: So Here's the Thing",
	'Horatio Gould: Sweet Prince',
	'The Bones',
	'The Waterboyz',
	'Night Carnage',
	'Night Carnage',
	"Rock 'n' Roll Guns for Hire: The Story of the Sidemen",
	'Normandie - Niémen',
	'Dean',
	'The Pickup',
	'Karate Warrior 3',
	'Surviving the Tunisia Beach Attack',
	"Don't Tell",
	'Doar cu buletinul la Paris',
	'Hercules Returns',
	'The United States of America'
  ]