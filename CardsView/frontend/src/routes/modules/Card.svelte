<script lang="ts" context="module">
    export interface IGame {
        link: string,
        name: string,
        image: string,
        video: string | null,
        logo: string,
        description: string,
        additionalMark: string | null,
        price: number | null,
        discount: number | null,
        linksToDescriptionStores: Record<string, string>,
        platforms: string[],
        genres: string[]
    };
</script>
<script lang="ts">
    import { fly } from "svelte/transition";

    export let game: IGame;
    
    import Image from "./modules/Image.svelte";
    import Info from "./modules/Info.svelte";

    function mouseOnCard(event: Event, isEnter: boolean): void {
        let image = (event.target as HTMLDivElement).querySelector(".image") as HTMLDivElement;
        image.style.setProperty("background-image", `url(${ (isEnter && game.video) ? game.video : game.image })`);
    }
</script>

<a href={ game.link } class="card" role="button" tabindex="0" on:mouseenter={ (event) => mouseOnCard(event, true) } on:mouseleave={ (event) => mouseOnCard(event, false) } transition:fly={{ duration: 500, x: -0.05*window.innerWidth, y: -0.05*window.innerHeight }}>
    <Image {game}/>
    <Info {game}/>
</a>

<style lang="postcss">
    .card {
        @apply flex flex-col border border-black rounded-[5px];
    }
</style>