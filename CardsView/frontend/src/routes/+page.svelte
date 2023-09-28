<script lang="ts">
    import { onMount } from "svelte";
    import Card from "./modules/Card.svelte";
    import type { IGame } from "./modules/Card.svelte";

    let games: IGame[] = [];
    
    // Управление загрузкой элементов
    let fromId = 0;
    let hasMore = true;

    // Расчет количества элементов на загрузку и предотвращения, если возможно, возникновения постых мест
    function calcToLoad(rows: number): number {
        // Определение количества столбцов в зависимости от экрана для прогрузки
        let widthCols: Record<number, number> = {
                0: 2,
                576: 3,
                1200: 4
            };
            let cols: number = 0;
            for (let px in widthCols) {
                if (window.innerWidth >= Number(px)) {
                    cols = widthCols[px];
                }
                else {
                    break;
                }
            }

            // Дополнительные элементы на прогрузку для предотвращения появления пустых мест в конце
            let additionalLoad: number = 0;
            if (games.length % cols != 0) {
                additionalLoad = cols - games.length % cols;
            }

            return (cols * rows + additionalLoad);
    }

    // Загрузка из сервера
    async function showMore(needToLoad: number): Promise<void> {
        let response: Response;
        try {
            response = await fetch("/getdata", {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ 
                    fromId,
                    count: needToLoad + 1 // +1 для проверки на достижение конца таблицы
                }),
            });
        } catch {
            return;
        }
        let data: { finalId: number, data: IGame[] } = await response.json();
        
        fromId = data.finalId;
        // Проверка на достижение конца таблицы
        if (data.data.length <= needToLoad) {
            hasMore = false;
            fromId++;
        }
        games = [...games, ...data.data.slice(0, needToLoad)];
    }

    // Для обработчиков событий
    async function showMoreHandler(event: Event, isPress: boolean) : Promise<void> {
        if (!isPress || (event as KeyboardEvent).key == "Enter") {
            await showMore(calcToLoad(3));
        }
    }

    // Начальная загрузка
    onMount(async () => {
        // Обработка предзагрузки
        let staticData = document.querySelector(".static-data");

        // !!! Игнорируй ошибки !!!
        if (staticJson) {
            fromId = staticJson.finalId + 1; // Для предотвращения дублирования последнего элемента в начальной загрузке
            games = [...games, ...staticJson.data];
        }

        staticData?.remove();
        
        await showMore(calcToLoad(0)); // Закрыть пустые места
    });

    // Загрузка при прокрутке
    let btn: HTMLDivElement;
    onMount(() => {
        btn = document.querySelector(".load-btn") as HTMLDivElement;
        window.addEventListener("scroll", (event: Event) => {
            if (hasMore) {
                if ((window.scrollY + window.innerHeight) >= (btn.offsetTop + btn.offsetHeight * 0.9)) {
                    showMoreHandler(event, false);
                }
            }
        });
    });
</script>

<div class="page">
    <div class="games">
        {#each games as game}
            <Card { game }/>
        {/each}
    </div>
    {#if hasMore}
        <div class="load-btn" role="button" tabindex="0" on:click={ async (event) => await showMoreHandler(event, false) } on:keydown={ (event) => showMoreHandler(event, true) } on:scroll>Show more...</div>
    {/if}
</div>

<style lang="postcss">
    :global(html) {
        @apply bg-[#111111] text-white;
        font-family: Arial, Helvetica, sans-serif;
        font-size: calc(9px + 12 * (100vw / 1920));
    }

    .page {
        @apply grid grid-cols-2 sm:grid-cols-3 xl:grid-cols-5;
    }

    .games {
        @apply xl:col-start-2 col-span-full grid grid-cols-2 sm:grid-cols-3 xl:grid-cols-4;
    }

    .load-btn {
        @apply xl:col-start-2 col-span-full text-center bg-[#191919] text-[#CDCDCD] py-[1rem] font-black hover:cursor-pointer hover:text-[#A0A0A0] transition-colors duration-500;
    }
</style>