
// Room: /u/cloud/nwroad1.c


inherit ROOM;

void create()
{
        set("coor",({2000,3950,0}));
	set("short", "���г�");
        set("long",
"�����������ı��г������򱱾�������ˡ�һ�ɲ������������ϵ���ζ�˱Ƕ���������\n"
"��������Ÿ�ţͷ;�����ǼҶ���Ĳ�¥����������ʮ�ֻ��ۡ�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"butchery",
  "north" : __DIR__"entrance",
  "south" : __DIR__"nwroad2",
  "east" : __DIR__"tearoom",
]));
        set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

