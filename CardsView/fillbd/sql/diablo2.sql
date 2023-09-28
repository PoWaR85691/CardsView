INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://diablo2.blizzard.com/ru-ru/',
		'Diablo II: Resurrected',
		'static/images/diablo2/diablo2-image.png',
		'static/images/diablo2/diablo2-video.gif',
		'static/images/diablo2/diablo2-logo.png',
		'Diablo II: Resurrected',
		NULL,
		59.99,
		0.33,
		ARRAY['Battle.net', 'https://eu.shop.battle.net/ru-ru/product/diablo_ii_resurrected'],
		ARRAY['Windows'],
		ARRAY['RPG', 'Action']
	);