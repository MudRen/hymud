 inherit ROOM;
void create()
{
        set("short", "南风街南");
        set("long", @LONG
白天这里门可罗雀，但一到夜晚，就车水马龙，热闹得成了不夜之都。西侧的
千金楼名声显赫，方圆千里的有钱人都愿意到这里来一掷千金，就算是没钱的穷小
子也会有事没事来转转，希望一睹楼里姑娘的芳容。千金楼为了方便客人，又在对
面开了一座千银当铺。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind5",
  "north" : __DIR__"swind3",
  "east" : __DIR__"qianyin",
//  "west" : AREA_QIANJIN"qianjin",
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
