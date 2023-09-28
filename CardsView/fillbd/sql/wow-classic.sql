INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://wowclassic.blizzard.com/ru-ru/',
		'World of Warcraft Classic',
		'static/images/wow-classic/wow-classic-image.png',
		'static/images/wow-classic/wow-classic-video.gif',
		'static/images/wow-classic/wow-classic-logo.png',
		'World of Warcraft Classic',
		NULL,
		79.99,
		0.25,
		ARRAY['Battle.net', 'https://us.shop.battle.net/ru-ru/family/world-of-warcraft-classic'],
		ARRAY['Windows'],
		ARRAY['MMORPG']
	);