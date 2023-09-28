<script lang="ts">
    import type { IGame } from "../Card.svelte";
    export let game: IGame;

    import Platforms from "./modules/Platforms.svelte";
    import Genre from "./modules/Genre.svelte";
    import Price from "./modules/Price.svelte";
</script>

<div class="info">
    <h2 class="name">{ game.name }</h2>
    <Platforms { game }/>
    <Genre { game }/>
    <Price { game }/>
</div>

<style lang="postcss">
    .info {
        @apply rounded-b-[5px] flex flex-col grow px-3 pt-1 pb-3 text-[#F7F7F7];
        background: linear-gradient(180deg, #111111 0%, #293441 100%);
    }

    .name {
        @apply text-lg font-bold;
    }
</style>