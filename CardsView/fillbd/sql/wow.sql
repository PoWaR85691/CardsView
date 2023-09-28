INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://worldofwarcraft.blizzard.com/ru-ru/',
		'World of Warcraft',
		'static/images/wow/wow-image.png',
		'static/images/wow/wow-video.gif',
		'static/images/wow/wow-logo.png',
		'World of Warcraft',
		NULL,
		0,
		NULL,
		ARRAY['Battle.net', 'https://us.shop.battle.net/ru-ru/family/world-of-warcraft'],
		ARRAY['Windows'],
		ARRAY['MMORPG']
	);