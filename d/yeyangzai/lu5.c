// Room: /open/stst/sazai/lu5.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
        �����Ұ��կ����Ϣ�ҡ�կ��ĵ����Ǵ��������˺��������ƽ
ʱû�¾��ڴ���Ϣ�����������߰���İ����˴����������������Ϣ��

LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"qianting",
]));
	set("objects",([
		__DIR__"npc/xiaotong":1,
		__DIR__"npc/chick":1,	
]));

        //set("no_fight", 1);
        set("sleep_room", 1);
        setup();
        replace_program(ROOM);
}


