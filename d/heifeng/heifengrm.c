// /d/heifeng/heifengrm.c

inherit ROOM;

void create()
{
        set("short", "�ڷ���");
        set("long", @LONG
�������ɽկ����Ĵ������м䲢�ŷ�������������
�Σ���λկ���ֱ��������档����վ������ɽ��������ǽ
�Ϲ��ż���������һ����֪������Ʒ��
LONG
        );
        set("exits", ([ 
            "south"   : __DIR__"corr03",
]));
	set("objects", ([
		"/clone/npc/npc" : 1,
				__DIR__"npc/toumu" : 3,	
	]));
        setup();
        replace_program(ROOM);
}

