inherit ROOM;
void create()
{
    set("short","驿道");
    set("long",@LONG
过了秦州，渐入岷州地界，南部的崇山峻岭地势愈加升高。山中多居住着西
蕃蛮部，不时出山骚扰州县田庄。翻山过去即是吐蕃国境。西去四百多里就是边
境，北面是大片良田，零星散布着一些田庄和军寨。
LONG);
    set("exits",([
        "southeast"   : __DIR__"yidao3",
        "west"  : __DIR__"yidao5",
    ]));
 set("outdoors","xibei");
    setup();
}

