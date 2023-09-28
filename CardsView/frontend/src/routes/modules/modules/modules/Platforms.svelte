<script lang="ts">
    import type { IGame } from "../../Card.svelte";
    export let game: IGame;

    import MenuItem from "./modules/MenuItem.svelte";

    import PlatformsConfigJSON from "./PlatformsConfig.json";
    type PlatformConfig = Record<string, {
        icon: string,
        stores: Record<string, {
            icon: string;
        }>
    }>;
    let platformsConfig = PlatformsConfigJSON as PlatformConfig;
</script>

<div class="main-container">
    <!-- Main menu -->
    <div class="menu-items" id="main-menu">
        {#each game.platforms as platform}
            <MenuItem name={ platform } icon={ platformsConfig[platform].icon }/>
        {/each}
    </div>

    <!-- Platform menu -->
    {#each game.platforms as platform}
        <div class="menu-items absolute top-0 invisible opacity-0" id="{ platform }-menu">
            <!-- Stores -->
            {#each Object.keys(platformsConfig[platform].stores) as store}
                {#if store in game.linksToDescriptionStores}
                    <MenuItem name={ store } icon={ platformsConfig[platform].stores[store].icon } link={ game.linksToDescriptionStores[store] }/>
                {/if}
            {/each}
            <!-- Back -->
            <MenuItem name="Back" icon="static/icons/store-icons/Back.svg"/>
        </div>
    {/each}
</div>

<style lang="postcss">
    .main-container {
        @apply relative;
    }

    .menu-items {
        @apply flex mb-[0.4rem] gap-[0.6rem] font-normal text-[#FFFFFF] transition-opacity duration-500;
    }
</style>