
// bank.c

inherit BANK;


void create()
{
        set("coor",({-50,4800,10}));
	set("short", "��ԴǮׯ");;
        set("long",
"����һ�������Թ�ƽ�������Ƶ�Ǯׯ��Ǯׯ���ϰ廹�Ǹ������й����˵Ķ����ˣ�����Կ�\n"
"��Ǯׯ�������ⶼ��ɨ��ǬǬ������һ�����ֵ����������ڹ�̨���棬��̨�Ϸ���һ������\n"
"(sign)����������Զ�Ǵ��\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mstreet2",
]));

        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ��


TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/banker": 1 ]) );
        setup();
}

