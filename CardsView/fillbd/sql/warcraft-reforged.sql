INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://warcraft3.blizzard.com/ru-ru/',
		'Warcraft III: Reforged',
		'static/images/warcraft-reforged/warcraft-reforged-image.png',
		'static/images/warcraft-reforged/warcraft-reforged-video.gif',
		'static/images/warcraft-reforged/warcraft-reforged-logo.png',
		'Warcraft III: Reforged',
		NULL,
		39.99,
		0.25,
		ARRAY['Battle.net', 'https://eu.shop.battle.net/en-us/product/warcraft-iii-reforged'],
		ARRAY['Windows'],
		ARRAY['Real-time strategy']
	);