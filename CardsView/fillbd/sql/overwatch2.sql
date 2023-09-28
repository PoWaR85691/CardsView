INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://overwatch.blizzard.com/ru-ru/',
		'Overwatch 2',
		'static/images/overwatch2/overwatch2-image.png',
		'static/images/overwatch2/overwatch2-video.gif',
		'static/images/overwatch2/overwatch2-logo.png',
		'Overwatch 2',
		'SOON',
		NULL,
		NULL,
		ARRAY['Battle.net', 'https://eu.shop.battle.net/ru-ru/product/overwatch', 'Steam', 'https://store.steampowered.com/app/2357570/Overwatch_2/'],
		ARRAY['Windows'],
		ARRAY['First-person shooter']
	);