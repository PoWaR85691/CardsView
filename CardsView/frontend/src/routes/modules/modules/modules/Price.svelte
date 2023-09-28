<script lang="ts">
    import type { IGame } from "../../Card.svelte";
    export let game: IGame;
</script>

{#if game.price !== null}
    <div class="price">
        {#if game.price === 0} <!-- Бесплатно -->
            <p class="now">Free</p>
        {:else if !game.discount} <!-- Без скидки -->
            <p class="now">${ game.price.toFixed(2) }</p>
        {:else} <!-- Со скидкой -->
            <p class="old">${ game.price.toFixed(2) }</p>
            <p class="discount">-{ (game.discount * 100).toFixed(0) }%</p>
            {#if game.discount != 1} <!-- Скидка 100% -->
                <p class="now">${ (game.price * (1 - game.discount)).toFixed(2) }</p>
            {:else}
                <p class="now">Free</p>
            {/if}
        {/if}
    </div>
{/if}

<style lang="postcss">
    .price {
        @apply grid grid-cols-3 items-center mt-auto h-6;
    }

    .old {
        @apply justify-self-start text-base line-through text-[#A8A8A8];
    }

    .discount {
        @apply justify-self-center pl-[0.4rem] pr-[0.3rem] text-xl text-[#BEEE10] leading-none py-[0.1rem] font-bold bg-[#4C6B21] rounded-[3px];
    }

    .now {
        @apply justify-self-end col-start-3 text-lg font-semibold;
    }
</style>