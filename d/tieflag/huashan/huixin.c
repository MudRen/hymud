 inherit ROOM;
void create()
{
        set("short", "迴心石");
        set("long", @LONG
山回路转，又开始了登山的道路，突然眼前路边出现一块巨石，石高数丈，一
面比较平整，上有篆体题刻“迴心石”三字。由“迴心石”拾级东上向北折，一条狭窄
的石峰中，凿有370多个台阶，便是华山第一险，千尺幢。
LONG
        );
    set("exits", ([ 
                "northdown" : __DIR__"qingke",
                "southup" : __DIR__"qianchi",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-580);
    set("coor/y",-80);
    set("coor/z",50);
        setup();
    replace_program(ROOM);
} 
