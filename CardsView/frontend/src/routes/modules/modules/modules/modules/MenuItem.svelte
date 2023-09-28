<script lang="ts">
    export let name: string;
    export let icon: string;
    export let link: string | undefined = undefined;

    let intervalIn: number | undefined = undefined;
    let intervalOut: number | undefined = undefined;
    function mouseOnIcon(event: Event, isEnter: boolean): void {
        let info = (event.target as HTMLElement).querySelector(".item-info") as HTMLDivElement;

        clearInterval(intervalIn);
        clearInterval(intervalOut);
        intervalIn = undefined;
        intervalOut = undefined;

        if (isEnter) {
            info.classList.remove("hidden");
            intervalIn = setTimeout(() => info.classList.remove("opacity-0"), 10);
        } else {
            info.classList.add("opacity-0");
            intervalOut = setTimeout(() => info.classList.add("hidden"), 510);
        }
    }

    let canClick = true;
    function menuSelect(event: Event, isClick: boolean): void {
        event.preventDefault();
        event.stopPropagation();

        if (isClick || (event as KeyboardEvent).key == "Enter") {
            if ((event.target as HTMLDivElement).id == "item-info") {
                return;
            }
            if (!canClick) {
                return;
            }
            canClick = false;

            let item = event.target as HTMLDivElement;
            let menuItems = item.parentElement as HTMLDivElement;
            let mainContainer = menuItems.parentElement as HTMLDivElement;
            
            if (menuItems.id == "main-menu") {
                menuItems.classList.add("opacity-0");
                setTimeout(() => menuItems.classList.add("invisible"), 510);

                let selectedMenu = mainContainer.querySelector(`#${ item.id }-menu`) as HTMLDivElement;
                selectedMenu.classList.remove("invisible");
                setTimeout(() => selectedMenu.classList.remove("opacity-0"), 10);
            } else {
                if (item.id == "Back") {
                    menuItems.classList.add("opacity-0");
                    setTimeout(() => menuItems.classList.add("invisible"), 510); 

                    let mainMenu = mainContainer.querySelector("#main-menu") as HTMLDivElement;
                    mainMenu.classList.remove("invisible");
                    setTimeout(() => mainMenu.classList.remove("opacity-0"), 10);
                } else {
                    window.location.href = (event.target as HTMLLinkElement).href;
                }
            }

            setTimeout(() => canClick = true, 510);
        }
    }
</script>

{#if link}
    <a href={ link } class="menu-item" id={ name } style="background-image: url({ icon });" role="button" tabindex="-1" on:mouseenter={ (event) => mouseOnIcon(event, true) } on:mouseleave={ (event) => mouseOnIcon(event, false) } on:click={ (event) => menuSelect(event, true) } on:keydown={ (event) => menuSelect(event, false) }>
        <div class="item-info hidden opacity-0" id="item-info">{ name }</div>
    </a>
{:else}
    <div class="menu-item" id={ name } style="background-image: url({ icon });" role="button" tabindex="-1" on:mouseenter={ (event) => mouseOnIcon(event, true) } on:mouseleave={ (event) => mouseOnIcon(event, false) } on:click={ (event) => menuSelect(event, true) } on:keydown={ (event) => menuSelect(event, false) }>
        <div class="item-info hidden opacity-0" id="item-info">{ name }</div>
    </div>
{/if}

<style lang="postcss">
    .menu-item {
        @apply w-5 h-5 bg-center bg-cover bg-no-repeat relative flex justify-center opacity-80 hover:opacity-100 transition-opacity duration-500;
    }

    .item-info {
        @apply whitespace-nowrap absolute mt-[0.4rem] text-xs top-full border-[2px] rounded-[3px] px-1 py-[0.08rem] border-white bg-[#111111] transition-opacity duration-500;
    }
</style>