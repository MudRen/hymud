//Cracked by Roath

inherit ROOM;
void create()
{
  set ("short", "大漠江州");
  set ("long", @LONG

    这个地方就是江州的东门了，这个地方比起长安城可真是差远了。
这个地方 虽然 和 江西的江州同名，但地处大漠 城市要小的多了。
 一眼东望，可以看到路上疏疏朗朗的几个行人，这个城门看起来
也很旧了。上书：
[1;32m
                ※※※※※※※※※※※※
                ※                    ※
                ※    江        州    ※
                ※                    ※
                ※※※※※※※※※※※※
[m
LONG);
        set("exits", ([
  "west" : __DIR__"sibei-w2",
  "north": "/d/qujing/shuangcha/shanlu1",
]));
        set("objects", ([
  "/d/city/npc/wujiang":2,
                ]));
  setup();
}
