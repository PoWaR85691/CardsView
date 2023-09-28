<script lang="ts">
    import type { IGame } from "../../Card.svelte";
    export let game: IGame;
</script>

<p class="genre">
    {#each game.genres as genre, i}
        <span>{ genre }</span>
        {#if i != game.genres.length - 1}
            <span> / </span>
        {/if}
    {/each}
</p>

<style lang="postcss">
    .genre {
        @apply text-xs font-bold;
    }
</style>