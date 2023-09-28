INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://starcraft2.blizzard.com/ru-ru/',
		'Starcraft II',
		'static/images/starcraft2/starcraft2-image.png',
		'static/images/starcraft2/starcraft2-video.gif',
		'static/images/starcraft2/starcraft2-logo.png',
		'Starcraft II',
		NULL,
		39.99,
		NULL,
		ARRAY['Battle.net', 'https://us.shop.battle.net/ru-ru/family/starcraft-ii'],
		ARRAY['Windows'],
		ARRAY['Real-time strategy']
	);