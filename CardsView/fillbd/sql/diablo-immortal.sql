INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://diabloimmortal.blizzard.com/ru-ru/',
		'Diablo Immortal',
		'static/images/diablo-immortal/diablo-immortal-image.png',
		'static/images/diablo-immortal/diablo-immortal-video.gif',
		'static/images/diablo-immortal/diablo-immortal-logo.png',
		'Diablo Immortal',
		'NEW',
		0,
		NULL,
		ARRAY['Battle.net', 'https://us.shop.battle.net/ru-ru/family/diablo-immortal', 'App Store', 'https://apps.apple.com/us/app/diablo-immortal/id1492005122', 'Google Play', 'https://play.google.com/store/apps/details?id=com.blizzard.diablo.immortal&hl=en_US'],
		ARRAY['Windows', 'iOS', 'Android'],
		ARRAY['RPG', 'Action']
	);