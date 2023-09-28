INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://us.diablo3.blizzard.com/ru-ru/',
		'Diablo III',
		'static/images/diablo3/diablo3-image.png',
		'static/images/diablo3/diablo3-video.gif',
		'static/images/diablo3/diablo3-logo.png',
		'Diablo III',
		NULL,
		19.99,
		NULL,
		ARRAY['Battle.net', 'https://us.shop.battle.net/ru-ru/family/diablo-iii'],
		ARRAY['Windows'],
		ARRAY['RPG', 'Action']
	);