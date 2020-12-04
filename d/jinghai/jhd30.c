inherit ROOM;

void create()
{
        set("short", "海滩上");
        set("long", @LONG
这里的海水非常平缓，你举目四望，发现这片海滩位于一座
弯弯地斜伸向海面的石崖后面，而石崖没有遮挡一的面大约有数
十座小小的珊瑚礁伸出海面一丈多高，把汹涌的海浪拒之门外，
使这里成为一个天然的避风巷。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
        "northwest" : __DIR__"jhd28",
]));

        set("outdoors", "jinghai");

        setup();
}
