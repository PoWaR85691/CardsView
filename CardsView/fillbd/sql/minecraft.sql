INSERT INTO public.cards_view(
	link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres)
	VALUES (
		'https://tlauncher.org/',
		'Minecraft',
		'static/images/minecraft/minecraft-image.png',
		'static/images/minecraft/minecraft-video.gif',
		'static/images/minecraft/minecraft-logo.png',
		'Minecraft',
		NULL,
		1000000.0,
		1,
		ARRAY['Steam', 'https://tlauncher.org/', 'Google Play','https://4pda.to/forum/index.php?showtopic=260256', 'App Store', 'https://appstorrent.ru/475-minecraft.html'],
		ARRAY['Windows', 'Android', 'iOS'],
		ARRAY['Sandbox', 'Adventure']
	);