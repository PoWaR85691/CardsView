INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://hearthstone.blizzard.com/ru-ru',
		'HearthStone',
		'static/images/hearthstone/hearthstone-image.png',
		'static/images/hearthstone/hearthstone-video.gif',
		'static/images/hearthstone/hearthstone-logo.png',
		'HearthStone',
		NULL,
		0,
		NULL,
		ARRAY['Battle.net', 'https://us.shop.battle.net/ru-ru/family/hearthstone', 'Google Play', 'https://play.google.com/store/apps/details?id=com.blizzard.wtcg.hearthstone&hl=ru&gl=US', 'App Store', 'https://apps.apple.com/ru/app/hearthstone/id625257520'],
		ARRAY['Windows', 'Android', 'iOS'],
		ARRAY['Collectible card game']
	);