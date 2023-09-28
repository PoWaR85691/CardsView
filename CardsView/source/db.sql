-- Database: CardsView

-- DROP DATABASE IF EXISTS "CardsView";

CREATE DATABASE "CardsView"
    WITH
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'Russian_Russia.1251'
    LC_CTYPE = 'Russian_Russia.1251'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1
    IS_TEMPLATE = False;
	


-- Table: public.cards_view

-- DROP TABLE IF EXISTS public.cards_view;

CREATE TABLE IF NOT EXISTS public.cards_view
(
    id integer NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 2147483647 CACHE 1 ),
    link text COLLATE pg_catalog."default" NOT NULL,
    name text COLLATE pg_catalog."default" NOT NULL,
    image text COLLATE pg_catalog."default" NOT NULL,
    video text COLLATE pg_catalog."default",
    logo text COLLATE pg_catalog."default" NOT NULL,
    description text COLLATE pg_catalog."default" NOT NULL,
    additional_mark text COLLATE pg_catalog."default",
    price real,
    discount real,
    links_to_description_stores text[] COLLATE pg_catalog."default" NOT NULL,
    platforms text[] COLLATE pg_catalog."default" NOT NULL,
    genres text[] COLLATE pg_catalog."default" NOT NULL,
    CONSTRAINT "CardsView_pkey" PRIMARY KEY (id)
)

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public.cards_view
    OWNER to postgres;