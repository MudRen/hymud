// Room: /d/fengtian/ftf1.c

inherit ROOM;

void create()
{
	set("short", "ʢ�������ſ�");
	set("long", @LONG
������ʢ�������������ڵأ��ſ������������ֳ��ջ����
ֱ��վ����������������������ŵ�ʯʨ�ӣ����ſڻ���һ��
��ģ��������ԩ������������������ԩ�� 
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xm2",
]));

        set("objects",([
        	__DIR__"npc/bing" :5,        
        	__DIR__"npc/wujiang" :1,        	
        ]));

        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
