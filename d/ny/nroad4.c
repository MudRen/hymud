
// Room: /d/snow/nroad4.c

inherit ROOM;
int do_mercy(string arg);
void create()
{
	set("coor",({-40,4870,10}));
	set("short", "С��ͬ");
	set("long",
"���ߵ�һ����ͬ����������ţ������Ƕ���ǽ�������������˿ڵĵط���\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yamen_square",
]));
        set("item_desc", ([
                "sign": @TEXT
�����Ḹ���۸񣺣������ƽ�

mercy    ͬ��ʩ��ƽ�

TEXT
        ]) );
	set("no_clean_up", 0);
	set("outdoor","snow");
	setup();
}

void init()
{
	add_action("do_mercy", "mercy");
}

