// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ����
    �ڶ����ǽ�Ϲ��˿�����(paizi)��
LONG );
	set("exits", ([
		"south" : __DIR__"dong1",
                        "up" : __DIR__"bank2",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/qian" : 1
]));
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
set("no_clean_up", 0);
	set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
	set("no_beg", 1);
        set("no_dazuo", 1);
         set("no_fight",1);
        set("no_kill", 1);
      set("no_drop","����ɲ������Ӷ���\n");
	setup();
	replace_program(ROOM);
}
