// lzxiaolu.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "����С·");
	set("long", @LONG
С·���ߵĹ�ľԽ��Խ�࣬·���ϵľ�����ʱ�İ�����ֽŻ��ƣ�һЩ��
���г���ٿ�Ĵڳ�һ�����ߣ������ľ�������
LONG	);

	set("outdoors", "houjizhen");

	set("exits", ([ 
                 "east" : __DIR__"shigang",
                 "northwest" : __DIR__"songlin1",
])); 

	  setup();
           replace_program(ROOM);
}

