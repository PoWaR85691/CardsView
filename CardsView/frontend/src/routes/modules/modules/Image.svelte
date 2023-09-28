<script lang="ts">
    import type { IGame } from "../Card.svelte";
    export let game: IGame;
</script>

<div class="image" style="background-image: url({ game.image });">
    <div class="logo" style="background-image: url({ game.logo });"></div>
    {#if game.additionalMark}
        <div class="mark">{ game.additionalMark }</div>
    {/if}
</div>

<style lang="postcss">
    .image {
        @apply pt-[100%] rounded-t-[5px] relative bg-center bg-cover transition-[background-image] duration-500;
    }

    .logo {
        @apply absolute bottom-0 w-full bg-contain bg-no-repeat bg-bottom h-full;
    }

    .mark {
        @apply absolute top-[4%] left-[4%] bg-black border-[3px] border-white rounded-[4px] font-bold px-[0.4rem] py-[0.1rem];
    }
</style>